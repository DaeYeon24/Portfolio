//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <conio.h>
//#include <Windows.h>
//
//// define 선언
//#define X 0
//#define Y 1
//#define NULL 0
//#define WALL 1
//#define CHARACTER 2
//#define STAR 3
//#define START 1
//#define SETTING 2
//#define EXIT 3
//#define EASY 3 // 별 최대 개수 3개
//#define NORMAL 4 // 별 최대 개수 4개
//#define HARD 5 // 별 최대 개수 5개
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
//void Init(int Map[][WIDTH], int Character[]) // 초기 화면
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
//void Reset(int Speed_Standard[][2], int Difficulty) // 게임 끝난 후 원래 속도 회복하는 기능
//{
//	Speed_Standard[STAR_SPEED][GRADE] = 1;
//	Speed_Standard[MAKE_SPEED][GRADE] = 1;
//	if (Difficulty == EASY) // easy 속도 10, 25
//	{
//		Speed_Standard[STAR_SPEED][SPEED] = 10;
//		Speed_Standard[MAKE_SPEED][SPEED] = 25;
//	}
//	else if (Difficulty == NORMAL) // normal 속도 6, 17
//	{
//		Speed_Standard[STAR_SPEED][SPEED] = 4;
//		Speed_Standard[MAKE_SPEED][SPEED] = 13;
//	}
//	else if (Difficulty == HARD) // hard 속도 2, 9
//	{
//		Speed_Standard[STAR_SPEED][SPEED] = 2;
//		Speed_Standard[MAKE_SPEED][SPEED] = 9;
//	}
//}
//
//void Move(int Map[][WIDTH], int Character[])
//{
//	char ch = getch();
//	Map[Character[X]][Character[Y]] = NULL; //현재 캐릭터좌표에널값 넣기
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
//	} // 좌,우 입력에 좌표 바꾸기
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
//				printf("읏");
//			else if (Map[x][y] == STAR)
//				printf("☆");
//			else
//				printf("  ");
//		}
//		printf("\n");
//	}
//	printf("점수 : %d", Score);
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
//	int MakeMax = (rand() % Difficulty) + 1; // 생성되는 별 최대 개수(3, 4, 5)안에서 랜덤
//	for (int i = 0; i < MakeMax; i++)
//	{
//		MakePoint = (rand() % 8) + 1; // 생성되는 좌표 랜덤
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
//	{ // 20점 추가될때마다 그리고 별속도가 1보다 클때
//		Standard[STAR_SPEED][SPEED]--;
//		Standard[STAR_SPEED][GRADE]++;
//	} // 속도가 1이되면 더이상 줄어들지 않는다.
//	if (Score / 20 >= Standard[MAKE_SPEED][GRADE] && Standard[MAKE_SPEED][SPEED] > 3)
//	{ // 20점 추가될때마다 그리고 생성속도가 3보다 클때
//		Standard[MAKE_SPEED][SPEED] -= 2;
//		Standard[MAKE_SPEED][GRADE]++;
//	} // 속도가 3이되면 더이상 줄어들지 않는다.
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
//		{ // LastScore 라는 변수가 생겨서 Speed_Standard 변수가 2차원일 필요가 없어졌음 추후에 수정요망.
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
//	printf("현재 난이도 : ");
//	if (Difficulty == EASY) printf("EASY\n");
//	else if (Difficulty == NORMAL) printf("NORMAL\n");
//	else if (Difficulty == HARD) printf("HARD\n");
//	printf("원하는 난이도를 선택하세요!\n");
//	printf("1. EASY모드\n");
//	printf("2. NORMAL모드\n");
//	printf("3. HARD모드\n");
//	printf("입력 : ");
//	scanf("%d", &temp);
//	Difficulty = temp + 2;
//	return Difficulty;
//}
//
//
//void main()
//{
//	int Character[2]; // 캐릭터 좌표
//	int Map[HEIGHT][WIDTH]; // 맵
//	int Select; // 메뉴 선택
//	int Exit = 1;
//	int Difficulty = EASY; // 기본 난이도 easy
//	int Speed_Standard[2][2] = { { 10, 1 }, { 25, 1 } }; // 기본 별속도, 생성속도 
//	//Speed_Standard[STAR_SPEED][SPEED] = 별 속도 Speed_Standard[STAR_SPEED][GRADE] = 20점마다 나눈 몫과 비교값
//	//Speed_Standard[MAKE_SPEED][SPEED] = 생성 속도 Speed_Standard[MAKE_SPEED][GRADE] = 20점마다 나눈 몫과 비교값
//	while (Exit)
//	{
//		system("cls");
//		printf("====별똥별 피하기====\n");
//		printf("   1. 게임시작\n");
//		printf("   2. 난이도조절\n");
//		printf("   3. 게임종료\n");
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