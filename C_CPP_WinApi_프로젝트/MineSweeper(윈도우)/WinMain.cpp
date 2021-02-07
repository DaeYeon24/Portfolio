#include "GameManager.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 399;

	HWND hWnd;
	MSG Message;
	HINSTANCE g_hInst;
	WNDCLASS WndClass;
	LPCTSTR lpszClass = TEXT("MineSweeper Game");
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 400, 20, WIDTH, 900, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	srand(time(NULL));
	GameManager::Get_Instance()->Init(hWnd);

	while (true)
	{
		/// 메시지큐에 메시지가 있으면 메시지 처리
		if (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
		{
			if (Message.message == WM_QUIT)
				break;

			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else
			GameManager::Get_Instance()->GameLoop();
	}

	GameManager::Get_Instance()->Release();

	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static POINT MousePoint;

	switch (iMessage)
	{
	case WM_TIMER:
		GameManager::Get_Instance()->Time_Counting();
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_EASY:
			GameManager::Get_Instance()->Change_Stage(EASY);
			break;
		case ID_NORMAL:
			GameManager::Get_Instance()->Change_Stage(NORMAL);
			break;
		case ID_HARD:
			GameManager::Get_Instance()->Change_Stage(HARD);
			break;
		}
		return 0;
	case WM_LBUTTONDOWN:
		MousePoint.x = LOWORD(lParam);
		MousePoint.y = HIWORD(lParam);
		GameManager::Get_Instance()->Cursor_Interaction(CURSOR_SELECT, MousePoint);
		return 0;
	case WM_RBUTTONDOWN:
		MousePoint.x = LOWORD(lParam);
		MousePoint.y = HIWORD(lParam);
		GameManager::Get_Instance()->Cursor_Interaction(CURSOR_MARK, MousePoint);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}