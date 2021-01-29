#pragma once
#include "Mecro.h"
#include "Login.h"

class Computer : public Login
{
private:
	string m_strName;
	BOOT m_eBoot;
	string m_strGPU;
	string m_strCPU;
	string m_strRam;
public:
	Computer();
	~Computer();
	void Main();
	void Starting();
	void ShowCom();
	void Function();
	void Off();
};