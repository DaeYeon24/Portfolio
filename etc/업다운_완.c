//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <Windows.h>
//
//#define MAX 1
//#define MIN 0
//#define END 2
//
///*원형 선언*/
//void Game(int Range[], int Game_Max_Turn);
//int Setting(int Range[], int Max_Turn);
//
//void Init(int Range[], int Max_Turn) // 최초 화면
//{
//	while (1)
//	{
//		int Select;
//		system("cls");
//		printf("===========Up Down===========\n");
//		printf("\t1. 게임시작\n");
//		printf("\t2. 게임설정\n");
//		printf("\t3. 게임종료\n");
//		printf("입력 : ");
//		scanf("%d", &Select);
//		switch (Select)
//		{
//		case 1:
//			Game(Range, Max_Turn);
//			break;
//		case 2:
//			Max_Turn = Setting(Range, Max_Turn);
//			break;
//		case 3:
//			return;
//		}
//	}
//}
//
//void Game(int Range[], int Game_Max_Turn) //본 게임
//{
//	int present = 1; //현재 턴
//	int NUM; // 선택할 숫자
//	int Right_Answer; // 정답
//	srand(time(NULL));
//	Right_Answer = (rand() % (Range[MAX] - (Range[MIN] - 1))) + Range[MIN]; // 최대 최소 안에서 정답 생성
//
//	while (Game_Max_Turn >= present)
//	{
//		system("cls");
//		printf("범위 : %d ~ %d\n", Range[MIN], Range[MAX]);
//		printf("최대 턴 수 : %d\n", Game_Max_Turn);
//		printf("========%d턴=========\n입력 : ", present);
//		scanf("%d", &NUM);
//		if (NUM >= Range[MIN] && NUM <= Range[MAX]) // 범위 안에서
//		{
//			if (NUM == Right_Answer)
//			{
//				printf("정답입니다!\t턴 수 : %d\n", present);
//				system("pause");
//				return;
//			}
//			else if (NUM < Right_Answer) //작으면
//			{
//				printf("Up!!\n");
//				system("pause");
//			}
//			else if (NUM > Right_Answer) //크면
//			{
//				printf("Down!!\n");
//				system("pause");
//			}
//		}
//		else // 범위 밖이면
//		{
//			printf("범위에서 벗어났습니다. 턴 수 감소\n");
//			system("pause");
//		}
//		present++;
//	}
//	system("cls");
//	printf("최대 턴 수까지 못 맞췄습니다.\n");
//	system("pause");
//	return;
//}
//
//void RangeLimit_Max(int Range[]) //최대 범위 설정
//{
//	int temp;
//	printf("[현재] 최소 %d 최대 %d.....최대 값 변경 : ", Range[MIN], Range[MAX]);
//	scanf("%d", &temp);
//	if (temp > Range[MIN] + 1)
//		Range[MAX] = temp;
//	else
//	{
//		printf("최대 값이 범위에 벗어났습니다.\n");
//		Sleep(500);
//		RangeLimit_Max(Range);
//	}
//	return;
//}
//
//void RangeLimit_Min(int Range[]) //최소 범위 설정
//{
//	int temp;
//	system("cls");
//	printf("[현재] : 최소 %d 최대 %d.....최소 값 변경 : ", Range[MIN], Range[MAX]);
//	scanf("%d", &temp);
//	if (temp < Range[MAX] - 1)
//		Range[MIN] = temp;
//	else
//	{
//		printf("최소 값이 범위에 벗어났습니다.\n");
//		Sleep(500);
//		RangeLimit_Min(Range);
//	}
//	RangeLimit_Max(Range);
//	return;
//}
//
//int TurnLimit(int Set_Turn) // 최대 턴 수 설정
//{
//	system("cls");
//	printf("[현재] : %d.....최대 턴 값 변경 : ", Set_Turn);
//	scanf("%d", &Set_Turn);
//	return Set_Turn;
//}
//
//int Setting(int Range[], int Max_Turn) //설정 메뉴
//{
//	int Setting_Select;
//	while (1)
//	{
//		system("cls");
//		printf("===========게임 설정===========\n");
//		printf("\t1. 최대, 최소범위 설정\n");
//		printf("\t2. 최대 턴 수 설정\n");
//		printf("\t3. 돌아가기\n");
//		printf("입력 : ");
//		scanf("%d", &Setting_Select);
//		switch (Setting_Select)
//		{
//		case 1:
//			RangeLimit_Min(Range);
//			break;
//		case 2:
//			Max_Turn = TurnLimit(Max_Turn);
//			break;
//		case 3:
//			return Max_Turn;
//		}
//	}
//}
//
//void main()
//{
//	/*최초 게임 설정*/
//	int Range[END];
//	Range[MIN] = 1;
//	Range[MAX] = 100;
//	int Max_Turn = 10;
//
//	Init(Range, Max_Turn);
//}