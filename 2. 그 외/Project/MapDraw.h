#pragma once
#include "Mecro.h"

class MapDraw
{
private:
	string m_strChar;
public:
	void BoxDraw(int Start_x, int Start_y, int Width, int Height);
	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};




//void ErasePoint(int x, int y);
//void DrawPoint(string str, int x, int y);
//void DrawMidText(string str, int x, int y);
//void TextDraw(string str, int x, int y);