#include "Manager.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Move Character");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static bool JumpState = false;

	switch (iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		Manager::GetInstance()->Init(hWnd, hdc, g_hInst);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_TIMER:
		if (JumpState)
			Manager::GetInstance()->Jump(hWnd, JumpState);
		else
			Manager::GetInstance()->Input(hWnd, wParam, BEGIN, JumpState);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_KEYUP:
		Manager::GetInstance()->Input(hWnd, wParam, END, JumpState);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_KEYDOWN:
		if (wParam == VK_SPACE)
			Manager::GetInstance()->Input(hWnd, wParam, BEGIN, JumpState);
		//InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Manager::GetInstance()->Draw(hWnd, hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		Manager::GetInstance()->DestroyInstance();
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}