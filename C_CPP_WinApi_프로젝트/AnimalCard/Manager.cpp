#include "Manager.h"

Manager::Manager()
{}

void Manager::Init(HWND hWnd, HDC hdc, HINSTANCE hInst)
{
	m_bInGame = false;
	m_Bitmap = new BitMap;
	m_Bitmap->Init(hdc, hInst);
}

void Manager::Play(HWND hWnd, HDC hdc)
{
	if (m_bInGame)
		m_Bitmap->InGame(hWnd, hdc);
	else
		m_Bitmap->Title(hdc);
}

void Manager::Time_Counting()
{
	m_Bitmap->Time_Counting();
}

void Manager::Click_Button(HWND hWnd, HDC hdc, int x, int y)
{
	m_Bitmap->Click_Button(hWnd, hdc, x, y, m_bInGame);
}

void Manager::Release()
{
	DestroyInstance();
}

Manager::~Manager()
{
	delete m_Bitmap;
}