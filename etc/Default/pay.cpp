#include "pay.h"

void pay::PayManager()
{
	while (1)
	{
		system("cls");
		cout << "��ĥ �ٹ��ϼ̽��ϱ� : ";
		cin >> m_idate;
		cout << "�ð��� �ñ��� �Է� �Ͻðڽ��ϱ�?" << endl;
		cout << " (Yes 1, No 2)" << endl;
		cin >> m_iselect;
		if (m_iselect == 1)
		{
			cout << "�ñ� �Է� : ";
			cin >> m_ipay;
			cout << "�ð� �Է� : ";
			cin >> m_itime;
			WageCalc(m_idate, m_itime, m_ipay);
		}
		else if (m_iselect == 2)
			WageCalc(m_idate);
		else
		{
			cout << "�߸� �Է�" << endl;
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
