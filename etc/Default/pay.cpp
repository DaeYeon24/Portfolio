#include "pay.h"

void pay::PayManager()
{
	while (1)
	{
		system("cls");
		cout << "며칠 근무하셨습니까 : ";
		cin >> m_idate;
		cout << "시간과 시급을 입력 하시겠습니까?" << endl;
		cout << " (Yes 1, No 2)" << endl;
		cin >> m_iselect;
		if (m_iselect == 1)
		{
			cout << "시급 입력 : ";
			cin >> m_ipay;
			cout << "시간 입력 : ";
			cin >> m_itime;
			WageCalc(m_idate, m_itime, m_ipay);
		}
		else if (m_iselect == 2)
			WageCalc(m_idate);
		else
		{
			cout << "잘못 입력" << endl;
			system("pause");
			continue;
		}
		return;
	}
}

void pay::WageCalc(int idate, int itime, int ipay)
{
	m_iwage = idate * itime * ipay;
	ShowWage(idate, itime, ipay);
}
