#include "StudentManager.h"

void main()
{
	StudentManager SManager;
	int iSelect;
	while (1)
	{
		system("cls");
		cout << "====학생관리 프로그램====" << endl;
		cout << "  1. 학생등록\n  2. 학생 목록<번호>\n  3. 학생 목록<학년>" << endl;
		cout << "  4. 학생 검색\n  5. 학년 검색\n  6. 마지막 학생 삭제" << endl;
		cout << "  7. 전체 학생 삭제\n  8. 종료\n  (학생 수 : " << SManager.GetCount() << ")" << endl;
		cout << "입력  : ";
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