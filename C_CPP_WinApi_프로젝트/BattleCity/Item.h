#pragma once
#include "Unit.h"

class Item
{
private:
	HDC m_MemDC;
	HBITMAP m_ItemBmp;
	HBITMAP m_OldBmp;
	BITMAP m_BmpInfo;
	ITEM_TYPE m_eType;
	RECT m_rtArea;
	bool m_bAcquire; //½Àµæ
	float m_fOldFrame;
public:
	Item(HDC hdc, float x, float y);
	~Item();
	void Draw(HDC hdc);
	void Draw_Icon(HDC hdc, int x, int y);
	bool Operate(Player* player, list<Enemy*>* enemylist, int& playerlife, float frame);
	void Get();
	RECT Get_Area();
	bool IsOperate();
};