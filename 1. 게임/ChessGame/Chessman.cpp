#include "Chessman.h"

Chessman::Chessman()
{}

Chessman::~Chessman()
{
	if (!m_vecMovableList.empty())
		m_vecMovableList.clear();
	SelectObject(m_MemDC, m_pOldBitMap);
	DeleteObject(m_pCurBitMap);
	DeleteDC(m_MemDC);
}

void Chessman::Init(HDC hdc, HINSTANCE hInst, int BitNumber, int x, int y, TEAM team, Board* BoardManager, CHESSMANMODEL_NUMBER model)
{
	m_MemDC = CreateCompatibleDC(hdc); // 메모리 DC 생성
	m_pCurBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(BitNumber));
	m_pOldBitMap = (HBITMAP)SelectObject(m_MemDC, m_pCurBitMap);// old 비트맵 저장
	for (int i = 0; i < 64; i++)
	{
		if (BoardManager->Get_BoardList().at(i)->Pt.x == x && BoardManager->Get_BoardList().at(i)->Pt.y == y)
			m_CurSpace = BoardManager->Get_BoardList().at(i);
	}
	m_CurSpace->IsEmpty = false;
	m_Rect = m_CurSpace->Rt;
	m_bIsSelect = false;
	m_bIsAlive = true;
	m_eTeam = team;
	m_eMyModel = model;
	m_ePromotionModel = NON;
	m_bIsPromotionSelect = false;
}

void Chessman::Die()
{
	m_Rect = { 0, 0, 0, 0 };
	m_bIsAlive = false;
	m_bIsSelect = false;
	m_vecMovableList.clear();
	m_CurSpace = NULL;
	m_ePromotionModel = NON;
	m_bIsPromotionSelect = false;
}

bool Chessman::Compartmentalizing(HWND hWnd, Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam, POINT pt)
{
	if (!m_vecMovableList.empty())
	{
		for (auto i = 0; i < m_vecMovableList.size(); i++)
		{
			if (PtInRect(&m_vecMovableList.at(i)->Rt, pt))
			{
				m_CurSpace->IsEmpty = true;
				m_CurSpace = m_vecMovableList.at(i);
				m_CurSpace->IsEmpty = false;
				for (int i = 0; i < 16; i++)
				{
					if (OpposingTeam[i]->Get_Alive() && Compare_Pt(OpposingTeam[i]->Get_CurPt()))
						OpposingTeam[i]->Die();
				}
				InvalidateRect(hWnd, NULL, FALSE);
				return true;
			}
		}
	}
	return false;
}

bool Chessman::Get_PromotionSelectState()
{
	return m_bIsPromotionSelect;
}

PROMOTIONMODEL Chessman::Get_PromotionModel()
{
	return m_ePromotionModel;
}

void Chessman::Set_SelectState()
{
	m_bIsSelect = true;
}

void Chessman::Release_SelectState()
{
	m_bIsSelect = false;
}

bool Chessman::Get_SelectState()
{
	return m_bIsSelect;
}

bool Chessman::Get_Alive()
{
	return m_bIsAlive;
}

RECT Chessman::Get_Rect()
{
	return m_CurSpace->Rt;
}

TEAM Chessman::Get_Team()
{
	return m_eTeam;
}

POINT Chessman::Get_CurPt()
{
	return m_CurSpace->Pt;
}

CHESSMANMODEL_NUMBER Chessman::Get_MyModel()
{
	return m_eMyModel;
}

bool Chessman::Compare_Pt(POINT pt)
{
	if (m_CurSpace->Pt.x == pt.x && m_CurSpace->Pt.y == pt.y)
		return true;
	else
		return false;
}

void Chessman::Flashing()
{
	if (!m_vecMovableList.empty())
	{
		for (auto i = 0; i < m_vecMovableList.size(); i++)
		{
			if (m_vecMovableList.at(i)->FlashingState)
				m_vecMovableList.at(i)->FlashingState = false;
			else
				m_vecMovableList.at(i)->FlashingState = true;
		}
	}
}

void Chessman::Flashing_Off()
{
	if (!m_vecMovableList.empty())
	{
		for (auto i = 0; i < m_vecMovableList.size(); i++)
		{
			m_vecMovableList.at(i)->FlashingState = false;
		}
	}
}

void Chessman::Draw(HWND hWnd, HDC hdc, POINT pt)
{
	if (!m_bIsSelect && m_bIsAlive)
	{
		SelectObject(m_MemDC, m_pCurBitMap);
		GetObject(m_pCurBitMap, sizeof(BITMAP), &m_BitInfo);
		TransparentBlt(hdc, m_CurSpace->Rt.left, m_CurSpace->Rt.top, 70, 70, m_MemDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, RGB(255, 0, 255));
	}
	else if (m_bIsSelect && m_bIsAlive)
	{
		m_Rect = { pt.x - 35, pt.y - 35, pt.x + 35, pt.y + 35 };
		SelectObject(m_MemDC, m_pCurBitMap);
		GetObject(m_pCurBitMap, sizeof(BITMAP), &m_BitInfo);
		TransparentBlt(hdc, m_Rect.left, m_Rect.top, 70, 70, m_MemDC, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, RGB(255, 0, 255));
	}
}

void Pawn::Promotion_Select(HWND hWnd)
{
	if ((Get_Team() == WHITE && m_CurSpace->Pt.y == 0) || (Get_Team() == BLACK && m_CurSpace->Pt.y == 7))
	{
		while (1)
		{
			if (MessageBox(hWnd, TEXT("Queen으로 승급하시겠습니까?"), TEXT("Promotion"), MB_YESNO) == IDYES)
				m_ePromotionModel = PROMOTION_QUEEN;
			else if (MessageBox(hWnd, TEXT("Bishop으로 승급하시겠습니까?"), TEXT("Promotion"), MB_YESNO) == IDYES)
				m_ePromotionModel = PROMOTION_BISHOP;
			else if (MessageBox(hWnd, TEXT("Knight으로 승급하시겠습니까?"), TEXT("Promotion"), MB_YESNO) == IDYES)
				m_ePromotionModel = PROMOTION_KNIGHT;
			else if (MessageBox(hWnd, TEXT("Rook으로 승급하시겠습니까?"), TEXT("Promotion"), MB_YESNO) == IDYES)
				m_ePromotionModel = PROMOTION_ROOK;
			if (m_ePromotionModel != NON)
				break;
		}
		m_bIsPromotionSelect = true;
	}
}

void Pawn::Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam)
{ // 말을 선택하기 전 보드에 있는 말들의 이동가능 칸을 미리 계산해서 벡터에 넣어둔다.
	if (!m_bIsAlive)
		return;
	int Direction, First_y;
	bool Continue = true;
	m_vecMovableList.clear();
	if (Get_Team() == WHITE)
	{
		Direction = -1;
		First_y = 6;
	}
	else
	{
		Direction = 1;
		First_y = 1;
	}
	for (int Distanse = 1; Distanse <= 2; Distanse++)
	{
		Distanse *= Direction;
		for (int i = 0; i < 64; i++)
		{
			if (abs(Distanse) == 1 && boardmanager->Get_BoardList().at(i)->Pt.y == (m_CurSpace->Pt.y + Distanse) && (boardmanager->Get_BoardList().at(i)->Pt.x == m_CurSpace->Pt.x - 1 || boardmanager->Get_BoardList().at(i)->Pt.x == m_CurSpace->Pt.x + 1))
			{
				if (!boardmanager->Get_BoardList().at(i)->IsEmpty)
				{
					for (int j = 0; j < 16; j++)
					{
						if (OpposingTeam[j]->Get_Alive() && OpposingTeam[j]->Compare_Pt(boardmanager->Get_BoardList().at(i)->Pt))
							m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
					}
				}
			}
			if (Continue && boardmanager->Get_BoardList().at(i)->Pt.x == m_CurSpace->Pt.x && boardmanager->Get_BoardList().at(i)->Pt.y == (m_CurSpace->Pt.y + Distanse))
			{
				if (!boardmanager->Get_BoardList().at(i)->IsEmpty)
				{
					Continue = false;
					continue;
				}
				else
					m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
			}
		}
		Distanse *= Direction;
		if (m_CurSpace->Pt.y != First_y)
			return;
	}
}

void King::Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam)
{
	if (!m_bIsAlive)
		return;
	m_vecMovableList.clear();
	for (int x = m_CurSpace->Pt.x - 1; x <= m_CurSpace->Pt.x + 1; x++)
	{
		for (int y = m_CurSpace->Pt.y - 1; y <= m_CurSpace->Pt.y + 1; y++)
		{
			if (x < 0 || x > 7 || y < 0 || y > 7 || (x == m_CurSpace->Pt.x && y == m_CurSpace->Pt.y))
				continue;
			for (int i = 0; i < 64; i++)
			{
				if (x == boardmanager->Get_BoardList().at(i)->Pt.x && y == boardmanager->Get_BoardList().at(i)->Pt.y)
				{
					if (!boardmanager->Get_BoardList().at(i)->IsEmpty)
					{
						for (int j = 0; j < 16; j++)
						{
							if (OpposingTeam[j]->Get_Alive() && OpposingTeam[j]->Compare_Pt(boardmanager->Get_BoardList().at(i)->Pt))
								m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
						}
					}
					else
						m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
				}
			}
		}
	}
}

void Queen::Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam)
{
	if (!m_bIsAlive)
		return;
	int CheckStep = 1, _x = -1, _y = 0, increase_x = -1, increase_y = 0;
	bool Continue;
	m_vecMovableList.clear();
	while (1)
	{
		Continue = true;
		for (int i = 0; i < 64; i++)
		{
			if (m_CurSpace->Pt.x + _x == boardmanager->Get_BoardList().at(i)->Pt.x && m_CurSpace->Pt.y + _y == boardmanager->Get_BoardList().at(i)->Pt.y)
			{
				if (!boardmanager->Get_BoardList().at(i)->IsEmpty)
				{
					for (int j = 0; j < 16; j++)
					{
						if (OpposingTeam[j]->Get_Alive() && OpposingTeam[j]->Compare_Pt(boardmanager->Get_BoardList().at(i)->Pt))
						{
							m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
							break;
						}
					}
					Continue = false;
				}
				else
					m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
				break;
			}
		}
		_x += increase_x;
		_y += increase_y;
		if (!Continue || abs(_x) > 7 || abs(_y) > 7)
			Check_Step(CheckStep, _x, _y, increase_x, increase_y);
		if (CheckStep > 8)
			break;
	}
}

void Bishop::Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam)
{
	if (!m_bIsAlive)
		return;
	int CheckStep = 1, _x = -1, _y = -1, increase_x = -1, increase_y = -1;
	bool Continue;
	m_vecMovableList.clear();
	while (1)
	{
		Continue = true;
		for (int i = 0; i < 64; i++)
		{
			if (m_CurSpace->Pt.x + _x == boardmanager->Get_BoardList().at(i)->Pt.x && m_CurSpace->Pt.y + _y == boardmanager->Get_BoardList().at(i)->Pt.y)
			{
				if (!boardmanager->Get_BoardList().at(i)->IsEmpty)
				{
					for (int j = 0; j < 16; j++)
					{
						if (OpposingTeam[j]->Get_Alive() && OpposingTeam[j]->Compare_Pt(boardmanager->Get_BoardList().at(i)->Pt))
						{
							m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
							break;
						}
					}
					Continue = false;
				}
				else
					m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
				break;
			}
		}
		_x += increase_x;
		_y += increase_y;
		if (!Continue || abs(_x) > 7 || abs(_y) > 7)
			Check_Step(CheckStep, _x, _y, increase_x, increase_y);
		if (CheckStep > 4)
			break;
	}
}

void Knight::Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam)
{
	if (!m_bIsAlive)
		return;
	int CheckStep = 1, _x = -2, _y = -1, increase_x = 0, increase_y = 2;
	m_vecMovableList.clear();
	while (1)
	{
		for (int i = 0; i < 64; i++)
		{
			if (m_CurSpace->Pt.x + _x == boardmanager->Get_BoardList().at(i)->Pt.x && m_CurSpace->Pt.y + _y == boardmanager->Get_BoardList().at(i)->Pt.y)
			{
				if (!boardmanager->Get_BoardList().at(i)->IsEmpty)
				{
					for (int j = 0; j < 16; j++)
					{
						if (OpposingTeam[j]->Get_Alive() && OpposingTeam[j]->Compare_Pt(boardmanager->Get_BoardList().at(i)->Pt))
						{
							m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
							break;
						}
					}
				}
				else
					m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
				break;
			}
		}
		_x += increase_x;
		_y += increase_y;
		if (abs(_x) >= 3 || abs(_y) >= 3)
			Check_Step(CheckStep, _x, _y, increase_x, increase_y);
		if (CheckStep > 4)
			break;
	}
}

void Rook::Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam)
{
	if (!m_bIsAlive)
		return;
	int CheckStep = 1, _x = -1, _y = 0, increase_x = -1, increase_y = 0;
	bool Continue;
	m_vecMovableList.clear();
	while (1)
	{
		Continue = true;
		for (int i = 0; i < 64; i++)
		{
			if (m_CurSpace->Pt.x + _x == boardmanager->Get_BoardList().at(i)->Pt.x && m_CurSpace->Pt.y + _y == boardmanager->Get_BoardList().at(i)->Pt.y)
			{
				if (!boardmanager->Get_BoardList().at(i)->IsEmpty)
				{
					for (int j = 0; j < 16; j++)
					{
						if (OpposingTeam[j]->Get_Alive() && OpposingTeam[j]->Compare_Pt(boardmanager->Get_BoardList().at(i)->Pt))
						{
							m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
							break;
						}
					}
					Continue = false;
				}
				else
					m_vecMovableList.push_back(boardmanager->Get_BoardList().at(i));
				break;
			}
		}
		_x += increase_x;
		_y += increase_y;
		if (!Continue || abs(_x) > 7 || abs(_y) > 7)
			Check_Step(CheckStep, _x, _y, increase_x, increase_y);
		if (CheckStep > 4)
			break;
	}
}

void Queen::Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y)
{
	step++;
	switch (step)
	{
	case 2:
		_x = 1;
		_y = 0;
		increase_x = 1;
		increase_y = 0;
		break;
	case 3:
		_x = 0;
		_y = -1;
		increase_x = 0;
		increase_y = -1;
		break;
	case 4:
		_x = 0;
		_y = 1;
		increase_x = 0;
		increase_y = 1;
		break;
	case 5:
		_x = -1;
		_y = -1;
		increase_x = -1;
		increase_y = -1;
		break;
	case 6:
		_x = 1;
		_y = -1;
		increase_x = 1;
		increase_y = -1;
		break;
	case 7:
		_x = -1;
		_y = 1;
		increase_x = -1;
		increase_y = 1;
		break;
	case 8:
		_x = 1;
		_y = 1;
		increase_x = 1;
		increase_y = 1;
		break;
	}
	return;
}

void Knight::Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y)
{
	step++;
	switch (step)
	{
	case 2:
		_x = -1;
		_y = -2;
		increase_x = 2;
		increase_y = 0;
		break;
	case 3:
		_x = 2;
		_y = -1;
		increase_x = 0;
		increase_y = 2;
		break;
	case 4:
		_x = -1;
		_y = 2;
		increase_x = 2;
		increase_y = 0;
		break;
	}
	return;
}

void Bishop::Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y)
{
	step++;
	switch (step)
	{
	case 2:
		_x = 1;
		_y = -1;
		increase_x = 1;
		increase_y = -1;
		break;
	case 3:
		_x = -1;
		_y = 1;
		increase_x = -1;
		increase_y = 1;
		break;
	case 4:
		_x = 1;
		_y = 1;
		increase_x = 1;
		increase_y = 1;
		break;
	}
	return;
}

void Rook::Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y)
{
	step++;
	switch (step)
	{
	case 2:
		_x = 1;
		_y = 0;
		increase_x = 1;
		increase_y = 0;
		break;
	case 3:
		_x = 0;
		_y = -1;
		increase_x = 0;
		increase_y = -1;
		break;
	case 4:
		_x = 0;
		_y = 1;
		increase_x = 0;
		increase_y = 1;
		break;
	}
	return;
}