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
	cout << "�л� �̸� : " << m_strName << endl;
	cout << "�л� ���� : " << m_iAge << endl;
	cout << "�л� �ּ� : " << m_strAddress << endl;
	cout << "���� ���� : " << m_iKor << endl;
	cout << "���� ���� : " << m_iEng << endl;
	cout << "���� ���� : " << m_iMat << endl;
	cout << "�հ� ���� : " << m_iSum << endl;
	cout << "��� ���� : " << m_iAvg << endl;
}

void Student::Modify(DATA what)
{
	string tmp_str;
	int tmp;
	switch (what)
	{
	case NAME:
		cout << "���� �̸� : " << m_strName << endl;
		cout << "������ �̸� : ";
		cin >> tmp_str;
		cout << m_strName << " -> " << tmp_str << "�� �̸� ���� �Ϸ�" << endl;
		m_strName = tmp_str;
		break;
	case AGE:
		cout << "���� ���� : " << m_iAge << endl;
		cout << "������ ���� : ";
		cin >> tmp;
		cout << m_iAge << " -> " << tmp << "�� ���� ���� �Ϸ�" << endl;
		m_iAge = tmp;
		break;
	case ADDRESS:
		cout << "���� �ּ� : " << m_strAddress << endl;
		cout << "������ �ּ� : ";
		cin >> tmp_str;
		cout << m_strAddress << " -> " << tmp_str << "�� �ּ� ���� �Ϸ�" << endl;
		m_strAddress = tmp_str;
		break;
	case SCORE:
		cout << "���� ����" << endl;
		cout << "���� : " << m_iKor << " ���� : " << m_iEng << " ���� : " << m_iMat << endl;
		cout << "������ ���� ���� : ";
		cin >> tmp;
		m_iKor = tmp;
		cout << "������ ���� ���� : ";
		cin >> tmp;
		m_iEng = tmp;
		cout << "������ ���� ���� : ";
		cin >> tmp;
		m_iMat = tmp;
		m_iSum = m_iKor + m_iEng + m_iMat;
		m_iAvg = (float)m_iSum / 3;
		cout <<"���� ���� �Ϸ�" << endl;
		break;
	}
	_getch();
}

Student::~Student()
{}