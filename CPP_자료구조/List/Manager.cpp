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
		cout << "< < < = = = = �޴� = = = = > > >" << endl << endl;
		cout << "  1. �л� ���\n  2. �л� �˻�\n  3. �л� ���\n  4. �л� ����\n  5. �л� ����\n  6. ����" << endl;
		cout << "�Է� >>> ";
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
	cout << "�л� �̸� �Է� : ";
	cin >> tmp_name;
	cout << tmp_name << "�л� ���� �Է� : ";
	cin >> tmp_age;
	cout << tmp_name << "�л� �ּ� �Է� : ";
	cin >> tmp_address;
	cout << tmp_name << "�л� ���� ���� : ";
	cin >> tmp_kor;
	cout << tmp_name << "�л� ���� ���� : ";
	cin >> tmp_eng;
	cout << tmp_name << "�л� ���� ���� : ";
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
	cout << "�л� ���� �Է� �Ϸ�" << endl;
	system("pause");
}

void Manager::Search_Student()
{
	Student* rear = m_Student;
	string search_name;
	bool search_fail = true;
	cout << "�˻��� �л� �̸� �Է� : ";
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
		cout << "�˻��� �̸��� �л��� �����ϴ�." << endl;
	system("pause");
}

void Manager::Info_Student()
{
	Student* rear = m_Student;
	cout << "< < = = = = = Information = = = = = > >" << endl << endl;
	cout << "�л��̸�\t�л�����\t�л��ּ�" << endl;
	while (rear != NULL)
	{
		rear->Simple_Info();
		rear = rear->GetNext();
	}
	cout << "�л� �������� ������ �˻��� �̿��ϼ���!" << endl;
	system("pause");
}

void Manager::Modify_Student()
{
	Student* rear = m_Student;
	string search_name;
	bool search_fail = true;
	cout << "������ �л� �̸� �Է� : ";
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
		cout << "�˻��� �̸��� �л��� �����ϴ�." << endl;
	system("pause");
}

void Manager::Modify_Detail(Student* student)
{
	int select;
	while (1)
	{
		system("cls");
		student->Detail_Info();
		cout << endl << endl << "������ �׸��� ���� �Ͻÿ�" << endl;
		cout << "1. �̸�\t2. ����\t3. �ּ�\t4. ����\t5. ���� ����" << endl;
		cout << "���� : ";
		cin >> select;
		if (select != 5)
			student->Modify((DATA)select);
		else
		{
			cout << "������ �����մϴ�" << endl;
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
	cout << "������ �л� �̸� �Է� : ";
	cin >> search_name;
	if (m_Student == NULL)
	{
		cout << "�л������ �����ϴ�." << endl;
		_getch();
		return;
	}
	if (search_name == m_Student->GetName())
	{
		m_Student = m_Student->GetNext();
		delete rear;
		m_iStudent_Count--;
		cout << "���� �Ϸ�" << endl;
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
				cout << "���� �Ϸ�" << endl;
				_getch();
				return;
			}
			rear = rear->GetNext();
		}
	}
	cout << "�˻��� �̸��� �����ϴ�" << endl;
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