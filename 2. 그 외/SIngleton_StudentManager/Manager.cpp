#include "Manager.h"

Manager::Manager()
{}

void Manager::New_Student()
{
	m_vecStd_List.push_back(new Student(m_vecStd_List.size() + 1));
}

void Manager::Info_Student()
{ // auto : 초기화된 값을 보고 자동으로 자료형을 잡아줌
	for (auto iter = m_vecStd_List.begin(); iter != m_vecStd_List.end(); iter++)
		(*iter)->Info();
}

Manager::~Manager()
{
	for (auto iter = m_vecStd_List.begin(); iter != m_vecStd_List.end(); iter++)
		delete (*iter);
}