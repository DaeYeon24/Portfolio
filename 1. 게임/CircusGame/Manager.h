#pragma once
#include "Character.h"

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
	HWND m_hWnd;
	HDC m_MainDC;
	BITMAP m_BitMap_Info;
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
	HBITMAP m_TitleBitMap;
	HBITMAP m_CursorBitMap;
	//
	Stage* m_Stage;
	Character* m_Character;
	bool m_bInGame;
	//타임체크용
	DWORD		m_dwLastFrame;
	DWORD		m_dwCurFrame;
	float		m_fOneFrame;
public:
	Manager();
	~Manager();
	void Init(HWND hWnd);
	void GameLoop();
	void MenuSelectCursor(int MenuLen, int AddCol);
	void InGame();
	void Title();
	void Render();
	void Release();
	void Game_Set();
};