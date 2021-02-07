#pragma once
#include "Item.h"

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

class Manager : public Singleton<Manager> //싱글턴
{
private:
	HWND m_hWnd;
	HWND m_DlghWnd;
	HWND m_DlgButton[5];
	HINSTANCE m_hInst;
	//
	HDC m_MainDC;
	HDC m_BufferDC;
	HDC m_BackDC;
	HDC m_DlgDC;
	//
	BITMAP m_BmpInfo;
	HBITMAP m_TitleBmp;
	HBITMAP m_BackBmp;
	HBITMAP m_StateBmp;
	HBITMAP m_PlayerIconBmp;
	HBITMAP m_EnemyIconBmp;
	HBITMAP m_OldBackBmp;
	HBITMAP m_BufferBmp;
	HBITMAP m_OldBmp;
	//
	HFONT m_Font;
	HFONT m_SmallFont;
	HFONT m_BigFont;
	HFONT m_OldFont;
	//
	Player* m_Player;
	list<Block*> m_vecBlockList;
	list<Enemy*> m_vecEnemyList;
	list<Item*> m_vecItemList;
	//
	PAINTSTRUCT m_DlgPS;
	// 
	STAGE m_eStage;
	GAME_STATE m_eGameState;
	//
	int m_eMaxEnemy; //스테이지당 최대 적군 수
	int m_eLiveEnemy; //살아있는 적군 수
	int m_iAppearanceEnemy; //출현한 적군 수
	int m_iKillCount;
	int m_iPlayerLife;
	int m_iDlgWidth;
	int m_iDlgHeight;
	int m_iDlgMap[13][15]; //맵툴 칸
	int m_iCurSelect; //선택된 오브젝트
	// 
	DWORD m_dwLastFrame; //프레임 관리
	DWORD m_dwCurFrame;
	float m_fFrame;
public:
	Manager();
	~Manager();
	void Init(HWND hWnd, HINSTANCE hInstance);
	void Player_Update();
	void Game_Set();
	void State_Render();
	void InGame_Render();
	void Enemy_Update();
	void InGame();
	void Win_Check();
	void Loading();
	void GameEnd();
	void GameLoop();
	void Release();
	void Render();
	GAME_STATE GameState();
	void InitDLG(HWND hWnd);
	void CommandDLG(WPARAM wParam);
	void PaintDLG();
	void ButtonDownDLG(POINT pt);
};