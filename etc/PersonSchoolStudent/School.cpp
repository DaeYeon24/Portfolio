#include "School.h"

School::School()
{
	cout << "학년 : ";
	cin >> m_iGrade;
	cout << "반 : ";
	cin >> m_iClass;
	cout << "번호 : ";
	cin >> m_iNumber;
}

School::~School()
{}