//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <Windows.h>
//
//#define ONCE 1
//#define SET 2
//#define EXIT 3
//
//void Class(int Probability)
//{
//	if (Probability >= 1 && Probability <= 60)
//		printf("�� 1��\n");
//	else if (Probability > 60 && Probability <= 80)
//		printf("�١� 2��\n");
//	else if (Probability > 80 && Probability <= 90)
//		printf("�١١� 3��\n");
//	else if (Probability > 90 && Probability <= 95)
//		printf("�١١١� 4��\n");
//	else if (Probability > 95 && Probability <= 99)
//		printf("�١١١١� 5��\n");
//	else if (Probability == 100)
//		printf("�١١١١١� 6��\n");
//	return;
//}
//
//void Once_Gambling()
//{
//	int Probability;
//	Probability = (rand() % 100) + 1;
//	Class(Probability);
//	return;
//}
//
//void Set_Gambling()
//{
//	int Probability;
//	for (int i = 0; i < 10; i++)
//	{
//		Probability = (rand() % 100) + 1;
//		Class(Probability);
//	}
//	return;
//}
//
//
//void main()
//{
//	int Game_Clear = 1;
//	srand(time(NULL));
//	while (Game_Clear)
//	{
//		int Select;
//		system("cls");
//		printf("===========�̱� ����===========\n");
//		printf("\t1. �̱� 1ȸ\n");
//		printf("\t2. �̱� 10+1ȸ\n");
//		printf("\t3. ����\n");
//		scanf("%d", &Select);
//		switch (Select)
//		{
//		case ONCE:
//			Once_Gambling();
//			break;
//		case SET:
//			Set_Gambling();
//			break;
//		case EXIT:
//			Game_Clear = 0;
//			break;
//		}
//		system("pause");
//	}
//}