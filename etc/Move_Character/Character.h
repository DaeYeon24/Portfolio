#pragma once
#include <Windows.h>
#include <time.h>
using namespace std;

#define MOVE_TIME 0
#define JUMP_TIME 1
#define UPDATE_TIME 50

enum INPUT_KEY
{
	NON,
	DOWN = 0,
	UP,
	LEFT,
	RIGHT
};

enum INPUT_STATE
{
	BEGIN,
	END
};

enum MOVEMENT
{
	MOVEMENT_1,
	MOVEMENT_2,
	MOVEMENT_3,
	MOVEMENT_4
};

class Character
{
private:
	HDC m_MemDC;
	HBITMAP m_pCurBitMap;
	HBITMAP m_pOldBitMap;
	BITMAP m_BitMap_Info;
	INPUT_KEY m_eInput_Key;
	MOVEMENT m_eMovement;
	bool m_bMoveFlag;
	int m_iOldClock;
	int m_iX;
	int m_iY;
	// 점프 변수
	bool m_bJumpFlag;
	int m_iJumpingFloor;
	float m_fJump_X;
	float m_fJump_Y;
public:
	Character();
	~Character();
	void Init(HDC hdc, HINSTANCE hInst);
	void Draw(HWND hWnd, HDC hdc);
	void Input(HWND hWnd, WPARAM wParam, bool& jumpstate);
	void Jump(HWND hWnd, bool& jumpstate);
	void MoveFinish();
};

