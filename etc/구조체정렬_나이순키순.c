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
	printf("�̸� : ");
	scanf("%s", P->name);
	printf("���� : ");
	scanf("%d", &P->age);
	printf("Ű : ");
	scanf("%f", &P->height);
}

void Showpeople(People P)
{
	printf("�̸� : %s\n", P.name);
	printf("���� : %d\n", P.age);
	printf("Ű : %.2f\n", P.height);
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
	printf("\n���� ��\n\n");
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