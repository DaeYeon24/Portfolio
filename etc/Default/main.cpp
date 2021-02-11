#include "sum.h"
#include "pay.h"
#include "gugu.h"

void main()
{
	int select;
	sum S1;
	pay P1;
	gugu G1;
	while (1)
	{
		system("cls");
		cout << "문제 1. 시급 계산" << endl;
		cout << "문제 2. 1 ~ n까지의 합" << endl;
		cout << "문제 3. 구구단 출력" << endl;
		cout << "       4. 종료" << endl;
		cout << "       입력 : ";
		cin >> select;
		system("cls");
		switch (select)
		{
		case 1:
			P1.PayManager();
			break;
		case 2:
			S1.SumManager();
			break;
		case 3:
			G1.GuguManager();
			break;
		case 4:
			return;
		}
		system("pause");
	}
}