#include <stdio.h>
#include <windows.h>
void main()
{
	// 프로세스 ID, 핸들 출력
	printf("process ID : %d\n", GetCurrentProcessId());
	printf("process Handle : %d\n", GetCurrentProcess()); // 프로세스 내에서만 사용 가능한 핸들 테이블에 등록되지 않는 핸들

	DWORD exitCode = 0;
	GetExitCodeProcess(GetCurrentProcess(), &exitCode);
	if(exitCode == STILL_ACTIVE)
		printf("프로세스가 사용 중~\n");

	//ID로 프로세스 핸들 얻기
	// PROCESS_QUERY_LIMITED_INFORMATION : GetExitCodeProcess() 호출 확인 위한 권한 설정
	HANDLE hProcess = OpenProcess( PROCESS_QUERY_LIMITED_INFORMATION, 0, GetCurrentProcessId());s

	printf("Open Process 반환 핸들 : %x\n", hProcess );

	//프
	GetExitCodeProcess(GetCurrentProcess(), &exitCode);
	if(exitCode == STILL_ACTIVE)
		printf("프로세스가 사용 중~\n");
}