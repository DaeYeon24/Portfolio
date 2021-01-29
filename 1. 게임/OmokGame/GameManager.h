#pragma once
#include "Stone.h"
#include "Draw.h"

class GameManager
{
private:
	Draw* m_DrawManager;
	Stone* m_Stone1p;
	Stone* m_Stone2p;
	int m_iWidth;
	int m_iHeight;
	bool m_bPlayer_Empty;
	bool m_bInGame;
public:
	GameManager();
	~GameManager();
	void RePlaySave(int gameturn);
	void RePlayLoad();
	void ReDraw();
	void SecondMenu();
	void SizeSet();
	void IconSet(int CurOrStone);
	void UndoSet();
	void BeforeGame();
	void PlayGame();
	void Change(int player, string str, int CurOrDrop);
};