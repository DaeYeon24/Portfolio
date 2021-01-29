#include "Manager.h"

Manager::Manager()
{
	m_Student = NULL;
	m_iStudent_Count = 0;
}

void Manager::Title()
{
	int Select;
	while (1)
	{
		system("cls");
		cout << "< < < = = = = 메뉴 = = = = > > >" << endl << endl;
		cout << "  1. 학생 등록\n  2. 학생 검색\n  3. 학생 목록\n  4. 학생 수정\n  5. 학생 삭제\n  6. 종료" << endl;
		cout << "입력 >>> ";
		cin >> Select;
		system("cls");
		switch (Select)
		{
		case 1:
			New_Student();
			break;
		case 2:
			Search_Student();
			break;
		case 3:
			Info_Student();
			break;
		case 4:
			Modify_Student();
			break;
		case 5:
			Delete_Student();
			break;
		case 6:
			Exit(m_Student);
			return;
		}
	}
}

void Manager::New_Student()
{
	Student* rear = m_Student;
	string tmp_name, tmp_address;
	int tmp_age, tmp_kor, tmp_eng, tmp_mat;
	cout << "학생 이름 입력 : ";
	cin >> tmp_name;
	cout << tmp_name << "학생 나이 입력 : ";
	cin >> tmp_age;
	cout << tmp_name << "학생 주소 입력 : ";
	cin >> tmp_address;
	cout << tmp_name << "학생 국어 점수 : ";
	cin >> tmp_kor;
	cout << tmp_name << "학생 영어 점수 : ";
	cin >> tmp_eng;
	cout << tmp_name << "학생 수학 점수 : ";
	cin >> tmp_mat;
	Student* tmp_student = new Student(tmp_name, tmp_age, tmp_address, tmp_kor, tmp_eng, tmp_mat);
	if (m_iStudent_Count == 0)
		m_Student = tmp_student;
	else
	{
		while (rear->GetNext() != NULL)
		{
			rear = rear->GetNext();
		}
		rear->SetNext(tmp_student);
	}
	m_iStudent_Count++;
	cout << "학생 정보 입력 완료" << endl;
	system("pause");
}

void Manager::Search_Student()
{
	Student* rear = m_Student;
	string search_name;
	bool search_fail = true;
	cout << "검색할 학생 이름 입력 : ";
	cin >> search_name;
	while (rear != NULL)
	{
		if (search_name == rear->GetName())
		{
			rear->Detail_Info();
			search_fail = false;
		}
		rear = rear->GetNext();
	}
	if (search_fail == true)
		cout << "검색한 이름의 학생이 없습니다." << endl;
	system("pause");
}

void Manager::Info_Student()
{
	Student* rear = m_Student;
	cout << "< < = = = = = Information = = = = = > >" << endl << endl;
	cout << "학생이름\t학생나이\t학생주소" << endl;
	while (rear != NULL)
	{
		rear->Simple_Info();
		rear = rear->GetNext();
	}
	cout << "학생 개개인의 점수는 검색을 이용하세요!" << endl;
	system("pause");
}

void Manager::Modify_Student()
{
	Student* rear = m_Student;
	string search_name;
	bool search_fail = true;
	cout << "수정할 학생 이름 입력 : ";
	cin >> search_name;
	while (rear != NULL)
	{
		if (search_name == rear->GetName())
		{
			Modify_Detail(rear);
			return;
		}
		rear = rear->GetNext();
	}
	if (search_fail == true)
		cout << "검색한 이름의 학생이 없습니다." << endl;
	system("pause");
}

void Manager::Modify_Detail(Student* student)
{
	int select;
	while (1)
	{
		system("cls");
		student->Detail_Info();
		cout << endl << endl << "수정할 항목을 선택 하시오" << endl;
		cout << "1. 이름\t2. 나이\t3. 주소\t4. 점수\t5. 수정 종료" << endl;
		cout << "선택 : ";
		cin >> select;
		if (select != 5)
			student->Modify((DATA)select);
		else
		{
			cout << "수정을 종료합니다" << endl;
			_getch();
			return;
		}
	}
}

void Manager::Delete_Student()
{
	Student* rear = m_Student;
	Student* rear_front, * rear_back;
	string search_name;
	cout << "삭제할 학생 이름 입력 : ";
	cin >> search_name;
	if (m_Student == NULL)
	{
		cout << "학생목록이 없습니다." << endl;
		_getch();
		return;
	}
	if (search_name == m_Student->GetName())
	{
		m_Student = m_Student->GetNext();
		delete rear;
		m_iStudent_Count--;
		cout << "삭제 완료" << endl;
		_getch();
		return;
	}
	else
	{
		while (rear != NULL)
		{
			if (search_name == rear->GetNext()->GetName())
			{
				rear_front = rear;
				rear_back = rear->GetNext()->GetNext();
				rear = rear->GetNext();
				delete rear;
				rear_front->SetNext(rear_back);
				m_iStudent_Count--;
				cout << "삭제 완료" << endl;
				_getch();
				return;
			}
			rear = rear->GetNext();
		}
	}
	cout << "검색한 이름이 없습니다" << endl;
	return;
}

void Manager::Exit(Student* student)
{
	if (student == NULL)
		return;
	Exit(student->GetNext());
	delete student;
}

Manager::~Manager()
{}