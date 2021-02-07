#include "BitMap.h"

BitMap::BitMap()
{}

void BitMap::Init(HDC hdc, HINSTANCE hInst)
{
	m_MemDC = CreateCompatibleDC(hdc); //�޸� DC ����
	m_iCount = 0; // ������Ʈ���� �� ��Ʈ�� ���� ��
	m_iSec = 0; // �ΰ��� ī��Ʈ
	m_bisIncorrect = false; // ī�� �ΰ� ���ý� Ʋ�ȴ��� Ȯ��
	m_iFirst_Select = UNSELECTED;
	m_iSecond_Select = UNSELECTED; // 1��, 2��
	m_pTitleBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP11)); // Ÿ��Ʋȭ�� ���ӽ��� ��ư
	m_pOldBitMap = (HBITMAP)SelectObject(m_MemDC, m_pTitleBitMap); // old ��Ʈ�� ����.
	m_pMyBrush = (HBRUSH)GetStockObject(BLACK_BRUSH); // ������ �귯�� ����
	m_pOldBrush = (HBRUSH)SelectObject(hdc, m_pMyBrush); // old �귯�� ����.
	ifstream load;
	TCHAR str[32];
	MyCard tmp_card;
	int tmp_num;
	while (1) // ��Ʈ������ �� ī��Ʈ
	{
		wsprintf(str, "%02d.bmp", m_iCount);
		load.open(str);
		if (load.is_open())
		{
			m_iCount++;
			load.close();
		}
		else
		{
			load.close();
			break;
		}
	}
	for (int j = 0; j < 2; j++) // ���ӿ� �ʿ��� �ν��� ī�� �����Է�
	{
		tmp_num = 1;
		for (int i = 101; i < (101 + m_iCount); i++)
		{
			tmp_card.Animal = LoadBitmap(hInst, MAKEINTRESOURCE(i));
			//Create_Sentence(i, tmp_card.str);
			tmp_card.isBlind = true;
			tmp_card.number = tmp_num++;
			m_vecCardList.push_back(tmp_card);
		}
	}
	random_shuffle(m_vecCardList.begin(), m_vecCardList.end()); //��������
}

void BitMap::Title(HDC hdc) // Ÿ��Ʋ ���ӽ��۹�ư ȭ��
{
	SelectObject(m_MemDC, m_pTitleBitMap);
	GetObject(m_pTitleBitMap, sizeof(m_Bitmap), &m_Bitmap);
	m_Size.cx = m_Bitmap.bmWidth;
	m_Size.cy = m_Bitmap.bmHeight;
	StretchBlt(hdc, 290, 200, 200, 150, m_MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
}

void BitMap::InGame(HWND hWnd, HDC hdc) // �ΰ��� ȭ��
{
	TCHAR str[32];
	int x = 0, y = 0;
	SetTextAlign(hdc, TA_CENTER);
	wsprintf(str, TEXT("%03d��"), m_iSec);
	TextOut(hdc, 390, 4, str, lstrlen(str));
	SelectObject(hdc, m_pMyBrush);
	Incorrect_TimeClear(hWnd);
	if (m_bisIncorrect) // Ʋ������� �ϴ� ���� ���
	{
		HFONT myFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "���");
		HFONT oldFont = (HFONT)SelectObject(hdc, myFont);
		SetTextColor(hdc, RGB(255, 0, 0));
		wsprintf(str, TEXT("Ʋ�Ƚ��ϴ�."));
		TextOut(hdc, 390, 850, str, lstrlen(str));
		SelectObject(hdc, oldFont);
		DeleteObject(myFont);
	}
	for (auto i = 0; i < m_vecCardList.size(); i++) //ī�� ����
	{
		m_vecCardList.at(i).rt = { (x * 150 + 10), (y * 205 + 20), (x * 150 + 155), (y * 205 + 220) };
		if (m_vecCardList.at(i).isBlind)
			Rectangle(hdc, m_vecCardList.at(i).rt.left, m_vecCardList.at(i).rt.top, m_vecCardList.at(i).rt.right, m_vecCardList.at(i).rt.bottom);
		else
		{
			SelectObject(m_MemDC, m_vecCardList.at(i).Animal);
			GetObject(m_vecCardList.at(i).Animal, sizeof(m_Bitmap), &m_Bitmap);
			m_Size.cx = m_Bitmap.bmWidth;
			m_Size.cy = m_Bitmap.bmHeight;
			StretchBlt(hdc, m_vecCardList.at(i).rt.left, m_vecCardList.at(i).rt.top, 145, 200, m_MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
		}
		x++;
		if (x % 5 == 0)
		{
			x = 0;
			y++;
		}
	}
	SelectObject(hdc, m_pOldBrush);
}

void BitMap::Time_Counting() // �ΰ��� ��� �ð� ī��Ʈ
{
	m_iSec++;
}

void BitMap::Click_Button(HWND hWnd, HDC hdc, int x, int y, bool& ingame) // ���콺 �Է�
{
	if (!ingame) // Ÿ��Ʋȭ��
	{
		if (x >= 290 && x <= 490 && y >= 200 && y <= 350)
		{
			ingame = true;
			SetTimer(hWnd, 1, 1000, NULL); //�ΰ��� ����, �ð� ī��Ʈ ����.
			InvalidateRect(hWnd, NULL, TRUE); // Ÿ��Ʋ���� �ΰ������� ȭ�� ��ȯ.
			return;
		}
	}
	else // �ΰ���ȭ��
	{
		if (m_bisIncorrect) // Ʋ����� �ߺ��Է� ����
			return;
		for (auto i = 0; i < m_vecCardList.size(); i++)
		{
			if (x >= m_vecCardList.at(i).rt.left && x <= m_vecCardList.at(i).rt.right && y >= m_vecCardList.at(i).rt.top && y <= m_vecCardList.at(i).rt.bottom)
			{ // ����ε� ī�� ���� ��
				if (!m_vecCardList.at(i).isBlind)
					return;
				else
				{
					m_vecCardList.at(i).isBlind = false;
					SelectObject(m_MemDC, m_vecCardList.at(i).Animal);
					GetObject(m_vecCardList.at(i).Animal, sizeof(m_Bitmap), &m_Bitmap);
					m_Size.cx = m_Bitmap.bmWidth;
					m_Size.cy = m_Bitmap.bmHeight;
					StretchBlt(hdc, m_vecCardList.at(i).rt.left, m_vecCardList.at(i).rt.top, 145, 200, m_MemDC, 0, 0, m_Size.cx, m_Size.cy, SRCCOPY);
					if (m_iFirst_Select == UNSELECTED) // 1��
						m_iFirst_Select = i;
					else if (m_iSecond_Select == UNSELECTED) // 2��
					{
						m_iSecond_Select = i;
						if (m_vecCardList.at(m_iFirst_Select).number == m_vecCardList.at(m_iSecond_Select).number)
						{
							m_iFirst_Select = UNSELECTED;
							m_iSecond_Select = UNSELECTED;
						}
						else
						{
							m_bisIncorrect = true; // ���Ƽ ����
							m_iOldClock = clock();
							InvalidateRect(hWnd, NULL, TRUE);
							return;
						}
					}
					//������ �������� üũ
					WinCheck(hWnd, ingame);
				}
				return;
			}
		}
	}
}

void BitMap::WinCheck(HWND hWnd, bool& ingame) // ��üũ �� ����
{
	bool AllOpen = true;
	TCHAR str[32];
	for (auto i = 0; i < m_vecCardList.size(); i++)
	{
		if (m_vecCardList.at(i).isBlind)
		{
			AllOpen = false;
			break;
		}
	}
	if (AllOpen)
	{
		KillTimer(hWnd, 1);
		wsprintf(str, "��� ���߾����ϴ�! ��� : %d��", m_iSec);
		MessageBox(hWnd, str, TEXT("����"), MB_OK);
		m_iSec = 0;
		ingame = false;
		for (auto i = 0; i < m_vecCardList.size(); i++)
		{
			m_vecCardList.at(i).isBlind = true;
		}
		random_shuffle(m_vecCardList.begin(), m_vecCardList.end());
		InvalidateRect(hWnd, NULL, TRUE);
	}
}

void BitMap::Incorrect_TimeClear(HWND hWnd) // ���Ƽ �ð����
{
	if (m_bisIncorrect && clock() - m_iOldClock >= INCORRECT_TIME)
	{ // Ʋ�������̸鼭 ���Ƽ �ð��� ���������.
		m_vecCardList.at(m_iFirst_Select).isBlind = true;
		m_vecCardList.at(m_iSecond_Select).isBlind = true; // 1��, 2���� �ٽ� �ݱ�
		m_iFirst_Select = UNSELECTED;
		m_iSecond_Select = UNSELECTED; // 1��, 2�� ���� ����
		m_bisIncorrect = false; // ���Ƽ ����
		InvalidateRect(hWnd, NULL, TRUE); //�ٽ� �׷��ֱ�
		return;
	}
	return;
}

//void BitMap::Create_Sentence(int index, TCHAR* str)
//{
//	switch (index)
//	{
//	case IDB_BITMAP1:
//		wsprintf(str, TEXT("������ �Դϴ�."));
//		break;
//	case IDB_BITMAP2:
//		wsprintf(str, TEXT("ȣ���� �Դϴ�."));
//		break;
//	case IDB_BITMAP3:
//		wsprintf(str, TEXT("���� �Դϴ�."));
//		break;
//	case IDB_BITMAP4:
//		wsprintf(str, TEXT("�ڳ��� �Դϴ�."));
//		break;
//	case IDB_BITMAP5:
//		wsprintf(str, TEXT("�� �Դϴ�."));
//		break;
//	case IDB_BITMAP6:
//		wsprintf(str, TEXT("�� �Դϴ�."));
//		break;
//	case IDB_BITMAP7:
//		wsprintf(str, TEXT("����� �Դϴ�."));
//		break;
//	case IDB_BITMAP8:
//		wsprintf(str, TEXT("������ �Դϴ�."));
//		break;
//	case IDB_BITMAP9:
//		wsprintf(str, TEXT("������ �Դϴ�."));
//		break;
//	case IDB_BITMAP10:
//		wsprintf(str, TEXT("�� �Դϴ�."));
//		break;
//	}
//}

BitMap::~BitMap()
{
	SelectObject(m_MemDC, m_pOldBitMap); //old��Ʈ�� ����
	for (auto i = 0; i < m_vecCardList.size(); i++)
	{
		DeleteObject(m_vecCardList.at(i).Animal); //����ī�� ����
	}
	DeleteObject(m_pTitleBitMap); //Ÿ��Ʋ��ư ����
	DeleteDC(m_MemDC); // �޸�DC ����
}
