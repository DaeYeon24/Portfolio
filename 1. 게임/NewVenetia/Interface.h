#pragma once
#include "Mecro.h"

class Interface
{
private:
	string m_input;
	string m_modify_input;
	int m_Taiping_index;
	int m_Fail_Clock;
	bool m_Fail_status;
public:
	Interface();
	~Interface();
	void Defalt();
	void BorderLine();
	template <typename T>
	void UnderLine(T value, UNDERLINE type);
	void UnderLine_Name(string name);
	void UnderLine_Score(int score);
	void UnderLine_Life(int life);
	void UnderLine_Erase(int data);
	void BoxDraw();
	void BoxText();
	void BoxText(string str, int line = 1);
	void BoxErase(int line = 1);
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y);
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	void Draw(string str, int x, int y);
	void Erase(string str, int x, int y);
	void MidText(string str, int line = NULL);
	void AlignedText(string str, int y = NULL);
	void RankingText(string name, string score, string stage, int y);
	bool InPut(string& input, int limit_length = 20);
	void SetFail();
	void ScrollErase(int Start_Width, int Start_Height, int End_Width, int End_Height);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

template <typename T>
void Interface::UnderLine(T value, UNDERLINE type)
{
	string heart = "";
	switch (type)
	{
	case NAME:
		UnderLine_Erase(NAME);
		gotoxy(NAME, HEIGHT + 1);
		cout << "NAME : " << value;
		break;
	case SCORE:
		UnderLine_Erase(SCORE);
		gotoxy(SCORE, HEIGHT + 1);
		cout << "SCORE : " << value;
		break;
	case LIFE:
		UnderLine_Erase(LIFE);
		gotoxy(LIFE, HEIGHT + 1);
		cout << "LIFE : ";
		for (int i = 0; i < (int)value; i++)
			heart += "¢¾";
		cout << heart;
		break;
	}
}

