#include "Item.h"

Item::Item(HDC hdc, float x, float y)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_eType = (ITEM_TYPE)(rand() % 5);
	switch (m_eType)
	{
	case TYPE_STOP:
		m_ItemBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\item_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		break;
	case TYPE_BOOM:
		m_ItemBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\item_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		break;
	case TYPE_LIFE:
		m_ItemBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\item_02.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		break;
	case TYPE_SPEED:
		m_ItemBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\item_03.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		break;
	case TYPE_POWER:
		m_ItemBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\item_04.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		break;
	}
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_ItemBmp);
	GetObject(m_ItemBmp, sizeof(BITMAP), &m_BmpInfo);
	m_bAcquire = false;
	m_rtArea = { (LONG)(x - (ROW / 2.0f)), (LONG)(y - (COL / 2.0f)), (LONG)(x + (ROW / 2.0f)), (LONG)(y + (COL / 2.0f)) };
	m_fOldFrame = 0.0f;
}

Item::~Item()
{
	SelectObject(m_MemDC, m_OldBmp);
	DeleteObject(m_ItemBmp);
	DeleteDC(m_MemDC);
}

void Item::Draw(HDC hdc) //인게임 출력
{
	if(!m_bAcquire)
		TransparentBlt(hdc, m_rtArea.left, m_rtArea.top, ROW, COL, m_MemDC, 0, 0, m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, RGB(255, 0, 255));
}

void Item::Draw_Icon(HDC hdc, int x, int y) //효과 유지동안 상태창 아이콘 출력
{
	TransparentBlt(hdc, x * 52 + 15, y * 45 + 460, 40, 40, m_MemDC, 0, 0, m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, RGB(255, 0, 255));
}

void Item::Get() 
{
	m_bAcquire = true;
}

RECT Item::Get_Area()
{
	return m_rtArea;
}

bool Item::IsOperate()
{
	if (m_bAcquire)
		return true;
	else
		return false;
}

bool Item::Operate(Player* player, list<Enemy*>* enemylist, int& playerlife, float frame) //아이템 효과 적용
{
	if (m_bAcquire)
	{
		switch (m_eType)
		{
		case TYPE_STOP:
			if (m_fOldFrame >= 10.0f)
			{
				for (auto iter = enemylist->begin(); iter != enemylist->end(); iter++)
				{
					(*iter)->Release_Stop();
				}
				m_fOldFrame = 0.0f;
				return true;
			}
			else
			{
				for (auto iter = enemylist->begin(); iter != enemylist->end(); iter++)
				{
					(*iter)->Stop();
				}
				m_fOldFrame += frame;
				return false;
			}
		case TYPE_BOOM:
			for (auto iter = enemylist->begin(); iter != enemylist->end(); iter++)
			{
				if((*iter)->Get_State() != CREATE)
					(*iter)->Destroy();
			}
			return true;
		case TYPE_LIFE:
			playerlife++;
			return true;
		case TYPE_SPEED:
			if (m_fOldFrame >= 10.0f)
			{
				player->Speed_Down();
				m_fOldFrame = 0.0f;
				return true;
			}
			else
			{
				player->Speed_Up();
				m_fOldFrame += frame;
				return false;
			}
		case TYPE_POWER:
			if (m_fOldFrame >= 10.0f)
			{
				player->Power_Down();
				m_fOldFrame = 0.0f;
				return true;
			}
			else
			{
				player->Power_Up();
				m_fOldFrame += frame;
				return false;
			}
		}
	}
	return false;
}