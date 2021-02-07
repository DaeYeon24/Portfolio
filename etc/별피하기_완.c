//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <conio.h>
//#include <Windows.h>
//
//// define ����
//#define X 0
//#define Y 1
//#define NULL 0
//#define WALL 1
//#define CHARACTER 2
//#define STAR 3
//#define START 1
//#define SETTING 2
//#define EXIT 3
//#define EASY 3 // �� �ִ� ���� 3��
//#define NORMAL 4 // �� �ִ� ���� 4��
//#define HARD 5 // �� �ִ� ���� 5��
//#define LEFT 97 
//#define RIGHT 100
//#define WIDTH 10
//#define HEIGHT 20
//#define STAR_SPEED 0
//#define MAKE_SPEED 1
//#define SPEED 0
//#define GRADE 1
//#define ZERO 0
//#define TRUE 1
//#define FALSE 0
//
//void Init(int Map[][WIDTH], int Character[]) // �ʱ� ȭ��
//{
//	for (int x = 0; x < HEIGHT; x++)
//	{
//		for (int y = 0; y < WIDTH; y++)
//		{
//			if (y == 0 || y == WIDTH - 1)
//				Map[x][y] = WALL;
//			else
//				Map[x][y] = NULL;
//		}
//	}
//	Character[X] = HEIGHT - 1;
//	Character[Y] = (WIDTH / 2) - 1;
//	Map[Character[X]][Character[Y]] = CHARACTER;
//}
//
//void Reset(int Speed_Standard[][2], int Difficulty) // ���� ���� �� ���� �ӵ� ȸ���ϴ� ���
//{
//	Speed_Standard[STAR_SPEED][GRADE] = 1;
//	Speed_Standard[MAKE_SPEED][GRADE] = 1;
//	if (Difficulty == EASY) // easy �ӵ� 10, 25
//	{
//		Speed_Standard[STAR_SPEED][SPEED] = 10;
//		Speed_Standard[MAKE_SPEED][SPEED] = 25;
//	}
//	else if (Difficulty == NORMAL) // normal �ӵ� 6, 17
//	{
//		Speed_Standard[STAR_SPEED][SPEED] = 4;
//		Speed_Standard[MAKE_SPEED][SPEED] = 13;
//	}
//	else if (Difficulty == HARD) // hard �ӵ� 2, 9
//	{
//		Speed_Standard[STAR_SPEED][SPEED] = 2;
//		Speed_Standard[MAKE_SPEED][SPEED] = 9;
//	}
//}
//
//void Move(int Map[][WIDTH], int Character[])
//{
//	char ch = getch();
//	Map[Character[X]][Character[Y]] = NULL; //���� ĳ������ǥ���ΰ� �ֱ�
//	switch (ch)
//	{
//	case LEFT:
//		if (Map[Character[X]][Character[Y] - 1] != WALL)
//			Character[Y]--;
//		break;
//	case RIGHT:
//		if (Map[Character[X]][Character[Y] + 1] != WALL)
//			Character[Y]++;
//		break;
//	} // ��,�� �Է¿� ��ǥ �ٲٱ�
//	Map[Character[X]][Character[Y]] = CHARACTER;
//}
//
//void MapDraw(int Map[][WIDTH], int Score, int Difficulty)
//{
//	system("cls");
//	if (Difficulty == EASY) printf("=======easy=======\n");
//	else if (Difficulty == NORMAL) printf("======normal======\n");
//	else if (Difficulty == HARD) printf("=======hard=======\n");
//	for (int x = 0; x < HEIGHT; x++)
//	{
//		for (int y = 0; y < WIDTH; y++)
//		{
//			if (Map[x][y] == WALL)
//				printf("|");
//			else if (Map[x][y] == CHARACTER)
//				printf("��");
//			else if (Map[x][y] == STAR)
//				printf("��");
//			else
//				printf("  ");
//		}
//		printf("\n");
//	}
//	printf("���� : %d", Score);
//}
//
//int ScoreCheck(int Map[][WIDTH], int Score)
//{
//	for (int i = 0; i < WIDTH; i++)
//	{
//		if (Map[HEIGHT - 1][i] == STAR)
//		{
//			Map[HEIGHT - 1][i] = NULL;
//			Score++;
//		}
//	}
//	return Score;
//}
//
//void MakeStar(int Map[][WIDTH], int Difficulty)
//{
//	int MakePoint;
//	int MakeMax = (rand() % Difficulty) + 1; // �����Ǵ� �� �ִ� ����(3, 4, 5)�ȿ��� ����
//	for (int i = 0; i < MakeMax; i++)
//	{
//		MakePoint = (rand() % 8) + 1; // �����Ǵ� ��ǥ ����
//		Map[0][MakePoint] = STAR;
//	}
//}
//
//int Falling(int Map[][WIDTH])
//{
//	for (int x = HEIGHT - 1; x >= 0; x--)
//	{
//		for (int y = 0; y < WIDTH; y++)
//		{
//			if (Map[x][y] == STAR)
//			{
//				Map[x][y] = NULL;
//				if (Map[x + 1][y] == CHARACTER)
//					return 0;
//				else if (x + 1 < HEIGHT)
//					Map[x + 1][y] = STAR;
//			}
//		}
//	}
//}
//
//void Upgrade(int Standard[][2], int Score)
//{
//	if (Score / 20 >= Standard[STAR_SPEED][GRADE] && Standard[STAR_SPEED][SPEED] > 1)
//	{ // 20�� �߰��ɶ����� �׸��� ���ӵ��� 1���� Ŭ��
//		Standard[STAR_SPEED][SPEED]--;
//		Standard[STAR_SPEED][GRADE]++;
//	} // �ӵ��� 1�̵Ǹ� ���̻� �پ���� �ʴ´�.
//	if (Score / 20 >= Standard[MAKE_SPEED][GRADE] && Standard[MAKE_SPEED][SPEED] > 3)
//	{ // 20�� �߰��ɶ����� �׸��� �����ӵ��� 3���� Ŭ��
//		Standard[MAKE_SPEED][SPEED] -= 2;
//		Standard[MAKE_SPEED][GRADE]++;
//	} // �ӵ��� 3�̵Ǹ� ���̻� �پ���� �ʴ´�.
//}
//
//void Game(int Map[][WIDTH], int Character[], int Speed_Standard[][2], int Difficulty)
//{
//	srand(time(NULL));
//	int Game_Clear = 1;
//	int Score = 0;
//	int LastScore = 1;
//	int DrawAnswer = FALSE;
//	int Star_Speed = Speed_Standard[STAR_SPEED][SPEED];
//	int Make_Speed = Speed_Standard[MAKE_SPEED][SPEED];
//	system("cls");
//	Init(Map, Character);
//	while (Game_Clear)
//	{ 
//		Score = ScoreCheck(Map, Score);
//		if (Score >= 1 && Score / 20 >= LastScore)
//		{ // LastScore ��� ������ ���ܼ� Speed_Standard ������ 2������ �ʿ䰡 �������� ���Ŀ� �������.
//			Upgrade(Speed_Standard, Score);
//			LastScore++;
//		}			
//		if (Make_Speed <= ZERO)
//		{
//			Make_Speed = Speed_Standard[MAKE_SPEED][SPEED];
//			MakeStar(Map, Difficulty);
//			DrawAnswer = TRUE;
//		}
//		if (Star_Speed <= ZERO)
//		{
//			Star_Speed = Speed_Standard[STAR_SPEED][SPEED];
//			Game_Clear = Falling(Map);
//			DrawAnswer = TRUE;
//		}
//		if (kbhit())
//		{
//			Move(Map, Character);
//			DrawAnswer = TRUE;
//		}
//		if (DrawAnswer == TRUE)
//			MapDraw(Map, Score, Difficulty);
//		Star_Speed--;
//		Make_Speed--;
//		DrawAnswer = FALSE;
//		Sleep(10);
//	}
//}
//
//int Setting(int Difficulty)
//{
//	int temp;
//	system("cls");
//	printf("���� ���̵� : ");
//	if (Difficulty == EASY) printf("EASY\n");
//	else if (Difficulty == NORMAL) printf("NORMAL\n");
//	else if (Difficulty == HARD) printf("HARD\n");
//	printf("���ϴ� ���̵��� �����ϼ���!\n");
//	printf("1. EASY���\n");
//	printf("2. NORMAL���\n");
//	printf("3. HARD���\n");
//	printf("�Է� : ");
//	scanf("%d", &temp);
//	Difficulty = temp + 2;
//	return Difficulty;
//}
//
//
//void main()
//{
//	int Character[2]; // ĳ���� ��ǥ
//	int Map[HEIGHT][WIDTH]; // ��
//	int Select; // �޴� ����
//	int Exit = 1;
//	int Difficulty = EASY; // �⺻ ���̵� easy
//	int Speed_Standard[2][2] = { { 10, 1 }, { 25, 1 } }; // �⺻ ���ӵ�, �����ӵ� 
//	//Speed_Standard[STAR_SPEED][SPEED] = �� �ӵ� Speed_Standard[STAR_SPEED][GRADE] = 20������ ���� ��� �񱳰�
//	//Speed_Standard[MAKE_SPEED][SPEED] = ���� �ӵ� Speed_Standard[MAKE_SPEED][GRADE] = 20������ ���� ��� �񱳰�
//	while (Exit)
//	{
//		system("cls");
//		printf("====���˺� ���ϱ�====\n");
//		printf("   1. ���ӽ���\n");
//		printf("   2. ���̵�����\n");
//		printf("   3. ��������\n");
//		scanf("%d", &Select);
//		switch (Select)
//		{
//		case START:
//			Game(Map, Character, Speed_Standard, Difficulty);
//			break;
//		case SETTING:
//			Difficulty = Setting(Difficulty);
//			break;
//		case EXIT:
//			Exit = 0;
//			break;
//		}
//		Reset(Speed_Standard, Difficulty);
//		system("pause");
//	}
//}