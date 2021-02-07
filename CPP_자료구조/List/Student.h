#pragma once
#include "Çì´õ.h"

class Student
{
private:
	string m_strName;
	int m_iAge;
	string m_strAddress;
	int m_iKor;
	int m_iEng;
	int m_iMat;
	int m_iSum;
	float m_iAvg;
	Student* m_Next;
public:
	Student(string name, int age, string address, int kor, int eng, int mat);
	~Student();
	void Simple_Info();
	void Detail_Info();
	void Modify(DATA what);
	inline string GetName()
	{
		return m_strName;
	}
	inline int GetAge()
	{
		return m_iAge;
	}
	inline string GetAddress()
	{
		return m_strAddress;
	}
	inline Student* GetNext()
	{
		return m_Next;
	}
	inline void SetNext(Student* next)
	{
		m_Next = next;
	}
};

