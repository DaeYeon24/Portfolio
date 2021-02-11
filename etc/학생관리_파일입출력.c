#include <stdio.h> // printf, scanf
#include <stdlib.h> // �����Ҵ�
#include <Windows.h> // cls, pause
#include <string.h> // strcmp

#define MAX 5
#define TRUE 0
#define FALSE 1

typedef struct student // ����ü ����
{
	int number;
	char name[10];
	int age;
	char gender[10];
	int grade;
}st;

void SetStudent(st* Student, int* StudentCount) // �л� ���
{
	int grade_range = FALSE;
	system("cls");
	Student->number = ++(*StudentCount);
	printf("=====%d�� �л� ���======\n", Student->number);
	printf("  �̸� �Է� : ");
	scanf("%s", Student->name);
	printf("  ���� �Է� : ");
	scanf("%d", &Student->age);
	printf("  ���� �Է� : ");
	scanf("%s", Student->gender);
	while (grade_range)
	{
		printf("  �г� �Է�(1~3) : ");
		scanf("%d", &Student->grade);
		if (Student->grade < 1 || Student->grade > 3)
		{
			printf("�г� ������ ������ϴ�.");
			continue;
		}
		else grade_range = TRUE;
	}
}

void ShowStudent(st* Student) // �л� ���� ���
{
	printf("========%s�л�(%d��)=========\n", Student->name, Student->number);
	printf("���� : %d, ���� : %s, �г� : %d\n", Student->age, Student->gender, Student->grade);
	printf("------------------------------\n");
}

void ShowPrint(st** Student, int StudentCount, int Num)
{
	for (int i = 0; i < StudentCount; i++)
		if (Student[i]->grade == Num)
			ShowStudent(Student[i]);
}

void ShowStudent_Grade(st** Student, int StudentCount) // �г� �� ���
{
	system("cls");
	for (int i = 1; i <= 3; i++)
	{
		printf("%d�г�*************************\n", i);
		ShowPrint(Student, StudentCount, i);
		printf("\n");
	}
	system("pause");
}

void Search_Name(st** Student, int StudentCount) // �̸��˻�
{
	char search[10];
	system("cls");
	printf("�˻��� �̸� �Է� : ");
	scanf("%s", search);
	for (int i = 0; i < StudentCount; i++)
		if (strcmp(Student[i]->name, search) == 0)
			ShowStudent(Student[i]);
	system("pause");
}

void Search_Grade(st** Student, int StudentCount) // �г� �˻�
{
	int search;
	system("cls");
	printf("�˻��� �г� �Է�(1~3) : ");
	scanf("%d", &search);
	printf("%d�г�**************\n", search);
	ShowPrint(Student, StudentCount, search);
	system("pause");
}

void Save(st** Student, int StudentCount)
{
	FILE* s = fopen("�л�����.txt", "w");
	for (int i = 0; i < StudentCount; i++)
	{
		fprintf(s, "%s %d %s %d", Student[i]->name, Student[i]->age, Student[i]->gender, Student[i]->grade);
		if (i == StudentCount - 1)
			break;
		fprintf(s, "\n");
	}
	fclose(s);
}

void Load(st** Student, int* StudentCount)
{
	FILE* l = fopen("�л�����.txt", "r");
	if (l == NULL)
	{
		printf("�ҷ��� �л������ �����ϴ�.\n");
		system("pause");
	}
	else
	{
		while (!feof(l))
		{
			if ((*StudentCount) + 1 > MAX)
			{
				printf("�ҷ��� �л��� �ʹ� �����ϴ�. ������ ����.\n");
				system("pause");
				break;
			}
			Student[*StudentCount] = (st*)malloc(sizeof(st));
			fscanf(l, "%s", Student[*StudentCount]->name);
			fscanf(l, "%d", &Student[*StudentCount]->age);
			fscanf(l, "%s", Student[*StudentCount]->gender);
			fscanf(l, "%d", &Student[*StudentCount]->grade);
			Student[*StudentCount]->number = *StudentCount + 1;
			(*StudentCount)++;
		}
		fclose(l);
	}
}

void main()
{
	st* Student_List[MAX];
	int StudentCount = 0;
	int select, search;
	while (1)
	{
		system("cls");
		printf("=====�л��������α׷�====(�� �ο� : %d)\n", StudentCount);
		printf("   1. �л� ���\n   2. �л� ���(��ȣ��)\n   3. �л� ���(�г��)\n   4. �г� �˻�\n");
		printf("   5. �л� �˻�\n   6. ������ �л� ����\n   7. ��ü �л� ����\n   8. �л����� ����\n");
		printf("   9. �л����� ����\n  10. ����\n");
		printf(" �Է� : ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			if (StudentCount + 1 > MAX)
			{
				printf("���� �ʰ�\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (st*)malloc(sizeof(st));
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;
		case 2:
			system("cls");
			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 3:
			ShowStudent_Grade(Student_List, StudentCount);
			break;
		case 4:
			Search_Grade(Student_List, StudentCount);
			break;
		case 5:
			Search_Name(Student_List, StudentCount);
			break;
		case 6:
			printf("%s�л� ���� ����\n", Student_List[--(StudentCount)]->name);
			free(Student_List[StudentCount]);
			Student_List[StudentCount] = NULL;
			system("pause");
			break;
		case 7:
			printf("��ü �л� ���� ����\n");
			while (StudentCount)
			{
				free(Student_List[--StudentCount]);
				Student_List[StudentCount] = NULL;
			}				
			system("pause");
			break;
		case 8:
			Save(Student_List, StudentCount);			
			break;
		case 9:
			Load(Student_List, &StudentCount);
			break;
		case 10:
			while (StudentCount)
				free(Student_List[--StudentCount]);
			return;
		}
	}
}