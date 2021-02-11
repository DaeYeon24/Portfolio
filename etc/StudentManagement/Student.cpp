#include "Student.h"

Student::Student()
{}

void Student::SetStudent(int* Count)
{
	int iTemp;
	cout << ++*Count << "번 학생 정보" << endl;
	m_iNumber = *Count;
	cout << "이름 : ";
	cin >> m_strName;
	cout << "나이 : ";
	cin >> m_iAge;
	while (1) // 학년
	{
		cout << "학년 : ";
		cin >> iTemp;
		m_eClass = (CLASS)iTemp;
		switch (m_eClass)
		{
		case CLASS_1:
		case CLASS_2:
		case CLASS_3:
			break;
		default:
			cout << "학년 범위를 벗어났습니다." << endl;
			system("pause");
			continue;
		}
		break;
	}
	while (1) // 성별
	{
		cout << "성별(남자 0, 여자 1) : ";
		cin >> iTemp;
		m_eGender = (GENDER)iTemp;
		switch (m_eGender)
		{
		case GENDER_MAN:
		case GENDER_WOMAN:
			break;
		default:
			cout << "성별 범위를 벗어났습니다." << endl;
			system("pause");
			continue;
		}
		break;
	}
}

void Student::ShowStudent()
{
	cout << "====" << m_iNumber << "번 학생====" << endl;
	cout << "  이름 : " << m_strName << endl;
	cout << "  나이 : " << m_iAge << endl;
	cout << "  성별 : ";
	switch (m_eGender)
	{
	case GENDER_MAN:
		cout << "남자" << endl;
		break;
	case GENDER_WOMAN:
		cout << "여자" << endl;
		break;
	}
	cout << "  학년 : " << GetClass() << endl;
}

Student::~Student()
{}