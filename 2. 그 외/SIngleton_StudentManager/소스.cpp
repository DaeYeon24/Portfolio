#include "Manager.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 161;

	int select;
	while (1)
	{
		system("cls");
		cout << "=======�л� ���� ���α׷�========" << endl;
		cout << "�� �л� �� : " << Manager::GetInstance()->Get_Count() << endl;
		cout << " 1. �л� �߰�\n 2. �л� ���\n 3. ����" << endl;
		cout << "�Է� : ";
		cin >> select;
		switch (select)
		{
		case 1:
			Manager::GetInstance()->New_Student();
			break;
		case 2:
			Manager::GetInstance()->Info_Student();
			system("pause");
			break;
		case 3:
			Manager::DestroyInstance();
			return;
		}
	}
}