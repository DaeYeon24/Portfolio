#include "Draw.h"

Draw::Draw()
{}

int Draw::Menu()
{
	int Select;
	Text("★ ★ ★ Snake Game ★ ★ ★");
	Text("1. 게임 시작", 3);
	Text("2. 게임 종료", 5);
	Text("Select : ", 7);
	cin >> Select;
	return Select;
}

void Draw::Score(int score)
{
	string str = "SCORE = ";
	gotoxy((WIDTH / 2) - (str.length() / 4), HEIGHT + 1);
	cout << str << score;
}

void Draw::NotifyTextXY(string str)
{
	gotoxy((WIDTH / 2) - (str.length() / 4), HEIGHT + 3);
	cout << str;
}

void Draw::NotifyTextErase()
{
	gotoxy((WIDTH / 2) - 20, HEIGHT + 3);
	cout << "                                                                   ";
}

void Draw::End()
{
	Text("★ ★ ★ Game Over ★ ★ ★");
	Text("Continue : 아무 키나 누르십시오", 3);
}

void Draw::Text(string str, int add)
{
	gotoxy((WIDTH / 2) - (str.length() / 4), (HEIGHT / 3) + add);
	cout << str;
}

Draw::~Draw()
{}