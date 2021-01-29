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
	STATE m_eState; // ĳ�� ����
	int m_iLife; // �����
	bool m_bRetryCoolTime;
	int m_iOldMovement; // ��� �ð�
	int m_iCurMotion; // ��� ����
	RECT m_rtCharacterArea; // ĳ�� ����
	// ĳ�� ��ǥ
	float m_fX;
	float m_fY;
	// ���� ��ǥ
	float m_fJumpX;
	float m_fJumpY;
	// retry ��ǥ
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
//���� �Ϸ�