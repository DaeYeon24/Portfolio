#pragma once
#include "Define.h"

class Block
{
protected:
	HDC m_MemDC;
	HBITMAP m_BlockBitMap[3];
	HBITMAP m_OldBitMap;
	BITMAP m_BitInfo;
	RECT m_rtArea;
	int m_iX;
	int m_iY;
	float m_iRow;
	float m_iCol;
	bool m_bisMine;
	BLOCK_STATE m_eState;
public:
	Block(int x, int y) : m_iX(x), m_iY(y) {}
	~Block();
	virtual void Init(HDC hdc, int rowcol) = 0; // 블라인드 아이콘, rect 설정
	void Draw(HDC hdc);
	virtual void FindEmptyBlock(Block** BlockManager, int total) = 0;
	void SetIcon(int count);
	void Mark();
	bool IsMine();
	bool IsOpen();
	void Open();
	bool GuessXY(int x, int y);
	GAME_STATE GuessWhat(Block** BlockManager, int total);
	void Show();
	bool Cursor_In_Area(POINT mousepoint);
};

class Mine : public Block
{
public:
	Mine(int x, int y) : Block(x, y) {}
	void Init(HDC hdc, int rowcol) override;
	void FindEmptyBlock(Block** BlockManager, int total) {};
};

class EmptyBlock : public Block
{
public:
	EmptyBlock(int x, int y) : Block(x, y) {}
	void Init(HDC hdc, int rowcol) override;
	void FindEmptyBlock(Block** BlockManager, int total) override;
};