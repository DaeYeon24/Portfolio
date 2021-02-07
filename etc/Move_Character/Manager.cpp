#include "Manager.h"

Manager::Manager()
{}

void Manager::Init(HWND hWnd, HDC hdc, HINSTANCE hInst)
{
	m_Character = new Character;
	m_Character->Init(hdc, hInst);
	SetTimer(hWnd, MOVE_TIME, 50, NULL);
}

void Manager::Input(HWND hWnd, WPARAM wParam, INPUT_STATE inputstate, bool& jumpstate)
{
	if (inputstate == BEGIN)
		m_Character->Input(hWnd, wParam, jumpstate);
	else
		m_Character->MoveFinish();
}

void Manager::Jump(HWND hWnd, bool& jumpstate)
{
	m_Character->Jump(hWnd, jumpstate);
}

void Manager::Draw(HWND hWnd, HDC hdc)
{
	m_Character->Draw(hWnd, hdc);
}

void Manager::Release()
{
	DestroyInstance();
}

Manager::~Manager()
{
	delete m_Character;
}