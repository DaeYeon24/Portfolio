#pragma once
#include <Windows.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>
#include "resource.h"
using namespace std;

#define UNSELECTED -1
#define INCORRECT_TIME 1500

struct MyCard
{
	HBITMAP Animal;
	//TCHAR str[128];
	RECT rt;
	int number;
	bool isBlind;
};

class BitMap
{
private:
	HDC m_MemDC;
	vector<MyCard> m_vecCardList;
	HBRUSH m_pMyBrush;
	HBRUSH m_pOldBrush;
	HBITMAP m_pTitleBitMap;
	HBITMAP m_pOldBitMap;
	BITMAP m_Bitmap;
	SIZE m_Size;
	int m_iCount;
	int m_iSec;
	int m_iFirst_Select;
	int m_iSecond_Select;
	int m_iOldClock;
	bool m_bisIncorrect;
public:
	BitMap();
	~BitMap();
	void Init(HDC hdc, HINSTANCE hInst);
	void InGame(HWND hWnd, HDC hdc);
	void Title(HDC hdc);
	void Click_Button(HWND hWnd, HDC hdc, int x, int y, bool& ingame);
	void Time_Counting();
	void WinCheck(HWND hWnd, bool& ingame);
	//void Create_Sentence(int index, TCHAR* str);
	void Incorrect_TimeClear(HWND hWnd);
};