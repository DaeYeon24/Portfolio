#include "Character.h"
#pragma comment(lib, "msimg32.lib")

Character::Character()
{}

void Character::MoveFinish()
{
	m_bMoveFlag = false;
	m_eMovement = MOVEMENT_1;
}

void Character::Jump(HWND hWnd, bool& jumpstate)
{
	if (m_iY > m_iJumpingFloor)
	{
		m_bJumpFlag = false;
		m_iY = m_iJumpingFloor;
		m_fJump_X = 2.0f;
		m_fJump_Y = 10.0f;
 		KillTimer(hWnd, JUMP_TIME);
		jumpstate = false;
		return;
	}
	if (m_eInput_Key == LEFT)
		m_iX -= m_fJump_X;
	else if(m_eInput_Key == RIGHT)
		m_iX += m_fJump_X;
	m_iY -= m_fJump_Y;
	m_fJump_Y -= 0.4f;
}

void Character::Input(HWND hWnd, WPARAM wParam, bool& jumpstate)
{
	if (!m_bJumpFlag)
	{
		if (wParam == VK_SPACE)
		{
			jumpstate = true;
			m_bJumpFlag = true;
			m_iJumpingFloor = m_iY;
			if (m_bMoveFlag)
			{
				m_fJump_X = 5.0f;
				m_fJump_Y = 12.0f;
			}
			SetTimer(hWnd, JUMP_TIME, 10, NULL);
			return;
		}
		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			m_bMoveFlag = true;
			m_eInput_Key = LEFT;
			m_iX -= 10;
		}
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			m_bMoveFlag = true;
			m_eInput_Key = RIGHT;
			m_iX += 10;
		}
		if (GetKeyState(VK_UP) & 0x8000)
		{
			m_bMoveFlag = true;
			m_eInput_Key = UP;
			m_iY -= 10;
		}
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			m_bMoveFlag = true;
			m_eInput_Key = DOWN;
			m_iY += 10;
		}
	}
}

void Character::Init(HDC hdc, HINSTANCE hInst)
{
	m_MemDC = CreateCompatibleDC(hdc); //메모리 DC 생성
	m_pCurBitMap = (HBITMAP)LoadImage(NULL, TEXT("Char.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_pOldBitMap = (HBITMAP)SelectObject(m_MemDC, m_pCurBitMap); // old 비트맵 저장.
	GetObject(m_pCurBitMap, sizeof(BITMAP), &m_BitMap_Info);
	m_iX = 500;
	m_iY = 500;
	m_iOldClock = clock();
	m_eInput_Key = NON;
	m_eMovement = MOVEMENT_1;
	m_bMoveFlag = false;
	m_bJumpFlag = false;
	m_fJump_X = 2.0f;
	m_fJump_Y = 10.0f;
}

void Character::Draw(HWND hWnd, HDC hdc) // 인게임 화면
{
	if (m_bMoveFlag && clock() - m_iOldClock >= UPDATE_TIME)
	{
		if (m_eMovement == MOVEMENT_1)
			m_eMovement = MOVEMENT_2;
		else if (m_eMovement == MOVEMENT_2)
			m_eMovement = MOVEMENT_3;
		else if (m_eMovement == MOVEMENT_3)
			m_eMovement = MOVEMENT_4;
		else if (m_eMovement == MOVEMENT_4)
			m_eMovement = MOVEMENT_1;
		m_iOldClock = clock();
	}
	TransparentBlt(hdc, m_iX, m_iY, (m_BitMap_Info.bmWidth / 4), (m_BitMap_Info.bmHeight / 4), m_MemDC, (m_BitMap_Info.bmWidth / 4) * m_eMovement, (m_BitMap_Info.bmHeight / 4) * m_eInput_Key, m_BitMap_Info.bmWidth / 4, m_BitMap_Info.bmHeight / 4, RGB(255, 0, 255));
}

Character::~Character()
{
	SelectObject(m_MemDC, m_pOldBitMap); 
	DeleteObject(m_pCurBitMap); 
	DeleteDC(m_MemDC); 
}
