#include "Manager.h"
LRESULT CALLBACK Wnd_Proc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Dlg_proc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam);

HWND hWnd; //윈도우핸들
HINSTANCE g_hInst; //윈도우 인스턴스

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 399; //메모리 누수체크

	LPCTSTR lpszClass = TEXT("BattleCity Game");
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = Wnd_Proc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 400, 5, FULL_WIDTH, HEIGHT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	srand(time(NULL));
	Manager::Get_Instance()->Init(hWnd, g_hInst); //초기화

	while (true)
	{
		if (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
		{
			if (Message.message == WM_QUIT)
				break;

			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else
			Manager::Get_Instance()->GameLoop(); //게임루프
	}

	Manager::Get_Instance()->Release(); //해제

	return (int)Message.wParam;
}

LRESULT CALLBACK Wnd_Proc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_COMMAND:
		if (Manager::Get_Instance()->GameState() == BEFOREGAME)
		{
			switch (LOWORD(wParam))
			{
			case ID_MAIN_B1: //맵툴
				DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg_proc); 
				break;
			case ID_MAIN_B2: //게임시작
				Manager::Get_Instance()->Game_Set(); 
				break;
			}
		}
		if (wParam == ID_MAIN_B3) //게임종료
			PostQuitMessage(0);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

BOOL CALLBACK Dlg_proc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static POINT pt;
	switch (iMessage)
	{
	case WM_INITDIALOG:
		Manager::Get_Instance()->InitDLG(hWnd); //DLG 초기화
		return TRUE;
	case WM_COMMAND:
		Manager::Get_Instance()->CommandDLG(wParam); // DLG 작동
		return TRUE;
	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		Manager::Get_Instance()->ButtonDownDLG(pt); //DLG 버튼
		return TRUE;
	case WM_PAINT:
		Manager::Get_Instance()->PaintDLG(); // DLG 출력
		return TRUE;
	}
	return FALSE;
}