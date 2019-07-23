//#include <stdio.h>
//#include <windows.h>
//void main()
//{
//	// 프로세스 ID, 핸들 출력
//	printf("process ID : %d\n", GetCurrentProcessId());
//	printf("process Handle : %d\n", GetCurrentProcess()); // 프로세스 내에서만 사용 가능한 핸들 테이블에 등록되지 않는 핸들
//    
//    DWORD exitCode = 0;
//    GetExitCodeProcess(GetCurrentProcess(), &exitCode);
//    if(exitCode == STILL_ACTIVE)
//        printf("프로세스가 사용 중~\n");
//
//    //ID로 프로세스 핸들 얻기
//    // PROCESS_QUERY_LIMITED_INFORMATION : GetExitCodeProcess() 호출 확인 위한 권한 설정
//    HANDLE hProcess = OpenProcess( PROCESS_QUERY_LIMITED_INFORMATION, 0, GetCurrentProcessId());
//	printf("Open Process 반환 핸들 : %x\n", hProcess );
//
//    GetExitCodeProcess(GetCurrentProcess(), &exitCode);
//
//    if(exitCode == STILL_ACTIVE)o
//        printf("프로세스가 사용 중~\n");
//}


#include <stdio.h>
#include <windows.h>
void main()
{
	//HWND hWnd = FindWindow( 
 //                   0, // 윈도우 클래스 이름
 //                   "제목 없음 - 메모장" // 윈도우 이름(윈도우 타이틀 이름)
 //                   );
	HWND hWnd = FindWindow( "notepad", 0);
    if( hWnd == NULL)
    {
        printf("메모장을 실행하시오!\n");
        return;
    }

	DWORD processID;
	DWORD threadID;
    threadID = GetWindowThreadProcessId( hWnd, &processID );

    // ID로 프로세스 핸들 얻기
    // PROCESS_TERMINATE : TerminateProcess() 호출 위한 권한 설정
    HANDLE hProcess;
    hProcess = OpenProcess( 
        PROCESS_TERMINATE|PROCESS_QUERY_LIMITED_INFORMATION,
        0, processID);
	printf("메모장의 윈도우 핸들 %d\n", hWnd);
	printf("메모장의 프로세스 ID %d\n", processID);
	printf("메모장의 프로세스 핸들 %d\n", hProcess);

    //프로세스의 커널오브젝트 종료 코드 값을 받음.
    DWORD exitCode;
    GetExitCodeProcess(hProcess, &exitCode);
    if(exitCode == STILL_ACTIVE)
        printf("메모장 프로세스가 사용 중~\n");

    printf("메모장을 종료하려면 '엔터'키 치시오\n");
    getchar();

    //메모장 프로세스 핸들을 이용하여 종료 시킴.
    TerminateProcess(hProcess, 100);
    GetExitCodeProcess(hProcess, &exitCode);
    if(exitCode == STILL_ACTIVE)
        printf("메모장 프로세스가 사용 중~\n");
    else
        printf("메모장의 종료 코드: %d\n", exitCode);
}
