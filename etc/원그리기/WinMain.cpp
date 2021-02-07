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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int X, Y;
	RECT rt = { 100, 100, 1000, 1000 };
	const TCHAR* str = TEXT("안녕하세요");
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	//case WM_LBUTTONDOWN:
	//	hdc = GetDC(hWnd);
	//	TextOut(hdc, 100, 100, TEXT("Hello"), 6);
	//	ReleaseDC(hWnd, hdc);
	//	return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		for (int i = 0; i < 100; i++)
			SetPixel(hdc, 10 + (i * 1), 10, RGB(255, 0, 0));
		double radian, x, y;
		for (int i = 0; i < 1000; i++) // 원을 n등분
		{
			radian = i * (2 * M_PI / 1000);
			// 360도는 2파이라디안 -> n등분한 360도에 대한 라디안으로
			//조금씩 각도 이동하며 x, y좌표 구함.
			x = (cos(radian) * 250) + 500;
			y = (sin(radian) * 250) + 500;
			SetPixel(hdc, x, y, RGB(255, 0, 0));
		}
		for (int i = 0; i < 1000; i++)
		{
			radian = i * (2 * M_PI / 1000);
			x = 400 * cos(radian) + 500; // x는 반지름 400인 원의 x좌표 입력.
			y = 70 * sin(radian) + 500; // y는 반지름 70인 원의 y좌표 입력.
			SetPixel(hdc, x, y, RGB(255, 0, 0));
		}
		MoveToEx(hdc, 50, 50, NULL);
		LineTo(hdc, 200, 50);
		TextOut(hdc, 50, 51, TEXT("hihihihihi"), 10);
		MoveToEx(hdc, 500, 300, NULL);
		LineTo(hdc, 700, 300);
		TextOut(hdc, 500, 301, TEXT("byebyebyebye"), 12);
		//Rectangle(hdc, 50, 100, 200, 180);
		//Ellipse(hdc, 50, 100, 200, 180);
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}