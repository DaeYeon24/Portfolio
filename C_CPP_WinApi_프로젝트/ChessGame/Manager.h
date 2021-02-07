#pragma once
#include "ChessmanFactory.h"

template <typename T>
class Singleton
{
private:
	static T* m_pThis;
protected:
	Singleton() {};
	virtual ~Singleton() {};
	Singleton(const T& other) {};
public:
	static T* Get_Instance()
	{
		if (m_pThis == NULL)
			m_pThis = new T;
		return m_pThis;
	}
	static void Destroy_Instance()
	{
		if (m_pThis != NULL)
			delete m_pThis;
	}
};
template <typename T>
T* Singleton<T>::m_pThis = NULL;

class Manager : public Singleton<Manager>
{
private:
	HDC m_MainDC; // 매니저 메인 핸들
	HDC m_BackDC; // 매니저 백 핸들 (더블버퍼링) (BackDC 하위는 각 클래스의 MemDC)
	HBITMAP m_pTitleBitMap; // 타이틀비트맵
	HBITMAP m_pStartBitMap; // 시작버튼
	HBITMAP m_pExitBitMap; // 종료버튼
	HBITMAP m_pCurBitMap; //메인화면
	HBITMAP m_pOldBitMap;
	HBITMAP m_pBackGroundBitMap; //뒤에서 그려질 화면
	HBITMAP m_pOldGroundBitMap;
	Board* m_BoardManager; //보드판
	ChessmanFactory* m_ChessmanFactory[TOTAL]; //체스말 생성 팩토리
	Chessman** m_ChessmanList_Black; //백팀
	Chessman** m_ChessmanList_White; //흑팀
	Chessman* m_SelectedChessman; // 선택 말
	BITMAP m_BitInfo;
	bool m_bInGame; //인게임 변수
	TEAM m_eTurnOwner; // 해당 턴의 팀
	TCHAR m_str[256]; // 코멘트
public:
	Manager();
	~Manager();
	void Init(HWND hWnd, HDC hdc, HINSTANCE hInst);
	void DefaultSetting(HWND hWnd, HINSTANCE hInst);
	void Title_Draw(HWND hWnd, HDC hdc);
	void Draw(HWND hWnd, HDC hdc, POINT pt);
	void Select_Title(HWND hWnd, HDC hdc, POINT pt, bool& Game_State);
	bool Select_Chessman(HWND hWnd, HDC hdc, POINT pt);
	bool Free_Chessman(HWND hWnd, HINSTANCE hInst, POINT pt, bool& Game_State);
	void Promotion(HDC hdc, HINSTANCE hInst);
	void Chessman_MoveCheck();
	void Flashing();
	void Release();
	bool WinCheck(HWND hWnd);
	void GameReSet(HWND hWnd, HINSTANCE hInst);
};

