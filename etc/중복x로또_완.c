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
//	int overlap; // �ߺ� Ȯ��.
//
//	while (1)
//	{
//		system("cls");
//		printf("�ߺ����� LOTTO ��ȣ\n");
//		for (int i = 0; i < LOTTO_NUM;) // i�� 0���� �ƽ����� ����.
//		{
//			overlap = FALSE; // �ߺ� �ƴ�.
//			Rnum = (rand() % 6) + 1; // ���� �� ����.
//			for (int j = 0; j < i; j++) // j�� 0���� i���� ����.
//			{
//				if (Rnum == Lotto[j]) // Rnum�� Lotto[j]�� �������
//					overlap = TRUE;
//			}
//			if (overlap != TRUE)
//			{
//				Lotto[i] = Rnum;
//				i++;
//			}
//		}
//		for (int i = 0; i < LOTTO_NUM; i++)
//			printf("%d��° ���� : %d\n", i + 1, Lotto[i]);
//		system("pause");
//	}
//}