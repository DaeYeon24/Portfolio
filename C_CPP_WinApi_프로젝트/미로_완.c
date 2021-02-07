#include<stdio.h>
#include<conio.h> //getch()
#include<Windows.h> //system("cls"),system("pause")
//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//���� ����
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////
#define WALL 1 // ��
#define NULL 0 // �����
#define X 0
#define Y 1
#define CHARACTER 2
#define POTAL_MAX 4//��Ż ����
#define ENTRY_START 10 //��Ż ������ŭ 10, 11, 12, 13 (4��)
#define EXIT_START 20 //�������� 20, 21, 22, 23 (4��)
#define COMMAND_MAX 3 // Ŀ�ǵ� ����
#define COMMAND_START 30 // Ŀ�ǵ��Է� ���� ��ȣ
#define COMMAND_EXIT_START 40 // Ŀ�ǵ� Ż�� ���� ��ȣ
#define STAR_MAX 5 // ���� ����
#define STAR_START 50 // ���� ���۹�ȣ
#define LEFT 75 // ������ �����¿�
#define RIGHT 77 // ������ �����¿�
#define UP 72 // ������ �����¿�
#define DOWN 80 // ������ �����¿�
#define WIDTH 20
#define HEIGHT 20
#define EXIT 90 // ��

int map[HEIGHT][WIDTH] = { //�� ����
  { 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 },
  { 2,  0,  0,  0,  1,  1,  0,  0,  0,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  1 },
  { 1,  1,  1,  0,  1,  1,  0,  1,  0,  1,  31,  0,  0,  0,  0,  0,  1,  1,  20, 1 },
  { 1, 10,  1,  0,  0,  0,  0,  1,  0,  1,  41,  1,  1,  1,  1,  1,  1,  1,  1,  1 },
  { 1,  0,  1,  1,  1,  1,  1,  1,  0,  1,  0,  1,  1,  1,  0,  32,  42,  0,  0,  1 },
  { 1,  0,  0,  0, 40, 30,  0,  0,  0, 1, 11, 1, 21,  0,  0,  1,  1,  1,  0, 12 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1 },
  { 1,  1,  0,  0,  0,  0,  0,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1 },
  { 22, 100,  0,  1,  1,  1,  0,  0,  0,  0,  1,  1,  0,  1,  1,  0,  1,  1,  101, 13 },
  { 1,  1,  0,  1,  0,  1,  1,  0,  1,  0,  1,  0,  0,  0,  1,  0,  0,  0,  0,  1 },
  { 1,  1,  0,  1,  0,  1,  1,  0,  0,  0,  1,  1,  1,  0,  1,  0,  1,  1,  1,  1 },
  { 1,  1,  0,  0,  0,  1,  1,  0,  1,  0,  0,  0,  0,  0,  1,  0,  0 , 0 , 1,  1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1,  0,  0,  50, 1,  1,  0,  0,  0,  0,  53,  0,  0,  0,  0,  0,  0,  0,  1,  1 },
  { 1,  0,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1,  1,  0,  1,  1 },
  { 1,  0,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,  0,  54,  0,  1,  1 },
  { 1,  0,  1,  51,  0,  0,  0,  0,  52,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1 },
  { 23, 0,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  90 },
  { 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 } };
int character[2];
int Entry_Potal[POTAL_MAX][2]; //[0] x ��ǥ [1] y ��ǥ ���� ����
int Exit_Potal[POTAL_MAX][2];
int Command_Potal[COMMAND_MAX][2];
int Command_Exit[COMMAND_MAX][2];
int Star[STAR_MAX][2];
int LastObjectIndex = NULL;
int Transparent_flag = 0; // ���� ����
int Star_flag[STAR_MAX] = { 0 }; // ���� ���� 0���� �ʱ�ȭ.
int Star_Count = 0; // ���� ���� ����
int GameFinish = 1; // ���� �Ϸ� ����
int CommandAnswer[3][3];
int Command_flag[COMMAND_MAX] = { 0 };
int reset_flag = 0;

void Init()
{
    int Width = (WIDTH * 2) + 2;
    int Height = HEIGHT + 5;
    char buf[256];
    sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
    system(buf);
    for (int x = 0; x < HEIGHT; x++)
    {
        for (int y = 0; y < WIDTH; y++)
        {
            if (map[x][y] == CHARACTER)
            {
                character[X] = x;
                character[Y] = y;
            }
            else if (map[x][y] >= COMMAND_START && map[x][y] < COMMAND_START + COMMAND_MAX)
            {
                Command_Potal[map[x][y] - COMMAND_START][X] = x;
                Command_Potal[map[x][y] - COMMAND_START][Y] = y;
            }
            else if (map[x][y] >= COMMAND_EXIT_START && map[x][y] < COMMAND_EXIT_START + COMMAND_MAX)
            {
                Command_Exit[map[x][y] - COMMAND_EXIT_START][X] = x;
                Command_Exit[map[x][y] - COMMAND_EXIT_START][Y] = y;
            }
            else if (map[x][y] >= ENTRY_START && map[x][y] < ENTRY_START + POTAL_MAX)
            {
                Entry_Potal[map[x][y] - ENTRY_START][X] = x;
                Entry_Potal[map[x][y] - ENTRY_START][Y] = y;
            }
            else if (map[x][y] >= EXIT_START && map[x][y] < EXIT_START + POTAL_MAX)
            {
                Exit_Potal[map[x][y] - EXIT_START][X] = x;
                Exit_Potal[map[x][y] - EXIT_START][Y] = y;
            }
            else if (map[x][y] >= STAR_START && map[x][y] < STAR_START + STAR_MAX)
            {
                Star[map[x][y] - STAR_START][X] = x;
                Star[map[x][y] - STAR_START][Y] = y;
            }
        }
    }
    CommandAnswer[0][0] = LEFT;
    CommandAnswer[0][1] = RIGHT;
    CommandAnswer[0][2] = LEFT;

    CommandAnswer[1][0] = UP;
    CommandAnswer[1][1] = DOWN;
    CommandAnswer[1][2] = LEFT;

    CommandAnswer[2][0] = LEFT;
    CommandAnswer[2][1] = LEFT;
    CommandAnswer[2][2] = UP;
}

void MapDraw()
{
    system("cls");
    for(int x =0;x <HEIGHT;x++)
    {
        for (int y = 0; y < WIDTH; y++)
        {
            if (map[x][y] == WALL)
                printf("��");
            else if (map[x][y] == CHARACTER && Transparent_flag == 0)
            {
                RED
                    printf("��");
                ORIGINAL
            }
            else if (map[x][y] >= ENTRY_START && map[x][y] < ENTRY_START + POTAL_MAX)
            {
                BLUE
                    printf("��");
                ORIGINAL
            }
            else if (map[x][y] >= COMMAND_START && map[x][y] < COMMAND_START + COMMAND_MAX)
            {
                PUPPLE
                    printf("��");
                ORIGINAL
            }
            else if (map[x][y] >= EXIT_START && map[x][y] < EXIT_START + POTAL_MAX)
            {
                YELLOW
                    printf("��");
                ORIGINAL
            }
            else if (map[x][y] >= STAR_START && map[x][y] < STAR_START + STAR_MAX && Star_flag[map[x][y] - STAR_START] == 0)
            {
                GOLD
                    printf("��");
                ORIGINAL
            }
            else printf("  ");
        }
        printf("\n");
    }
    BLUE printf("�Ա� : ��\t\t");
    YELLOW printf("�ⱸ : ��\n");
    PUPPLE printf("Ŀ�ǵ� : @\t\t");
    GOLD printf("�� : ��\n");
    ORIGINAL
}

void AllowDraw(char check)
{
    switch (check)
    {
    case LEFT:
        printf("��...");
        break;
    case RIGHT:
        printf("��...");
        break;
    case UP:
        printf("��...");
        break;
    case DOWN:
        printf("��...");
        break;
    }
}

void CommandCheck_Step(int index)
{
    char check;
    int Life_Count = 5; // ���� 5��
    int Next = 0;
    index = index - COMMAND_START;
    system("cls");
    printf("Ŀ�ǵ� �Է� : ");
    while (1) 
    {
        check = getch();
        if (check == -32) 
            check = getch();
            if (CommandAnswer[index][Next] == check)
            {
                
                AllowDraw(check);
                Next++;
                if (Next == 3)
                {
                    printf("���!!");
                    Command_flag[index] = 1;
                    reset_flag = 0;
                    Sleep(500);
                    return;
                }
            }            
            else if (CommandAnswer[index][Next] != check)
            {
                printf("x");
                Life_Count--;
                if (Life_Count == 0) {
                    system("cls");
                    printf("���� ����");
                    reset_flag = 1;
                    Sleep(1000);
                    return;
                }
                continue;
            }
     }
}

void StarCheck(int index)
{
    index = index - STAR_START;
    Star_Count++;
    Star_flag[index] = 1;
}

void ExitCheck()
{   
        int Star_Eat;
        system("cls");
        printf("���� ���� ������? ");
        scanf("%d", &Star_Eat);
        if (Star_Eat == Star_Count)
        {
            GameFinish = 0;
        }
}

void MoveCheck()
{
    int index = map[character[X]][character[Y]];
    if (index == 100) Transparent_flag = 1;
    if (index == 101) Transparent_flag = 0;
    if (index >= ENTRY_START && index < ENTRY_START + POTAL_MAX)
    {
        character[X] = Exit_Potal[index - ENTRY_START][X];
        character[Y] = Exit_Potal[index - ENTRY_START][Y];
    }
    if (index >= COMMAND_START && index < COMMAND_START + COMMAND_MAX && Command_flag[index - COMMAND_START] == 0)
    {
        CommandCheck_Step(index);
        if (reset_flag == 1) {
            character[X] = 1;
            character[Y] = 0;
            for (int i = 0; i < COMMAND_MAX; i++) {
                Command_flag[i] = 0;
            }
        }
        else {
            character[X] = Command_Exit[index - COMMAND_START][X];
            character[Y] = Command_Exit[index - COMMAND_START][Y];
        }
    }
    if (index >= STAR_START && index < STAR_START + STAR_MAX && Star_flag[index - STAR_START] == 0)
    {
        StarCheck(index);
    }
    if (index == EXIT)
    {
        ExitCheck();
    }
}

void Move()
{
    char ch;
    ch = getch();
    system("cls");
    map[character[X]][character[Y]] = LastObjectIndex;
    switch (ch)
    {
    case LEFT:
        if (map[character[X]][character[Y] - 1] != WALL)
            character[Y]--;
        break;
    case RIGHT:
        if (map[character[X]][character[Y] + 1] != WALL)
            character[Y]++;
        break;
    case UP:
        if (map[character[X] - 1][character[Y]] != WALL)
            character[X]--;
        break;
    case DOWN:
        if (map[character[X] + 1][character[Y]] != WALL)
            character[X]++;
        break;
    }
    MoveCheck();
    LastObjectIndex = map[character[X]][character[Y]];
    map[character[X]][character[Y]] = CHARACTER;
}

void main()
{
    //while (1) 
    //{
        Init();
        while (GameFinish)
        {
            MapDraw();
            Move();
        }
        system("cls");
        printf("����!\nŻ�⼺��!!");
    //}

}