#pragma once
#include "Define.h"
class Character;

class Trap
{
protected:
	HDC m_MemDC;
	HBITMAP m_BitMap[2];
	HBITMAP m_OldBitMap;
	BITMAP m_BitMapInfo;
	RECT m_rtArea;
	float m_fX;
	int m_iOldClock;
	int m_iCurMotion;
public:
	virtual void Draw(HDC hdc) = 0;
	virtual bool Coming(PROGRESS progress, float oneframe) = 0;
	RECT Get_Area();
	float Get_X();
};

class Hurdle : public Trap
{
public:
	Hurdle(HDC hdc);
	~Hurdle();
	bool Coming(PROGRESS progress, float oneframe) override;
	void Draw(HDC hdc) override;
};

class Ring : public Trap
{
private:
	HBITMAP m_FrontBitMap[2];
	HBITMAP m_CashBitMap;
	RECT m_rtSafeZone;
	bool m_bHaveCash;
public:
	Ring(HDC hdc);
	~Ring();
	bool Coming(PROGRESS progress, float oneframe) override;
	void Draw(HDC hdc) override;
	void FrontDraw(HDC hdc);
	bool IsHaveCash();
	bool Character_In_SafeZone(Character* character);
};

class Deco
{
protected:
	HDC m_MemDC;
	HBITMAP m_OldBitMap;
	HBITMAP m_DecoBitMap;
	BITMAP m_BitMapInfo;
	float m_fX;
public:
	~Deco();
	bool Coming(PROGRESS progress, float oneframe);
	virtual void Draw(HDC hdc) = 0;
};

class Elephant : public Deco
{
public:
	Elephant(HDC hdc);
	void Draw(HDC hdc) override;
};

class Miter : public Deco
{
private:
	int m_iMiter;
public:
	Miter(HDC hdc, int miter);
	void Draw(HDC hdc) override;
};

class Stage
{
private:
	HDC m_MemDC;
	BITMAP m_BitMapInfo;
	HBITMAP m_TrackBitMap;
	HBITMAP m_AudienceBitMap[2];
	HBITMAP m_EndBitMap;
	HBITMAP m_OldBitMap;
	vector<Hurdle*> m_vecHurdleList;
	vector<Ring*> m_vecRingList;
	vector<Deco*> m_vecDecoList;
	float m_fBackGroundX;
	//골인지점
	RECT m_rtFinishArea;
	float m_fEndX;
	bool m_bShowEnd;
	//
	bool m_bGameClear;
	int m_iDistance; // 캐릭 이동거리
	int m_iLastDistance; // 최대 이동거리
	int m_iScore; // 점수
	int m_iOldMovement; // 모션 시간
	int m_iCurMotion; // 모션 동작
public:
	~Stage();
	void Init(HDC hdc);
	void Draw(HDC hdc, bool frontdraw = false);
	void Progress(PROGRESS progress, float oneframe);
	void Progress_Ring(PROGRESS progress, float oneframe);
	void Update(HDC hdc, float oneframe);
	void Create_Trap(HDC hdc);
	void Create_Deco(HDC hdc);
	void Add_CashScore();
	int Get_Score();
	vector<Hurdle*> Get_TrapList_Hurdle();
	vector<Ring*> Get_TrapList_Ring();
	RECT Get_FinishArea();
	bool IsShowEnd();
	bool IsTrackFinish();
	void Game_Clear();
};