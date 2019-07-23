//#include <stdio.h>
//#include <windows.h>
//void main()
//{
//	// ���μ��� ID, �ڵ� ���
//	printf("process ID : %d\n", GetCurrentProcessId());
//	printf("process Handle : %d\n", GetCurrentProcess()); // ���μ��� �������� ��� ������ �ڵ� ���̺� ��ϵ��� �ʴ� �ڵ�
//    
//    DWORD exitCode = 0;
//    GetExitCodeProcess(GetCurrentProcess(), &exitCode);
//    if(exitCode == STILL_ACTIVE)
//        printf("���μ����� ��� ��~\n");
//
//    //ID�� ���μ��� �ڵ� ���
//    // PROCESS_QUERY_LIMITED_INFORMATION : GetExitCodeProcess() ȣ�� Ȯ�� ���� ���� ����
//    HANDLE hProcess = OpenProcess( PROCESS_QUERY_LIMITED_INFORMATION, 0, GetCurrentProcessId());
//	printf("Open Process ��ȯ �ڵ� : %x\n", hProcess );
//
//    GetExitCodeProcess(GetCurrentProcess(), &exitCode);
//
//    if(exitCode == STILL_ACTIVE)o
//        printf("���μ����� ��� ��~\n");
//}


#include <stdio.h>
#include <windows.h>
void main()
{
	//HWND hWnd = FindWindow( 
 //                   0, // ������ Ŭ���� �̸�
 //                   "���� ���� - �޸���" // ������ �̸�(������ Ÿ��Ʋ �̸�)
 //                   );
	HWND hWnd = FindWindow( "notepad", 0);
    if( hWnd == NULL)
    {
        printf("�޸����� �����Ͻÿ�!\n");
        return;
    }

	DWORD processID;
	DWORD threadID;
    threadID = GetWindowThreadProcessId( hWnd, &processID );

    // ID�� ���μ��� �ڵ� ���
    // PROCESS_TERMINATE : TerminateProcess() ȣ�� ���� ���� ����
    HANDLE hProcess;
    hProcess = OpenProcess( 
        PROCESS_TERMINATE|PROCESS_QUERY_LIMITED_INFORMATION,
        0, processID);
	printf("�޸����� ������ �ڵ� %d\n", hWnd);
	printf("�޸����� ���μ��� ID %d\n", processID);
	printf("�޸����� ���μ��� �ڵ� %d\n", hProcess);

    //���μ����� Ŀ�ο�����Ʈ ���� �ڵ� ���� ����.
    DWORD exitCode;
    GetExitCodeProcess(hProcess, &exitCode);
    if(exitCode == STILL_ACTIVE)
        printf("�޸��� ���μ����� ��� ��~\n");

    printf("�޸����� �����Ϸ��� '����'Ű ġ�ÿ�\n");
    getchar();

    //�޸��� ���μ��� �ڵ��� �̿��Ͽ� ���� ��Ŵ.
    TerminateProcess(hProcess, 100);
    GetExitCodeProcess(hProcess, &exitCode);
    if(exitCode == STILL_ACTIVE)
        printf("�޸��� ���μ����� ��� ��~\n");
    else
        printf("�޸����� ���� �ڵ�: %d\n", exitCode);
}
