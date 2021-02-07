#pragma once
#include "Board.h"

class Chessman
{
private: // 초기화 후 수정 x
	HDC m_MemDC;
	HBITMAP m_pOldBitMap;
	HBITMAP m_pCurBitMap;
	BITMAP m_BitInfo; // 참조구조체
	TEAM m_eTeam;
	CHESSMANMODEL_NUMBER m_eMyModel;
protected: // 초기화 후 수정 o
	RECT m_Rect; // 체스말 마우스 영역
	vector<BOARDPART*> m_vecMovableList; // 이동할 수 있는 보드 칸
	BOARDPART* m_CurSpace; //현재 보드 칸
	PROMOTIONMODEL m_ePromotionModel;
	bool m_bIsPromotionSelect;
	bool m_bIsSelect; // 선택 변수
	bool m_bIsAlive; // 생존 변수
public:
	Chessman();
	~Chessman();
	void Init(HDC hdc, HINSTANCE hInst, int BitNumber, int x, int y, TEAM team, Board* BoardManager, CHESSMANMODEL_NUMBER model);
	void Draw(HWND hWnd, HDC hdc, POINT pt);
	void Die();
	void Set_SelectState();
	void Release_SelectState();
	void Flashing();
	void Flashing_Off();
	bool Compare_Pt(POINT pt);
	bool Compartmentalizing(HWND hWnd, Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam, POINT pt);
	bool Get_SelectState();
	bool Get_Alive();
	bool Get_PromotionSelectState();
	RECT Get_Rect();
	TEAM Get_Team();
	POINT Get_CurPt();
	PROMOTIONMODEL Get_PromotionModel();
	CHESSMANMODEL_NUMBER Get_MyModel();
	virtual void Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam) = 0;
	virtual void Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y) = 0;
	virtual void Promotion_Select(HWND hWnd) = 0;
};

class King : public Chessman
{
public:
	void Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y) {};
	void Promotion_Select(HWND hWnd) {};
	void Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam) override;
};

class Queen : public Chessman
{
public:
	void Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y) override;
	void Promotion_Select(HWND hWnd) {};
	void Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam) override;
};

class Rook : public Chessman
{
public:
	void Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y) override;
	void Promotion_Select(HWND hWnd) {};
	void Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam) override;
};

class Bishop : public Chessman
{
public:
	void Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y) override;
	void Promotion_Select(HWND hWnd) {};
	void Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam) override;
};

class Knight : public Chessman
{
public:
	void Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y) override;
	void Promotion_Select(HWND hWnd) {};
	void Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam) override;
};

class Pawn : public Chessman
{
public:
	void Check_Step(int& step, int& _x, int& _y, int& increase_x, int& increase_y) {};
	void Promotion_Select(HWND hWnd) override;
	void Move_Check(Board* boardmanager, Chessman** OurTeam, Chessman** OpposingTeam) override;
};