#include "GameManager.h"

GameManager::GameManager()
{
	m_iWidth = 20;
	m_iHeight = 20;
	m_DrawManager = new Draw(m_iWidth, m_iHeight);
	m_Stone1p = new Stone(m_iWidth, m_iHeight, PLAYER_1P, m_DrawManager);
	m_Stone2p = new Stone(m_iWidth, m_iHeight, PLAYER_2P, m_DrawManager);
	m_bPlayer_Empty = false;
	m_bInGame = false;
}

void GameManager::BeforeGame()
{
	int select; // 메뉴 or 플레이어 선택 변수
	string temp; // 문자 임시 저장
	m_DrawManager->BoardDraw();
	while (1)
	{
		select = m_DrawManager->Menu();
		m_DrawManager->BoardDraw();
		switch (select)
		{
		case 1:
			if (m_bPlayer_Empty == false)
			{
				delete m_Stone1p;
				delete m_Stone2p;
				m_bPlayer_Empty = true;
			}
			if (m_bPlayer_Empty == true)
			{
				m_Stone1p = new Stone(m_iWidth, m_iHeight, PLAYER_1P, m_DrawManager);
				m_Stone2p = new Stone(m_iWidth, m_iHeight, PLAYER_2P, m_DrawManager);
				m_bPlayer_Empty = false;
			}
			m_DrawManager->Text("1P 이름 입력 : ");
			cin >> temp;
			m_Stone1p->SetName(temp);
			m_DrawManager->Text("2P 이름 입력 : ", 2);
			cin >> temp;
			m_Stone2p->SetName(temp);
			m_bInGame = true;
			PlayGame();
			break;
		case 2:
			RePlayLoad();
			break;
		case 3:
			SecondMenu();
			break;
		case 4:
			return;
		}
	}
}

void GameManager::ReDraw()
{
	m_DrawManager->BoardDraw();
	m_Stone1p->AllStoneDraw();
	m_Stone2p->AllStoneDraw();
}

void GameManager::SecondMenu()
{
	int select;
	while (1)
	{
		select = m_DrawManager->SecondMenu();
		m_DrawManager->BoardDraw(HIDE);
		switch (select) // EXIT면 빠져 나옴
		{
		case 1:
			if (m_bInGame == true)
			{
				m_DrawManager->Text("접근 불가");
				m_DrawManager->Text("<게임 중>", 1);
				getch();
				break;
			}
			else
			{
				SizeSet();
				break;
			}
		case 2:
			IconSet(CURSORICON);
			break;
		case 3:
			IconSet(STONEICON);
			break;
		case 4:
			if (m_bInGame == true)
			{
				m_DrawManager->Text("접근 불가");
				m_DrawManager->Text("<게임 중>", 1);
				getch();
				break;
			}
			else
			{
				UndoSet();
				break;
			}
		case 5:
			m_DrawManager->BoardDraw();
			return;
		}
		m_DrawManager->BoardDraw(HIDE);
	}
}

void GameManager::IconSet(int CurOrStone)
{
	int player;
	string temp;
	m_DrawManager->Text("변경할 플레이어 선택(1, 2) : ", 2);
	cin >> player;
	m_DrawManager->Text("변경할 아이콘 입력(기호) : ", 4);
	cin >> temp;
	Change(player, temp, CurOrStone);
}

void GameManager::Change(int player, string str, int CurOrStone)
{
	if (player == PLAYER_1P)
	{
		m_Stone1p->ChangeIcon(str, CurOrStone, player);
		m_Stone1p->ChangeIconSet(player);
	}
	else if (player == PLAYER_2P)
	{
		m_Stone2p->ChangeIcon(str, CurOrStone, player);
		m_Stone2p->ChangeIconSet(player);
	}
}

void GameManager::SizeSet()
{
	m_DrawManager->Text("변경할 가로 길이 : ");
	cin >> m_iWidth;
	m_DrawManager->Text("변경할 세로 길이 : ", 2);
	cin >> m_iHeight;
	delete m_DrawManager;
	m_DrawManager = new Draw(m_iWidth, m_iHeight);
}

void GameManager::UndoSet()
{
	int select;
	while (1)
	{
		m_DrawManager->BoardDraw(HIDE);
		m_DrawManager->Text(" ==Set Undo==");
		m_DrawManager->Text("1. 무르기 횟수 변경", 2);
		m_DrawManager->Text("2. 무르기 끄기", 4);
		m_DrawManager->Text("3. 돌아가기", 6);
		m_DrawManager->Text("입력 : ", 8);
		cin >> select;
		m_DrawManager->BoardDraw(HIDE);
		switch (select)
		{
		case 1:
			m_DrawManager->Text("무르기 횟수 입력(최대 10회) : ", 2);
			cin >> select;
			if (select > 10 || select < 0)
			{
				m_DrawManager->BoardDraw(HIDE);
				m_DrawManager->Text("무르기 횟수 제한 초과", 2);
				getch();
				continue;
			}
			m_Stone1p->ChangeUndo(select);
			m_Stone2p->ChangeUndo(select);
			break;
		case 2:
			m_DrawManager->Text("무르기 기능 끄기", 2);
			m_Stone1p->ChangeUndo(0);
			m_Stone2p->ChangeUndo(0);
			m_DrawManager->BoardDraw(HIDE);
			m_DrawManager->Text("무르기 꺼짐", 2);
			getch();
			break;
		case 3:
			return;
		}
	}
}

void GameManager::PlayGame()
{
	int GameTurn = 1;
	int GameFlag = ING;
	int TurnOwner = PLAYER_1P;
	m_DrawManager->BoardDraw();
	while (1)
	{
		switch (TurnOwner) // 플레이어 행동으로 Gameflag 바뀜
		{
		case PLAYER_1P:
			m_DrawManager->BoardUnderDraw(m_Stone1p->GetName(),m_Stone1p->GetUndo(), GameTurn);
			GameFlag = m_Stone1p->Move(m_Stone2p);
			break;
		case PLAYER_2P:
			m_DrawManager->BoardUnderDraw(m_Stone2p->GetName(),m_Stone2p->GetUndo(), GameTurn);
			GameFlag = m_Stone2p->Move(m_Stone1p);
			break;
		}
		switch (GameFlag) // Gameflag에 따라 게임 관리
		{
		case WIN:
			if (TurnOwner == PLAYER_1P)
			{
				m_DrawManager->Text(m_Stone1p->GetName());
				m_DrawManager->Text("플레이어 승리!",1);
			}
			else if (TurnOwner == PLAYER_2P)
			{
				m_DrawManager->Text(m_Stone2p->GetName());
				m_DrawManager->Text("플레이어 승리!",1);
			}
			getch();
			m_DrawManager->BoardDraw();
			m_bInGame = false;
			RePlaySave(++GameTurn);
			return;
		case PAUSE:
			SecondMenu(); 
			ReDraw();
			break;
		case RETURN:
			if (TurnOwner == PLAYER_1P)
			{
				if (m_Stone2p->GetUndo() <= 0)
					continue;
				else
				{
					m_Stone1p->RemoveCursor();
					m_Stone2p->Undo();
					TurnOwner = PLAYER_2P;
				}
			}
			else if (TurnOwner == PLAYER_2P)
			{
				if (m_Stone1p->GetUndo() <= 0)
					continue;
				else
				{
					m_Stone2p->RemoveCursor();
					m_Stone1p->Undo();
					TurnOwner = PLAYER_1P;
				}
			}
			ReDraw();
			GameTurn--;
			break;
		case EXIT:
			m_DrawManager->BoardDraw();
			m_bInGame = false;
			RePlaySave(GameTurn);
			return;
		default:
			if (TurnOwner == PLAYER_1P)
				TurnOwner = PLAYER_2P;
			else if (TurnOwner == PLAYER_2P)
				TurnOwner = PLAYER_1P;
			GameTurn++;
			break;
		}
	}
}

void GameManager::RePlaySave(int gameturn)
{
	Position* Record_1p = m_Stone1p->GetRecord();
	Position* Record_2p = m_Stone2p->GetRecord();
	ofstream save;
	save.open("replay.txt");
	if (save.is_open())
	{
		save << gameturn<< endl;
		save << m_Stone1p->GetName() << " " << m_Stone2p->GetName() << endl;
		save << m_Stone1p->GetIcon() << " " << m_Stone2p->GetIcon() << endl;
		for (int i = 0, j = 0; ; )
		{
			if (i < m_Stone1p->GetCount())
			{
				save << Record_1p[i].ix << " " << Record_1p[i].iy << endl;
				i++;
			}
			if (j < m_Stone2p->GetCount())
			{
				save << Record_2p[j].ix << " " << Record_2p[j].iy << endl;
				j++;
			}
			if (!(i < m_Stone1p->GetCount() || j < m_Stone2p->GetCount()))
				break;
		}
		save.close();
	}
}

void GameManager::RePlayLoad()
{
	string Stone_1p, Stone_2p, Name_1p, Name_2p;
	int Turn, x, y;
	int TurnOwner = PLAYER_1P;
	ifstream load;
	load.open("replay.txt");
	if (load.is_open() == NULL)
	{
		cout << "저장된 기록이 없습니다." << endl;
		getch();
		system("cls");
		m_DrawManager->BoardDraw();
		return;
	}
	m_DrawManager->BoardDraw();
	load >> Turn;
	load >> Name_1p;
	load >> Name_2p;
	load >> Stone_1p;
	load >> Stone_2p;
	for (int i = 1; i < Turn; i++)
	{
		if (TurnOwner == PLAYER_1P)
		{
			m_DrawManager->BoardUnderDraw(Name_1p);
		}
		else if (TurnOwner == PLAYER_2P)
		{
			m_DrawManager->BoardUnderDraw(Name_2p);
		}
		load >> x;
		load >> y;
		m_DrawManager->gotoxy(x, y);
		if (TurnOwner == PLAYER_1P)
		{
			cout << Stone_1p;
			TurnOwner = PLAYER_2P;
		}
		else if (TurnOwner == PLAYER_2P)
		{
			cout << Stone_2p;
			TurnOwner = PLAYER_1P;
		}
		Sleep(800);
	}
	load.close();
	m_DrawManager->BoardUnderText("replay가 끝났습니다...");
	getch();
	m_DrawManager->BoardDraw();
}

GameManager::~GameManager()
{
	if (m_bPlayer_Empty == false)
	{
		delete m_Stone1p;
		delete m_Stone2p;
	}
	delete m_DrawManager;
}