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
}; // 보드 한 칸 구조체

class Board
{
private:
	HDC m_MemDC;
	HBITMAP m_pOldBitMap;
	vector<BOARDPART*> m_vecBoardList;
	BITMAP m_BitInfo; // 참조 구조체
public:
	Board();
	~Board();
	void Init(HDC hdc, HINSTANCE hInst);
	void Draw(HWND hWnd, HDC hdc);
	vector<BOARDPART*> Get_BoardList();
};

