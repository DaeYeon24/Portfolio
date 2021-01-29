#pragma once
#include "Student.h"
#include "Singleton.h"

class Manager : public Singleton<Manager>
{
private:
	vector<Student*> m_vecStd_List;
public:
	inline int Get_Count()
	{
		return m_vecStd_List.size();
	}
	void New_Student();
	void Info_Student();
	Manager();
	~Manager();
};