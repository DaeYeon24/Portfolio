#include "Student.h"

Student::Student(int num)
{
	m_iNumber = num;
	cout << "==============" << endl;
	cout << "�̸� �Է� : ";
	cin >> m_strName;
	cout << "���� ���� : ";
	cin >> m_iKor;
	cout << "���� ���� : ";
	cin >> m_iEng;
	cout << "���� ���� : ";
	cin >> m_iMat;
	m_iSum = m_iKor + m_iEng + m_iMat;
	m_dAvg = (double)m_iSum / 3;
	if (m_dAvg >= 90)
		m_chScore = 'A';
	else if (m_dAvg >= 80)
		m_chScore = 'B';
	else if (m_dAvg >= 70)
		m_chScore = 'C';
	else if (m_dAvg >= 60)
		m_chScore = 'D';
	else
		m_chScore = 'F';
}

void Student::Info()
{
	cout << "==============" << endl;
	cout << "�̸� : " << m_strName << "(" << m_iNumber << "�� �л�)" << endl;
	cout << "���� ���� : " << m_iKor << endl;
	cout << "���� ���� : " << m_iEng << endl;
	cout << "���� ���� : " << m_iMat << endl;
	cout << "��� : " << m_chScore << endl;
	cout << "==============" << endl;
}

Student::~Student()
{}