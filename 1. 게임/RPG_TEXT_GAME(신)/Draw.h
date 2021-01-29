#pragma once
#include "Header.h"

class Draw
{
public:
	Draw();
	~Draw();
	void BorderLine();
	void VersusLine();
	void Text(string str, int line = NULL);
	void MenuText(string str, int line = NULL);
	void EraseText(int line = NULL);
	void DrawCost(int line, int cost);
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	int ShopMenu();
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};