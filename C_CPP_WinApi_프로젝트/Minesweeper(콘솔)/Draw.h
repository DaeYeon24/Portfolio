#pragma once
#include "Header.h"

class Draw
{
private:
	int m_iWidth;
	int m_iHeight;
public:
	Draw();
	~Draw();
	void Window();
	void BorderLine(int width, int height);
	void Text(string str, int line = NULL);
	void MenuText(string str, int line = NULL);
	void UnderLineText(string str, int line = NULL);
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	int MenuSelectCursor(int MenuLen, int AddCol);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

//template <typename T>
//void Interface::UnderLine(T value, UNDERLINE type)
//{
//	string heart = "";
//	switch (type)
//	{
//	case NAME:
//		UnderLine_Erase(NAME);
//		gotoxy(NAME, HEIGHT + 1);
//		cout << "NAME : " << value;
//		break;
//	case SCORE:
//		UnderLine_Erase(SCORE);
//		gotoxy(SCORE, HEIGHT + 1);
//		cout << "SCORE : " << value;
//		break;
//	case LIFE:
//		UnderLine_Erase(LIFE);
//		gotoxy(LIFE, HEIGHT + 1);
//		cout << "LIFE : ";
//		for (int i = 0; i < (int)value; i++)
//			heart += "¢¾";
//		cout << heart;
//		break;
//	}
//}