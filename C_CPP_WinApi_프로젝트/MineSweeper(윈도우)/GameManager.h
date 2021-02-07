#pragma once
#include "Block.h"

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

class GameManager : public Singleton<GameManager>
{
private:
	HWND m_hWnd;
	HDC m_MainDC;
	BITMAP m_BitInfo;
	//
	HDC m_BackDC;
	HBITMAP m_BackBitMap;
	HBITMAP m_OldBitMap;
	HFONT m_MyFont;
	HFONT m_OldFont;
	//
	HDC m_BackGroundDC;
	HBITMAP m_BackGroundBitMap;
	HBITMAP m_OldBackGroundBitMap;
	//
	HBITMAP m_ScreenBitMap;
	HBITMAP m_TitleBitMap;
	HBITMAP m_StartBitMap;
	HBITMAP m_ExitBitMap;
	//
	Block** m_BlockManager; // 블럭
	GAME_STATE m_eGameState;
	bool m_bInGame;
	int m_iRow; // 가로
	int m_iCol; // 세로
	int m_iTotal; // 블럭개수
	int m_iMineCount; // 지뢰 수
	int m_iTimer;
public:
	GameManager();
	~GameManager();
	void Init(HWND hWnd);
	void Game_Set();
	void Time_Counting();
	void GameLoop();
	void Release();
	void Render();
	void Title();
	void Change_Stage(STAGE stage);
	void InGame();
	bool WinCheck();
	void Boom();
	void Win();
	void Cursor_Interaction(CURSER_INTERACTION interaction, POINT mousepoint);
};

