#include <Windows.h>
#define _USE_MATH_DEFINES
#include <cmath>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("HelloWorld");

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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}


enum FIGURE
{
	CIRCLE,
	RECTANGLE
};

TCHAR str[256];
FIGURE CurFigure = CIRCLE;

void MoveFigure(HDC hdc, RECT rt, int x, int y)
{
	wsprintf(str, TEXT("마우스 좌표 X = %d, Y = %d"), x, y);
	TextOut(hdc, 10, 20, str, lstrlen(str));
	TextOut(hdc, 10, 5, TEXT("움직이기 = 좌클릭 or 방향키, 도형변경 = 우클릭"), 29);
	MoveToEx(hdc, 150, 150, NULL);
	LineTo(hdc, 150, 850);
	LineTo(hdc, 1650, 850);
	LineTo(hdc, 1650, 150);
	LineTo(hdc, 150, 150);
	if (CurFigure == CIRCLE)
		Ellipse(hdc, x - 50, y - 50, x + 50, y + 50);
	else
		Rectangle(hdc, x - 50, y - 50, x + 50, y + 50);
}

void Coordinate(RECT rt, int& x, int& y)
{
	if (x <= rt.left && y <= rt.top)
	{
		x = rt.left;
		y = rt.top;
	}
	else if (x <= rt.left && y >= rt.bottom)
	{
		x = rt.left;
		y = rt.bottom;
	}
	else if (x >= rt.right && y <= rt.top)
	{
		x = rt.right;
		y = rt.top;
	}
	else if (x >= rt.right && y >= rt.bottom)
	{
		x = rt.right;
		y = rt.bottom;
	}
	else if (x <= rt.left)
		x = rt.left;
	else if (x >= rt.right)
		x = rt.right;
	else if (y <= rt.top)
		y = rt.top;
	else if (y >= rt.bottom)
		y = rt.bottom;
	else
		return;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int len;
	static int x = 500;
	static int y = 500;
	static bool m_move = FALSE;
	RECT rt = { 200, 200, 1600, 800 };
	switch (iMessage)
	{
	case WM_KEYDOWN:
		hdc = GetDC(hWnd);
		switch (wParam)
		{
		case VK_LEFT:
			x -= 10;
			break;
		case VK_RIGHT:
			x += 10;
			break;
		case VK_UP:
			y -= 10;
			break;
		case VK_DOWN:
			y += 10;
			break;
		}
		ReleaseDC(hWnd, hdc);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		if (m_move == TRUE)
			m_move = FALSE;
		else
			m_move = TRUE;
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_RBUTTONDOWN:
		hdc = GetDC(hWnd);
		if (MessageBox(hWnd, TEXT("도형을 바꾸시겠습니까?"), TEXT("도형 바꾸기"), MB_OKCANCEL) == IDOK)
		{
			if (CurFigure == CIRCLE)
				CurFigure = RECTANGLE;
			else
				CurFigure = CIRCLE;
		}
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_MOUSEMOVE:
		if (m_move == TRUE) {
			hdc = GetDC(hWnd);
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			ReleaseDC(hWnd, hdc);
			InvalidateRect(hWnd, NULL, TRUE);
		}
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Coordinate(rt, x, y);
		MoveFigure(hdc, rt, x, y);
		EndPaint(hWnd, &ps);
		return 0;
	//case WM_CHAR:
	//	len = lstrlen(str);
	//	str[len] = (TCHAR)wParam;
	//	str[len + 1] = 0;
	//	InvalidateRect(hWnd, &rt, TRUE);
	//	return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}