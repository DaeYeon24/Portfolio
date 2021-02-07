#include <Windows.h>
#define _USE_MATH_DEFINES
#include <cmath>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Clock(HDC hdc, SYSTEMTIME st);
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

//void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
//{
//	//Coordinate(rt, x, y);
//	InvalidateRect(hWnd, NULL, TRUE);
//}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;
	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 1000, NULL);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, TRUE);
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GetLocalTime(&st);
		Clock(hdc, st);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void Clock(HDC hdc, SYSTEMTIME st)
{
	TCHAR num[4];
	TCHAR sTime[128];
	double radian, x, y;
	double s_radian, s_x, s_y;
	double m_radian, m_x, m_y;
	double h_radian, h_x, h_y;
	SetTextAlign(hdc, TA_CENTER);
	wsprintf(sTime, TEXT("���� �ð� = %d:%d:%d"), st.wHour, st.wMinute, st.wSecond);
	TextOut(hdc, 550, 500, sTime, lstrlen(sTime));
	Ellipse(hdc, 450, 200, 650, 400);
	for (int i = 1; i <= 60; i++)
	{
		radian = (2 * M_PI / 60) * i;
		x = (cos(radian - (0.5 * M_PI)) * 90) + 550;
		y = (sin(radian - (0.5 * M_PI)) * 90) + 300;
		MoveToEx(hdc, x, y, NULL);
		x = (cos(radian - (0.5 * M_PI)) * 100) + 550;
		y = (sin(radian - (0.5 * M_PI)) * 100) + 300;
		LineTo(hdc, x, y);
		if (i % 5 == 0)
		{
			x = (cos(radian - (0.5 * M_PI)) * 110) + 550;
			y = (sin(radian - (0.5 * M_PI)) * 110) + 290;
			wsprintf(num, TEXT("%d"), i / 5);
			TextOut(hdc, x, y, num, lstrlen(num));
		}
	}
	s_radian = (st.wSecond * (2 * M_PI / 60)) - (0.5 * M_PI); // 1��и鿡�� ����ϴ� 0��(3�ù���)���� ��ȸ�� 90�� => �ð��� 12�ù��⿡ �츮�� ���� 0�� ǥ��
	//��, 15�ʸ� ǥ���Ϸ��� ���� 3���� ����ϴ� 90���� 6(30��)�� ����Ű�� ������ ��ȸ�� 90�� => 0������ 3(15��)�� ����Ŵ
	m_radian = ((st.wMinute * (2 * M_PI / 60)) - (0.5 * M_PI)) + (st.wSecond * (2 * M_PI / 60 / 60));
	//ex) 2��30�ʸ� ��Ÿ���� 30�ʸ�ŭ ��ħ�� �� ���������ϴ� +�ᰢ���� ��ȸ�� 90���� �������� 30��(180���� ����)�� �߰�
	h_radian = ((st.wHour * (2 * M_PI / 12)) - (0.5 * M_PI)) + (st.wMinute * (2 * M_PI / 12 / 60));
	//���� ����
	MoveToEx(hdc, 550, 300, NULL);
	h_x = (cos(h_radian) * 50) + 550;
	h_y = (sin(h_radian) * 50) + 300;
	LineTo(hdc, h_x, h_y); // ��ħ
	MoveToEx(hdc, 550, 300, NULL);
	m_x = (cos(m_radian) * 70) + 550;
	m_y = (sin(m_radian) * 70) + 300;
	LineTo(hdc, m_x, m_y); // ��ħ
	MoveToEx(hdc, 550, 300, NULL);
	s_x = (cos(s_radian) * 90) + 550;
	s_y = (sin(s_radian) * 90) + 300;
	LineTo(hdc, s_x, s_y); // ��ħ
}