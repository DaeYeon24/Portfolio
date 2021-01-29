#include "Unit.h"
#include "Item.h"

Missile::~Missile()
{
	SelectObject(m_MemDC, m_OldBmp);
	for (auto i = 0; i < (int)DIRECTION_TOTAL; i++)
	{
		DeleteObject(m_MissileBmp[i]);
	}
	for (auto i = 0; i < (int)MOVEMENT_TOTAL; i++)
	{
		DeleteObject(m_BoomBmp[i]);
	}
	DeleteDC(m_MemDC);
}

Missile::Missile(HDC hdc, float x, float y, DIRECTION direction)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_MissileBmp[LEFT] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\missile_left.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_MissileBmp[RIGHT] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\missile_right.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_MissileBmp[UP] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\missile_up.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_MissileBmp[DOWN] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\missile_down.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_BoomBmp[MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\boom_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_BoomBmp[MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\boom_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_eDirection = direction;
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_MissileBmp[direction]);
	m_eMovement = MOVEMENT1;
	m_fX = x;
	m_fY = y;
	m_bIsHit = false;
	m_iOldClock = clock();
	m_fOldFrame = 0.0f;
}

void Missile::Draw(HDC hdc)
{
	if (m_bIsHit)
	{
		if (clock() - m_iOldClock >= 100)
		{
			if (m_eMovement == MOVEMENT1)
				m_eMovement = MOVEMENT2;
			else if (m_eMovement == MOVEMENT2)
				m_eMovement = MOVEMENT1;
			m_iOldClock = clock();
		}
		SelectObject(m_MemDC, m_BoomBmp[m_eMovement]);
		GetObject(m_BoomBmp[m_eMovement], sizeof(BITMAP), &m_BmpInfo);
	}
	else
	{
		SelectObject(m_MemDC, m_MissileBmp[m_eDirection]);
		GetObject(m_MissileBmp[m_eDirection], sizeof(BITMAP), &m_BmpInfo);
	}
	TransparentBlt(hdc, m_fX - (m_BmpInfo.bmWidth / 2.0f), m_fY - (m_BmpInfo.bmHeight / 2.0f), m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, m_MemDC, 0, 0, m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, RGB(255, 0, 255));
}

bool Missile::Shooting(Unit* unit, list<Block*>* blocklist, Player* player, list<Enemy*>* enemylist, float frame)
{
	if (!m_bIsHit)
	{
		switch (m_eDirection)
		{
		case LEFT:
			m_fX -= 500.0f * frame;
			break;
		case RIGHT:
			m_fX += 500.0f * frame;
			break;
		case UP:
			m_fY -= 500.0f * frame;
			break;
		case DOWN:
			m_fY += 500.0f * frame;
			break;
		}
		Hit_Object(unit, blocklist, player, enemylist);
	}
	else
	{
		if (m_fOldFrame >= 1.0f)
		{
			m_fOldFrame = 0.0f;
			return true;
		}
		else
			m_fOldFrame += frame;
	}
	return false;
}

void Missile::Hit_Object(Unit* unit, list<Block*>* blocklist, Player* player, list<Enemy*>* enemylist)
{
	if (m_fX < 0 || m_fX > INGAME_WIDTH || m_fY < 0 || m_fY > HEIGHT - 45)
	{ // 게임벽
		m_bIsHit = true;
		return;
	}
	POINT pt;
	pt.x = m_fX;
	pt.y = m_fY;
	Player* _player = dynamic_cast<Player*>(unit->Get_Type());
	if (_player) // dynamic_case 플레이어
	{
		for (auto iter = enemylist->begin(); iter != enemylist->end(); iter++)
		{
			RECT area = (*iter)->Get_Area();
			if (((*iter)->Get_State() == ALIVE || (*iter)->Get_State() == STOP) && PtInRect(&area, pt))
			{ //쉴드가 없거나 미사일 레벨이 HIGH일 때
				if (!(*iter)->Have_Shield() || player->Get_Level() == HIGH)
					(*iter)->Destroy();
				m_bIsHit = true;
				return;
			}
		}
	}
	Enemy* _enemy = dynamic_cast<Enemy*>(unit->Get_Type()); // 문제 추측
	if (_enemy) //dynamic_case 에너미
	{
		RECT area = player->Get_Area();
		if (player->Get_State() == ALIVE && PtInRect(&area, pt))
		{
			if(!player->Have_Shield())
				player->Destroy();
			m_bIsHit = true;
			return;
		}
	}
	for (auto iter = blocklist->begin(); iter != blocklist->end(); iter++)
	{
		RECT area = (*iter)->Get_Area();
		if (PtInRect(&area, pt))
		{
			Forest* forest = dynamic_cast<Forest*>((*iter)->Get_Type());
			River* river = dynamic_cast<River*>((*iter)->Get_Type());
			if (forest || river)
				return; //숲과 강은 패스
 			BreakableWall* breakablewall = dynamic_cast<BreakableWall*>((*iter)->Get_Type());
			if (breakablewall)
			{ // 일반 벽은 깨지기 때문에 Break함수 호출
				if ((*iter)->Break(pt))
				{
					delete* iter;
					*iter = NULL;
					blocklist->erase(iter);
				}
				m_bIsHit = true;
				return;
			}
			if (_player && player->Get_Level() == HIGH)
			{ // 플레이어의 미사일레벨이 HIGH일 때 강화벽도 깨짐
				UnBreakableWall* unbreakablewall = dynamic_cast<UnBreakableWall*>((*iter)->Get_Type());
				if (unbreakablewall)
				{ // 마찬가지로 Break함수 호출
					if ((*iter)->Break(pt))
					{
						delete* iter;
						*iter = NULL;
						blocklist->erase(iter);
					}
					m_bIsHit = true;
					return;
				}
			}
			Camp* camp = dynamic_cast<Camp*>((*iter)->Get_Type());
			if (camp)
			{ //에너미의 미사일은 캠프를 타격 시 캠프 Break
				if (_enemy)
					(*iter)->Break(pt);
				else
					return;
			}
			m_bIsHit = true;
			return;
		}
	}
}

Unit::~Unit()
{
	SelectObject(m_MemDC, m_OldBmp);
	for (auto i = 0; i < (int)DIRECTION_TOTAL; i++)
	{
		for (auto j = 0; j < (int)MOVEMENT_TOTAL; j++)
		{
			DeleteObject(m_UnitBmp[i][j]);
		}
	}
	for (auto i = 0; i < (int)MOVEMENT_TOTAL; i++)
	{
		DeleteObject(m_CreateBmp[i]);
		DeleteObject(m_DestroyBmp[i]);
		DeleteObject(m_ShieldBmp[i]);
	}
	DeleteDC(m_MemDC);
	if (!m_MissileList.empty())
	{
		for (auto iter = m_MissileList.begin(); iter != m_MissileList.end(); iter++)
		{
			delete* iter;
		}
		m_MissileList.clear();
	}
}

Unit::Unit(HDC hdc)
{
	m_MemDC = CreateCompatibleDC(hdc);
	m_DestroyBmp[MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\destroy_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_DestroyBmp[MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\destroy_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_ShieldBmp[MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\shield_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_ShieldBmp[MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\shield_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_CreateBmp[MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\create_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_CreateBmp[MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\create_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_eDirection = UP;
	m_eMovement = MOVEMENT1;
	m_iOldClock = clock();
	m_eState = CREATE;
	m_bShield = false;
	m_fOldFrame = 0.0f;
}

void Player::Init(HDC hdc)
{
	m_UnitBmp[LEFT][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\tank_left_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[LEFT][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\tank_left_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[RIGHT][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\tank_right_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[RIGHT][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\tank_right_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[UP][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\tank_up_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[UP][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\tank_up_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[DOWN][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\tank_down_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[DOWN][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\tank_down_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_UnitBmp[UP][MOVEMENT1]);
	wsprintf(m_cName, TEXT("Player"));
	m_fX = 325.0f;
	m_fY = 920.0f;
	m_rtArea = { (LONG)(m_fX - (ROW / 2.0f)), (LONG)(m_fY - (COL / 2.0f)), (LONG)(m_fX + (ROW / 2.0f)), (LONG)(m_fY + (COL / 2.0f)) };
	m_fSpeed = 200.0f;
	m_eMissileLevel = LOW;
}

void Enemy_Lv2::Init(HDC hdc)
{
	m_UnitBmp[LEFT][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_left_02.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[RIGHT][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_right_02.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[UP][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_up_02.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[DOWN][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_down_02.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[LEFT][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_left_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[RIGHT][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_right_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[UP][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_up_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[DOWN][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_down_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_UnitBmp[UP][MOVEMENT1]);
	wsprintf(m_cName, TEXT("Lv. 2"));
	switch (rand() % 3)
	{
	case 0:
		m_fX = 35.0f;
		break;
	case 1:
		m_fX = 475.0f;
		break;
	case 2:
		m_fX = 915.0f;
		break;
	}
	m_fY = 32.0f;
	m_rtArea = { (LONG)(m_fX - (ROW / 2.0f)), (LONG)(m_fY - (COL / 2.0f)), (LONG)(m_fX + (ROW / 2.0f)), (LONG)(m_fY + (COL / 2.0f)) };
	m_AutoClock = clock();
	m_iLife = 2;
	m_rtStayArea = { 0, 0, 0, 0 };
}

void Enemy::Init(HDC hdc)
{
	m_UnitBmp[LEFT][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_left_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[RIGHT][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_right_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[UP][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_up_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[DOWN][MOVEMENT1] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_down_00.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[LEFT][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_left_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[RIGHT][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_right_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[UP][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_up_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_UnitBmp[DOWN][MOVEMENT2] = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\e_down_01.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_UnitBmp[UP][MOVEMENT1]);
	wsprintf(m_cName, TEXT("Lv. 1"));
	switch (rand() % 3)
	{
	case 0:
		m_fX = 35.0f;
		break;
	case 1:
		m_fX = 475.0f;
		break;
	case 2:
		m_fX = 915.0f;
		break;
	}
	m_fY = 32.0f;
	m_rtArea = { (LONG)(m_fX - (ROW / 2.0f)), (LONG)(m_fY - (COL / 2.0f)), (LONG)(m_fX + (ROW / 2.0f)), (LONG)(m_fY + (COL / 2.0f)) };
	m_AutoClock = clock();
}

void Unit::Draw(HDC hdc)
{
	if (!m_MissileList.empty())
	{
		for (auto iter = m_MissileList.begin(); iter != m_MissileList.end(); iter++)
		{
			(*iter)->Draw(hdc);
		}
	}
	if (clock() - m_iOldClock >= 300)
	{
		if (m_eMovement == MOVEMENT1)
			m_eMovement = MOVEMENT2;
		else if (m_eMovement == MOVEMENT2)
			m_eMovement = MOVEMENT1;
		m_iOldClock = clock();
	}
	switch (m_eState)
	{
	case CREATE:
		SelectObject(m_MemDC, m_CreateBmp[m_eMovement]);
		GetObject(m_CreateBmp[m_eMovement], sizeof(BITMAP), &m_BmpInfo);
		break;
	case ALIVE:
	case STOP:
		SelectObject(m_MemDC, m_UnitBmp[m_eDirection][m_eMovement]);
		GetObject(m_UnitBmp[m_eDirection][m_eMovement], sizeof(BITMAP), &m_BmpInfo);
		break;
	case DESTROY:
		SelectObject(m_MemDC, m_DestroyBmp[m_eMovement]);
		GetObject(m_DestroyBmp[m_eMovement], sizeof(BITMAP), &m_BmpInfo);
		break;
	}
	TextOut(hdc, m_fX, m_fY - 30, m_cName, lstrlen(m_cName));
	TransparentBlt(hdc, m_rtArea.left, m_rtArea.top, ROW, COL, m_MemDC, 0, 0, m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, RGB(255, 0, 255));
	if (m_bShield)
	{
		SelectObject(m_MemDC, m_ShieldBmp[m_eMovement]);
		GetObject(m_ShieldBmp[m_eMovement], sizeof(BITMAP), &m_BmpInfo);
		TransparentBlt(hdc, m_rtArea.left, m_rtArea.top, ROW, COL, m_MemDC, 0, 0, m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, RGB(255, 0, 255));
	}
}

void Unit::Unit_Update(float frame)
{
	switch (m_eState)
	{
	case CREATE: //생성
		if (m_fOldFrame >= 3.0f)
		{
			m_fOldFrame = 0.0f;
			m_eState = ALIVE;
			m_bShield = true;
		}
		else
			m_fOldFrame += frame;
		return;
	case DESTROY: //파괴
		if (m_fOldFrame >= 3.0f)
		{
			m_fOldFrame = 0.0f;
			m_eState = DISAPPEAR;
		}
		else
			m_fOldFrame += frame;
		return;
	default:
		break;
	}
	if (m_bShield)
	{
		if (m_fOldFrame >= 3.0f)
		{
			m_fOldFrame = 0.0f;
			m_bShield = false;
			return;
		}
		else
			m_fOldFrame += frame;
	}
}

void Player::Operate_Shoot(HDC hdc, list<Block*>* blocklist, list<Enemy*>* enemylist, float frame)
{
	Missile* new_missile;
	static float delay = 0.0f; // 포탄발사에 딜레이를 주어서 최대 공격속도 제한
	if (m_eState == CREATE)
		return;
	if (m_eState != DESTROY && GetKeyState(VK_SPACE) & 0x8000)
	{
		if (delay >= 0.2f)
		{
			delay = 0.0f;
			new_missile = new Missile(hdc, m_fX, m_fY, m_eDirection);
			m_MissileList.push_back(new_missile);
		}
	}
	else
		delay += frame;
	if (!m_MissileList.empty())
	{ //발사된 미사일이 있을때
		for (auto iter = m_MissileList.begin(); iter != m_MissileList.end();)
		{
			if ((*iter)->Shooting(this, blocklist, this, enemylist, frame))
			{ //타격 후 해제
				delete* iter;
				*iter = NULL;
				iter = m_MissileList.erase(iter);
			}
			else
				iter++;
		}
	}
}

MISSILE_LEVEL Player::Get_Level()
{
	return m_eMissileLevel;
}

void Player::Power_Up()
{
	m_eMissileLevel = HIGH;
}

void Player::Speed_Up()
{
	m_fSpeed = 400.0f;
}

void Player::Power_Down()
{
	m_eMissileLevel = LOW;
}

void Player::Speed_Down()
{
	m_fSpeed = 200.0f;
}

void Player::Get_Item(list<Item*>* itemlist)
{
	RECT tmp;
	for (auto iter = itemlist->begin(); iter != itemlist->end(); iter++)
	{
		RECT area = (*iter)->Get_Area();
		if (IntersectRect(&tmp, &m_rtArea, &area))
			(*iter)->Get();
	}
}

void Unit::SideWay(list<Block*> blocklist, float beforeX, float beforeY, float frame)
{ // 유닛이 이동중 블럭의 일부와 부딪힐 때 비껴가는 함수
	RECT tmp;
	for (auto iter = blocklist.begin(); iter != blocklist.end(); iter++)
	{
		RECT area = (*iter)->Get_Area();
		if (IntersectRect(&tmp, &m_rtArea, &area))
		{
			Forest* forest = dynamic_cast<Forest*>((*iter)->Get_Type());
			if (forest)
				continue;
			m_fX = beforeX;
			m_fY = beforeY;
			if (m_eDirection == LEFT || m_eDirection == RIGHT)
			{ // 가는 방향의 블럭의 중심점을 찾아 비껴갈 방향 찾음
				if (m_fY <= (*iter)->Get_Center_Of_Col())
				{
					if (m_fY < 0 + (COL / 2))
						break;
					m_fY -= 150.0f * frame;
				}
				else
				{
					if (m_fY > HEIGHT - (COL / 2 + 42))
						break;
					m_fY += 150.0f * frame;
				}
			}
			else if (m_eDirection == UP || m_eDirection == DOWN)
			{
				if (m_fX <= (*iter)->Get_Center_Of_Row())
				{
					if (m_fX < 0 + (ROW / 2))
						break;
					m_fX -= 150.0f * frame;
				}
				else
				{
					if (m_fX > INGAME_WIDTH - (ROW / 2))
						break;
					m_fX += 150.0f * frame;
				}
			}
			m_rtArea = { (LONG)(m_fX - (ROW / 2.0f)), (LONG)(m_fY - (COL / 2.0f)), (LONG)(m_fX + (ROW / 2.0f)), (LONG)(m_fY + (COL / 2.0f)) };
		}
	}
}

void Player::Operate_Input(list<Block*> blocklist, float frame)
{
	float beforeX = m_fX, beforeY = m_fY;
	if (m_eState == CREATE || m_eState == DESTROY)
		return;
	if (GetKeyState(VK_LEFT) & 0x8000) 
	{
		if (m_fX > 0 + (ROW / 2))
		{
			m_eDirection = LEFT;
			m_fX -= m_fSpeed * frame;
			beforeX += 50.0f * frame;
		}
	} // 대각선이동 방지를 위해 else if
	else if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		if (m_fX < INGAME_WIDTH - (ROW / 2))
		{
			m_eDirection = RIGHT;
			m_fX += m_fSpeed * frame;
			beforeX -= 50.0f * frame;
		}
	}
	else if (GetKeyState(VK_UP) & 0x8000)
	{
		if (m_fY > 0 + (COL / 2))
		{
			m_eDirection = UP;
			m_fY -= m_fSpeed * frame;
			beforeY += 50.0f * frame;
		}
	}
	else if (GetKeyState(VK_DOWN) & 0x8000)
	{
		if (m_fY < HEIGHT - (COL / 2 + 42))
		{
			m_eDirection = DOWN;
			m_fY += m_fSpeed * frame;
			beforeY -= 50.0f * frame;
		}
	}
	m_rtArea = { (LONG)(m_fX - (ROW / 2.0f)), (LONG)(m_fY - (COL / 2.0f)), (LONG)(m_fX + (ROW / 2.0f)), (LONG)(m_fY + (COL / 2.0f)) };
	SideWay(blocklist, beforeX, beforeY, frame);
}

Unit* Unit::Get_Type()
{
	return this;
}

RECT Unit::Get_Area()
{
	return m_rtArea;
}

UNIT_STATE Unit::Get_State()
{
	return m_eState;
}

bool Unit::Have_Shield()
{
	return m_bShield;
}

void Unit::Destroy()
{
	m_eState = DESTROY;
	m_fOldFrame = 0.0f;
}

void Enemy_Lv2::Destroy()
{
	m_iLife--;
	if (m_iLife == 0)
	{
		m_eState = DESTROY;
		m_fOldFrame = 0.0f;
	}
}

void Enemy::Auto_Shoot(HDC hdc, list<Block*>* blocklist, Player* player, list<Enemy*>* enemylist, float  frame)
{
	Missile* tmp;
	static float delay = 0.0f;
	if (m_eState == CREATE)
		return;
	if (m_eState != STOP && m_eState != DESTROY && rand() % 5 == 0)
	{
		if (delay >= 1.5f)
		{
			delay = 0.0f;
			tmp = new Missile(hdc, m_fX, m_fY, m_eDirection);
			m_MissileList.push_back(tmp);
		}
	}
	else
		delay += frame;
	if (!m_MissileList.empty())
	{
		for (auto iter = m_MissileList.begin(); iter != m_MissileList.end();)
		{
			if ((*iter)->Shooting(this, blocklist, player, enemylist, frame))
			{
				delete* iter;
				*iter = NULL;
				iter = m_MissileList.erase(iter);
			}
			else
				iter++;
		}
	}
}
//
void Enemy::Find_Camp()
{
	m_eDirection = (DIRECTION)(rand() % 4);
}

void Enemy_Lv2::Find_Camp()
{
	RECT tmp;
	int random;
	if (rand() % 2 == 0)
	{ // 매개변수로 블록리스트를 가져와 캠프좌표를 참조해서 가변값으로 비교해도 되지만
		// 이 프로젝트에선 캠프위치를 전스테이지 고정이므로 고정값 비교
		if (m_fX <= CAMP_X)
			m_eDirection = RIGHT;
		else
			m_eDirection = LEFT;
	}
	else // x, y좌표 중 확률로 캠프좌표로 찾아간다.
	{
		if (m_fY <= CAMP_Y)
			m_eDirection = DOWN;
		else
			m_eDirection = UP;
	}
	if (IntersectRect(&tmp, &m_rtArea, &m_rtStayArea))
	{	// 함수진입 이전에 결정됐던 m_rtStayArea에 충돌체크 true처리가 되면 
		// 유닛이 그자리에 함수진입때까지 머물렀다는 뜻
		// 결정된 방향을 제외하고 다른 방향으로 간다.
		while (true)
		{
			random = rand() % 4;
			if (random != (int)m_eDirection)
			{
				m_eDirection = (DIRECTION)random;
				break;
			}
		}
	}
	m_rtStayArea = { (LONG)(m_fX - 5), (LONG)(m_fY - 5), (LONG)(m_fX + 5), (LONG)(m_fY + 5) };
}

void Enemy::Auto_Input(list<Block*> blocklist, float frame)
{
	float beforeX = m_fX, beforeY = m_fY;
	if (m_eState == CREATE || m_eState == STOP || m_eState == DESTROY)
		return;
	if (clock() - m_AutoClock >= MOVETIME)
	{
		Find_Camp();
		m_AutoClock = clock();
	}
	switch (m_eDirection)
	{
	case LEFT:
		if (m_fX > 0 + (ROW / 2))
		{
			m_fX -= 200.0f * frame;
			beforeX += 50.0f * frame;
		}
			break;
	case RIGHT:
		if (m_fX < INGAME_WIDTH - (ROW / 2))
		{
			m_fX += 200.0f * frame;
			beforeX -= 50.0f * frame;
		}
			break;
	case UP:
		if (m_fY > 0 + (COL / 2))
		{
			m_fY -= 200.0f * frame;
			beforeY += 50.0f * frame;
		}
		break;
	case DOWN:
		if (m_fY < HEIGHT - (COL + 15))
		{
			m_fY += 200.0f * frame;
			beforeY -= 50.0f * frame;
		}
		break;
	}
	m_rtArea = { (LONG)(m_fX - (ROW / 2.0f)), (LONG)(m_fY - (COL / 2.0f)), (LONG)(m_fX + (ROW / 2.0f)), (LONG)(m_fY + (COL / 2.0f)) };
	for (auto iter = blocklist.begin(); iter != blocklist.end(); iter++)
	{
		Camp* camp = dynamic_cast<Camp*>((*iter)->Get_Type());
		if (camp)
		{
			RECT tmp;
			RECT area = (*iter)->Get_Area();
			if (IntersectRect(&tmp, &m_rtArea, &area))
			{
				POINT tmp;
				tmp.x = 0;
				tmp.y = 0;
				(*iter)->Break(tmp);
				return;
			}
		}
	}
	SideWay(blocklist, beforeX, beforeY, frame);
}

void Enemy::Stop()
{
	if (m_eState == ALIVE)
		m_eState = STOP;
}

void Enemy::Release_Stop()
{
	if(m_eState == STOP)
		m_eState = ALIVE;
}

POINT Enemy::Get_XY()
{
	POINT pt;
	pt.x = m_fX;
	pt.y = m_fY;
	return pt;
}