//#include <stdio.h>	
//#include <stdlib.h>
//#include <time.h>
//#define LOTTO_NUM 6
//#define TRUE 1
//#define FALSE 0
//
//void main()
//{
//	int Rnum;
//	int Lotto[LOTTO_NUM] = { 0 };
//	srand(time(NULL));
//	int overlap; // 중복 확인.
//
//	while (1)
//	{
//		system("cls");
//		printf("중복없는 LOTTO 번호\n");
//		for (int i = 0; i < LOTTO_NUM;) // i가 0부터 맥스까지 증가.
//		{
//			overlap = FALSE; // 중복 아님.
//			Rnum = (rand() % 6) + 1; // 랜덤 수 생성.
//			for (int j = 0; j < i; j++) // j가 0부터 i까지 증가.
//			{
//				if (Rnum == Lotto[j]) // Rnum이 Lotto[j]와 같을경우
//					overlap = TRUE;
//			}
//			if (overlap != TRUE)
//			{
//				Lotto[i] = Rnum;
//				i++;
//			}
//		}
//		for (int i = 0; i < LOTTO_NUM; i++)
//			printf("%d번째 숫자 : %d\n", i + 1, Lotto[i]);
//		system("pause");
//	}
//}