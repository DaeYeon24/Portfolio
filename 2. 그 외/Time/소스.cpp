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
		cout << "=====���� �ð� ���� ���α׷�(" << day << "day)=====" << endl;
		cout << "\t\t1. �ð� ���" << endl;
		cout << "\t\t2. ����" << endl;
		cout << "\t\t�Է� : ";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "�ð� : ";
			cin >> hour;
			cout << "�� : ";
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