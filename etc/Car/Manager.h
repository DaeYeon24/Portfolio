#pragma once
#include "Mecro.h"
#include "Rabbit.h"

class Manager
{
private:
	Rabbit* m_Rabbit[MAX];
public:
	Manager();
	~Manager();
	void GogoRabbit();
	void Floor();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

