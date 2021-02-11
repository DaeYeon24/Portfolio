#include "Student.h"

Student::Student()
{}

void Student::Display()
{
	system("cls");
	cout << m_iGrade << "학년 " << m_iClass << "반 " << m_iNumber << "번 학생" << endl;
	cout << "나이 : " << m_iAge << endl;
	cout << "이름 : " << m_strName << endl;
	cout << "성별 : " << m_strGender << endl;
	system("pause");
}
Student::~Student()
{}