#include "Manager.h"

Manager::Manager()
{
	m_Stage = NULL;
	m_Character = NULL;
	m_bInGame = false;
}

Manager::~Manager()
{
	SelectObject(m_BackGroundDC, m_OldBackGroundBitMap);
	DeleteObject(m_BackGroundBitMap);
	DeleteDC(m_BackGroundDC);
	SelectObject(m_BackDC, m_OldBitMap);
	SelectObject(m_BackDC, m_OldFont);
	DeleteObject(m_MyFont);
	DeleteObject(m_BackBitMap);
	DeleteDC(m_BackDC);
	DeleteObject(m_TitleBitMap);
	DeleteObject(m_CursorBitMap);
	if (m_Stage != NULL)
		delete m_Stage;
	if (m_Character != NULL)
		delete m_Character;
}

void Manager::Game_Set()
{
	if (m_Stage != NULL)
	{
		delete m_Stage;
		m_Stage = NULL;
	}
	if (m_Character != NULL)
	{
		delete m_Character;
		m_Character = NULL;
	}
	m_Stage = new Stage;
	m_Character = new Character;
	m_Stage->Init(m_BackDC);
	m_Character->Init(m_BackDC);
	m_dwCurFrame = GetTickCount();
	m_dwLastFrame = m_dwCurFrame;
}

void Manager::Init(HWND hWnd)
{
	m_hWnd = hWnd;
	m_MainDC = GetDC(m_hWnd);

	m_BackDC = CreateCompatibleDC(m_MainDC);
	m_BackGroundDC = CreateCompatibleDC(m_BackDC);

	m_BackBitMap = CreateCompatibleBitmap(m_MainDC, WIDTH, HEIGHT);
	m_BackGroundBitMap = CreateCompatibleBitmap(m_BackDC, WIDTH, HEIGHT);

	m_OldBitMap = (HBITMAP)SelectObject(m_BackDC, m_BackBitMap);
	m_OldBackGroundBitMap = (HBITMAP)SelectObject(m_BackGroundDC, m_BackGroundBitMap);

	m_MyFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "고딕");
	m_OldFont = (HFONT)SelectObject(m_BackDC, m_MyFont);

	m_TitleBitMap = (HBITMAP)LoadImage(NULL, TEXT("Circus\\title.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_CursorBitMap = (HBITMAP)LoadImage(NULL, TEXT("Circus\\cursor.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	SetTextAlign(m_BackDC, TA_CENTER);
	SetTextColor(m_BackDC, RGB(255, 255, 255));
	SetBkMode(m_BackDC, TRANSPARENT);
	ReleaseDC(m_hWnd, m_MainDC);
}

void Manager::GameLoop()
{
	if (m_bInGame)
		InGame();
	else
		Title();
}

void Manager::Title()
{
	TCHAR str[256];
	m_MainDC = GetDC(m_hWnd);
	SelectObject(m_BackGroundDC, m_BackGroundBitMap);
	BitBlt(m_BackDC, 0, 0, WIDTH, HEIGHT, m_BackGroundDC, 0, 0, BLACKNESS);
	
	SelectObject(m_BackGroundDC, m_TitleBitMap);
	GetObject(m_TitleBitMap, sizeof(BITMAP), &m_BitMap_Info);
	BitBlt(m_BackDC, (WIDTH / 2) - (m_BitMap_Info.bmWidth/2), 170, m_BitMap_Info.bmWidth, m_BitMap_Info.bmHeight, m_BackGroundDC, 0, 0, SRCCOPY);
	
	wsprintf(str, TEXT("게임 시작"));
	TextOut(m_BackDC, WIDTH / 2, 500, str, lstrlen(str));
	wsprintf(str, TEXT("게임 종료"));
	TextOut(m_BackDC, WIDTH / 2, 600, str, lstrlen(str));
	
	MenuSelectCursor(2, 100);
	
	BitBlt(m_MainDC, 0, 0, WIDTH, HEIGHT, m_BackDC, 0, 0, SRCCOPY);
	ReleaseDC(m_hWnd, m_MainDC);
}

void Manager::MenuSelectCursor(int MenuLen, int AddCol)
{
	static int x = WIDTH / 2 - 220;
	static int y = 495;
	static int select = 1;
	if (GetKeyState(VK_UP) & 0x8000)
	{
		if (select - 1 >= 1)
		{
			y -= AddCol;
			select--;
		}
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		if (select + 1 <= MenuLen)
		{
			y += AddCol;
			select++;
		}
	}
	if (GetKeyState(VK_RETURN) & 0x8000)
	{
		if (select == 1)
		{
			m_bInGame = true;
			Game_Set();
			return;
		}
		else
		{
			PostQuitMessage(0);
			return;
		}
	}
	SelectObject(m_BackGroundDC, m_CursorBitMap);
	GetObject(m_CursorBitMap, sizeof(BITMAP), &m_BitMap_Info);
	TransparentBlt(m_BackDC, x, y, 60, 60, m_BackGroundDC, 0, 0, m_BitMap_Info.bmWidth, m_BitMap_Info.bmHeight, RGB(255, 255, 255));
}

void Manager::InGame()
{
	m_dwCurFrame = GetTickCount();
	m_fOneFrame = (m_dwCurFrame - m_dwLastFrame) / 1000.0f;
	m_dwLastFrame = m_dwCurFrame;

	m_Stage->Update(m_BackDC, m_fOneFrame);

	m_Character->Update(m_Stage, m_fOneFrame, m_bInGame);

	Render();
}

void Manager::Render()
{
	TCHAR str[256];
	m_MainDC = GetDC(m_hWnd);
	// 배경 그려주고
	SelectObject(m_BackGroundDC, m_BackGroundBitMap);
	BitBlt(m_BackDC, 0, 0, WIDTH, HEIGHT, m_BackGroundDC, 0, 0, BLACKNESS);
	// 점수
	wsprintf(str, TEXT("SCORE = %d"), m_Stage->Get_Score());
	TextOut(m_BackDC, WIDTH / 2, 50, str, lstrlen(str));
	// 스테이지 그려주고
	SelectObject(m_BackDC, m_OldFont);
	m_Stage->Draw(m_BackDC);
	SelectObject(m_BackDC, m_MyFont);
	// 캐릭터 그려주고
	m_Character->Draw(m_BackDC);
	m_Stage->Draw(m_BackDC, true);
	// 완성된 backDC 그려준다.
	BitBlt(m_MainDC, 0, 0, WIDTH, HEIGHT, m_BackDC, 0, 0, SRCCOPY);
	ReleaseDC(m_hWnd, m_MainDC);
}

void Manager::Release()
{
	Destroy_Instance();
}