#include "Board.h"

Board::Board()
{}

Board::~Board()
{
	SelectObject(m_MemDC, m_pOldBitMap);
	for (auto i = 0; i < m_vecBoardList.size(); i++)
	{
		DeleteObject(m_vecBoardList.at(i)->NormalBitMap);
		DeleteObject(m_vecBoardList.at(i)->FlashingBitMap);
		delete m_vecBoardList.at(i);
	}
	m_vecBoardList.clear();
	DeleteDC(m_MemDC);
}

vector<BOARDPART*> Board::Get_BoardList()
{
	return m_vecBoardList;
}

void Board::Init(HDC hdc, HINSTANCE hInst)
{
	BOARDPART* tmp;
	int x = 0, y = 0;
	m_MemDC = CreateCompatibleDC(hdc); // 메모리 DC 생성
	for (int i = 0; i < 64; i++)
	{
		tmp = new BOARDPART;
		if (y % 2 == 0)
		{
			if (i % 2 == 0)
				tmp->NormalBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP13));
			else
				tmp->NormalBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14));
		}
		else
		{
			if (i % 2 == 0)
				tmp->NormalBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14));
			else
				tmp->NormalBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP13));
		}
		tmp->FlashingBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP15));
		tmp->Pt.x = x;
		tmp->Pt.y = y;
		tmp->Rt = { (x * 75 + 150), (y * 75 + 150), (x * 75 + 150) + 70, (y * 75 + 150) + 70 };
		tmp->IsEmpty = true;
		tmp->FlashingState = false;
		m_vecBoardList.push_back(tmp);
		x++;
		if (x % 8 == 0)
		{
			x = 0;
			y++;
		}
	}
	m_pOldBitMap = (HBITMAP)SelectObject(m_MemDC, m_vecBoardList.at(0)->NormalBitMap); // old 비트맵 저장
}

void Board::Draw(HWND hWnd, HDC hdc)
{
	for (auto i = 0; i < m_vecBoardList.size(); i++)
	{
		if (m_vecBoardList.at(i)->FlashingState)
		{
			SelectObject(m_MemDC, m_vecBoardList.at(i)->FlashingBitMap);
			GetObject(m_vecBoardList.at(i)->FlashingBitMap, sizeof(BITMAP), &m_BitInfo);
		}
		else
		{
			SelectObject(m_MemDC, m_vecBoardList.at(i)->NormalBitMap);
			GetObject(m_vecBoardList.at(i)->NormalBitMap, sizeof(BITMAP), &m_BitInfo);
		}
		StretchBlt(hdc, m_vecBoardList.at(i)->Rt.left, m_vecBoardList.at(i)->Rt.top, 70, 70, m_MemDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
	}
}