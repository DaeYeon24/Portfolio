#include "Manager.h"

Manager::Manager()
{
	m_Player = NULL;
	m_eGameState = BEFOREGAME;
	m_eStage = STAGE1;
	m_eMaxEnemy = 0;
	m_eLiveEnemy = 0;
	m_iAppearanceEnemy = 0;
	m_iKillCount = 0;
	m_iPlayerLife = 3;
	m_dwCurFrame = GetTickCount();
	m_dwLastFrame = m_dwCurFrame;
	//DLG
	m_iDlgWidth = 13;
	m_iDlgHeight = 15;
	m_iCurSelect = 0;
	memset(m_iDlgMap, 0, sizeof(m_iDlgMap));
}

Manager::~Manager()
{
	SelectObject(m_BufferDC, m_OldBmp);
	SelectObject(m_BackDC, m_OldBackBmp);
	SelectObject(m_BufferDC, m_OldFont);
	DeleteObject(m_BufferBmp);
	DeleteObject(m_BackBmp);
	DeleteObject(m_StateBmp);
	DeleteObject(m_PlayerIconBmp);
	DeleteObject(m_EnemyIconBmp);
	DeleteObject(m_TitleBmp);
	DeleteObject(m_Font);
	DeleteObject(m_BigFont);
	DeleteObject(m_SmallFont);
	DeleteDC(m_BackDC);
	DeleteDC(m_BufferDC);
	DeleteDC(m_DlgDC);
	if (m_Player)
		delete m_Player;
	if (!m_vecBlockList.empty())
	{
		for (auto iter = m_vecBlockList.begin(); iter != m_vecBlockList.end(); iter++)
		{
			delete* iter;
		}
		m_vecBlockList.clear();
	}
	if (!m_vecEnemyList.empty())
	{
		for (auto iter = m_vecEnemyList.begin(); iter != m_vecEnemyList.end(); iter++)
		{
			delete* iter;
		}
		m_vecEnemyList.clear();
	}
	if (!m_vecItemList.empty())
	{
		for (auto iter = m_vecItemList.begin(); iter != m_vecItemList.end(); iter++)
		{
			delete* iter;
		}
		m_vecItemList.clear();
	}
}

GAME_STATE Manager::GameState()
{
	return m_eGameState;
}

void Manager::Init(HWND hWnd, HINSTANCE hInstance)
{
	m_hWnd = hWnd;
	m_hInst = hInstance;
	m_MainDC = GetDC(m_hWnd); // ����dc
	// ����
	m_BufferDC = CreateCompatibleDC(m_MainDC); 
	m_BufferBmp = CreateCompatibleBitmap(m_MainDC, FULL_WIDTH, HEIGHT);
	// ����
	m_BackDC = CreateCompatibleDC(m_BufferDC); 
	m_BackBmp = CreateCompatibleBitmap(m_BufferDC, INGAME_WIDTH, HEIGHT); 

	m_StateBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\state.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);//����â
	m_PlayerIconBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\player_icon.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_EnemyIconBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\enemy_icon.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_TitleBmp = (HBITMAP)LoadImage(NULL, TEXT("BattleCity\\title.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBmp = (HBITMAP)SelectObject(m_BufferDC, m_StateBmp);
	m_OldBackBmp = (HBITMAP)SelectObject(m_BackDC, m_BackBmp);

	m_Font = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "���");
	m_SmallFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "���");
	m_BigFont = CreateFont(80, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "���");
	m_OldFont = (HFONT)SelectObject(m_BufferDC, m_Font);

	SetTextAlign(m_BufferDC, TA_CENTER | TA_BOTTOM);
	SetTextColor(m_BufferDC, RGB(255, 0, 0));
	SetBkMode(m_BufferDC, TRANSPARENT);

	StretchBlt(m_MainDC, 0, 0, FULL_WIDTH, HEIGHT, m_BufferDC, 0, 0, 200, 800, SRCCOPY);
	SelectObject(m_BufferDC, m_BufferBmp);

	CreateWindow("button", "CREATE MAP", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 990, 20, 100, 25, m_hWnd, (HMENU)ID_MAIN_B1, m_hInst, NULL);
	CreateWindow("button", "GAME START", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 990, 50, 100, 25, m_hWnd, (HMENU)ID_MAIN_B2, m_hInst, NULL);
	CreateWindow("button", "GAME EXIT", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 990, 80, 100, 25, m_hWnd, (HMENU)ID_MAIN_B3, m_hInst, NULL);

	ReleaseDC(m_hWnd, m_MainDC);
}

void Manager::State_Render()
{ //����â ��� �Լ�
	int x = 0, y = 0;
	SelectObject(m_BackDC, m_StateBmp);
	BitBlt(m_BufferDC, 0, 0, 200, 800, m_BackDC, 0, 0, SRCCOPY);
	if (m_eGameState == INGAME)
	{
		TextOut(m_BufferDC, 93, 25, TEXT("ENEMY"), lstrlen("ENEMY"));
		TextOut(m_BufferDC, 93, 450, TEXT("ITEM"), lstrlen("ITEM"));
		TextOut(m_BufferDC, 93, 570, TEXT("PLAYER"), lstrlen("PLAYER"));

		SelectObject(m_BackDC, m_EnemyIconBmp);
		GetObject(m_EnemyIconBmp, sizeof(BITMAP), &m_BmpInfo);
		for (auto i = 0; i < (int)m_eMaxEnemy - m_iKillCount; i++)
		{ // ���� ���ʹ� ��
			TransparentBlt(m_BufferDC, x * 52 + 15, y * 45 + 50, 40, 40, m_BackDC, 0, 0, m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, RGB(255, 0, 255));
			if (x < 2)
				x++;
			else
			{
				x = 0;
				y++;
			}
		}
		//
		x = 0, y = 0;
		for (auto iter = m_vecItemList.begin(); iter != m_vecItemList.end(); iter++)
		{ // ������ ������ ���
			if ((*iter)->IsOperate())
			{
				(*iter)->Draw_Icon(m_BufferDC, x, y);
				if (x < 2)
					x++;
				else
				{
					x = 0;
					y++;
				}
			}
		}
		//
		x = 0, y = 0;
		SelectObject(m_BackDC, m_PlayerIconBmp);
		GetObject(m_PlayerIconBmp, sizeof(BITMAP), &m_BmpInfo);
		for (auto i = 0; i < (int)m_iPlayerLife; i++)
		{ // �����
			TransparentBlt(m_BufferDC, x * 52 + 15, y * 45 + 600, 40, 40, m_BackDC, 0, 0, m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, RGB(255, 0, 255));
			if (x < 2)
				x++;
			else
			{
				x = 0;
				y++;
			}
		}
	}
	BitBlt(m_MainDC, 950, 190, 200, 800, m_BufferDC, 0, 0, SRCCOPY);
}

void Manager::InGame_Render()
{
	for (auto iter = m_vecBlockList.begin(); iter != m_vecBlockList.end(); iter++) 
	{ //��� ���
		(*iter)->Draw(m_BufferDC);
	}
	for (auto iter = m_vecItemList.begin(); iter != m_vecItemList.end(); iter++) 
	{ // ������
		(*iter)->Draw(m_BufferDC);
	}
	SelectObject(m_BufferDC, m_SmallFont);
	SetTextColor(m_BufferDC, RGB(255, 255, 255));
	for (auto iter = m_vecEnemyList.begin(); iter != m_vecEnemyList.end(); iter++) 
	{ // ����
		if ((*iter)->Get_State() != DISAPPEAR)
			(*iter)->Draw(m_BufferDC);
	}
	m_Player->Draw(m_BufferDC); //�÷��̾�
	SelectObject(m_BufferDC, m_Font);
	SetTextColor(m_BufferDC, RGB(255, 0, 0));
	for (auto iter = m_vecBlockList.begin(); iter != m_vecBlockList.end(); iter++) 
	{ //��� �� ��
		Forest* forest = dynamic_cast<Forest*>((*iter)->Get_Type());
		if (!forest)
			continue;
		(*iter)->Draw(m_BufferDC);
	}
}

void Manager::Render()
{
	m_MainDC = GetDC(m_hWnd); // ��ȭ��

	State_Render(); //����â

	SelectObject(m_BackDC, m_BackBmp);
	BitBlt(m_BufferDC, 0, 0, INGAME_WIDTH, HEIGHT, m_BackDC, 0, 0, BLACKNESS);

	switch (m_eGameState)
	{
	case BEFOREGAME:
		SelectObject(m_BackDC, m_TitleBmp);
		GetObject(m_TitleBmp, sizeof(BITMAP), &m_BmpInfo);
		StretchBlt(m_BufferDC, 50, 350, 850, 200, m_BackDC, 0, 0, m_BmpInfo.bmWidth, m_BmpInfo.bmHeight, SRCCOPY);
		break;
	case LOADING:
		SelectObject(m_BufferDC, m_BigFont);
		switch (m_eStage)
		{
		case STAGE1:
			TextOut(m_BufferDC, INGAME_WIDTH / 2, HEIGHT / 2, TEXT("STAGE 1"), lstrlen("STAGE 1"));
			break;
		case STAGE2:
			TextOut(m_BufferDC, INGAME_WIDTH / 2, HEIGHT / 2, TEXT("STAGE 2"), lstrlen("STAGE 1"));
			break;
		case STAGE3:
			TextOut(m_BufferDC, INGAME_WIDTH / 2, HEIGHT / 2, TEXT("STAGE 3"), lstrlen("STAGE 1"));
			break;
		case STAGE4:
			TextOut(m_BufferDC, INGAME_WIDTH / 2, HEIGHT / 2, TEXT("STAGE 4"), lstrlen("STAGE 1"));
			break;
		case STAGE5:
			TextOut(m_BufferDC, INGAME_WIDTH / 2, HEIGHT / 2, TEXT("STAGE 5"), lstrlen("STAGE 1"));
			break;
		}
		SelectObject(m_BufferDC, m_Font);
		break;
	case INGAME:
		InGame_Render();
		break;
	case GAMEOVER:
		InGame_Render();
		SelectObject(m_BufferDC, m_BigFont);
		TextOut(m_BufferDC, INGAME_WIDTH / 2, HEIGHT / 2, TEXT("GAME OVER!!..."), lstrlen("GAME OVER!!..."));
		SelectObject(m_BufferDC, m_Font);
		break;
	case GAMECLEAR:
		SelectObject(m_BufferDC, m_BigFont);
		TextOut(m_BufferDC, INGAME_WIDTH / 2, HEIGHT / 2, TEXT("GAME CLEAR!!"), lstrlen("GAME CLEAR!!"));
		SelectObject(m_BufferDC, m_Font);
		break;
	}

	BitBlt(m_MainDC, 0, 0, INGAME_WIDTH, HEIGHT, m_BufferDC, 0, 0, SRCCOPY);
	ReleaseDC(m_hWnd, m_MainDC);
}

void Manager::GameLoop()
{
	//������ ����
	m_dwCurFrame = GetTickCount();
	m_fFrame = (m_dwCurFrame - m_dwLastFrame) / 1000.0f;
	m_dwLastFrame = m_dwCurFrame;

	switch (m_eGameState) // ���� ���¿� ���� ���� �� 
	{
	case LOADING:
		Loading();
		break;
	case INGAME:
		InGame();
		break;
	case GAMECLEAR:
	case GAMEOVER:
		GameEnd();
		break;
	}

	Render(); // �������� ȭ�� ���
}

void Manager::InGame()
{
	if (!m_vecItemList.empty()) // ������ ������ ȿ���� ������ ȿ�� ����
	{
		for (auto iter = m_vecItemList.begin(); iter != m_vecItemList.end();)
		{
			if ((*iter)->Operate(m_Player, &m_vecEnemyList, m_iPlayerLife, m_fFrame))
			{ //ȿ�� �����ð��� ������ ��Ͽ��� ����.
				delete* iter;
				*iter = NULL;
				iter = m_vecItemList.erase(iter);
			}
			else
				iter++;
		}
	}
	// �÷��̾�� ���ʹ̵��� �� �Է°��� ���� ���� ������Ʈ
	Player_Update();

	Enemy_Update();
	// �¸� üũ
	Win_Check();
}

void Manager::Player_Update()
{ // ���� > �Է� > ������ ���� > �̻��� �߻�
	m_Player->Unit_Update(m_fFrame);
	m_Player->Operate_Input(m_vecBlockList, m_fFrame);
	m_Player->Get_Item(&m_vecItemList);
	m_Player->Operate_Shoot(m_BufferDC, &m_vecBlockList, &m_vecEnemyList, m_fFrame);
}

void Manager::Loading() //�÷��̾�� ���ʹ� �ʱ�ȭ
{
	static float old = 0.0f;
	if (old >= 2.5f)
	{
		m_eGameState = INGAME;
		if (m_Player)
			delete m_Player;
		m_Player = NULL;
		m_Player = new Player(m_BufferDC);
		m_Player->Init(m_BufferDC);
		m_iPlayerLife = 3;
		m_iKillCount = 0;

		if (!m_vecEnemyList.empty())
		{
			for (auto iter = m_vecEnemyList.begin(); iter != m_vecEnemyList.end(); iter++)
			{
				delete* iter;
				*iter = NULL;
			}
			m_vecEnemyList.clear();
		} // enemy_update���� ����
		m_iAppearanceEnemy = 0;

		if (!m_vecItemList.empty())
		{
			for (auto iter = m_vecItemList.begin(); iter != m_vecItemList.end(); iter++)
			{
				delete* iter;
				*iter = NULL;
			}
			m_vecItemList.clear();
		} // �ΰ��ӿ��� ����

		old = 0.0f;
		return;
	}
	else
		old += m_fFrame;
}

void Manager::GameEnd()
{
	static float old = 0.0f;
	if (old >= 3.0f)
	{
		m_eGameState = BEFOREGAME;
		m_eStage = STAGE1;
		old = 0.0f;
		return;
	}
	else
		old += m_fFrame;
}

void Manager::Win_Check()
{
	bool clear = true;
	Camp* camp = NULL;
	if (m_Player->Get_State() == DISAPPEAR)
	{
		m_iPlayerLife--;
		if (m_iPlayerLife == 0)
		{
			m_eGameState = GAMEOVER;
			return;
		}
		else
		{
			if (m_Player)
				delete m_Player;
			m_Player = NULL;
			m_Player = new Player(m_BufferDC);
			m_Player->Init(m_BufferDC);
		}
	}
	for (auto iter = m_vecBlockList.begin(); iter != m_vecBlockList.end(); iter++)
	{
		camp = dynamic_cast<Camp*>((*iter)->Get_Type());
		if (camp)
		{
			if ((*iter)->Get_State())
			{
				m_eGameState = GAMEOVER;
				return;
			}
		}
	}
	if (m_iAppearanceEnemy == (int)m_eMaxEnemy)
	{
		for (auto iter = m_vecEnemyList.begin(); iter != m_vecEnemyList.end(); iter++)
		{
			if ((*iter)->Get_State() != DISAPPEAR)
				clear = false;
		}
		if (clear)
		{
			m_eGameState = LOADING;
			switch (m_eStage)
			{
			case STAGE1:
				m_eStage = STAGE2;
				break;
			case STAGE2:
				m_eStage = STAGE3;
				break;
			case STAGE3:
				m_eStage = STAGE4;
				break;
			case STAGE4:
				m_eStage = STAGE5;
				break;
			case STAGE5:
				m_eGameState = GAMECLEAR;
				break;
			}
			if(m_eGameState != GAMECLEAR)
				Game_Set();
		}
	}
}

void Manager::Enemy_Update()
{
	Enemy* tmp;
	static float old = 0.0f;
	if (m_iAppearanceEnemy < m_eMaxEnemy)
	{
		if (m_vecEnemyList.size() < m_eLiveEnemy)
		{
			if (old >= 2.5f)
			{
				if (rand() % 2 == 0)
					tmp = new Enemy(m_BufferDC);
				else
					tmp = new Enemy_Lv2(m_BufferDC);
				tmp->Init(m_BufferDC);
				m_vecEnemyList.push_back(tmp);
				m_iAppearanceEnemy++;
				if (m_vecEnemyList.size() == m_eLiveEnemy)
					old = 0.0f;
			}
			else
				old += m_fFrame;
		}
	}

	for (auto iter = m_vecEnemyList.begin(); iter != m_vecEnemyList.end();)
	{
		(*iter)->Unit_Update(m_fFrame);
		(*iter)->Auto_Input(m_vecBlockList, m_fFrame);
		(*iter)->Auto_Shoot(m_BufferDC, &m_vecBlockList, m_Player, &m_vecEnemyList, m_fFrame);
		if ((*iter)->Get_State() == DISAPPEAR)
		{ //2������ ���ʹ̴� �ı��� �������� ���
			Enemy_Lv2* enemy_lv2 = dynamic_cast<Enemy_Lv2*>((*iter)->Get_Type());
			if (enemy_lv2)
			{
				Item* item = new Item(m_BufferDC, (*iter)->Get_XY().x, (*iter)->Get_XY().y);
				m_vecItemList.push_back(item);
			}
			delete* iter;
			*iter = NULL;
			iter = m_vecEnemyList.erase(iter);
			m_iKillCount++;
		}
		else
			iter++;
	}
}

void Manager::Game_Set() //����ʱ�ȭ 
{
	HANDLE hFile;
	DWORD read;
	Block* tmp;
	char tmpblock;
	if (!m_vecBlockList.empty())
	{
		for (auto iter = m_vecBlockList.begin(); iter != m_vecBlockList.end(); iter++)
		{
			delete* iter;
			*iter = NULL;
		}
		m_vecBlockList.clear();
	}

	switch (m_eStage)
	{
	case STAGE1:
		hFile = CreateFile("stage1.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		break;
	case STAGE2:
		hFile = CreateFile("stage2.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		break;
	case STAGE3:
		hFile = CreateFile("stage3.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		break;
	case STAGE4:
		hFile = CreateFile("stage4.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		break;
	case STAGE5:
		hFile = CreateFile("stage5.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		break;
	}

	if (hFile != INVALID_HANDLE_VALUE)
	{
		for (int i = 0; i < m_iDlgWidth; i++)
		{
			for (int j = 0; j < m_iDlgHeight; j++)
			{
				tmp = NULL;
				ReadFile(hFile, &tmpblock, sizeof(char), &read, NULL);
				if (tmpblock == '0')
					m_iDlgMap[i][j] = LOAD;
				else if (tmpblock == '1')
					m_iDlgMap[i][j] = BREAKABLEWALL;
				else if (tmpblock == '2')
					m_iDlgMap[i][j] = UNBREAKABLEWALL;
				else if (tmpblock == '3')
					m_iDlgMap[i][j] = FOREST;
				else if (tmpblock == '4')
					m_iDlgMap[i][j] = RIVER;
				else if (tmpblock == '5')
					m_iDlgMap[i][j] = CREATEPOINT;
				else if (tmpblock == '6')
					m_iDlgMap[i][j] = CAMP;
				switch (m_iDlgMap[i][j])
				{
				case 0:
					break;
				case 1:
					tmp = new BreakableWall(m_BufferDC, i, j);
					break;
				case 2:
					tmp = new UnBreakableWall(m_BufferDC, i, j);
					break;
				case 3:
					tmp = new Forest(m_BufferDC, i, j);
					break;
				case 4:
					tmp = new River(m_BufferDC, i, j);
					break;
				case 5:
					break;
				case 6:
					tmp = new Camp(m_BufferDC, i, j);
					break;
				}
				if (tmp)
				{
					tmp->Init();
					m_vecBlockList.push_back(tmp);
				}
			}
		}
		ReadFile(hFile, &m_eMaxEnemy, sizeof(int), &read, NULL);
		ReadFile(hFile, &m_eLiveEnemy, sizeof(int), &read, NULL);
		CloseHandle(hFile);
		m_eGameState = LOADING;
	}
	else
		MessageBox(m_hWnd, TEXT("����� �������� ������ �����ϴ�."), TEXT("���"), MB_OK);
}

void Manager::Release()
{
	Destroy_Instance();
}


//DLG///////////////////////////////////////////////////////////////////////////////////////////DLG


void Manager::InitDLG(HWND hWnd)
{ //���̾�α� �ʱ�ȭ
	m_DlghWnd = hWnd;
	CreateWindow(TEXT("button"), TEXT("Stage"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 440, 5, 90, 170, m_DlghWnd, (HMENU)ID_DLG_GB1, m_hInst, NULL);
	CreateWindow(TEXT("button"), TEXT("Object"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 550, 5, 150, 170, m_DlghWnd, (HMENU)ID_DLG_GB2, m_hInst, NULL);

	m_DlgButton[0] = CreateWindow(TEXT("button"), TEXT("stage1"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, 445, 20, 80, 30, m_DlghWnd, (HMENU)ID_DLG_B1, m_hInst, NULL);
	m_DlgButton[1] = CreateWindow(TEXT("button"), TEXT("stage2"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 445, 50, 80, 30, m_DlghWnd, (HMENU)ID_DLG_B2, m_hInst, NULL);
	m_DlgButton[2] = CreateWindow(TEXT("button"), TEXT("stage3"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 445, 80, 80, 30, m_DlghWnd, (HMENU)ID_DLG_B3, m_hInst, NULL);
	m_DlgButton[3] = CreateWindow(TEXT("button"), TEXT("stage4"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 445, 110, 80, 30, m_DlghWnd, (HMENU)ID_DLG_B4, m_hInst, NULL);
	m_DlgButton[4] = CreateWindow(TEXT("button"), TEXT("stage5"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 445, 140, 80, 30, m_DlghWnd, (HMENU)ID_DLG_B5, m_hInst, NULL);

	CreateWindow(TEXT("button"), TEXT("Load"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, 555, 20, 140, 30, m_DlghWnd, (HMENU)ID_DLG_B6, m_hInst, NULL);
	CreateWindow(TEXT("button"), TEXT("Breakable Wall"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 555, 50, 140, 30, m_DlghWnd, (HMENU)ID_DLG_B7, m_hInst, NULL);
	CreateWindow(TEXT("button"), TEXT("UnBreakable Wall"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 555, 80, 140, 30, m_DlghWnd, (HMENU)ID_DLG_B8, m_hInst, NULL);
	CreateWindow(TEXT("button"), TEXT("Forest"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 555, 110, 140, 30, m_DlghWnd, (HMENU)ID_DLG_B9, m_hInst, NULL);
	CreateWindow(TEXT("button"), TEXT("River"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 555, 140, 140, 30, m_DlghWnd, (HMENU)ID_DLG_B10, m_hInst, NULL);

	CheckRadioButton(hWnd, ID_DLG_B1, ID_DLG_B5, NULL);
	CheckRadioButton(hWnd, ID_DLG_B6, ID_DLG_B10, ID_DLG_B6);

	CreateWindow("button", "Reset", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 520, 210, 100, 30, m_DlghWnd, (HMENU)ID_DLG_B11, m_hInst, NULL);
	CreateWindow("button", "Save", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 520, 270, 100, 30, m_DlghWnd, (HMENU)ID_DLG_B12, m_hInst, NULL);
	CreateWindow("button", "Load", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 520, 330, 100, 30, m_DlghWnd, (HMENU)ID_DLG_B13, m_hInst, NULL);

	memset(m_iDlgMap, 0, sizeof(m_iDlgMap));
}

void Manager::CommandDLG(WPARAM wParam)
{
	HANDLE hFile;
	static TCHAR filename[32] = "";

	switch (wParam)
	{
	case ID_DLG_B1:
		wsprintf(filename, TEXT("stage1.txt"));
		break;
	case ID_DLG_B2:
		wsprintf(filename, TEXT("stage2.txt"));
		break;
	case ID_DLG_B3:
		wsprintf(filename, TEXT("stage3.txt"));
		break;
	case ID_DLG_B4:
		wsprintf(filename, TEXT("stage4.txt"));
		break;
	case ID_DLG_B5:
		wsprintf(filename, TEXT("stage5.txt"));
		break;
	case ID_DLG_B6: //�� ������Ʈ ����
	case ID_DLG_B7:
	case ID_DLG_B8:
	case ID_DLG_B9:
	case ID_DLG_B10:
		m_iCurSelect = LOWORD(wParam) - 6;
		break;
	case ID_DLG_B11: //����
		memset(m_iDlgMap, 0, sizeof(m_iDlgMap));
		InvalidateRect(m_DlghWnd, NULL, false);
		break;
	case ID_DLG_B12: //���̺�
	{
		//OPENFILENAME OFN;
		//char str[300];
		//char lpstrFile[MAX_PATH] = "*.txt";
		//char lpstrPath[MAX_PATH] = "";
		//memset(&OFN, 0, sizeof(OPENFILENAME));
		//OFN.lStructSize = sizeof(OPENFILENAME);
		//OFN.hwndOwner = m_DlghWnd;
		//OFN.lpstrFilter = "Text File\0*.txt\0";
		//OFN.lpstrFile = lpstrFile;
		//OFN.nMaxFile = 256;
		//GetCurrentDirectory(MAX_PATH, lpstrPath);
		//OFN.lpstrInitialDir = lpstrPath;
		//if (GetSaveFileName(&OFN) == 0)
		//{
		//	DWORD err = CommDlgExtendedError();
		//	break;
		//}
		TCHAR buf[32];
		DWORD write;
		int max_enemy, live_enemy;
		if (SendMessage(m_DlgButton[0], BM_GETCHECK, 0, 0) == BST_UNCHECKED && SendMessage(m_DlgButton[1], BM_GETCHECK, 0, 0) == BST_UNCHECKED && SendMessage(m_DlgButton[2], BM_GETCHECK, 0, 0) == BST_UNCHECKED && SendMessage(m_DlgButton[3], BM_GETCHECK, 0, 0) == BST_UNCHECKED && SendMessage(m_DlgButton[4], BM_GETCHECK, 0, 0) == BST_UNCHECKED)
		{
			MessageBox(m_DlghWnd, TEXT("���������� �����ϼ���"), TEXT("���"), MB_OK);
			break;
		}
		hFile = CreateFile(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
		for (int i = 0; i < m_iDlgWidth; i++)
		{
			for (int j = 0; j < m_iDlgHeight; j++)
			{
				if (m_iDlgMap[i][j] == LOAD)
					wsprintf(buf, TEXT("0"));
				else if (m_iDlgMap[i][j] == BREAKABLEWALL)
					wsprintf(buf, TEXT("1"));
				else if (m_iDlgMap[i][j] == UNBREAKABLEWALL)
					wsprintf(buf, TEXT("2"));
				else if (m_iDlgMap[i][j] == FOREST)
					wsprintf(buf, TEXT("3"));
				else if (m_iDlgMap[i][j] == RIVER)
					wsprintf(buf, TEXT("4"));
				else if (m_iDlgMap[i][j] == CREATEPOINT)
					wsprintf(buf, TEXT("5"));
				else if (m_iDlgMap[i][j] == CAMP)
					wsprintf(buf, TEXT("6"));
				WriteFile(hFile, &buf, lstrlen(buf), &write, NULL);
			}
		}
		if (SendMessage(m_DlgButton[0], BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			max_enemy = 5;
			live_enemy = 2;
		}
		else if(SendMessage(m_DlgButton[1], BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			max_enemy = 10;
			live_enemy = 3;
		}
		else if (SendMessage(m_DlgButton[2], BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			max_enemy = 15;
			live_enemy = 4;
		}
		else if (SendMessage(m_DlgButton[3], BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			max_enemy = 20;
			live_enemy = 5;
		}
		else if (SendMessage(m_DlgButton[4], BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			max_enemy = 25;
			live_enemy = 6;
		}
		WriteFile(hFile, &max_enemy, sizeof(int), &write, NULL);
		WriteFile(hFile, &live_enemy, sizeof(int), &write, NULL);
		CloseHandle(hFile);
		InvalidateRect(m_DlghWnd, NULL, false);
	}
	break;
	case ID_DLG_B13: //�ε�
	{
		DWORD read;
		char buf;
		if (SendMessage(m_DlgButton[0], BM_GETCHECK, 0, 0) == BST_UNCHECKED && SendMessage(m_DlgButton[1], BM_GETCHECK, 0, 0) == BST_UNCHECKED && SendMessage(m_DlgButton[2], BM_GETCHECK, 0, 0) == BST_UNCHECKED && SendMessage(m_DlgButton[3], BM_GETCHECK, 0, 0) == BST_UNCHECKED && SendMessage(m_DlgButton[4], BM_GETCHECK, 0, 0) == BST_UNCHECKED)
		{
			MessageBox(m_DlghWnd, TEXT("���������� �����ϼ���"), TEXT("���"), MB_OK);
			break;
		}
		hFile = CreateFile(filename, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			for (int i = 0; i < m_iDlgWidth; i++)
			{
				for (int j = 0; j < m_iDlgHeight; j++)
				{
					ReadFile(hFile, &buf, sizeof(char), &read, NULL);
					if (buf == '0')
						m_iDlgMap[i][j] = LOAD;
					else if (buf == '1')
						m_iDlgMap[i][j] = BREAKABLEWALL;
					else if (buf == '2')
						m_iDlgMap[i][j] = UNBREAKABLEWALL;
					else if (buf == '3')
						m_iDlgMap[i][j] = FOREST;
					else if (buf == '4')
						m_iDlgMap[i][j] = RIVER;
					else if (buf == '5')
						m_iDlgMap[i][j] = CREATEPOINT;
					else if (buf == '6')
						m_iDlgMap[i][j] = CAMP;
				}
			}
			CloseHandle(hFile);
			InvalidateRect(m_DlghWnd, NULL, false);
		}
		else
			MessageBox(m_DlghWnd, TEXT("����� �������� ������ �����ϴ�."), TEXT("���"), MB_OK);
	}
	break;
	case ID_OK:
		EndDialog(m_DlghWnd, 0);
		break;
	}
}

void Manager::PaintDLG()
{
	m_DlgDC = BeginPaint(m_DlghWnd, &m_DlgPS);

	//���� ���� ��ġ ����
	m_iDlgMap[0][0] = CREATEPOINT;
	m_iDlgMap[6][0] = CREATEPOINT;
	m_iDlgMap[12][0] = CREATEPOINT;
	m_iDlgMap[6][14] = CAMP;
	m_iDlgMap[5][13] = BREAKABLEWALL;
	m_iDlgMap[5][14] = BREAKABLEWALL;
	m_iDlgMap[6][13] = BREAKABLEWALL;
	m_iDlgMap[7][13] = BREAKABLEWALL;
	m_iDlgMap[7][14] = BREAKABLEWALL;
	m_iDlgMap[4][14] = CREATEPOINT;

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	HPEN GreenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	HPEN BluePen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HPEN RedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN OldPen = (HPEN)SelectObject(m_DlgDC, Pen);

	HBRUSH BlackBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
	HBRUSH OldBrush = (HBRUSH)SelectObject(m_DlgDC, BlackBrush);

	for (int i = 0; i < m_iDlgWidth; i++)
	{
		for (int j = 0; j < m_iDlgHeight; j++)
		{
			if (m_iDlgMap[i][j] == LOAD)
			{
				SelectObject(m_DlgDC, Pen);
				SelectObject(m_DlgDC, OldBrush);
				Rectangle(m_DlgDC, i * DLG_WIDTH, j * DLG_HEIGHT, (i + 1) * DLG_WIDTH, (j + 1) * DLG_HEIGHT);
			}
			else if (m_iDlgMap[i][j] == BREAKABLEWALL)
			{
				SelectObject(m_DlgDC, Pen);
				SelectObject(m_DlgDC, OldBrush);
				Ellipse(m_DlgDC, i * DLG_WIDTH, j * DLG_HEIGHT, (i + 1) * DLG_WIDTH, (j + 1) * DLG_HEIGHT);
			}
			else if (m_iDlgMap[i][j] == UNBREAKABLEWALL)
			{
				SelectObject(m_DlgDC, Pen);
				SelectObject(m_DlgDC, BlackBrush);
				Ellipse(m_DlgDC, i * DLG_WIDTH, j * DLG_HEIGHT, (i + 1) * DLG_WIDTH, (j + 1) * DLG_HEIGHT);
			}
			else if (m_iDlgMap[i][j] == FOREST)
			{
				SelectObject(m_DlgDC, GreenPen);
				SelectObject(m_DlgDC, BlackBrush);
				Ellipse(m_DlgDC, i * DLG_WIDTH, j * DLG_HEIGHT, (i + 1) * DLG_WIDTH, (j + 1) * DLG_HEIGHT);
			}
			else if (m_iDlgMap[i][j] == RIVER)
			{
				SelectObject(m_DlgDC, BluePen);
				SelectObject(m_DlgDC, BlackBrush);
				Ellipse(m_DlgDC, i * DLG_WIDTH, j * DLG_HEIGHT, (i + 1) * DLG_WIDTH, (j + 1) * DLG_HEIGHT);
			}
			else if (m_iDlgMap[i][j] == CREATEPOINT)
			{
				SelectObject(m_DlgDC, RedPen);
				SelectObject(m_DlgDC, BlackBrush);
				Ellipse(m_DlgDC, i * DLG_WIDTH, j * DLG_HEIGHT, (i + 1) * DLG_WIDTH, (j + 1) * DLG_HEIGHT);
			}
			else if (m_iDlgMap[i][j] == CAMP)
			{
				SelectObject(m_DlgDC, RedPen);
				SelectObject(m_DlgDC, BlackBrush);
				Rectangle(m_DlgDC, i * DLG_WIDTH, j * DLG_HEIGHT, (i + 1) * DLG_WIDTH, (j + 1) * DLG_HEIGHT);
			}
		}
	}
	SelectObject(m_DlgDC, OldBrush);
	SelectObject(m_DlgDC, OldPen);
	DeleteObject(Pen);
	DeleteObject(GreenPen);
	DeleteObject(BluePen);
	DeleteObject(RedPen);

	EndPaint(m_DlghWnd, &m_DlgPS);
}

void Manager::ButtonDownDLG(POINT pt)
{
	if ((pt.x < DLG_WIDTH * m_iDlgWidth && pt.x > 0) && (pt.y < DLG_HEIGHT * m_iDlgHeight && pt.y > 0))
	{
		m_iDlgMap[pt.x / DLG_WIDTH][pt.y / DLG_HEIGHT] = m_iCurSelect;
		InvalidateRect(m_DlghWnd, NULL, false);
	}
}