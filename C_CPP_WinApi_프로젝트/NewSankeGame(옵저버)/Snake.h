#pragma once
#include "Block.h"
#include "Draw.h"
class Alarm;
class Enemy;

struct LIST_BODY
{
	int m_ix;
	int m_iy;
	int m_iBeforeX;
	int m_iBeforeY;
	char m_Direction;
	char m_LastDirection;
};

class Observer
{
public:
	virtual void Notify(string name) = 0;
};

class Snake : public Observer
{
protected:
	list<LIST_BODY> m_list;
	list<LIST_BODY>::iterator m_Head;
	int m_iCount;
	int m_iSpeed;
	int m_iOldClock;
	bool m_alarmState;
	Alarm* m_Alarm;
public:
	Snake();
	~Snake();
	list<LIST_BODY>::iterator GetHead();
	void Notify(string name) override; //
	void StartSnake();
	void GrowSnake();
	virtual void DrawSnake(int x, int y);
	void EraseSnake(list<LIST_BODY>::iterator CurPosition);
	virtual int Move(Block* block, Enemy* enemy = NULL);
	int CheckTail(Enemy* enemy);
	void Input(char key);
	void SetAlarm(Alarm* alarm, bool alarmstate = true);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

