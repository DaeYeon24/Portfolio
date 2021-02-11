#include <stdio.h> // printf, scanf
#include <stdlib.h> // 동적할당
#include <Windows.h> // cls, pause
#include <string.h> // strcmp

#define MAX 5
#define TRUE 0
#define FALSE 1

typedef struct student // 구조체 정의
{
	int number;
	char name[10];
	int age;
	char gender[10];
	int grade;
}st;

void SetStudent(st* Student, int* StudentCount) // 학생 등록
{
	int grade_range = FALSE;
	system("cls");
	Student->number = ++(*StudentCount);
	printf("=====%d번 학생 등록======\n", Student->number);
	printf("  이름 입력 : ");
	scanf("%s", Student->name);
	printf("  나이 입력 : ");
	scanf("%d", &Student->age);
	printf("  성별 입력 : ");
	scanf("%s", Student->gender);
	while (grade_range)
	{
		printf("  학년 입력(1~3) : ");
		scanf("%d", &Student->grade);
		if (Student->grade < 1 || Student->grade > 3)
		{
			printf("학년 범위를 벗어났습니다.");
			continue;
		}
		else grade_range = TRUE;
	}
}

void ShowStudent(st* Student) // 학생 정보 출력
{
	printf("========%s학생(%d번)=========\n", Student->name, Student->number);
	printf("나이 : %d, 성별 : %s, 학년 : %d\n", Student->age, Student->gender, Student->grade);
	printf("------------------------------\n");
}

void ShowPrint(st** Student, int StudentCount, int Num)
{
	for (int i = 0; i < StudentCount; i++)
		if (Student[i]->grade == Num)
			ShowStudent(Student[i]);
}

void ShowStudent_Grade(st** Student, int StudentCount) // 학년 순 출력
{
	system("cls");
	for (int i = 1; i <= 3; i++)
	{
		printf("%d학년*************************\n", i);
		ShowPrint(Student, StudentCount, i);
		printf("\n");
	}
	system("pause");
}

void Search_Name(st** Student, int StudentCount) // 이름검색
{
	char search[10];
	system("cls");
	printf("검색할 이름 입력 : ");
	scanf("%s", search);
	for (int i = 0; i < StudentCount; i++)
		if (strcmp(Student[i]->name, search) == 0)
			ShowStudent(Student[i]);
	system("pause");
}

void Search_Grade(st** Student, int StudentCount) // 학년 검색
{
	int search;
	system("cls");
	printf("검색할 학년 입력(1~3) : ");
	scanf("%d", &search);
	printf("%d학년**************\n", search);
	ShowPrint(Student, StudentCount, search);
	system("pause");
}

void Save(st** Student, int StudentCount)
{
	FILE* s = fopen("학생정보.txt", "w");
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
	FILE* l = fopen("학생정보.txt", "r");
	if (l == NULL)
	{
		printf("불러올 학생명단이 없습니다.\n");
		system("pause");
	}
	else
	{
		while (!feof(l))
		{
			if ((*StudentCount) + 1 > MAX)
			{
				printf("불러올 학생이 너무 많습니다. 정원만 받음.\n");
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
		printf("=====학생관리프로그램====(총 인원 : %d)\n", StudentCount);
		printf("   1. 학생 등록\n   2. 학생 목록(번호순)\n   3. 학생 목록(학년순)\n   4. 학년 검색\n");
		printf("   5. 학생 검색\n   6. 마지막 학생 삭제\n   7. 전체 학생 삭제\n   8. 학생정보 저장\n");
		printf("   9. 학생정보 열기\n  10. 종료\n");
		printf(" 입력 : ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			if (StudentCount + 1 > MAX)
			{
				printf("정원 초과\n");
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
			printf("%s학생 정보 삭제\n", Student_List[--(StudentCount)]->name);
			free(Student_List[StudentCount]);
			Student_List[StudentCount] = NULL;
			system("pause");
			break;
		case 7:
			printf("전체 학생 정보 삭제\n");
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