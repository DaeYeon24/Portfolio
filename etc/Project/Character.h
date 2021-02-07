#pragma once
#include "Mecro.h"

class Character
{
private:
	string m_strChar;
	int m_iCharx; //ĳ���� ��ǥ x
	int m_iChary; //ĳ���� ��ǥ y
	int m_iarrLimit[4]; // �����¿� �̵��� �� �ִ� �Ÿ�
public:
	void CharSetting(int Start_x, int Start_y, int Width, int Height);
	void Start();
	void CharMove();
	void CharDraw(int x, int y);
	void EraseChar(int x, int y);
	Character();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~Character();
};

