#include "Block.h"

Block::~Block()
{
	SelectObject(m_MemDC, m_OldBitMap);
	for (int i = 0; i < 3; i++)
	{
		DeleteObject(m_BlockBitMap[i]);
	}
	DeleteDC(m_MemDC);
}

void Mine::Init(HDC hdc, int rowcol)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_BlockBitMap[BLIND] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\mine.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_BlockBitMap[MARK] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\flag.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBitMap = (HBITMAP)SelectObject(m_MemDC, m_BlockBitMap[BLIND]);
	m_iRow = 720.0f / rowcol;
	m_iCol =  660.0f / rowcol;
	m_rtArea = { (LONG)((m_iX * m_iRow) - (m_iRow - 92)), (LONG)((m_iY * m_iCol) - (m_iCol - 85)), (LONG)((m_iX * m_iRow) - (m_iRow - 92) + m_iRow), (LONG)((m_iY * m_iCol) - (m_iCol - 85) + m_iCol) };
	m_bisMine = true;
	m_eState = BLIND;
}

void EmptyBlock::Init(HDC hdc, int rowcol)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_BlockBitMap[BLIND] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_BlockBitMap[MARK] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\flag.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBitMap = (HBITMAP)SelectObject(m_MemDC, m_BlockBitMap[BLIND]);
	m_iRow = 720.0f / rowcol;
	m_iCol = 660.0f / rowcol;
	m_rtArea = { (LONG)((m_iX * m_iRow) - (m_iRow - 92)), (LONG)((m_iY * m_iCol) - (m_iCol - 85)), (LONG)((m_iX * m_iRow) - (m_iRow - 92) + m_iRow), (LONG)((m_iY * m_iCol) - (m_iCol - 85) + m_iCol) };
	m_bisMine = false;
	m_eState = BLIND;
}

void Block::Draw(HDC hdc)
{
	if (m_eState == BLIND)
	{
		SelectObject(m_MemDC, m_BlockBitMap[BLIND]);
		GetObject(m_BlockBitMap[BLIND], sizeof(BITMAP), &m_BitInfo);
	}
	else if (m_eState == OPEN)
	{
		SelectObject(m_MemDC, m_BlockBitMap[OPEN]);
		GetObject(m_BlockBitMap[OPEN], sizeof(BITMAP), &m_BitInfo);
	}
	else if (m_eState == MARK)
	{
		SelectObject(m_MemDC, m_BlockBitMap[MARK]);
		GetObject(m_BlockBitMap[MARK], sizeof(BITMAP), &m_BitInfo);
	}
	StretchBlt(hdc, m_rtArea.left, m_rtArea.top, m_iRow, m_iCol, m_MemDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
}

void Block::Mark()
{
	if (m_eState != OPEN && m_eState == BLIND)
		m_eState = MARK;
	else if (m_eState != OPEN && m_eState == MARK)
		m_eState = BLIND;
}

bool Block::Cursor_In_Area(POINT mousepoint)
{
	if (PtInRect(&m_rtArea, mousepoint))
		return true;
	return false;
}
//
bool Block::IsMine()
{
	return m_bisMine;
}
//
bool Block::IsOpen()
{
	if (m_eState == OPEN)
		return true;
	else
		return false;
}
//
bool Block::GuessXY(int x, int y)
{
	if (m_iX == x && m_iY == y)
		return true;
	else
		return false;
}
//
void Block::Open()
{
	m_eState = OPEN;
}
//
GAME_STATE Block::GuessWhat(Block** BlockManager, int total)
{
	if (m_eState == MARK)
		return CONTINUE;
	if (!IsMine())
	{
		FindEmptyBlock(BlockManager, total);
		return CONTINUE;
	}
	else
		return BOOM;
}
//
void EmptyBlock::FindEmptyBlock(Block** BlockManager, int total)
{
	int Count_mine = 0;
	bool Full_empty = false;
	while (1)
	{
		for (int y = m_iY - 1; y <= m_iY + 1; y++)
		{
			for (int x = m_iX - 1; x <= m_iX + 1; x++)
			{
				if (x == m_iX && y == m_iY)
					continue;
				for (int i = 0; i < total; i++)
				{
					if (BlockManager[i]->IsOpen() == false && BlockManager[i]->GuessXY(x, y))
					{
						if (Full_empty)
							BlockManager[i]->FindEmptyBlock(BlockManager, total);
						else if (BlockManager[i]->IsMine())
							Count_mine++;
						break;
					}
				}
			}
		}
		SetIcon(Count_mine);
		Open();
		if (Full_empty == false && Count_mine == 0)
			Full_empty = true;
		else
			return;
	}
}
//
void Block::SetIcon(int count)
{
	switch (count)
	{
	case 0:
		m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block_0.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		return;
	case 1:
		m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block_1.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		return;
	case 2:
		m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block_2.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		return;
	case 3:
		m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block_3.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		return;
	case 4:
		m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block_4.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		return;
	case 5:
		m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block_5.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		return;
	case 6:
		m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block_6.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		return;
	case 7:
		m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block_7.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		return;
	case 8:
		m_BlockBitMap[OPEN] = (HBITMAP)LoadImage(NULL, TEXT("Mine\\block_8.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		return;
	}
}