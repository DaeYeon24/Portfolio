#pragma once
#include "Mecro.h"

class Draw
{
public:
	Draw();
	~Draw();
	int Menu();
	void Score(int score);
	void NotifyTextXY(string str);
	void NotifyTextErase();
	void End();
	void Text(string str, int add = NULL);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

