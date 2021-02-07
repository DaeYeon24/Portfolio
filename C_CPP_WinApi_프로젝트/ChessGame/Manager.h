#pragma once
#include "ChessmanFactory.h"

template <typename T>
class Singleton
{
private:
	static T* m_pThis;
protected:
	Singleton() {};
	virtual ~Singleton() {};
	Singleton(const T& other) {};
public:
	static T* Get_Instance()
	{
		if (m_pThis == NULL)
			m_pThis = new T;
		return m_pThis;
	}
	static void Destroy_Instance()
	{
		if (m_pThis != NULL)
			delete m_pThis;
	}
};
template <typename T>
T* Singleton<T>::m_pThis = NULL;

class Manager : public Singleton<Manager>
{
private:
	HDC m_MainDC; // �Ŵ��� ���� �ڵ�
	HDC m_BackDC; // �Ŵ��� �� �ڵ� (������۸�) (BackDC ������ �� Ŭ������ MemDC)
	HBITMAP m_pTitleBitMap; // Ÿ��Ʋ��Ʈ��
	HBITMAP m_pStartBitMap; // ���۹�ư
	HBITMAP m_pExitBitMap; // �����ư
	HBITMAP m_pCurBitMap; //����ȭ��
	HBITMAP m_pOldBitMap;
	HBITMAP m_pBackGroundBitMap; //�ڿ��� �׷��� ȭ��
	HBITMAP m_pOldGroundBitMap;
	Board* m_BoardManager; //������
	ChessmanFactory* m_ChessmanFactory[TOTAL]; //ü���� ���� ���丮
	Chessman** m_ChessmanList_Black; //����
	Chessman** m_ChessmanList_White; //����
	Chessman* m_SelectedChessman; // ���� ��
	BITMAP m_BitInfo;
	bool m_bInGame; //�ΰ��� ����
	TEAM m_eTurnOwner; // �ش� ���� ��
	TCHAR m_str[256]; // �ڸ�Ʈ
public:
	Manager();
	~Manager();
	void Init(HWND hWnd, HDC hdc, HINSTANCE hInst);
	void DefaultSetting(HWND hWnd, HINSTANCE hInst);
	void Title_Draw(HWND hWnd, HDC hdc);
	void Draw(HWND hWnd, HDC hdc, POINT pt);
	void Select_Title(HWND hWnd, HDC hdc, POINT pt, bool& Game_State);
	bool Select_Chessman(HWND hWnd, HDC hdc, POINT pt);
	bool Free_Chessman(HWND hWnd, HINSTANCE hInst, POINT pt, bool& Game_State);
	void Promotion(HDC hdc, HINSTANCE hInst);
	void Chessman_MoveCheck();
	void Flashing();
	void Release();
	bool WinCheck(HWND hWnd);
	void GameReSet(HWND hWnd, HINSTANCE hInst);
};

