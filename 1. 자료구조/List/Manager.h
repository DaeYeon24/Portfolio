#pragma once
#include "Student.h"

class Manager
{
private:
	Student* m_Student;
	int m_iStudent_Count;
public:
	Manager();
	~Manager();
	void Title();
	void New_Student();
	void Search_Student();
	void Info_Student();
	void Modify_Student();
	void Modify_Detail(Student* student);
	void Delete_Student();
	void Exit(Student* student);
};

