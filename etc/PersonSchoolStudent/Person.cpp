#include "Person.h"

Person::Person()
{
	cout << "���� : ";
	cin >> m_iAge;
	cout << "�̸� : ";
	cin >> m_strName;
	cout << "���� : ";
	cin >> m_strGender;
}

Person::~Person()
{}