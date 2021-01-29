#include "Block.h"

Block::Block(HDC hdc, int x, int y) : m_iX(x), m_iY(y)
{ //ºí·° ÁÂÇ¥, Å©±â, ¿µ¿ª ÃÊ±âÈ­
	m_MemDC = CreateCompatibleDC(hdc);
	m_fRow = BLOCK_ROW;
	m_fCol = BLOCK_COL;
	m_rtArea = { (LONG)(m_iX * m_fRow), (LONG)(m_iY * m_fCol), (LONG)((m_iX * m_fRow) + m_fRow), (LONG)((m_iY * m_fCol) + m_fCol) };
	m_fBmpStartX = 0.0f;
	m_fBmpStartY = 0.0f;
	m_fBmpEndX = 0.0f;
	m_fBmpEndY = 0.0f;
}

Block::~Block()
{
	SelectObject(m_MemDC, m_OldBmp);
	DeleteObject(m_BlockBmp);
	DeleteDC(m_MemDC);
}

Camp::~Camp()
{
	DeleteObject(m_DestroyBmp);
}

RECT Block::Get_Area()
{
	return m_rtArea;
}

float Block::Get_Center_Of_Row()
{
	return m_rtArea.left + (m_fRow / 2.0f);
}

float Block::Get_Center_Of_Col()
{
	return m_rtArea.top + (m_fCol / 2.0f);
}

Block* Block::Get_Type()
{
	return this;
}

void BreakableWall::Init()
{
	m_BlockBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\break00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_BlockBmp);
	GetObject(m_BlockBmp, sizeof(BITMAP), &m_BmpInfo);
}

void UnBreakableWall::Init()
{
	m_BlockBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\unbreak.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_BlockBmp);
	GetObject(m_BlockBmp, sizeof(BITMAP), &m_BmpInfo);
}

void Forest::Init()
{
	m_BlockBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\forest.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_BlockBmp);
	GetObject(m_BlockBmp, sizeof(BITMAP), &m_BmpInfo);
}

void River::Init()
{
	m_BlockBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\river.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_BlockBmp);
	GetObject(m_BlockBmp, sizeof(BITMAP), &m_BmpInfo);
}

void Camp::Init()
{
	m_BlockBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\camp_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_DestroyBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\camp_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_BlockBmp);
	GetObject(m_BlockBmp, sizeof(BITMAP), &m_BmpInfo);
	m_bDestroy = false;
}

void Block::Draw(HDC hdc)
{
	TransparentBlt(hdc, m_rtArea.left, m_rtArea.top, m_fRow, m_fCol, m_MemDC, 0, 0, m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, RGB(255, 0, 255));
}

void BreakableWall::Draw(HDC hdc)
{
	StretchBlt(hdc, m_rtArea.left, m_rtArea.top, m_fRow, m_fCol, m_MemDC, 0 + m_fBmpStartX , 0 +m_fBmpStartY, (m_BmpInfo.bmWidth - m_fBmpEndX) - m_fBmpStartX, (m_BmpInfo.bmHeight - m_fBmpEndY) - m_fBmpStartY, SRCCOPY);
}

void UnBreakableWall::Draw(HDC hdc)
{
	StretchBlt(hdc, m_rtArea.left, m_rtArea.top, m_fRow, m_fCol, m_MemDC, 0 + m_fBmpStartX, 0 + m_fBmpStartY, (m_BmpInfo.bmWidth - m_fBmpEndX) - m_fBmpStartX, (m_BmpInfo.bmHeight - m_fBmpEndY) - m_fBmpStartY, SRCCOPY);
}

bool Camp::Get_State()
{
	return m_bDestroy;
}

bool Block::Break(POINT pt)
{ //ºí·Ï ±úÁü
	static float decreaseRow = 950.0f / 13.0f / 3.0f;
	static float decreaseCol = 950.0f / 15.0f / 3.0f;
	RECT top = { m_rtArea.left, m_rtArea.top - 10, m_rtArea.right, m_rtArea.top + 10 };
	RECT bottom = { m_rtArea.left, m_rtArea.bottom - 10, m_rtArea.right, m_rtArea.bottom + 10 };
	RECT left = { m_rtArea.left - 10, m_rtArea.top, m_rtArea.left + 10, m_rtArea.bottom };
	RECT right = { m_rtArea.right - 10, m_rtArea.top, m_rtArea.right + 10, m_rtArea.bottom };
	if (PtInRect(&left, pt))
	{ 
		m_rtArea.left += decreaseRow;
		m_fRow -= decreaseRow;
		m_fBmpStartX += decreaseRow;
	}
	else if (PtInRect(&right, pt))
	{
		m_rtArea.right -= decreaseRow;
		m_fRow -= decreaseRow;
		m_fBmpEndX += decreaseRow;
	}
	else if (PtInRect(&top, pt))
	{
		m_rtArea.top += decreaseCol;
		m_fCol -= decreaseCol;
		m_fBmpStartY += decreaseCol;
	}
	else if (PtInRect(&bottom, pt))
	{
		m_rtArea.bottom -= decreaseCol;
		m_fCol -= decreaseCol;
		m_fBmpEndY += decreaseCol;
	}
	if ((int)m_fRow == 0 || (int)m_fCol == 0)
		return true;
	return false;
}

bool Camp::Break(POINT pt)
{
	SelectObject(m_MemDC, m_DestroyBmp);
	GetObject(m_DestroyBmp, sizeof(BITMAP), &m_BmpInfo);
	m_bDestroy = true;
	return true;
}