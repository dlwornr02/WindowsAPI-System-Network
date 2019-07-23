//���ķ� �ٷ�� ��κ��� �ڵ�� ITCOOKBOOK �������Ʈ��ũ���α׷��� �輱���� �ҽ����� ������ ����մϴ�.
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 512

// ���� �Լ� ���� ��� �� ����
void err_quit(char *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER| // ���� �޽��� ���� �޸𸮸� ���ο��� �Ҵ��϶�
		FORMAT_MESSAGE_FROM_SYSTEM, //�ü���� ���� ���� �޽����� �����´�
		NULL, 
        WSAGetLastError(), //���� �ڵ带 ���������� �����´�
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), //���(������ ���� ���)
		(LPTSTR)&lpMsgBuf, // ���� �޽��� outparameter ������ �Ǿ��ִ� �����ڵ带 ���ڿ��� �޾ƿ´�.
        0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf); // ���� �޽��� ���� �޸� ��ȯ 
	exit(-1);
}

// ���� �Լ� ���� ���
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

	// ���� �ʱ�ȭ
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2)/*2����Ʈ,������*/, &wsa/**/) != 0)  //�ʱ�ȭ�Լ�,WSACleanup();�� �־���Ѵ�.
		return -1;

	// socket()
	SOCKET listen_sock = socket( //������ ���� & �ڵ�
        AF_INET, //�ּ�ü��: ��� ���� ����, ���ͳ� ������ ����ϸ� ����Ʈ ��ǻ�� ������ ����� ���, IPv4
		//��Ʈ��ũ ���� ǥ���Ѵ�. ������ ���ؼ� �ܺο� �����Ҷ� ���,�ּ� �йи����̶�� �Ѵ�.
		//�ּ�ü�踶�� �����Ҽ��ִ� ���� �ٸ���.
        SOCK_STREAM, //������������: TCP/IP ��� ���, SOCK_STREAM(TCP���) , SOCK_DEGRAM(UDP���)
        0 //�� �� ���ڷ� �������� ������ ��Ȯ�ϸ� 0���, IPPROTO_TCP, IPPROTO_UDP
        );
	if(listen_sock == INVALID_SOCKET) err_quit("socket()");
	
	// bind() - �������� �ּ�ü��� ������Ʈ��ȣ,���� IP����
	SOCKADDR_IN serveraddr; 
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET; //�ּ�ü��
	serveraddr.sin_port = htons(9000); //������Ʈ��ȣ (htons�޼��� => ������ ��Ʈ��ũ ���·� ��ȯ )
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); //����IP �ּ� ,address
	retval = bind(listen_sock/*���ϳѰ���*/, (SOCKADDR *)&serveraddr/*in-out parameter*/, sizeof(serveraddr));
	if(retval == SOCKET_ERROR) err_quit("bind()");
	
	// listen()
	retval = listen(  //��� listen������ �����ؾ� Ŭ���̾�Ʈ ���� ����
        listen_sock, 
        SOMAXCONN //���Ӵ�� ť�� ũ��,SOMAXCONN : �ִ밹��
        ); // TCP ���¸� LISTENING ����
	if(retval == SOCKET_ERROR) err_quit("listen()");

	// ������ ��ſ� ����� ����
	SOCKET client_sock;
	SOCKADDR_IN clientaddr;
	int addrlen;
	char buf[BUFSIZE+1];

	while(1){
		// accept()
		addrlen = sizeof(clientaddr);
		client_sock = accept( //��ż����� �ڵ�
            listen_sock, //��� ����
            (SOCKADDR *)&clientaddr, //Ŭ���̾�Ʈ�� ���� out param ����ü out-parameter
            &addrlen //�ּұ���ü������ũ��, in(ũ������), out(�ʱ�ȭ��ũ���ȯ) param
            ); //��ż��� ����: ���� IP, ���� ��Ʈ ����
		if(client_sock == INVALID_SOCKET){ //��ż����� ���������? �׷� ���!
			err_display("accept()");
			continue;
		}
		printf("\n[TCP ����] Ŭ���̾�Ʈ ����: IP �ּ�=%s, ��Ʈ ��ȣ=%d\n",
			inet_ntoa(clientaddr.sin_addr), //���ڿ��� IP�ּ� ��ȯ
            ntohs(clientaddr.sin_port) // ��Ʈ��ȣ network to host
            );

		// Ŭ���̾�Ʈ�� ������ ���
		while(1){
			// ������ �ޱ�
			retval = recv( //recv�� blocking�Լ��̴�. ���� ����Ʈ���� retval�� �����Ѵ�.0�����޵Ǹ� �������Ḧ ����. ���� �����͸� ������ ����Ʈ������ȯ
                client_sock, //��ż����ڵ�
                buf, //���� ���ø����̼� ����
                BUFSIZE, //���� ������ �ִ� ũ��
                0 //��κ� 0 or MSG_PEEK�� MSG_OOB�� ��� ����, ������ ������ 0�̶�� �����ϸ� �ȴ�.
                );
			if(retval == SOCKET_ERROR){
				err_display("recv()");
				break;
			}
			else if(retval == 0){
				break;
			}
			else{
				// ���� ������ ���
				buf[retval] = '\0';
				printf("%s", buf);
			}
		}

		// closesocket()
		closesocket(client_sock);
		printf("\n[TCP ����] Ŭ���̾�Ʈ ����: IP �ּ�=%s, ��Ʈ ��ȣ=%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
	}

	// closesocket()
	closesocket(listen_sock);

	// ���� ����
	WSACleanup();
	return 0;
}