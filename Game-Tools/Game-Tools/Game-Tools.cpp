// Game-Tools.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>

void MainMenu()
{
	printf("==========�˵�==========\n");
	printf("       1.�޸�����\n");
	printf("       2.�޸Ľ��\n");
	printf("       3.�˳�\n");
	printf("========================\n");
}
int DisplaySun()
{
	//974488891
	HWND hGame = ::FindWindow(NULL, L"Plants vs. Zombies 1.2.0.1073 RELEASE");
	//�õ��̻߳���̵�ID
	DWORD ProcessId;
    //���������õ����ڵ��̵߳�Id
	::GetWindowThreadProcessId(hGame,&ProcessId);
	//����id�õ����̾��
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS,false,ProcessId);
	//windows ���� ����ֵ
	LPVOID pBase = (LPVOID)6987456;//��ֵ CE
	int sun = 0;
	LPVOID rbuffer = (LPVOID)&sun;
	//hook
	DWORD byred;
	::ReadProcessMemory(hProcess, pBase,rbuffer,4,&byred);

	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);

	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);
}
int main()
{
	//���ݴ������ֵõ����
	HWND hGame = ::FindWindow(NULL,L"Plants vs. Zombies 1.2.0.1073 RELEASE");
	//�õ����ڵ���ϸ��Ϣ
	RECT r;
	::GetWindowRect(hGame,&r);
	printf("��Ϸ����Ϣ : %d, %d, %d, %d",r.left,r.top,r.right,r.bottom);
	//�õ����ĵ��λ��
	POINT P;
	::GetCursorPos(&P);
	printf("���λ�� ��%d %d\n\n\n",P.x,P.y);
	if (NULL == hGame)
	{
		printf("�����������Ϸֲ���ս��ʬ���ڿ�����ң�");
		Sleep(30000);
		return 0;
	}

	
	MainMenu();
	int op = 0;
	while (1)
	{
		MainMenu();
		scanf("%d",&op);
		int temp = 0;
		switch (op)
		{
		case 1:
		{
			DisplaySun();
		}
		case 2:
		default:
			break;
		}

	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
