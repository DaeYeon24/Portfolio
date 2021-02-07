#include "Manager.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Chess Game");

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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 470, 30, 900, 1000, NULL, (HMENU)NULL, hInstance, NULL);
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
	static POINT Mouse_Point;
	static bool Select_State = false;
	static bool Game_State = false;

	switch (iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		Manager::Get_Instance()->Init(hWnd, hdc, g_hInst);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_TIMER:
		Manager::Get_Instance()->Flashing();
		InvalidateRect(hWnd, NULL, FALSE);
		return 0;
	case WM_LBUTTONDOWN:
		if (!Select_State)
		{
			hdc = GetDC(hWnd);
			Mouse_Point.x = LOWORD(lParam);
			Mouse_Point.y = HIWORD(lParam);
			if (Game_State)
			{
				Select_State = Manager::Get_Instance()->Select_Chessman(hWnd, hdc, Mouse_Point);
				SendMessage(hWnd, WM_TIMER, 1, 0);
			}
			else
				Manager::Get_Instance()->Select_Title(hWnd, hdc, Mouse_Point, Game_State);
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_LBUTTONUP:
		if (Select_State && Game_State)
		{
			hdc = GetDC(hWnd);
			Select_State = Manager::Get_Instance()->Free_Chessman(hWnd, g_hInst, Mouse_Point, Game_State);
			Manager::Get_Instance()->Promotion(hdc, g_hInst);
			Manager::Get_Instance()->Chessman_MoveCheck();
			InvalidateRect(hWnd, NULL, FALSE);
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_MOUSEMOVE:
		if (Select_State && Game_State)
		{
			hdc = GetDC(hWnd);
			Mouse_Point.x = LOWORD(lParam);
			Mouse_Point.y = HIWORD(lParam);
			InvalidateRect(hWnd, NULL, FALSE);
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Manager::Get_Instance()->Draw(hWnd, hdc, Mouse_Point);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		Manager::Get_Instance()->Release();
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}