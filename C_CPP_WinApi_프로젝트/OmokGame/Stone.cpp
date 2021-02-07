#include "Stone.h"
string Stone::strCursor_1p = "○";
string Stone::strStone_1p = "○";
string Stone::strCursor_2p = "●";
string Stone::strStone_2p = "●";
int Stone::iUndo = 5;

Stone::Stone(int Width, int Height, int playernumber, Draw* DrawManager)
{
	m_DrawManager = DrawManager;
	if (Width <= Height) // 대각선 길이는 가로 세로 중 짧은 쪽 만큼
		m_iDiagonal = Width;
	else
		m_iDiagonal = Height;
	m_XY.ix = Width / 2;
	m_XY.iy = Height / 2;
	m_Limit.iLeft = m_XY.ix - (Width / 2);
	m_Limit.iRight = m_XY.ix + (Width / 2);
	m_Limit.iTop = m_XY.iy - (Height / 2);
	m_Limit.iBottom = m_XY.iy + (Height / 2);
	if (Width % 2 == 0)
		m_Limit.iRight--;
	if (Height % 2 == 0)
		m_Limit.iBottom--;
	m_iCount = 0;
	m_Record = new Position[(Width * Height) / 2];
	if (playernumber == PLAYER_1P)
	{
		m_strCursor = strCursor_1p;
		m_strStone = strStone_1p;
	}
	else if (playernumber == PLAYER_2P)
	{
		m_strCursor = strCursor_2p;
		m_strStone = strStone_2p;
	}
	m_iUndo = iUndo;
}

void Stone::AllStoneDraw()
{
	for (int i = 0; i < m_iCount; i++)
	{
		gotoxy(m_Record[i].ix, m_Record[i].iy);
		cout << m_strStone;
	}
}

void Stone::DrawStone(int x, int y)
{
	gotoxy(x, y);
	cout << m_strCursor;
}

void Stone::Erase(Stone* opponent)
{
	gotoxy(m_XY.ix, m_XY.iy);
	if (Check(m_XY, true) == true || opponent->Check(m_XY, true) == true)
		return;
	else
		m_DrawManager->ReDraw(m_XY);
}

bool Stone::Check(Position CursorPosition, bool DrawStatus)
{
	for (int i = 0; i < m_iCount; i++)
	{
		if (CursorPosition.ix == m_Record[i].ix && CursorPosition.iy == m_Record[i].iy)
		{
			if (DrawStatus == true)
			{
				gotoxy(CursorPosition.ix, CursorPosition.iy);
				cout << m_strStone;
			}
			return true;
		}
	}
	return false;
}

int Stone::Move(Stone* opponent)
{
	if (m_iCount == 0)
		DrawStone(m_XY.ix, m_XY.iy);
	while (1)
	{
		switch (getch())
		{
		case DROP:
			if (Check(m_XY) == true || opponent->Check(m_XY) == true)
				break;
			else
			{
				gotoxy(m_XY.ix, m_XY.iy);
				cout << m_strStone;
				m_Record[m_iCount].ix = m_XY.ix;
				m_Record[m_iCount++].iy = m_XY.iy;
				if (WinCheck(m_XY.ix, m_XY.iy) == WIN)
					return WIN;
				else
					return ING;
			}
		case LEFT:
			if (m_XY.ix - 1 < m_Limit.iLeft)
				break;
			Erase(opponent);
			DrawStone(--m_XY.ix, m_XY.iy);
			break;
		case RIGHT:
			if (m_XY.ix + 1 > m_Limit.iRight)
				break;
			Erase( opponent);
			DrawStone(++m_XY.ix, m_XY.iy);
			break;
		case UP:
			if (m_XY.iy - 1 < m_Limit.iTop)
				break;
			Erase(opponent);
			DrawStone(m_XY.ix, --m_XY.iy);
			break;
		case DOWN:
			if (m_XY.iy + 1 > m_Limit.iBottom)
				break;
			Erase(opponent);
			DrawStone(m_XY.ix, ++m_XY.iy);
			break;
		case OPTION:
			return PAUSE;
		case UNDO:
			return RETURN;
		case ESC:
			return EXIT;
		}
	}
}

void Stone::Undo()
{
	m_Record[--m_iCount].ix = NULL;
	m_Record[m_iCount].iy = NULL;
	m_iUndo--;
}

void Stone::RemoveCursor()
{
	gotoxy(m_XY.ix, m_XY.iy);
	cout << "  ";
}

int Stone::WinCheck(int x, int y)
{
	bool FiveStone = false;
	int Linked = 0;
	for (int i = 0; i < m_Limit.iRight; i++) // 가로 체크
	{
		if (Check(Position(i, y)) == true)
			Linked++;
		else
		{
			if (FiveStone == true)
				return WIN;
			else
				Linked = 0;
		}
		if (Linked == 5)
			FiveStone = true;
		else if (Linked >= 5)
			FiveStone = false;
	}
	if (FiveStone == true)
		return WIN;
	Linked = 0;
	for (int i = 0; i < m_Limit.iBottom; i++) // 세로체크
	{
		if (Check(Position(x, i)) == true)
			Linked++;
		else
		{
			if (FiveStone == true)
				return WIN;
			else
				Linked = 0;
		}
		if (Linked == 5)
			FiveStone = true;
		else if (Linked >= 5)
			FiveStone = false;
	}
	if (FiveStone == true)
		return WIN;
	Linked = 0;
	for (int i = -m_iDiagonal; i < m_iDiagonal; i++) // 우하향 대각선
	{
		if (Check(Position(x+i, y+i)) == true)
			Linked++;
		else
		{
			if (FiveStone == true)
				return WIN;
			else
				Linked = 0;
		}
		if (Linked == 5)
			FiveStone = true;
		else if (Linked >= 5)
			FiveStone = false;
	}
	if (FiveStone == true)
		return WIN;
	Linked = 0;
	for (int i = -m_iDiagonal; i < m_iDiagonal; i++) // 우상향 대각선
	{
		if (Check(Position(x+i, y-i)) == true)
			Linked++;
		else
		{
			if (FiveStone == true)
				return WIN;
			else
				Linked = 0;
		}
		if (Linked == 5)
			FiveStone = true;
		else if (Linked >= 5)
			FiveStone = false;
	}
	if (FiveStone == true)
		return WIN;
	Linked = 0;
	return ING;
}

void Stone::ChangeIconSet(int playernumber)
{
	if (playernumber == PLAYER_1P)
	{
		m_strCursor = strCursor_1p;
		m_strStone = strStone_1p;
	}
	else if (playernumber == PLAYER_2P)
	{
		m_strCursor = strCursor_2p;
		m_strStone = strStone_2p;
	}
}

Stone::~Stone()
{
	delete m_Record;
}