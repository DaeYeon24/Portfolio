#pragma once
#include "Çì´õ.h"

class Student
{
private:
	string m_strName;
	int m_iNumber;
	int m_iKor, m_iEng, m_iMat;
	int m_iSum;
	double m_dAvg;
	char m_chScore;
public:
	Student(int num);
	~Student();
	void Info();
};