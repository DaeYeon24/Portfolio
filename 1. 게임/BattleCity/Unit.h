#pragma once
#include "Block.h"
class Unit;
class Player;
class Enemy;
class Item;

class Missile
{
private:
	HDC m_MemDC;
	HBITMAP m_MissileBmp[DIRECTION_TOTAL];
	HBITMAP m_BoomBmp[MOVEMENT_TOTAL];
	HBITMAP m_OldBmp;
	BITMAP m_BmpInfo;
	DIRECTION m_eDirection;
	MOVEMENT m_eMovement;
	int m_iOldClock;
	float m_fX;
	float m_fY;
	bool m_bIsHit;
	float m_fOldFrame;
public:
	Missile(HDC hdc, float x, float y, DIRECTION direction);
	~Missile();
	void Draw(HDC hdc);
	bool Shooting(Unit* unit, list<Block*>* blocklist, Player* player, list<Enemy*>* enemylist, float frame);
	void Hit_Object(Unit* unit, list<Block*>* blocklist, Player* player, list<Enemy*>* enemylist);
};

class Unit
{
protected:
	HDC m_MemDC;
	HBITMAP m_UnitBmp[DIRECTION_TOTAL][MOVEMENT_TOTAL];
	HBITMAP m_CreateBmp[MOVEMENT_TOTAL];
	HBITMAP m_DestroyBmp[MOVEMENT_TOTAL];
	HBITMAP m_ShieldBmp[MOVEMENT_TOTAL];
	HBITMAP m_OldBmp;
	BITMAP m_BmpInfo;
	RECT m_rtArea;
	DIRECTION m_eDirection;
	MOVEMENT m_eMovement;
	list<Missile*> m_MissileList;
	UNIT_STATE m_eState;
	TCHAR m_cName[10];
	bool m_bShield;
	int m_iOldClock;
	float m_fX;
	float m_fY;
	float m_fOldFrame;
public:
	~Unit();
	Unit(HDC hdc);
	virtual void Init(HDC hdc) = 0;
	virtual void Destroy();
	void Draw(HDC hdc);
	void SideWay(list<Block*> blocklist, float beforeX, float beforeY, float frame); //블럭 비껴가기
	bool Have_Shield();
	void Unit_Update(float frame);
	Unit* Get_Type();
	RECT Get_Area();
	UNIT_STATE Get_State();
};

class Player : public Unit
{
private:
	float m_fSpeed;
	MISSILE_LEVEL m_eMissileLevel;
public:
	Player(HDC hdc) : Unit(hdc) {}
	void Init(HDC hdc)	 override;
	void Operate_Shoot(HDC hdc, list<Block*>* blocklist, list<Enemy*>* enemylist, float frame); // 에너미 벡터 받을 예정
	void Operate_Input(list<Block*> blocklist, float frame);
	void Get_Item(list<Item*>* itemlist);
	void Power_Up();
	void Speed_Up();
	void Power_Down();
	void Speed_Down();
	MISSILE_LEVEL Get_Level();
};

class Enemy : public Unit
{
protected:
	int m_AutoClock;
public:
	Enemy(HDC hdc) : Unit(hdc) {}
	void Init(HDC hdc)	 override;
	void Auto_Shoot(HDC hdc, list<Block*>* blocklist, Player* player, list<Enemy*>* enemylist, float frame); // 에너미 벡터 받을 예정
	void Auto_Input(list<Block*> blocklist, float frame);
	virtual void Find_Camp();
	void Stop();
	void Release_Stop();
	POINT Get_XY();
};

class Enemy_Lv2 : public Enemy
{
private:
	int m_iLife;
	RECT m_rtStayArea;
public:
	Enemy_Lv2(HDC hdc) : Enemy(hdc) {}
	void Init(HDC hdc)	 override;
	void Find_Camp() override;
	void Destroy() override;
};