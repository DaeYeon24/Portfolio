#include "Draw.h"

Draw::Draw()
{}

void Draw::VersusLine()
{
	gotoxy(1, HEIGHT / 2);
	RED
		cout << "--------------------------------------VS------------------------------------";
	ORIGINAL
}

void Draw::BorderLine()
{
	gotoxy(0, 0);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (y == 0 || y == HEIGHT - 1)
			{
				BLUE
					cout << "▩";
				ORIGINAL
			}
			else if (x == 0 || x == WIDTH - 1)
			{
				BLUE
					cout << "▩";
				ORIGINAL
			}
			else
				cout << "  ";
		}
	}
	HIGH_GREEN
		gotoxy(13, HEIGHT + 1);
	cout << "ENTER = [메뉴 선택], [기본공격]";
	gotoxy(13, HEIGHT + 3);
	cout << "p = 7 COST 이상 [무기스킬] 발동";
	ORIGINAL
}

void Draw::Text(string str, int line)
{
	gotoxy((WIDTH / 2) - (str.length() / 4), (HEIGHT / 10) + line);
	cout << str;
}

void Draw::MenuText(string str, int line)
{
	gotoxy((WIDTH / 2) - 3, (HEIGHT / 3) + line);
	cout << str;
}

void Draw::EraseText(int line)
{
	gotoxy(10, (HEIGHT / 10) + line);
	cout << "                                                          ";
}

int Draw::ShopMenu()
{
	Text("★ ★ ★ Weapon Shop ★ ★ ★ ", 9);
	MenuText("1.  Bow", 3);
	MenuText("2.  Sword", 5);
	MenuText("3.  Wand", 7);
	MenuText("4.  Spear", 9);
	MenuText("5.  Exit", 11);
	return MenuSelectCursor(5, 2, 15, (HEIGHT / 3) + 3);
}

void Draw::ErasePoint(int x, int y)
{
	gotoxy(x, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

void Draw::DrawPoint(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

int Draw::MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
{
	int Select = 1;
	RED
		DrawPoint("▷", x, y);
	ORIGINAL
		while (1)
		{
			switch (_getch())
			{
			case UP:
				if (Select - 1 >= 1)
				{
					ErasePoint(x, y);
					y -= AddCol;
					Select--;
				}
				else
				{
					ErasePoint(x, y);
					y += (MenuLen - 1) * AddCol;
					Select = MenuLen;
				}
				break;
			case DOWN:
				if (Select + 1 <= MenuLen)
				{
					ErasePoint(x, y);
					y += AddCol;
					Select++;
				}
				else
				{
					ErasePoint(x, y);
					y -= (MenuLen - 1) * AddCol;
					Select = 1;
				}
				break;
			case ENTER:
				return Select;
			}
			RED
				DrawPoint("▷", x, y);
			ORIGINAL
		}
}

void Draw::DrawCost(int line, int cost)
{
	string str = "";
	for (int i = 0; i < cost; i++)
		str += "◆";
	gotoxy(15, (HEIGHT / 10) + line);
	GOLD
		cout << str;
	ORIGINAL
}

Draw::~Draw()
{}