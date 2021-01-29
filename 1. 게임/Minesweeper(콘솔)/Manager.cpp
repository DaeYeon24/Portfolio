#include "Manager.h"

Manager::Manager()
{
	m_strDifficulty = "��  �� (10 x 10)";
	m_iWidth = 12;
	m_iHeight = 12;
	m_itotal = (m_iWidth - 2) * (m_iHeight - 2);
	m_iMineCount = 0;
	m_DrawManager = new Draw;
	m_BlockManager = NULL;
	m_Player = NULL;
}

void Manager::Title()
{
	m_DrawManager->Window();
	while (1)
	{
		system("cls");
		m_DrawManager->Text("�� �� ã ��");
		m_DrawManager->MenuText("�� �� �� ��");
		m_DrawManager->MenuText("�� �� ���̵�", 2);
		m_DrawManager->MenuText("�� �� �� ��", 4);
		switch (m_DrawManager->MenuSelectCursor(3, 2))
		{
		case 1:
			system("cls");
			m_DrawManager->BorderLine(m_iWidth, m_iHeight);
			Init();
			InGame();
			break;
		case 2:
			system("cls");
			Difficulty();
			break;
		case 3:
			return;
		}
	}
}

void Manager::Difficulty()
{
	if (m_BlockManager)
	{
		for (int i = 0; i < m_itotal; i++)
		{
			if (m_BlockManager[i])
			{
				delete m_BlockManager[i];
				m_BlockManager[i] = NULL;
			}
		}
		delete m_BlockManager;
		m_BlockManager = NULL;
	}
	m_DrawManager->Text("�� �� �� �� ��");
	m_DrawManager->MenuText("��  �� (5 x 5)");
	m_DrawManager->MenuText("��  �� (10 x 10)", 2);
	m_DrawManager->MenuText("��  �� (20 x 20)", 4);
	switch (m_DrawManager->MenuSelectCursor(3, 2))
	{
	case 1:
		m_strDifficulty = "��  �� (5 x 5)";
		m_iWidth = 7;
		m_iHeight = 7;
		m_itotal = (m_iWidth - 2) * (m_iHeight - 2);
		return;
	case 2:
		m_strDifficulty = "��  �� (10 x 10)";
		m_iWidth = 12;
		m_iHeight = 12;
		m_itotal = (m_iWidth - 2) * (m_iHeight - 2);
		return;
	case 3:
		m_strDifficulty = "��  �� (20 x 20)";
		m_iWidth = 22;
		m_iHeight = 22;
		m_itotal = (m_iWidth - 2) * (m_iHeight - 2);
		return;
	}
}

void Manager::InGameText()
{
	m_DrawManager->UnderLineText(m_strDifficulty);
	m_DrawManager->UnderLineText("���� �� = " + to_string(m_iMineCount), 1);
	m_DrawManager->UnderLineText("��ŷ = [m] / ���� = [Enter]", 2);
}

void Manager::InGame()
{
	STEP GameFlag;
	InGameText();
	m_Player->StartCursor();
	while (1)
	{
		GameFlag = m_Player->Move(m_BlockManager, m_itotal);
		if (GameFlag == BOOM)
			return Boom();
		else if(WinCheck())
			return;
	}
}

void Manager::Boom()
{
	RED
	for (int i = 0; i < m_itotal; i++)
	{
		if (m_BlockManager[i]->IsMine())
			m_BlockManager[i]->Open();
	}
	ORIGINAL
		_getch();
	m_iMineCount = 0;
}

bool Manager::WinCheck()
{
	for (int i = 0; i < m_itotal; i++)
	{
		if ((!m_BlockManager[i]->IsMine() && m_BlockManager[i]->IsOpen()) || (m_BlockManager[i]->IsMine() && !m_BlockManager[i]->IsOpen()))
			continue;
		else
			return false;
	}
	HIGH_GREEN
		m_DrawManager->UnderLineText("��� ���ڸ� ã�ҽ��ϴ�!!", -1);
	ORIGINAL
		_getch();
		return true;
}

void Manager::Init()
{
	int random, x = 1, y = 1;
	if (m_BlockManager)
	{
		for (int i = 0; i < m_itotal; i++)
		{
			if (m_BlockManager[i])
			{
				delete m_BlockManager[i];
				m_BlockManager[i] = NULL;
			}
		}
		delete m_BlockManager;
		m_BlockManager = NULL;
	}
	m_BlockManager = new Block * [m_itotal];
	for (int i = 0; i < m_itotal; i++)
	{
		random = rand() % 5;
		switch (random)
		{
		case 0:
			m_iMineCount++;
			m_BlockManager[i] = new Mine(x, y);
			break;
		default:
			m_BlockManager[i] = new EmptyBlock(x, y);
			break;
		}
		m_BlockManager[i]->Show();
		if (x == (m_iWidth - 2))
		{
			x = 1;
			y++;
		}
		else
			x++;
	}
	if (m_Player)
	{
		delete m_Player;
		m_Player = NULL;
	}
	m_Player = new Player(m_iWidth, m_iHeight);
}

Manager::~Manager()
{
	if (m_DrawManager)
		delete m_DrawManager;
	if (m_BlockManager)
	{
		for (int i = 0; i < m_itotal; i++)
		{
			if (m_BlockManager[i])
				delete m_BlockManager[i];
		}
		delete m_BlockManager;
	}
	if (m_Player)
		delete m_Player;
}