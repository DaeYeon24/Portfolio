#include "Student.h"

Student::Student(string name, int age, string address, int kor, int eng, int mat)
{
	m_strName = name;
	m_iAge = age;
	m_strAddress = address;
	m_iKor = kor;
	m_iEng = eng;
	m_iMat = mat;
	m_iSum = m_iKor + m_iEng + m_iMat;
	m_iAvg = (float)m_iSum / 3;
	m_Next = NULL;
}

void Student::Simple_Info()
{
	cout << m_strName << "\t\t" << m_iAge << "\t\t" << m_strAddress << endl;
}

void Student::Detail_Info()
{
	cout << "< < = = = = = Information = = = = = > >" << endl;
	cout << "학생 이름 : " << m_strName << endl;
	cout << "학생 나이 : " << m_iAge << endl;
	cout << "학생 주소 : " << m_strAddress << endl;
	cout << "국어 점수 : " << m_iKor << endl;
	cout << "영어 점수 : " << m_iEng << endl;
	cout << "수학 점수 : " << m_iMat << endl;
	cout << "합계 점수 : " << m_iSum << endl;
	cout << "평균 점수 : " << m_iAvg << endl;
}

void Student::Modify(DATA what)
{
	string tmp_str;
	int tmp;
	switch (what)
	{
	case NAME:
		cout << "현재 이름 : " << m_strName << endl;
		cout << "수정할 이름 : ";
		cin >> tmp_str;
		cout << m_strName << " -> " << tmp_str << "로 이름 수정 완료" << endl;
		m_strName = tmp_str;
		break;
	case AGE:
		cout << "현재 나이 : " << m_iAge << endl;
		cout << "수정할 나이 : ";
		cin >> tmp;
		cout << m_iAge << " -> " << tmp << "로 나이 수정 완료" << endl;
		m_iAge = tmp;
		break;
	case ADDRESS:
		cout << "현재 주소 : " << m_strAddress << endl;
		cout << "수정할 주소 : ";
		cin >> tmp_str;
		cout << m_strAddress << " -> " << tmp_str << "로 주소 수정 완료" << endl;
		m_strAddress = tmp_str;
		break;
	case SCORE:
		cout << "현재 점수" << endl;
		cout << "국어 : " << m_iKor << " 영어 : " << m_iEng << " 수학 : " << m_iMat << endl;
		cout << "수정할 국어 점수 : ";
		cin >> tmp;
		m_iKor = tmp;
		cout << "수정할 영어 점수 : ";
		cin >> tmp;
		m_iEng = tmp;
		cout << "수정할 수학 점수 : ";
		cin >> tmp;
		m_iMat = tmp;
		m_iSum = m_iKor + m_iEng + m_iMat;
		m_iAvg = (float)m_iSum / 3;
		cout <<"점수 수정 완료" << endl;
		break;
	}
	_getch();
}

Student::~Student()
{}