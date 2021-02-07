#include "Draw.h"

Draw::Draw(int x, int y)
{
	m_iWidth = x;
	m_iHeight = y;
}

void Draw::BoardDraw(int Show)
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", m_iHeight + 5, m_iWidth * 2 + 1);
	system(buf);
	for (int y = 0; y < m_iHeight; y++)
	{
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < m_iWidth - 1; x++)
			{
				if (Show == HIDE)
					cout << "─";
				else
					cout << "┬";
			}
			cout << "┐";
		}
		else if (y == m_iHeight - 1)
		{
			cout << "└";
			for (int x = 1; x < m_iWidth - 1; x++)
			{
				if (Show == HIDE)
					cout << "─";
				else
					cout << "┴";
			}
			cout << "┘";
		}
		else
		{
			if (Show == HIDE)
				cout << "│";
			else
				cout << "├";
			for (int x = 1; x < m_iWidth - 1; x++)
			{
				if (Show == HIDE)
					cout << "  ";
				else
					cout << "┼";
			}
			if (Show == HIDE)
				cout << "│";
			else
			cout << "┤";
		}
		cout << endl;
	}
	return;
}

void Draw::ReDraw(Position XY)
{
	if (XY.ix == 0 && XY.iy == 0)
		cout << "┌";
	else if (XY.ix == 0 && XY.iy == m_iHeight - 1)
		cout << "└";
	else if (XY.ix == m_iWidth - 1 && XY.iy == 0)
		cout << "┐";
	else if (XY.ix == m_iWidth - 1 && XY.iy == m_iHeight - 1)
		cout << "┘";
	else if (XY.ix == 0)
		cout << "├";
	else if (XY.ix == m_iWidth - 1)
		cout << "┤";
	else if (XY.iy == 0)
		cout << "┬";
	else if (XY.iy == m_iHeight - 1)
		cout << "┴";
	else
		cout << "┼";
}

void Draw::BoardUnderDraw(string Name, int UndoCount, int turn)
{
	if (UndoCount == NULL && turn == NULL)
		BoardUnderText("Player Name : ", 1, Name);
	else
	{
		BoardUnderText("Turn : ");
		cout << turn;
		BoardUnderText("Player Name : ", 1, Name, "  무르기 : ");
		cout << UndoCount;
	}
	BoardUnderText("====조작키====", 2);
	BoardUnderText("이동 : A, S, W, D\t돌놓기 : ENTER", 3);
	BoardUnderText("무르기 : N 옵션 : P 종료 : ESC", 4);
}

int Draw::Menu()
{
	int select;
	Text(" ★ 오 목 ★");
	Text("1. 게임 시작", 2);
	Text("2. RePlay", 4);
	Text("3. 게임 옵션", 6);
	Text("4. 게임 종료" , 8);
	Text("____________" , 10);
	gotoxy(m_iWidth / 2, (m_iHeight / 4) + 10);
	cin >> select;
	return select;
}

int Draw::SecondMenu()
{
	int select;
	BoardDraw(HIDE);
	Text(" ★ 오 목 ★");
	Text("1. 판 크기 변경", 2);
	Text("2. 커서 변경", 4);
	Text("3. 바둑알 변경", 6);
	Text("4. 무르기 횟수 변경", 8);
	Text("5. 돌아가기", 10);
	Text("____________", 12);
	gotoxy(m_iWidth / 2, (m_iHeight / 4) + 12); // 이거 수정 보류
	cin >> select;
	return select;
}

void Draw::Text(string str, int add)
{
	gotoxy((m_iWidth / 2) - (str.length() / 4), (m_iHeight / 4) + add);
	cout << str;
}

void Draw::BoardUnderText(string str1, int add, string str2, string str3)
{
	gotoxy((m_iWidth / 2) - ((str1.length() + str2.length() + str3.length()) / 4), m_iHeight + add);
	cout << str1 << str2 << str3;
}

Draw::~Draw()
{

}