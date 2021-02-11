#pragma once
#include <iostream>
using namespace std;

class gugu
{
private:
	int m_iselect;
	int m_imin;
	int m_imax;
public:
	void GuguManager();
	void Gugu(int imin = 2, int imax = 9);
};

