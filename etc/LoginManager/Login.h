#pragma once
#include "Mecro.h"

struct User
{
	string id;
	string pw;
	string nn;
	int age;
	string pn;
	int mileage;
};

class Login
{
protected:
	User* m_pUser_List[MAX]; // 10Έν
	int m_iUser_Count;
	int m_iLogin_index;
public:
	Login();
	~Login();
	void Join_InPut_Check(int IDorPW);
	void Join();
	void ShowUser();
	void AlterUser();
	int LoginUser();
	int Menu();
	void Starting();
};