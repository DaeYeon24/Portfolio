#include "Manager.h"

Manager::Manager()
{
	m_BoardManager = new Board;
	m_ChessmanList_Black = new Chessman * [16];
	m_ChessmanList_White = new Chessman * [16];
	m_ChessmanFactory[ROOK] = new RookFactory;
	m_ChessmanFactory[KNIGHT] = new KnightFactory;
	m_ChessmanFactory[BISHOP] = new BishopFactory;
	m_ChessmanFactory[QUEEN] = new QueenFactory;
	m_ChessmanFactory[KING] = new KingFactory;
	m_ChessmanFactory[PAWN] = new PawnFactory;
	m_SelectedChessman = NULL;
	m_bInGame = false;
	m_eTurnOwner = WHITE;
}

Manager::~Manager()
{
	if (m_BoardManager)
		delete m_BoardManager;
	if (m_ChessmanList_Black)
	{
		for (int i = 0; i < 16; i++)
		{
			if(m_ChessmanList_Black[i])
				delete m_ChessmanList_Black[i];
		}
		delete m_ChessmanList_Black;
	}
	if (m_ChessmanList_White)
	{
		for (int i = 0; i < 16; i++)
		{
			if(m_ChessmanList_White[i])
				delete m_ChessmanList_White[i];
		}
		delete m_ChessmanList_White;
	}
	if (m_ChessmanFactory)
	{
		for (int i = 0; i < TOTAL; i++)
		{
			if(m_ChessmanFactory[i])
				delete m_ChessmanFactory[i];
		}
	}
	SelectObject(m_BackDC, m_pOldGroundBitMap);
	SelectObject(m_MainDC, m_pOldBitMap);
	DeleteObject(m_pBackGroundBitMap);
	DeleteObject(m_pCurBitMap);
	DeleteObject(m_pTitleBitMap);
	DeleteObject(m_pStartBitMap);
	DeleteObject(m_pExitBitMap);
	DeleteDC(m_BackDC);
	DeleteDC(m_MainDC);
}

void Manager::Init(HWND hWnd, HDC hdc, HINSTANCE hInst)
{
	m_MainDC = CreateCompatibleDC(hdc);
	m_BackDC = CreateCompatibleDC(m_MainDC);
	m_pCurBitMap = CreateCompatibleBitmap(hdc, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	m_pBackGroundBitMap = CreateCompatibleBitmap(m_MainDC, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	m_pOldBitMap = (HBITMAP)SelectObject(m_MainDC, m_pCurBitMap);
	m_pOldGroundBitMap = (HBITMAP)SelectObject(m_BackDC, m_pBackGroundBitMap);
	m_pTitleBitMap = (HBITMAP)LoadImage(NULL, TEXT("Title.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_pStartBitMap = (HBITMAP)LoadImage(NULL, TEXT("Start.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_pExitBitMap = (HBITMAP)LoadImage(NULL, TEXT("Exit.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	DefaultSetting(hWnd, hInst);
}

void Manager::GameReSet(HWND hWnd, HINSTANCE hInst)
{
	SelectObject(m_MainDC, m_pCurBitMap);
	SelectObject(m_BackDC, m_pBackGroundBitMap);
	if (m_BoardManager)
		delete m_BoardManager;
	m_BoardManager = NULL;
	m_BoardManager = new Board;
	if (m_ChessmanList_Black)
	{
		for (int i = 0; i < 16; i++)
		{
			if(m_ChessmanList_Black[i])
				delete m_ChessmanList_Black[i];
			m_ChessmanList_Black[i] = NULL;
		}
		delete m_ChessmanList_Black;
	}
	m_ChessmanList_Black = NULL;
	m_ChessmanList_Black = new Chessman * [16];
	if (m_ChessmanList_White)
	{
		for (int i = 0; i < 16; i++)
		{
			if(m_ChessmanList_White[i])
				delete m_ChessmanList_White[i];
			m_ChessmanList_White[i] = NULL;
		}
		delete m_ChessmanList_White;
	}
	m_ChessmanList_White = NULL;
	m_ChessmanList_White = new Chessman * [16];
	m_SelectedChessman = NULL;
	m_bInGame = false;
	m_eTurnOwner = WHITE;
	DefaultSetting(hWnd, hInst);
}

void Manager::DefaultSetting(HWND hWnd, HINSTANCE hInst)
{
	m_BoardManager->Init(m_MainDC, hInst);
	for (int i = 0, x = 0; i < 16; i++)
	{
		if (i == 0 || i == 7)
		{
			m_ChessmanList_Black[i] = m_ChessmanFactory[ROOK]->Create_Chessman();
			m_ChessmanList_Black[i]->Init(m_MainDC, hInst, 104, i, 0, BLACK, m_BoardManager, ROOK);
			m_ChessmanList_White[i] = m_ChessmanFactory[ROOK]->Create_Chessman();
			m_ChessmanList_White[i]->Init(m_MainDC, hInst, 110, i, 7, WHITE, m_BoardManager, ROOK);
		}
		else if (i == 1 || i == 6)
		{
			m_ChessmanList_Black[i] = m_ChessmanFactory[KNIGHT]->Create_Chessman();
			m_ChessmanList_Black[i]->Init(m_MainDC, hInst, 102, i, 0, BLACK, m_BoardManager, KNIGHT);
			m_ChessmanList_White[i] = m_ChessmanFactory[KNIGHT]->Create_Chessman();
			m_ChessmanList_White[i]->Init(m_MainDC, hInst, 108, i, 7, WHITE, m_BoardManager, KNIGHT);
		}
		else if (i == 2 || i == 5)
		{
			m_ChessmanList_Black[i] = m_ChessmanFactory[BISHOP]->Create_Chessman();
			m_ChessmanList_Black[i]->Init(m_MainDC, hInst, 103, i, 0, BLACK, m_BoardManager, BISHOP);
			m_ChessmanList_White[i] = m_ChessmanFactory[BISHOP]->Create_Chessman();
			m_ChessmanList_White[i]->Init(m_MainDC, hInst, 109, i, 7, WHITE, m_BoardManager, BISHOP);
		}
		else if (i == 3)
		{
			m_ChessmanList_Black[i] = m_ChessmanFactory[QUEEN]->Create_Chessman();
			m_ChessmanList_Black[i]->Init(m_MainDC, hInst, 105, i, 0, BLACK, m_BoardManager, QUEEN);
			m_ChessmanList_White[i] = m_ChessmanFactory[QUEEN]->Create_Chessman();
			m_ChessmanList_White[i]->Init(m_MainDC, hInst, 111, i, 7, WHITE, m_BoardManager, QUEEN);
		}
		else if (i == 4)
		{
			m_ChessmanList_Black[i] = m_ChessmanFactory[KING]->Create_Chessman();
			m_ChessmanList_Black[i]->Init(m_MainDC, hInst, 106, i, 0, BLACK, m_BoardManager, KING);
			m_ChessmanList_White[i] = m_ChessmanFactory[KING]->Create_Chessman();
			m_ChessmanList_White[i]->Init(m_MainDC, hInst, 112, i, 7, WHITE, m_BoardManager, KING);
		}
		else
		{
			m_ChessmanList_Black[i] = m_ChessmanFactory[PAWN]->Create_Chessman();
			m_ChessmanList_Black[i]->Init(m_MainDC, hInst, 101, x, 1, BLACK, m_BoardManager, PAWN);
			m_ChessmanList_White[i] = m_ChessmanFactory[PAWN]->Create_Chessman();
			m_ChessmanList_White[i]->Init(m_MainDC, hInst, 107, x, 6, WHITE, m_BoardManager, PAWN);
			x++;
		}
	}
	wsprintf(m_str, TEXT("백팀 차례입니다."));
	Chessman_MoveCheck();
}

void Manager::Title_Draw(HWND hWnd, HDC hdc)
{
	SelectObject(m_MainDC, m_pTitleBitMap);
	GetObject(m_pTitleBitMap, sizeof(BITMAP), &m_BitInfo);
	StretchBlt(hdc, 310, 100, 300, 100, m_MainDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
	SelectObject(m_MainDC, m_pStartBitMap);
	GetObject(m_pStartBitMap, sizeof(BITMAP), &m_BitInfo);
	StretchBlt(hdc, 100, 300, 300, 150, m_MainDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
	SelectObject(m_MainDC, m_pExitBitMap);
	GetObject(m_pExitBitMap, sizeof(BITMAP), &m_BitInfo);
	StretchBlt(hdc, 500, 300, 300, 150, m_MainDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
}

void Manager::Select_Title(HWND hWnd, HDC hdc, POINT pt, bool& Game_State)
{
	RECT StartButton = { 100, 300, 400, 450 };
	RECT ExitButton = { 500, 300, 800, 450 };
	if (PtInRect(&StartButton, pt))
	{
		Game_State = true;
		m_bInGame = true;
		SelectObject(m_MainDC, m_pCurBitMap);
		InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (PtInRect(&ExitButton, pt))
	{
		Release();
		PostQuitMessage(0);
	}
}

void Manager::Chessman_MoveCheck()
{
	for (int i = 0; i < 16; i++)
	{
		m_ChessmanList_Black[i]->Move_Check(m_BoardManager, m_ChessmanList_Black, m_ChessmanList_White);
		m_ChessmanList_White[i]->Move_Check(m_BoardManager, m_ChessmanList_White, m_ChessmanList_Black);
	}
}

bool Manager::WinCheck(HWND hWnd)
{
	if (!m_ChessmanList_Black[KING]->Get_Alive() || !m_ChessmanList_White[KING]->Get_Alive())
	{
		if (!m_ChessmanList_Black[KING]->Get_Alive())
			wsprintf(m_str, TEXT("백팀이 이겼습니다!!"));
		else if (!m_ChessmanList_White[KING]->Get_Alive())
			wsprintf(m_str, TEXT("흑팀이 이겼습니다!!"));
		if(MessageBox(hWnd, m_str, TEXT("Game Set"), MB_OK) == IDOK);
		{
			InvalidateRect(hWnd, NULL, TRUE);
			return true;
		}
	}
	return false;
}

bool Manager::Free_Chessman(HWND hWnd, HINSTANCE hInst, POINT pt, bool& Game_State)
{
	bool MoveSuccessful;
	if (m_SelectedChessman)
	{
		m_SelectedChessman->Flashing_Off();
		KillTimer(hWnd, 1);
		m_SelectedChessman->Release_SelectState();
		switch (m_eTurnOwner)
		{
		case WHITE:
			MoveSuccessful = m_SelectedChessman->Compartmentalizing(hWnd, m_BoardManager, m_ChessmanList_White, m_ChessmanList_Black, pt);
			break;
		case BLACK:
			MoveSuccessful = m_SelectedChessman->Compartmentalizing(hWnd, m_BoardManager, m_ChessmanList_Black, m_ChessmanList_White, pt);
			break;
		}
		if (MoveSuccessful)
		{
			if (!WinCheck(hWnd))
			{
				m_SelectedChessman->Promotion_Select(hWnd);
				if (m_eTurnOwner == BLACK)
				{
					m_eTurnOwner = WHITE;
					wsprintf(m_str, TEXT("백팀 차례입니다."));
				}
				else
				{
					m_eTurnOwner = BLACK;
					wsprintf(m_str, TEXT("흑팀 차례입니다."));
				}
			}
			else
			{
				GameReSet(hWnd, hInst);
				Game_State = false;
			}
		}
		else
			wsprintf(m_str, TEXT("이동할 수 없습니다."));
		m_SelectedChessman = NULL;
		return false;
	}
}

void Manager::Promotion(HDC hdc, HINSTANCE hInst)
{
	Chessman** PromotionOwner;
	TEAM PromotionTeam;
	int PromotionBitNumber;
	Chessman* tmp;
	if (m_eTurnOwner == BLACK)
	{
		PromotionOwner = m_ChessmanList_White;
		PromotionTeam = WHITE;
		PromotionBitNumber = 108;
	}
	else
	{
		PromotionOwner = m_ChessmanList_Black;
		PromotionTeam = BLACK;
		PromotionBitNumber = 102;
	}
	for (int i = 0; i < 16; i++)
	{
		if (PromotionOwner[i]->Get_MyModel() == PAWN && PromotionOwner[i]->Get_PromotionSelectState())
		{
			switch (PromotionOwner[i]->Get_PromotionModel())
			{
			case PROMOTION_KNIGHT:
				tmp = m_ChessmanFactory[KNIGHT]->Create_Chessman();
				tmp->Init(hdc, hInst, PromotionBitNumber, PromotionOwner[i]->Get_CurPt().x, PromotionOwner[i]->Get_CurPt().y, PromotionTeam, m_BoardManager, KNIGHT);
				wsprintf(m_str, TEXT("Pawn이 Knight로 승진하였습니다!"));
				break;
			case PROMOTION_BISHOP:
				tmp = m_ChessmanFactory[BISHOP]->Create_Chessman();
				tmp->Init(hdc, hInst, PromotionBitNumber + 1, PromotionOwner[i]->Get_CurPt().x, PromotionOwner[i]->Get_CurPt().y, PromotionTeam, m_BoardManager, BISHOP);
				wsprintf(m_str, TEXT("Pawn이 Bishop로 승진하였습니다!"));
				break;
			case PROMOTION_ROOK:
				tmp = m_ChessmanFactory[ROOK]->Create_Chessman();
				tmp->Init(hdc, hInst, PromotionBitNumber + 2, PromotionOwner[i]->Get_CurPt().x, PromotionOwner[i]->Get_CurPt().y, PromotionTeam, m_BoardManager, ROOK);
				wsprintf(m_str, TEXT("Pawn이 Rook로 승진하였습니다!"));
				break;
			case PROMOTION_QUEEN:
				tmp = m_ChessmanFactory[QUEEN]->Create_Chessman();
				tmp->Init(hdc, hInst, PromotionBitNumber + 3, PromotionOwner[i]->Get_CurPt().x, PromotionOwner[i]->Get_CurPt().y, PromotionTeam, m_BoardManager, QUEEN);
				wsprintf(m_str, TEXT("Pawn이 Queen로 승진하였습니다!"));
				break;
			}
			delete PromotionOwner[i];
			PromotionOwner[i] = NULL;
			PromotionOwner[i] = tmp;
		}
	}
}

void Manager::Flashing()
{
	if (m_SelectedChessman)
		m_SelectedChessman->Flashing();
}

bool Manager::Select_Chessman(HWND hWnd, HDC hdc, POINT pt)
{
	Chessman** TurnOwner;
	if (!m_SelectedChessman)
	{
		if (m_eTurnOwner == BLACK)
			TurnOwner = m_ChessmanList_Black;
		else
			TurnOwner = m_ChessmanList_White;
		for (int i = 0; i < 16; i++)
		{
			if (TurnOwner[i]->Get_Alive())
			{
				if (PtInRect(&TurnOwner[i]->Get_Rect(), pt))
				{
					if (!TurnOwner[i]->Get_SelectState())
					{
						m_SelectedChessman = TurnOwner[i];
						m_SelectedChessman->Set_SelectState();
						SetTimer(hWnd, 1, 500, NULL);
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Manager::Draw(HWND hWnd, HDC hdc, POINT pt)
{

	if (!m_bInGame)
		Title_Draw(hWnd, hdc);
	else
	{
		BitBlt(m_MainDC, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), m_BackDC, 0, 0, WHITENESS);
		SelectObject(m_BackDC, m_pTitleBitMap);
		GetObject(m_pTitleBitMap, sizeof(BITMAP), &m_BitInfo);
		StretchBlt(m_MainDC, 310, 30, 300, 80, m_BackDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, SRCCOPY);
		SetTextAlign(m_MainDC, TA_CENTER);
		//폰트변경
		HFONT myFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "고딕");
		HFONT oldFont = (HFONT)SelectObject(m_MainDC, myFont);
		SetTextColor(m_MainDC, RGB(255, 0, 0));
		TextOut(m_MainDC, 450, 800, m_str, lstrlen(m_str));
		SelectObject(m_MainDC, oldFont);
		DeleteObject(myFont);
		//폰트변경끝
		m_BoardManager->Draw(hWnd, m_MainDC);
		for (int i = 0; i < 16; i++)
		{
			if (!m_ChessmanList_Black[i]->Get_SelectState())
				m_ChessmanList_Black[i]->Draw(hWnd, m_MainDC, pt);
			if (!m_ChessmanList_White[i]->Get_SelectState())
				m_ChessmanList_White[i]->Draw(hWnd, m_MainDC, pt);
		}
		if (m_SelectedChessman)
			m_SelectedChessman->Draw(hWnd, m_MainDC, pt);
		BitBlt(hdc, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), m_MainDC, 0, 0, SRCCOPY);
	}
}

void Manager::Release()
{
	Destroy_Instance();
}