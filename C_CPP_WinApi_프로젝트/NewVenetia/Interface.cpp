#include "Interface.h"

Interface::Interface()
{
	Defalt();
}

void Interface::Defalt()
{
	m_Fail_status = false;
	m_Taiping_index = -1;
	m_input = "";
	m_modify_input = "";
}

void Interface::SetFail()
{
	m_Fail_status = true;
	m_input = "입력제한";
	BoxText();
	m_Fail_Clock = clock();
}

void Interface::BorderLine()
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
}

void Interface::BoxDraw()
{
	//(WIDTH / 2) - 10, HEIGHT * 0.8, 20, 3
	//	Start_x -= Width;
	for (int y = 0; y < 3; y++)
	{
		gotoxy((WIDTH / 2) - 10, HEIGHT * 0.8 + y);
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < 20 - 1; x++)
				cout << "─";
			cout << "┐";
		}
		else if (y == 2)
		{
			cout << "└";
			for (int x = 1; x < 20 - 1; x++)
				cout << "─";
			cout << "┘";
		}
		else
		{
			cout << "│";
			for (int x = 1; x < 20 - 1; x++)
				cout << "  ";
			cout << "│";
		}
	}
	gotoxy((WIDTH / 2), HEIGHT * 0.8 + 1);
	return;
}

bool Interface::InPut(string& input, int limit_length)
{
	char tmp;
	if (m_Fail_status)
	{
		if (clock() - m_Fail_Clock >= PENALTY_TIME)
		{
			m_Fail_status = false;
			m_input = "";
			BoxErase();
		}
	}
	if (kbhit())
	{
		tmp = getch();
		if (m_Fail_status)
			return false;
		else if (tmp == ENTER)
		{
			input = m_input;
			m_Taiping_index = -1;
			m_input = "";
			m_modify_input = "";
			BoxErase();
			return true;
		}
		else if (tmp == BACKSPACE)
		{
			if (m_Taiping_index == -1)
				m_modify_input = "";
			else
			{
				for (int i = 0; i < m_Taiping_index; i++)
					m_modify_input += m_input[i];
				m_Taiping_index--;
				BoxErase(-1);
			}
			m_input = m_modify_input;
			m_modify_input = "";
		}
		else
		{
			if (m_Taiping_index >= limit_length - 1)
			{
				RED
					BoxText("글자 제한", -1);
				ORIGINAL
			}
			else
			{
				BoxErase(-1);
				m_input += tmp;
				m_Taiping_index++;
			}
		}
		BoxErase();
		input = m_input;
		BoxText(m_input);
		return false;
	}
	return false;
}

void Interface::MidText(string str, int line)
{
	gotoxy((WIDTH / 2) - (str.length() / 4), (HEIGHT / 10) + line);
	cout << str;
}

void Interface::ScrollErase(int Start_Width, int Start_Height, int End_Width, int End_Height)
{
	for (int y = Start_Height; y < End_Height - 1; y++)
	{
		gotoxy(Start_Width, y);
		for (int x = Start_Width; x < End_Width - 1; x++)
			cout << "  ";
	}
}

void Interface::BoxText()
{
	gotoxy((WIDTH / 2) - (m_input.length() / 4), HEIGHT * 0.8 + 1);
	if (m_Fail_status)
		RED
		cout << m_input;
	ORIGINAL
}

void Interface::BoxText(string str, int line)
{
	gotoxy((WIDTH / 2) - (str.length() / 4), HEIGHT * 0.8 + line);
	cout << str;
}

void Interface::BoxErase(int line)
{
	gotoxy((WIDTH / 2) - 9, HEIGHT * 0.8 + line);
	cout << "                                    ";
}

void Interface::AlignedText(string str, int y)
{
	gotoxy((WIDTH / 2) - 3, (HEIGHT / 10) + y);
	cout << str;
}

void Interface::RankingText(string name, string score, string stage, int y)
{
	gotoxy(21, (HEIGHT / 10) + y);
	cout << name;
	gotoxy(35, (HEIGHT / 10) + y);
	cout << score;
	gotoxy(48, (HEIGHT / 10) + y);
	cout << stage;
}

void Interface::ErasePoint(int x, int y)
{
	gotoxy(x, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

void Interface::Erase(string str, int x, int y)
{
	string tmp = "";
	for (int i = 0; i < str.length(); i++)
		tmp += " ";
	gotoxy(x, y);
	cout << tmp;
	gotoxy(-1, -1);
	return;
}

void Interface::DrawPoint(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void Interface::Draw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}


int Interface::MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
{
	int Select = 1;
	RED
		DrawPoint("▷", x, y);
	ORIGINAL
		while (1)
		{
			switch (getch())
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

void Interface::UnderLine_Erase(int data)
{
	gotoxy(data, HEIGHT + 1);
	cout << "                                       ";
}

void Interface::UnderLine_Name(string name)
{
	UnderLine_Erase(NAME);
	gotoxy(NAME, HEIGHT + 1);
	cout << "NAME : " << name;
}

void Interface::UnderLine_Score(int score)
{
	UnderLine_Erase(SCORE);
	gotoxy(SCORE, HEIGHT + 1);
	cout << "SCORE : " << score;
}

void Interface::UnderLine_Life(int life)
{
	UnderLine_Erase(LIFE);
	string str = "";
	gotoxy(LIFE, HEIGHT + 1);
	cout << "LIFE : ";
	for (int i = 0; i < life; i++)
		str += "♥";
	cout << str;
}


Interface::~Interface()
{}