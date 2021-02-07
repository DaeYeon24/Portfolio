#pragma once
#include "Define.h"

class Block
{
protected:
	HDC m_MemDC;
	HBITMAP m_BlockBmp;
	HBITMAP m_OldBmp;
	BITMAP m_BmpInfo;
	RECT m_rtArea;
	int m_iX;
	int m_iY;
	float m_fRow;
	float m_fCol;
	float m_fBmpStartX;
	float m_fBmpStartY;
	float m_fBmpEndX;
	float m_fBmpEndY;
public:
	Block(HDC hdc, int x, int y);
	~Block();
	virtual void Init() = 0; //초기화
	virtual bool Break(POINT pt); //벽깨짐
	virtual bool Get_State() = 0; //상태
	virtual void Draw(HDC hdc); //출력
	float Get_Center_Of_Row();
	float Get_Center_Of_Col();
	RECT Get_Area();
	Block* Get_Type();
};

class BreakableWall : public Block
{
public:
	BreakableWall(HDC hdc, int x, int y) : Block(hdc, x, y) {}
	void Draw(HDC hdc) override;
	void Init() override;
	bool Get_State() { return false; }
};

class UnBreakableWall : public Block
{
public:
	UnBreakableWall(HDC hdc, int x, int y) : Block(hdc, x, y) {}
	void Draw(HDC hdc) override;
	void Init() override;
	bool Get_State() { return false; }
};

class Forest : public Block
{
public:
	Forest(HDC hdc, int x, int y) : Block(hdc, x, y) {}
	void Init() override;
	bool Break(POINT pt) { return false; }
	bool Get_State() { return false; }
};

class River : public Block
{
public:
	River(HDC hdc, int x, int y) : Block(hdc, x, y) {}
	void Init() override;
	bool Break(POINT pt) { return false; }
	bool Get_State() { return false; }
};

class Camp : public Block
{
private:
	HBITMAP m_DestroyBmp;
	bool m_bDestroy;
public:
	Camp(HDC hdc, int x, int y) : Block(hdc, x, y) {}
	~Camp();
	void Init() override;
	bool Break(POINT pt) override;
	bool Get_State() override;
};
