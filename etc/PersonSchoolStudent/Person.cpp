#include "Person.h"

Person::Person()
{
	cout << "나이 : ";
	cin >> m_iAge;
	cout << "이름 : ";
	cin >> m_strName;
	cout << "성별 : ";
	cin >> m_strGender;
}

Person::~Person()
{}