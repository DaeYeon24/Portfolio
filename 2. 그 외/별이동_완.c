//#include <stdio.h>
//#include <Windows.h>
//#include <conio.h>
//#define STAR 1
//#define STOP 2
//#define RIGHT 1
//#define LEFT -1
//#define HEIGHT 10
//#define WIDTH 10
//
//
//
//void Draw(int Map[][WIDTH])
//{
//	system("cls");
//	for (int y = 0; y < HEIGHT; y++)
//	{
//		for (int x = 0; x < WIDTH; x++)
//		{
//			if (Map[y][x] == STAR || Map[y][x] == STOP)
//				printf("��");
//			else
//				printf("  ");
//		}
//		printf("\n");
//	}
//	printf("�� ���߱� = d");
//}
//
//int Update(int Map[][WIDTH], int Switch)
//{
//	for (int y = 0; y < HEIGHT; y++)
//	{
//		for (int x = 0; x < WIDTH; x++)
//		{
//			if (Map[y][x] == STAR)
//			{
//				if (Switch == RIGHT && x + Switch > 9)
//					Switch = LEFT;
//				else if (Switch == LEFT && x + Switch < 0)
//					Switch = RIGHT;
//
//				Map[y][x] = 0;
//				Map[y][x + Switch] = 1;
//				break;
//			}
//		}
//	}
//	return Switch;
//}
//
////void Update(int Map[][WIDTH], int Switch)
////{
////	for (int y = 0; y < HEIGHT; y++)
////	{
////		for (int x = 0; x < WIDTH; x++)
////		{
////			if (Map[y][x] == STAR)
////			{
////				Map[y][x] = 0;
////				if (x + Switch > 9 || x + Switch < 0)
////					Switch = Switch * (-1);
////				else
////					Map[y][x + Switch] = 1;
////				break;
////			}
////		}
////	}
////}
//
//void Stop(int Map[][WIDTH], int y)
//{
//	for (int x = 0; x < 10; x++)
//	{
//		if (Map[y][x] == STAR)
//		{
//			Map[y][x] = STOP;
//			return;
//		}
//	}
//}
//
//void main()
//{
//	int Mapy = 10;
//	int Switch = RIGHT;
//	int Map[HEIGHT][WIDTH] = { 0 };
//	char ch;
//	for (int y = 0; y < HEIGHT; y++) // �ʱ� ����
//	{
//		for (int x = 0; x < WIDTH; x++)
//		{
//			if (x == 0)
//				Map[y][x] = STAR;
//		}
//	}
//	printf("���� ���ðڽ��ϱ�??\n");
//	system("pause");
//	system("cls");
//	while (1)
//	{
//		Switch = Update(Map, Switch);
//		if (kbhit())
//		{
//			ch = getch();
//			if (ch == 'd' || ch == 'D')
//			{
//				Mapy--;
//				Stop(Map, Mapy);
//			}
//		} // ������Ʈ ��ο� ���� �۵����� ����
//		// 0,0 ���� 10,10���� ���� for���� ������ ��ο� ����
//		// 0,0 ��ο� 0,1 ��ο� �̷� ������
//		Draw(Map);
//		Sleep(100);
//	}
//}