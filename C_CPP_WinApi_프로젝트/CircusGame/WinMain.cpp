#include "Manager.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 399;

	HWND hWnd;
	MSG Message;
	HINSTANCE g_hInst;
	WNDCLASS WndClass;
	LPCTSTR lpszClass = TEXT("Circus Game");
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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 300, 50, 1200, 800, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	//서커스찰리 수정사항
	//1. 자동진행이 아니다 수동플레이로 변경
	//2. 생명력시스템 도입
	//3. 항아리 코끼리 미터 골인지점은 맵에 고정
	//4. 링은 계속 생성과 다가옴
	//5. 캐릭터가 화면 밖으로 안나가게
	//링은 캐쉬를 가지는지 랜덤으로 정하고 랜덤으로 생성
	//맵의 끝자락오기전까지 계속 생성 및 이동
	//끝자락에 다다르면 생성 금지 이동만

	Manager::Get_Instance()->Init(hWnd);
	srand(time(NULL));

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
		{
			Manager::Get_Instance()->GameLoop();
		}
	}

	Manager::Get_Instance()->Release();

	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}