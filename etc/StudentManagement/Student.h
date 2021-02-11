#pragma once
#include <iostream>
#include <string>
using namespace std;

enum GENDER
{
	GENDER_MAN,
	GENDER_WOMAN
};

enum  CLASS
{
	CLASS_START = 1,
	CLASS_1 = 1,
	CLASS_2,
	CLASS_3,
	CLASS_END
};

class Student
{
private:
	int m_iNumber;
	int m_iAge;
	CLASS m_eClass;
	GENDER m_eGender;
	string m_strName;
public:
	inline string GetName()
	{
		return m_strName;
	}
	inline CLASS GetClass()
	{
		return m_eClass;
	}
	void ShowStudent();
	void SetStudent(int* Count);
	Student();
	~Student();
};

