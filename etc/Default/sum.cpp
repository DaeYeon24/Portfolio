#include "sum.h"

void sum::SumManager()
{
	while (1)
	{
		system("cls");
		cout << "���� ���� �����Ͻðڽ��ϱ�?" << endl;
		cout << " (Yes 1, No 2)" << endl;
		cin >> m_iselect;
		if (m_iselect == 1)
		{
			cout << "�ִ� �� �Է� : (���� : 10) ";
			cin >> m_iend;
			Sum(m_iend);
		}
		else if (m_iselect == 2)
			Sum();
		else
		{
			cout << "�߸� �Է�" << endl;
			system("pause");
			continue;
		}
		return;
	}
}

void sum::Sum(int iend)
{
	for (int i = 0; i <= iend; i++)
		m_isum += i;
	ShowSum(iend);
}