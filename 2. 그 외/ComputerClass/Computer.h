#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

enum BOOT
{
	ON,
	OFF
};

class Computer
{
private:
	string m_strName;
	BOOT m_eBoot;
	string m_strGPU;
	string m_strCPU;
	int m_iRam;
public:
	Computer();
	void Starting();
	void ShowCom();
	void Function();
	void Off();
};

