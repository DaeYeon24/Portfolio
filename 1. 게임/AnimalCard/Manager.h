#pragma once
#include "BitMap.h"
#include "Singleton.h"

class Manager : public Singleton<Manager>
{
private:
	BitMap* m_Bitmap;
	bool m_bInGame;
public:
	Manager();
	~Manager();
	void Init(HWND hWnd, HDC hdc, HINSTANCE hInst);
	void Play(HWND hWnd, HDC hdc);
	void Click_Button(HWND hWnd, HDC hdc, int x, int y);
	void Time_Counting();
	void Release();
};

