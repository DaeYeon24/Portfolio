#include "Computer.h"

Computer::Computer()
{
	m_strName = "DaeYeon";
	m_eBoot = ON;
	m_strGPU = "RTX 2060";
	m_strCPU = "I5-8500";
	m_iRam = 16;
	cout << "��ǻ�� On" << endl;
	Sleep(3000);
}

void Computer::Starting()
{
	int select;
	while (1)
	{
		system("cls");
		cout << "======ȯ �� �� �� ��======" << endl;
		cout << " 1. ��ǻ�� ����" << endl;
		cout << " 2. ��  ��" << endl;
		cout << " 3. Off" << endl;
		cout << "�Է� >>>> ";
		cin >> select;
		system("cls");
		switch (select)
		{
		case 1:
			ShowCom();
			break;
		case 2:
			Function();
			break;
		case 3:
			Off();
			return;
		}
		system("pause");
	}
}

void Computer::ShowCom()
{
	cout << "��  ǰ  �� : " << m_strName << endl;
	cout << "����  ���� : ";
	switch (m_eBoot)
	{
	case ON:
		cout << "On" << endl;
		break;
	case OFF:
		cout << "Off" << endl;
		break;
	}
	cout << "�׷���ī�� : " << m_strGPU << endl;
	cout << "C    P   U : " << m_strCPU << endl;
	cout << "��  ��  �� : " << m_iRam << "G" << endl;
}

void Computer::Function()
{
	int select;
	while (1)
	{
		system("cls");
		cout << " 1. �� �� ��" << endl;
		cout << " 2. �� �� ��" << endl;
		cout << " 3. �� �� ��" << endl;
		cout << " 4. ���ư���" << endl;
		cout << " ���� >>>>";
		cin >> select;
		switch (select)
		{
		case 1:
			system("calc");
			break;
		case 2:
			system("notepad");
			break;
		case 3:
			system("mspaint");
			break;
		case 4:
			return;
		}
	}
}

void Computer::Off()
{
	for (int i = 5; i > 0; i--)
	{
		cout << "Off " << i << "�� ��..." << endl;
		Sleep(1000);
	}
}