//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <Windows.h>
//
//#define MAX 1
//#define MIN 0
//#define END 2
//
///*���� ����*/
//void Game(int Range[], int Game_Max_Turn);
//int Setting(int Range[], int Max_Turn);
//
//void Init(int Range[], int Max_Turn) // ���� ȭ��
//{
//	while (1)
//	{
//		int Select;
//		system("cls");
//		printf("===========Up Down===========\n");
//		printf("\t1. ���ӽ���\n");
//		printf("\t2. ���Ӽ���\n");
//		printf("\t3. ��������\n");
//		printf("�Է� : ");
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
//void Game(int Range[], int Game_Max_Turn) //�� ����
//{
//	int present = 1; //���� ��
//	int NUM; // ������ ����
//	int Right_Answer; // ����
//	srand(time(NULL));
//	Right_Answer = (rand() % (Range[MAX] - (Range[MIN] - 1))) + Range[MIN]; // �ִ� �ּ� �ȿ��� ���� ����
//
//	while (Game_Max_Turn >= present)
//	{
//		system("cls");
//		printf("���� : %d ~ %d\n", Range[MIN], Range[MAX]);
//		printf("�ִ� �� �� : %d\n", Game_Max_Turn);
//		printf("========%d��=========\n�Է� : ", present);
//		scanf("%d", &NUM);
//		if (NUM >= Range[MIN] && NUM <= Range[MAX]) // ���� �ȿ���
//		{
//			if (NUM == Right_Answer)
//			{
//				printf("�����Դϴ�!\t�� �� : %d\n", present);
//				system("pause");
//				return;
//			}
//			else if (NUM < Right_Answer) //������
//			{
//				printf("Up!!\n");
//				system("pause");
//			}
//			else if (NUM > Right_Answer) //ũ��
//			{
//				printf("Down!!\n");
//				system("pause");
//			}
//		}
//		else // ���� ���̸�
//		{
//			printf("�������� ������ϴ�. �� �� ����\n");
//			system("pause");
//		}
//		present++;
//	}
//	system("cls");
//	printf("�ִ� �� ������ �� ������ϴ�.\n");
//	system("pause");
//	return;
//}
//
//void RangeLimit_Max(int Range[]) //�ִ� ���� ����
//{
//	int temp;
//	printf("[����] �ּ� %d �ִ� %d.....�ִ� �� ���� : ", Range[MIN], Range[MAX]);
//	scanf("%d", &temp);
//	if (temp > Range[MIN] + 1)
//		Range[MAX] = temp;
//	else
//	{
//		printf("�ִ� ���� ������ ������ϴ�.\n");
//		Sleep(500);
//		RangeLimit_Max(Range);
//	}
//	return;
//}
//
//void RangeLimit_Min(int Range[]) //�ּ� ���� ����
//{
//	int temp;
//	system("cls");
//	printf("[����] : �ּ� %d �ִ� %d.....�ּ� �� ���� : ", Range[MIN], Range[MAX]);
//	scanf("%d", &temp);
//	if (temp < Range[MAX] - 1)
//		Range[MIN] = temp;
//	else
//	{
//		printf("�ּ� ���� ������ ������ϴ�.\n");
//		Sleep(500);
//		RangeLimit_Min(Range);
//	}
//	RangeLimit_Max(Range);
//	return;
//}
//
//int TurnLimit(int Set_Turn) // �ִ� �� �� ����
//{
//	system("cls");
//	printf("[����] : %d.....�ִ� �� �� ���� : ", Set_Turn);
//	scanf("%d", &Set_Turn);
//	return Set_Turn;
//}
//
//int Setting(int Range[], int Max_Turn) //���� �޴�
//{
//	int Setting_Select;
//	while (1)
//	{
//		system("cls");
//		printf("===========���� ����===========\n");
//		printf("\t1. �ִ�, �ּҹ��� ����\n");
//		printf("\t2. �ִ� �� �� ����\n");
//		printf("\t3. ���ư���\n");
//		printf("�Է� : ");
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
//	/*���� ���� ����*/
//	int Range[END];
//	Range[MIN] = 1;
//	Range[MAX] = 100;
//	int Max_Turn = 10;
//
//	Init(Range, Max_Turn);
//}