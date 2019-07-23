//이후로 다루는 대부분의 코드는 ITCOOKBOOK 윈도우네트워크프로그래밍 김선우저 소스에서 가져다 사용합니다.
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 512

// 소켓 함수 오류 출력 후 종료
void err_quit(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER| // 오류 메시지 저장 메모리를 내부에서 할당하라
		FORMAT_MESSAGE_FROM_SYSTEM, //운영체제로 부터 오류 메시지를 가져온다
		NULL, 
        WSAGetLastError(), //오류 코드를 정수형으로 가져온다
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), //언어(제어판 설정 언어)
		(LPTSTR)&lpMsgBuf, // 오류 메시지 outparameter 정수로 되어있는 오류코드를 문자열로 받아온다.
        0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf); // 오류 메시지 저장 메모리 반환 
	exit(-1);
}

// 소켓 함수 오류 출력
void err_display(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER|
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	printf("[%s] %s", msg, (LPCTSTR)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

int main(int argc, char* argv[])
{
	int retval;

	// 윈속 초기화
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2)/*2바이트,버전명*/, &wsa/**/) != 0)  //초기화함수,WSACleanup();가 있어야한다.
		return -1;

	// socket()
	SOCKET listen_sock = socket( //대기소켓 생성 & 핸들
        AF_INET, //주소체계: 통신 영역 설정, 인터넷 영역을 사용하며 리모트 컴퓨터 사이의 통신을 사용, IPv4
		//네트워크 군을 표시한다. 보안을 위해서 외부와 차단할때 사용,주소 패밀리군이라고도 한다.
		//주소체계마다 접속할수있는 군이 다르다.
        SOCK_STREAM, //프로토콜유형: TCP/IP 기반 사용, SOCK_STREAM(TCP기반) , SOCK_DEGRAM(UDP기반)
        0 //앞 두 인자로 프로토콜 결정이 명확하면 0사용, IPPROTO_TCP, IPPROTO_UDP
        );
	if(listen_sock == INVALID_SOCKET) err_quit("socket()");
	
	// bind() - 대기소켓의 주소체계와 지역포트번호,지역 IP결정
	SOCKADDR_IN serveraddr; 
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET; //주소체계
	serveraddr.sin_port = htons(9000); //지역포트번호 (htons메서드 => 정수를 네트워크 형태로 변환 )
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); //지역IP 주소 ,address
	retval = bind(listen_sock/*소켓넘겨줌*/, (SOCKADDR *)&serveraddr/*in-out parameter*/, sizeof(serveraddr));
	if(retval == SOCKET_ERROR) err_quit("bind()");
	
	// listen()
	retval = listen(  //적어도 listen까지는 성공해야 클라이언트 접속 가능
        listen_sock, 
        SOMAXCONN //접속대기 큐의 크기,SOMAXCONN : 최대갯수
        ); // TCP 상태를 LISTENING 변경
	if(retval == SOCKET_ERROR) err_quit("listen()");

	// 데이터 통신에 사용할 변수
	SOCKET client_sock;
	SOCKADDR_IN clientaddr;
	int addrlen;
	char buf[BUFSIZE+1];

	while(1){
		// accept()
		addrlen = sizeof(clientaddr);
		client_sock = accept( //통신소켓의 핸들
            listen_sock, //대기 소켓
            (SOCKADDR *)&clientaddr, //클라이언트의 정보 out param 구조체 out-parameter
            &addrlen //주소구조체형식의크기, in(크기지정), out(초기화한크기반환) param
            ); //통신소켓 생성: 원격 IP, 원격 포트 결정
		if(client_sock == INVALID_SOCKET){ //통신소켓이 만들어졌니? 그럼 출력!
			err_display("accept()");
			continue;
		}
		printf("\n[TCP 서버] 클라이언트 접속: IP 주소=%s, 포트 번호=%d\n",
			inet_ntoa(clientaddr.sin_addr), //문자열로 IP주소 변환
            ntohs(clientaddr.sin_port) // 포트번호 network to host
            );

		// 클라이언트와 데이터 통신
		while(1){
			// 데이터 받기
			retval = recv( //recv도 blocking함수이다. 실제 바이트수를 retval에 전달한다.0이전달되면 정상종료를 뜻함. 실제 데이터를 보내면 바이트수를반환
                client_sock, //통신소켓핸들
                buf, //받을 애플리케이션 버퍼
                BUFSIZE, //수신 버퍼의 최대 크기
                0 //대부분 0 or MSG_PEEK와 MSG_OOB를 사용 가능, 지금은 무조건 0이라고 생각하면 된다.
                );
			if(retval == SOCKET_ERROR){
				err_display("recv()");
				break;
			}
			else if(retval == 0){
				break;
			}
			else{
				// 받은 데이터 출력
				buf[retval] = '\0';
				printf("%s", buf);
			}
		}

		// closesocket()
		closesocket(client_sock);
		printf("\n[TCP 서버] 클라이언트 종료: IP 주소=%s, 포트 번호=%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
	}

	// closesocket()
	closesocket(listen_sock);

	// 윈속 종료
	WSACleanup();
	return 0;
}