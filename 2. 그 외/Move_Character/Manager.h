#pragma once
#include "Character.h"
#include "Singleton.h"

class Manager : public Singleton<Manager>
{
private:
	Character* m_Character;
public:
	Manager();
	~Manager();
	void Init(HWND hWnd, HDC hdc, HINSTANCE hInst);
	void Draw(HWND hWnd, HDC hdc);
	void Input(HWND hWnd, WPARAM wParam, INPUT_STATE inputstate, bool& jumpstate);
	void Jump(HWND hWnd, bool& jumpstate);
	void Release();
};