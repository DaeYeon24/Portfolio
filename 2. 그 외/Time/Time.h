#pragma once
#include <iostream>
#include <string>
using namespace std;

#define AN_HOUR 60

class Time
{
private:
	int m_iHour;
	int m_iMin;
public:
	void ShowTime();
	Time operator + (Time time);
	Time();
	Time(int Hour, int Min);
	~Time();
};