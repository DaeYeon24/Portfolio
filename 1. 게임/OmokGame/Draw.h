#pragma once
#include "Basic.h"

class Draw
{
private:
	int m_iWidth;
	int m_iHeight;
public:
	Draw(int x, int y);
	~Draw();
	void BoardDraw(int Show = NULL);
	void ReDraw(Position XY);
	void BoardUnderDraw(string Name, int UndoCount = NULL, int turn = NULL);
	int Menu();
	int SecondMenu();
	void Text(string str, int add = NULL);
	void BoardUnderText(string str1, int add = NULL, string str2 = "", string str3 = "");
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};