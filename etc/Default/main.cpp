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
		cout << "���� 1. �ñ� ���" << endl;
		cout << "���� 2. 1 ~ n������ ��" << endl;
		cout << "���� 3. ������ ���" << endl;
		cout << "       4. ����" << endl;
		cout << "       �Է� : ";
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