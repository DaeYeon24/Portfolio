#pragma once
#include "Mecro.h"

class Rabbit
{
private:
	int m_iX;
	int m_iY;
	int m_iSpeed;
	int m_iOldClock;
	Rabbit* m_Next;
public:
	Rabbit();
	~Rabbit();
	inline void SetNext(Rabbit* next)
	{
		m_Next = next;
	}
	inline Rabbit* GetNext()
	{
		return m_Next;
	}
	void DrawRabbit(int x, int add);
	void EraseRabbit(int x, int add);
	void SetRabbit();
	bool MoveRabbit();
	void ChangeSpeed();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

