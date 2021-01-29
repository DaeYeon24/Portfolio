#include "GameManager.h"

GameManager::GameManager()
{
	m_BlockManager = NULL;
	m_bInGame = false;
	m_iRow = EASY; // 최초 쉬움단계
	m_iCol = EASY; //
	m_iTotal = m_iRow * m_iCol;
}

GameManager::~GameManager()
{
	SelectObject(m_BackGroundDC, m_OldBackGroundBitMap);
	DeleteObject(m_BackGroundBitMap);
	DeleteDC(m_BackGroundDC);
	SelectObject(m_BackDC, m_OldBitMap);
	SelectObject(m_BackDC, m_OldFont);
	DeleteObject(m_MyFont);
	DeleteObject(m_BackBitMap);
	DeleteDC(m_BackDC);
	DeleteObject(m_ScreenBitMap);
	DeleteObject(m_TitleBitMap);
	DeleteObject(m_StartBitMap);
	DeleteObject(m_ExitBitMap);
	if (m_BlockManager)
	{
		for (int i = 0; i < m_iTotal; i++)
		{
			if (m_BlockManager[i])
				delete m_BlockManager[i];
		}
		delete m_BlockManager;
	}
}

void GameManager::Init(HWND hWnd)
{
	m_hWnd = hWnd;
	m_MainDC = GetDC(m_hWnd);

	m_BackDC = CreateCompatibleDC(m_MainDC);
	m_BackGroundDC = CreateCompatibleDC(m_BackDC);

	m_BackBitMap = CreateCompatibleBitmap(m_MainDC, WIDTH, HEIGHT);
	m_BackGroundBitMap = CreateCompatibleBitmap(m_BackDC, WIDTH, HEIGHT);

	m_OldBitMap = (HBITMAP)SelectObject(m_BackDC, m_BackBitMap);
	m_OldBackGroundBitMap = (HBITMAP)SelectObject(m_BackGroundDC, m_BackGroundBitMap);

	m_MyFont = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "고딕");
	m_OldFont = (HFONT)SelectObject(m_BackDC, m_MyFont);

	m_ScreenBitMap = (HBITMAP)LoadImage(NULL, TEXT("Mine\\back.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_TitleBitMap = (HBITMAP)LoadImage(NULL, TEXT("Mine\\title.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_StartBitMap = (HBITMAP)LoadImage(NULL, TEXT("Mine\\start.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_ExitBitMap = (HBITMAP)LoadImage(NULL, TEXT("Mine\\exit.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	SetTextAlign(m_BackDC, TA_CENTER);
	SetTextColor(m_BackDC, RGB(255, 0, 0));
	SetBkMode(m_BackDC, TRANSPARENT);
	ReleaseDC(m_hWnd, m_MainDC);
}

void GameManager::Game_Set()
{
	int x = 1, y = 1;
	m_iMineCount = 0;
	m_iTimer = 0;
	m_eGameState = CONTINUE;
	if (m_BlockManager)
	{
		for (int i = 0; i < m_iTotal; i++) // 이전 블럭개수
		{
			if (m_BlockManager[i])
			{
				delete m_BlockManager[i];
				m_BlockManager[i] = NULL;
			}
		}
		delete m_BlockManager;
		m_BlockManager = NULL;
	}
	m_iTotal = m_iRow * m_iCol; // 난이도 단계 별 블럭개수 갱신
	m_BlockManager = new Block * [m_iTotal];
	for (int i = 0; i < m_iTotal; i++)
	{
		switch (rand() % 5)
		{
		case 0:
			m_iMineCount++;
			m_BlockManager[i] = new Mine(x, y);
			break;
		default:
			m_BlockManager[i] = new EmptyBlock(x, y);
			break;
		}
		m_BlockManager[i]->Init(m_BackDC, m_iRow);
		if (x == (m_iRow))
		{
			x = 1;
			y++;
		}
		else
			x++;
	}
	SetTimer(m_hWnd, 1, 1000, NULL);
}

void GameManager::Time_Counting()
{
	m_iTimer++;
}

void GameManager::GameLoop()
{
	if (m_bInGame)
		InGame();
	else
		Title();
}

void GameManager::Release()
{
	Destroy_Instance();
}

void GameManager::InGame()
{
	m_MainDC = GetDC(m_hWnd);

	if (WinCheck())
		m_eGameState = CLEAR;

	if (m_eGameState == CLEAR)
		Win();
	else if (m_eGameState == BOOM)
		Boom();

	Render();

	ReleaseDC(m_hWnd, m_MainDC);
}

void GameManager::Render()
{
	TCHAR str[32];
	SelectObject(m_BackGroundDC, m_BackGroundBitMap);
	BitBlt(m_BackDC, 0, 0, WIDTH, HEIGHT, m_BackGroundDC, 0, 0, WHITENESS);

	SelectObject(m_BackGroundDC, m_ScreenBitMap);
	GetObject(m_ScreenBitMap, sizeof(BITMAP), &m_BitInfo);
	StretchBlt(m_BackDC, (WIDTH / 2) - (m_BitInfo.bmWidth / 2), 10, m_BitInfo.bmWidth, m_BitInfo.bmHeight, m_BackGroundDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
	
	for (int i = 0; i < m_iTotal; i++)
	{
		m_BlockManager[i]->Draw(m_BackDC);
	}

	wsprintf(str, TEXT("%02d"), m_iMineCount);
	TextOut(m_BackDC, 226, 34, str, lstrlen(str));

	wsprintf(str, TEXT("%03d"), m_iTimer);
	TextOut(m_BackDC, 681, 34, str, lstrlen(str));

	BitBlt(m_MainDC, 0, 0, WIDTH, HEIGHT, m_BackDC, 0, 0, SRCCOPY);
}
void GameManager::Title()
{
	m_MainDC = GetDC(m_hWnd);
	SelectObject(m_BackGroundDC, m_BackGroundBitMap);
	BitBlt(m_BackDC, 0, 0, WIDTH, HEIGHT, m_BackGroundDC, 0, 0, WHITENESS);

	SelectObject(m_BackGroundDC, m_ScreenBitMap);
	GetObject(m_ScreenBitMap, sizeof(BITMAP), &m_BitInfo);
	StretchBlt(m_BackDC, (WIDTH / 2) - (m_BitInfo.bmWidth / 2), 10, m_BitInfo.bmWidth, m_BitInfo.bmHeight, m_BackGroundDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
	
	SelectObject(m_BackGroundDC, m_TitleBitMap);
	GetObject(m_TitleBitMap, sizeof(BITMAP), &m_BitInfo);
	StretchBlt(m_BackDC, (WIDTH / 2) - (m_BitInfo.bmWidth / 2), 150, m_BitInfo.bmWidth, m_BitInfo.bmHeight, m_BackGroundDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
	
	SelectObject(m_BackGroundDC, m_StartBitMap);
	GetObject(m_StartBitMap, sizeof(BITMAP), &m_BitInfo);
	StretchBlt(m_BackDC, (WIDTH / 2) - (m_BitInfo.bmWidth / 2), 300, m_BitInfo.bmWidth, m_BitInfo.bmHeight, m_BackGroundDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
	
	SelectObject(m_BackGroundDC, m_ExitBitMap);
	GetObject(m_ExitBitMap, sizeof(BITMAP), &m_BitInfo);
	StretchBlt(m_BackDC, (WIDTH / 2) - (m_BitInfo.bmWidth / 2), 500, m_BitInfo.bmWidth, m_BitInfo.bmHeight, m_BackGroundDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);

	BitBlt(m_MainDC, 0, 0, WIDTH, HEIGHT, m_BackDC, 0, 0, SRCCOPY);
	ReleaseDC(m_hWnd, m_MainDC);
}

void GameManager::Change_Stage(STAGE stage)
{
	if (m_bInGame)
	{
		MessageBox(m_hWnd, TEXT("타이틀화면에서만 변경 가능."), TEXT("error"), MB_OK);
		return;
	}
	switch (stage)
	{
	case EASY:
		m_iRow = EASY;
		m_iCol = EASY;
		break;
	case NORMAL:
		m_iRow = NORMAL;
		m_iCol = NORMAL;
		break;
	case HARD:
		m_iRow = HARD;
		m_iCol = HARD;
		break;
	}
	MessageBox(m_hWnd, TEXT("난이도가 변경되었습니다."), TEXT("success"), MB_OK);
	return;
}

void GameManager::Cursor_Interaction(CURSER_INTERACTION interaction, POINT mousepoint)
{
	SelectObject(m_BackGroundDC, m_StartBitMap);
	GetObject(m_StartBitMap, sizeof(BITMAP), &m_BitInfo);
	RECT StartRect = { (WIDTH / 2) - (m_BitInfo.bmWidth / 2), 300, (WIDTH / 2) - (m_BitInfo.bmWidth / 2) + m_BitInfo.bmWidth, 300 + m_BitInfo.bmHeight };
	
	SelectObject(m_BackGroundDC, m_ExitBitMap);
	GetObject(m_ExitBitMap, sizeof(BITMAP), &m_BitInfo);
	RECT ExitRect = { (WIDTH / 2) - (m_BitInfo.bmWidth / 2), 500, (WIDTH / 2) - (m_BitInfo.bmWidth / 2) + m_BitInfo.bmWidth, 500 + m_BitInfo.bmHeight };
	
	if (m_bInGame)
	{
		for (int i = 0; i < m_iTotal; i++)
		{
			if (m_BlockManager[i]->Cursor_In_Area(mousepoint))
			{
				switch (interaction)
				{
				case CURSOR_MARK:
					m_BlockManager[i]->Mark();
					return;
				case CURSOR_SELECT:
					m_eGameState = m_BlockManager[i]->GuessWhat(m_BlockManager, m_iTotal);
					return;
				}
			}
		}
	}
	else if(interaction == CURSOR_SELECT)// 타이틀
	{
		if (PtInRect(&StartRect, mousepoint))
		{
			m_bInGame = true;
			Game_Set();
			return;
		}
		if (PtInRect(&ExitRect, mousepoint))
		{
			PostQuitMessage(0);
			return;
		}
	}
}

void GameManager::Win()
{
	TCHAR str[128];
	wsprintf(str, TEXT("지뢰가 모두 찾았습니다.\n기록 : %d초\n타이틀 화면으로 돌아갑니다."), m_iTimer);
	Render();
	if (MessageBox(m_hWnd, str, TEXT("성공"), MB_OK) == IDOK)
	{
		m_bInGame = false;
		KillTimer(m_hWnd, 1);
	}
}

void GameManager::Boom()
{
	TCHAR str[128];
	wsprintf(str, TEXT("지뢰가 터졌습니다.\n타이틀 화면으로 돌아갑니다."), m_iTimer);
	for (int i = 0; i < m_iTotal; i++)
	{
		if (m_BlockManager[i]->IsMine())
			m_BlockManager[i]->Open();
	}
	Render();
	if (MessageBox(m_hWnd, str, TEXT("실패"), MB_OK) == IDOK)
	{
		m_bInGame = false;
		KillTimer(m_hWnd, 1);
	}
}
//
bool GameManager::WinCheck()
{
	for (int i = 0; i < m_iTotal; i++)
	{
		if ((!m_BlockManager[i]->IsMine() && m_BlockManager[i]->IsOpen()) || (m_BlockManager[i]->IsMine() && !m_BlockManager[i]->IsOpen()))
			continue;
		else
			return false;
	}
	return true;
}