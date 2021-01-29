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

	//��Ŀ������ ��������
	//1. �ڵ������� �ƴϴ� �����÷��̷� ����
	//2. ����½ý��� ����
	//3. �׾Ƹ� �ڳ��� ���� ���������� �ʿ� ����
	//4. ���� ��� ������ �ٰ���
	//5. ĳ���Ͱ� ȭ�� ������ �ȳ�����
	//���� ĳ���� �������� �������� ���ϰ� �������� ����
	//���� ���ڶ����������� ��� ���� �� �̵�
	//���ڶ��� �ٴٸ��� ���� ���� �̵���

	Manager::Get_Instance()->Init(hWnd);
	srand(time(NULL));

	while (true)
	{
		/// �޽���ť�� �޽����� ������ �޽��� ó��
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