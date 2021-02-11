#include <iostream>
#include <string>
using namespace std;

#define MAX 10
#define A 'A'
#define B 'B'
#define C 'C'
#define D 'D'
#define F 'F'

typedef struct Student
{
	string name;
	int age;
	int grade;
	int number;
	int kor;
	int eng;
	int mat;
	int sum;
	float avg;
	char score;
}student;

void SetStudent(student* st, int* Count)
{
	st->number = ++(*Count);
	system("cls");
	cout << "======" << st->number << "��° �л�======" << endl;
	cout << "�̸� : ";
	cin >> st->name;
	cout << "���� : ";
	cin >> st->age;
	while (1)
	{
		cout << "�г�(1~3) : ";
		cin >> st->grade;
		if (st->grade < 1 || st->grade > 3)
		{
			cout << "�г� ������ ������ϴ�." << endl;
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "�������� : ";
		cin >> st->kor;
		cout << "�������� : ";
		cin >> st->eng;
		cout << "�������� : ";
		cin >> st->mat;
		if (st->kor > 100 || st->eng > 100 || st->mat > 100 || st->kor < 0 || st->eng < 0 || st->mat < 0)
		{
			cout << "���� ���� ������ ������ϴ�." << endl;
			continue;
		}
		break;
	}
	st->sum = st->kor + st->eng + st->mat;
	st->avg = (float)st->sum / 3.0;
	if (st->avg >= 90)
		st->score = A;
	else if (st->avg >= 80)
		st->score = B;
	else if (st->avg >= 70)
		st->score = C;
	else if (st->avg >= 60)
		st->score = D;
	else if (st->avg < 60)
		st->score = F;
}

void ShowStudent(student* st)
{
	cout << "=========" << st->number << "��° �л�=========" << endl;
	cout << "  �̸� : " << st->name << endl;
	cout << "  ���� : " << st->age << endl;
	cout << "  �г� : " << st->grade << endl;
	cout << "  �������� : " << st->kor << endl;
	cout << "  �������� : " << st->eng << endl;
	cout << "  �������� : " << st->mat << endl;
	cout << "  �հ����� : " << st->sum << "\t������� : " << st->avg << endl;
	cout << " ��� : [" << st->score << "]" << endl;
}

void SearchStudent(student** st, int Count)
{
	string search_name;
	while (1)
	{
		system("cls");
		cout << "  �̸� �˻�(�˻� ������[0]) : ";
		cin >> search_name;
		for (int i = 0; i < Count; i++)
		{
			if (search_name == st[i]->name)
			{
				ShowStudent(st[i]);
				system("pause");
				return;
			}
		}
		if (search_name == "0")
			return;
		cout << "�ش� �̸��� ���� �л��� �����ϴ�." << endl;
		system("pause");
	}
}

void SortScore(student** st, int Count)
{
	system("cls");
	for (char i = A; i <= F ; i++)
	{
		cout << "***********" << i << "���*************" << endl;
		for (int j = 0; j < Count; j++)
		{
			if (st[j]->score == i)
				ShowStudent(st[j]);
		}
		cout << "*****************************" << endl << endl;
	}
	system("pause");
}

void SortGrade(student** st, int Count)
{
	system("cls");
	for (int i = 1; i <= 3; i++) // �г⸸ŭ
	{
		cout << "***********" << i << "�г�*************" << endl;
		for (int j = 0; j < Count; j++) //�л�����ŭ
		{
			if (st[j]->grade == i)
				ShowStudent(st[j]);
		}
		cout << "*****************************" << endl<<endl;
	}
	system("pause");
}

void main()
{
	student* Student_List[MAX];
	int Count = 0;
	int select;
	while (1)
	{
		system("cls");
		cout << "===�л���������===(�л��� : " << Count << "��)"<<endl;
		cout << "  1. �л����\n  2. �л����� ����\n  3. �л� �˻�" << endl;
		cout << "  4. ��޺� ����\n  5. �г⺰ ����\n  6. ����" << endl;
		cout << " �Է� : ";
		cin >> select;
		switch (select)
		{
		case 1:
			if (Count + 1 <= MAX)
			{
				Student_List[Count] = new student;
				SetStudent(Student_List[Count], &Count);
			}
			else
				cout << "���� �ʰ�" << endl;
			break;
		case 2:
			if (Count == 0)
			{
				cout << "��ϵ� �л��� �����ϴ�." << endl;
				break;
			}
			else
			{
				system("cls");
				for (int i = 0; i < Count; i++)
					ShowStudent(Student_List[i]);
				system("pause");
				break;
			}
		case 3:
			SearchStudent(Student_List, Count);
			break;
		case 4:
			SortScore(Student_List, Count);
			break;
		case 5:
			SortGrade(Student_List, Count);
			break;
		case 6:
			for (int i = 0; i < Count; i++)
			{
				cout << i + 1 << "�� �л� " << Student_List[i]->name << " �����Ҵ� ���� �Ϸ�" << endl;
				delete Student_List[i];
			}
			system("pause");
			return;
		}
	}
}