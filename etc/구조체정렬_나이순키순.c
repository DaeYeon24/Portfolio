#include <stdio.h>
#include <Windows.h>

typedef struct people
{
	char name[10];
	int age;
	float height;
}People;

void Setpeople(People* P)
{
	printf("이름 : ");
	scanf("%s", P->name);
	printf("나이 : ");
	scanf("%d", &P->age);
	printf("키 : ");
	scanf("%f", &P->height);
}

void Showpeople(People P)
{
	printf("이름 : %s\n", P.name);
	printf("나이 : %d\n", P.age);
	printf("키 : %.2f\n", P.height);
}

void Sort(People* P)
{
	People temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 4; j++)
		{
			if (P[i].age < P[j].age)
			{
				temp = P[i];
				P[i] = P[j];
				P[j] = temp;
			}
			else if (P[i].age == P[j].age)
			{
				if (P[i].height < P[j].height)
				{
					temp = P[i];
					P[i] = P[j];
					P[j] = temp;
				}
			}
		}
	}
}

void main()
{
	People P[4];
	for (int i = 0; i < 4; i++)
	{
		printf("======%d======\n", i + 1);
		Setpeople(&P[i]);
		printf("==============\n");
	}
	printf("\n정렬 전\n\n");
	system("pause");
	system("cls");
	Sort(P);
	for (int i = 0; i < 4; i++)
	{
		printf("======%d======\n", i + 1);
		Showpeople(P[i]);
		printf("==============\n");
	}
}