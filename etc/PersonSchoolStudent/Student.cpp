#include "Student.h"

Student::Student()
{}

void Student::Display()
{
	system("cls");
	cout << m_iGrade << "�г� " << m_iClass << "�� " << m_iNumber << "�� �л�" << endl;
	cout << "���� : " << m_iAge << endl;
	cout << "�̸� : " << m_strName << endl;
	cout << "���� : " << m_strGender << endl;
	system("pause");
}
Student::~Student()
{}