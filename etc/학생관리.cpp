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
	cout << "======" << st->number << "번째 학생======" << endl;
	cout << "이름 : ";
	cin >> st->name;
	cout << "나이 : ";
	cin >> st->age;
	while (1)
	{
		cout << "학년(1~3) : ";
		cin >> st->grade;
		if (st->grade < 1 || st->grade > 3)
		{
			cout << "학년 범위가 벗어났습니다." << endl;
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "국어점수 : ";
		cin >> st->kor;
		cout << "영어점수 : ";
		cin >> st->eng;
		cout << "수학점수 : ";
		cin >> st->mat;
		if (st->kor > 100 || st->eng > 100 || st->mat > 100 || st->kor < 0 || st->eng < 0 || st->mat < 0)
		{
			cout << "과목 점수 범위가 벗어났습니다." << endl;
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
	cout << "=========" << st->number << "번째 학생=========" << endl;
	cout << "  이름 : " << st->name << endl;
	cout << "  나이 : " << st->age << endl;
	cout << "  학년 : " << st->grade << endl;
	cout << "  국어점수 : " << st->kor << endl;
	cout << "  영어점수 : " << st->eng << endl;
	cout << "  수학점수 : " << st->mat << endl;
	cout << "  합계점수 : " << st->sum << "\t평균점수 : " << st->avg << endl;
	cout << " 등급 : [" << st->score << "]" << endl;
}

void SearchStudent(student** st, int Count)
{
	string search_name;
	while (1)
	{
		system("cls");
		cout << "  이름 검색(검색 나가기[0]) : ";
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
		cout << "해당 이름을 가진 학생이 없습니다." << endl;
		system("pause");
	}
}

void SortScore(student** st, int Count)
{
	system("cls");
	for (char i = A; i <= F ; i++)
	{
		cout << "***********" << i << "등급*************" << endl;
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
	for (int i = 1; i <= 3; i++) // 학년만큼
	{
		cout << "***********" << i << "학년*************" << endl;
		for (int j = 0; j < Count; j++) //학생수만큼
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
		cout << "===학생정보관리===(학생수 : " << Count << "명)"<<endl;
		cout << "  1. 학생등록\n  2. 학생정보 보기\n  3. 학생 검색" << endl;
		cout << "  4. 등급별 보기\n  5. 학년별 보기\n  6. 종료" << endl;
		cout << " 입력 : ";
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
				cout << "정원 초과" << endl;
			break;
		case 2:
			if (Count == 0)
			{
				cout << "등록된 학생이 없습니다." << endl;
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
				cout << i + 1 << "번 학생 " << Student_List[i]->name << " 동적할당 해제 완료" << endl;
				delete Student_List[i];
			}
			system("pause");
			return;
		}
	}
}