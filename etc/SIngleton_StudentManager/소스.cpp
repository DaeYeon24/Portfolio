#include "Manager.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 161;

	int select;
	while (1)
	{
		system("cls");
		cout << "=======학생 관리 프로그램========" << endl;
		cout << "총 학생 수 : " << Manager::GetInstance()->Get_Count() << endl;
		cout << " 1. 학생 추가\n 2. 학생 목록\n 3. 종료" << endl;
		cout << "입력 : ";
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