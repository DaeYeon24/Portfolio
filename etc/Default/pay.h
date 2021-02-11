#pragma once
#include <iostream>
using namespace std;

class pay
{
private:
	int m_iselect;
	int m_idate;
	int m_itime;
	int m_ipay;
	int m_iwage = 0;
public:
	void PayManager();
	void WageCalc(int idate, int itime = 8, int ipay = 7500);
	inline void ShowWage(int idate, int itime, int ipay)
	{
		cout << "시급 : " << ipay << endl;
		cout << "시간 : " << itime << " 시간\t일 수 : " << idate << " 일" << endl;
		cout << "급여 : " << m_iwage << endl;
	}
};

