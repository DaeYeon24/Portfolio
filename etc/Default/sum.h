#pragma once
#include <iostream>
using namespace std;

class sum
{
private:
	int m_iend;
	int m_isum = 0;
	int m_iselect;
public:
	void Sum(int iend = 10);
	void SumManager();
	inline void ShowSum(int iend)
	{
		cout << "1 ~ "<< iend <<" ÃÑ ÇÕ : "<< m_isum << endl;
		m_isum = 0;
	}
};

