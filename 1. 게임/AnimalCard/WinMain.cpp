#include "Manager.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("AnimalCard");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	srand(time(NULL));

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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 780, 960, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

//void CALLBACK TimeProc_Count(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
//{
//	Manager::GetInstance()->Time_Counting();
//	InvalidateRect(hWnd, NULL, TRUE);
//}
//
//void CALLBACK TimeProc_Incorrect(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
//{
//	Manager::GetInstance()->Time_Counting();
//	InvalidateRect(hWnd, NULL, TRUE);
//}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x, y;

	switch (iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		Manager::GetInstance()->Init(hWnd, hdc, g_hInst);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_TIMER:
		Manager::GetInstance()->Time_Counting();
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Manager::GetInstance()->Play(hWnd, hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		Manager::GetInstance()->Click_Button(hWnd, hdc, x, y);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		Manager::GetInstance()->DestroyInstance();
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}