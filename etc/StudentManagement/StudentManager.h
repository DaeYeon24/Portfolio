#pragma once
#include "Student.h"

#define MAX 10

enum NUMORGRADE
{
	NUMORGRADE_NUM = 2,
	NUMORGRADE_GRADE
};

class StudentManager
{
private:
	int m_iCount = 0;
	Student* m_pStudentList[MAX];
public:
	void SetNewStudent();
	void ShowStudentList(int NorG);
	inline int GetCount()
	{
		return m_iCount;
	}
	void SearchStudent();
	void GradeList(int i);
	void SearchGrade();
	void RemoveStudent();
	void RemoveAll();
	StudentManager();
	~StudentManager();
};

