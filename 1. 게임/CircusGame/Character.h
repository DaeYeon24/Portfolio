#pragma once
#include "Stage.h"

class Character
{
private:
	HDC m_MemDC;
	BITMAP m_BitMapInfo;
	HBITMAP m_CurBitMap[4];
	HBITMAP m_WinBitMap[2];
	HBITMAP m_LifeBitMap;
	HBITMAP m_OldBitMap;
	STATE m_eState; // 캐릭 상태
	int m_iLife; // 생명력
	bool m_bRetryCoolTime;
	int m_iOldMovement; // 모션 시간
	int m_iCurMotion; // 모션 동작
	RECT m_rtCharacterArea; // 캐릭 영역
	// 캐릭 좌표
	float m_fX;
	float m_fY;
	// 점프 좌표
	float m_fJumpX;
	float m_fJumpY;
	// retry 좌표
	float m_fRetryX;
public:
	~Character();
	void Init(HDC hdc);
	void Draw(HDC hdc);
	void Update(Stage* stage, float oneframe, bool& ingame);
	void Operate_Input(Stage* stage, float oneframe);
	void Collision(Stage* stage);
	void RetryCoolDown(float oneframe);
	bool Die(float oneframe);
	void Shock(float oneframe);
	bool Game_Clear(Stage* stage, float oneframe);
	RECT Get_Area();
};
//정리 완료