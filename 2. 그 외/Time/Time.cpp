#include "Time.h"

Time::Time()
{
	m_iHour = 0;
	m_iMin = 0;
}

Time::Time(int Hour, int Min)
{
	m_iHour = Hour;
	if (Min >= AN_HOUR)
	{
		m_iHour += Min / AN_HOUR;
		m_iMin = Min % AN_HOUR;
	}
	else
		m_iMin = Min;
}

void Time::ShowTime()
{
	cout << "ÃÑ °øºÎ ½Ã°£ : " << m_iHour << " : " << m_iMin << endl;
}

Time Time::operator+(Time time)
{
	time.m_iHour += m_iHour;
	if (time.m_iMin + m_iMin >= AN_HOUR)
	{
		time.m_iHour += (time.m_iMin + m_iMin) / AN_HOUR;
		time.m_iMin = (time.m_iMin + m_iMin) % AN_HOUR;
	}
	else
		time.m_iMin += m_iMin;
	return time;
}

Time::~Time()
{}