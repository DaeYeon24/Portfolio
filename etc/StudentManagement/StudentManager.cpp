#include "StudentManager.h"

StudentManager::StudentManager()
{}

void StudentManager::SetNewStudent()
{
	if (m_iCount < MAX)
	{
		m_pStudentList[m_iCount] = new Student;
		m_pStudentList[m_iCount]->SetStudent(&m_iCount);
	}
	else
		cout << "정원 초과" << endl;
}

void StudentManager::GradeList(int input)
{
	cout << input << "학년 *************************" << endl;
	for (int j = 0; j < m_iCount; j++)
	{
		if (m_pStudentList[j]->GetClass() == (CLASS)input)
			m_pStudentList[j]->ShowStudent();
	}
}

void StudentManager::ShowStudentList(int iNorG)
{
	if(iNorG == NUMORGRADE_NUM)
		for (int i = 0; i < m_iCount; i++)
			m_pStudentList[i]->ShowStudent();
	else
	{
		for (int i = CLASS_START; i < CLASS_END; i++)
		{
			GradeList(i);
			cout << endl;
		}
	}
}

void StudentManager::SearchGrade()
{
	int iSelect;
	while (1)
	{
		cout << "  학년 검색(1 ~ 3) : ";
		cin >> iSelect;
		if (iSelect < 1 || iSelect > 3)
		{
			cout << "학년 범위를 벗어났습니다." << endl;
			system("pause");
			continue;
		}
		GradeList(iSelect);
		return;
	}
}

void StudentManager::SearchStudent()
{
	string strName;
	while (1)
	{
		system("cls");
		cout << "  이름 검색(검색 나가기[0]) : ";
		cin >> strName;
		for (int i = 0; i < m_iCount; i++)
		{
			if (strName == m_pStudentList[i]->GetName())
			{
				m_pStudentList[i]->ShowStudent();
				return;
			}
		}
		if (strName == "0")
			return;
		cout << "해당 이름을 가진 학생이 없습니다." << endl;
		system("pause");
	}
}

void StudentManager::RemoveStudent()
{
	cout << m_pStudentList[--m_iCount]->GetName() << "학생 동적할당 해제 완료" << endl;
	delete m_pStudentList[m_iCount];
}

void StudentManager::RemoveAll()
{
	while (m_iCount)
	{
		cout << m_pStudentList[--m_iCount]->GetName() << "학생 동적할당 해제 완료" << endl;
		delete m_pStudentList[m_iCount];
	}
}


StudentManager::~StudentManager()
{}