#include "Student.h"

Student::Student()
{}

void Student::SetStudent(int* Count)
{
	int iTemp;
	cout << ++*Count << "�� �л� ����" << endl;
	m_iNumber = *Count;
	cout << "�̸� : ";
	cin >> m_strName;
	cout << "���� : ";
	cin >> m_iAge;
	while (1) // �г�
	{
		cout << "�г� : ";
		cin >> iTemp;
		m_eClass = (CLASS)iTemp;
		switch (m_eClass)
		{
		case CLASS_1:
		case CLASS_2:
		case CLASS_3:
			break;
		default:
			cout << "�г� ������ ������ϴ�." << endl;
			system("pause");
			continue;
		}
		break;
	}
	while (1) // ����
	{
		cout << "����(���� 0, ���� 1) : ";
		cin >> iTemp;
		m_eGender = (GENDER)iTemp;
		switch (m_eGender)
		{
		case GENDER_MAN:
		case GENDER_WOMAN:
			break;
		default:
			cout << "���� ������ ������ϴ�." << endl;
			system("pause");
			continue;
		}
		break;
	}
}

void Student::ShowStudent()
{
	cout << "====" << m_iNumber << "�� �л�====" << endl;
	cout << "  �̸� : " << m_strName << endl;
	cout << "  ���� : " << m_iAge << endl;
	cout << "  ���� : ";
	switch (m_eGender)
	{
	case GENDER_MAN:
		cout << "����" << endl;
		break;
	case GENDER_WOMAN:
		cout << "����" << endl;
		break;
	}
	cout << "  �г� : " << GetClass() << endl;
}

Student::~Student()
{}