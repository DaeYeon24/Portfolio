#include "Computer.h"

Computer::Computer()
{
	m_strName = "DaeYeon";
	m_eBoot = ON;
	m_strGPU = "RTX 2060";
	m_strCPU = "I5-8500";
	m_iRam = 16;
	cout << "컴퓨터 On" << endl;
	Sleep(3000);
}

void Computer::Starting()
{
	int select;
	while (1)
	{
		system("cls");
		cout << "======환 영 합 니 다======" << endl;
		cout << " 1. 컴퓨터 상태" << endl;
		cout << " 2. 기  능" << endl;
		cout << " 3. Off" << endl;
		cout << "입력 >>>> ";
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
	cout << "제  품  명 : " << m_strName << endl;
	cout << "현재  상태 : ";
	switch (m_eBoot)
	{
	case ON:
		cout << "On" << endl;
		break;
	case OFF:
		cout << "Off" << endl;
		break;
	}
	cout << "그래픽카드 : " << m_strGPU << endl;
	cout << "C    P   U : " << m_strCPU << endl;
	cout << "메  모  리 : " << m_iRam << "G" << endl;
}

void Computer::Function()
{
	int select;
	while (1)
	{
		system("cls");
		cout << " 1. 계 산 기" << endl;
		cout << " 2. 메 모 장" << endl;
		cout << " 3. 그 림 판" << endl;
		cout << " 4. 돌아가기" << endl;
		cout << " 선택 >>>>";
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
		cout << "Off " << i << "초 전..." << endl;
		Sleep(1000);
	}
}