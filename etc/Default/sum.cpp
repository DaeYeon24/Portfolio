#include "sum.h"

void sum::SumManager()
{
	while (1)
	{
		system("cls");
		cout << "최종 값을 변경하시겠습니까?" << endl;
		cout << " (Yes 1, No 2)" << endl;
		cin >> m_iselect;
		if (m_iselect == 1)
		{
			cout << "최대 값 입력 : (현재 : 10) ";
			cin >> m_iend;
			Sum(m_iend);
		}
		else if (m_iselect == 2)
			Sum();
		else
		{
			cout << "잘못 입력" << endl;
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