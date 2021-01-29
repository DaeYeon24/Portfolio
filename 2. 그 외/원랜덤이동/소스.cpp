#include <Windows.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <time.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void MoveFigure(HDC hdc, RECT rt, int x, int y, SYSTEMTIME st);
void Coordinate(RECT rt, int& x, int& y);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("HelloWorld");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	srand(time(NULL));
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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

RECT rt = { 200, 200, 1600, 800 };
int x = 500, y = 500;
int x_distance = 50, y_distance = 50;

void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	Coordinate(rt, x, y);
	InvalidateRect(hWnd, NULL, TRUE);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;
	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 50, TimeProc);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GetLocalTime(&st);
		MoveFigure(hdc, rt, x, y, st);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void MoveFigure(HDC hdc, RECT rt, int x, int y, SYSTEMTIME st)
{
	MoveToEx(hdc, 150, 150, NULL);
	LineTo(hdc, 150, 850);
	LineTo(hdc, 1650, 850);
	LineTo(hdc, 1650, 150);
	LineTo(hdc, 150, 150);
	Ellipse(hdc, x - 50, y - 50, x + 50, y + 50);
}

void Coordinate(RECT rt, int& x, int& y)
{
	x += x_distance;
	y += y_distance;
	if (x <= rt.left)
	{
		x = rt.left;
		x_distance = rand() % 50 + 1;
	}
	else if (x >= rt.right)
	{
		x = rt.right;
		x_distance = (rand() % 50 + 1) * (-1);
	}
	if (y <= rt.top)
	{
		y = rt.top;
		y_distance = rand() % 50 + 1;
	}
	else if (y >= rt.bottom)
	{
		y = rt.bottom;
		y_distance = (rand() % 50 + 1) * (-1);
	}
}