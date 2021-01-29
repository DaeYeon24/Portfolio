#include "Student.h"

Student::Student(int num)
{
	m_iNumber = num;
	cout << "==============" << endl;
	cout << "이름 입력 : ";
	cin >> m_strName;
	cout << "국어 점수 : ";
	cin >> m_iKor;
	cout << "영어 점수 : ";
	cin >> m_iEng;
	cout << "수학 점수 : ";
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
	cout << "이름 : " << m_strName << "(" << m_iNumber << "번 학생)" << endl;
	cout << "국어 점수 : " << m_iKor << endl;
	cout << "영어 점수 : " << m_iEng << endl;
	cout << "수학 점수 : " << m_iMat << endl;
	cout << "등급 : " << m_chScore << endl;
	cout << "==============" << endl;
}

Student::~Student()
{}