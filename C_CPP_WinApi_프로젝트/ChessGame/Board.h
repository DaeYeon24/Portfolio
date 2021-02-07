#pragma once
#include "Generic.h"

struct BOARDPART
{
	HBITMAP NormalBitMap;
	HBITMAP FlashingBitMap;
	POINT Pt;
	RECT Rt;
	bool IsEmpty;
	bool FlashingState;
}; // ���� �� ĭ ����ü

class Board
{
private:
	HDC m_MemDC;
	HBITMAP m_pOldBitMap;
	vector<BOARDPART*> m_vecBoardList;
	BITMAP m_BitInfo; // ���� ����ü
public:
	Board();
	~Board();
	void Init(HDC hdc, HINSTANCE hInst);
	void Draw(HWND hWnd, HDC hdc);
	vector<BOARDPART*> Get_BoardList();
};

