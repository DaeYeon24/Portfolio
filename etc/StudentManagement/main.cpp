#include "StudentManager.h"

void main()
{
	StudentManager SManager;
	int iSelect;
	while (1)
	{
		system("cls");
		cout << "====�л����� ���α׷�====" << endl;
		cout << "  1. �л����\n  2. �л� ���<��ȣ>\n  3. �л� ���<�г�>" << endl;
		cout << "  4. �л� �˻�\n  5. �г� �˻�\n  6. ������ �л� ����" << endl;
		cout << "  7. ��ü �л� ����\n  8. ����\n  (�л� �� : " << SManager.GetCount() << ")" << endl;
		cout << "�Է�  : ";
		cin >> iSelect;
		system("cls");
		switch (iSelect)
		{
		case 1:
			SManager.SetNewStudent();
			break;
		case 2:
			SManager.ShowStudentList(iSelect);
			break;
		case 3:
			SManager.ShowStudentList(iSelect);
			break;
		case 4:
			SManager.SearchStudent();
			break;
		case 5:
			SManager.SearchGrade();
			break;
		case 6:
			SManager.RemoveStudent();
			break;
		case 7:
			SManager.RemoveAll();
			break;
		case 8:
			SManager.RemoveAll();
			return;
		}
		system("pause");
	}
}