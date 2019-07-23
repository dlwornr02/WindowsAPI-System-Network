#include <stdio.h>
#include <windows.h>
void main()
{
	// ���μ��� ID, �ڵ� ���
	printf("process ID : %d\n", GetCurrentProcessId());
	printf("process Handle : %d\n", GetCurrentProcess()); // ���μ��� �������� ��� ������ �ڵ� ���̺� ��ϵ��� �ʴ� �ڵ�

	DWORD exitCode = 0;
	GetExitCodeProcess(GetCurrentProcess(), &exitCode);
	if(exitCode == STILL_ACTIVE)
		printf("���μ����� ��� ��~\n");

	//ID�� ���μ��� �ڵ� ���
	// PROCESS_QUERY_LIMITED_INFORMATION : GetExitCodeProcess() ȣ�� Ȯ�� ���� ���� ����
	HANDLE hProcess = OpenProcess( PROCESS_QUERY_LIMITED_INFORMATION, 0, GetCurrentProcessId());s

	printf("Open Process ��ȯ �ڵ� : %x\n", hProcess );

	//��
	GetExitCodeProcess(GetCurrentProcess(), &exitCode);
	if(exitCode == STILL_ACTIVE)
		printf("���μ����� ��� ��~\n");
}