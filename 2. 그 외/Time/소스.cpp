#include "Time.h"

void main()
{
	Time T;
	Time* AddT = NULL;
	int hour, min, day = 0, select;
	while (1)
	{
		system("cls");
		T.ShowTime();
		cout << "=====공부 시간 관리 프로그램(" << day << "day)=====" << endl;
		cout << "\t\t1. 시간 등록" << endl;
		cout << "\t\t2. 종료" << endl;
		cout << "\t\t입력 : ";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "시간 : ";
			cin >> hour;
			cout << "분 : ";
			cin >> min;
			AddT = new Time(hour, min);
			T = T + *AddT;
			delete AddT;
			AddT = NULL;
			day++;
			break;
		case 2:
			return;
		}
	}
}