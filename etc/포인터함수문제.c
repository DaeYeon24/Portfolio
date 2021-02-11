#include <stdio.h>

#define MAX 5

void ConverToUpper(char* str)
{
	for (int i = 0; ; i++)
	{
		if (*(str + i) == NULL)
			break;
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
			*(str + i) -= 32;
	}
}

void Bigger(int* Max, int* Min)
{
	if (*Max < *Min)
		*Max = *Min;
}

void Gauss(int* Num, int * Sum)
{
	for (int i = 1; i <= *Num; i++)
	{
		*Sum = *Sum + i;
	}
}

void DoAlignment(int Alignment[])
{
	int temp;
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i; j < MAX; j++)
		{
			if (Alignment[i] >= Alignment[j])
			{
				temp = Alignment[i];
				Alignment[i] = Alignment[j];
				Alignment[j] = temp;
			}
		}
	}
}

void main()
{
	char problem_one[50];
	int problem_two_max, problem_two_min;
	int problem_three;
	int sum = 0;
	int Alignment[MAX];

	printf("1. ���ڿ��� �Է��ϼ��� : ");
	gets(problem_one);
	printf("�Լ� ȣ�� �� = %s\n", problem_one);
	ConverToUpper(problem_one);
	printf("�Լ� ȣ�� �� = %s\n\n", problem_one); // 1����
	printf("2. �� ������ �Է��ϼ��� : ");
	scanf("%d%d", &problem_two_max, &problem_two_min);
	printf("%d�� %d�� ū ���� ", problem_two_max, problem_two_min);
	Bigger(&problem_two_max, &problem_two_min);
	printf("%d\n\n", problem_two_max); // 2�� ��
	printf("3. ������ �Է��ϼ��� : ");
	scanf("%d", &problem_three);
	printf("1 ~ %d�� �� �� : ", problem_three);
	Gauss(&problem_three, &sum);
	printf("%d\n\n", sum); // 3�� ��
	printf("4. �������� ����\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("[%d]��° ���� �Է� : ", i + 1);
		scanf("%d", &Alignment[i]);
	}
	printf("���� �� : %d %d %d %d %d\n", Alignment[0], Alignment[1], Alignment[2], Alignment[3], Alignment[4]);
	DoAlignment(Alignment);
	printf("���� �� : %d %d %d %d %d\n", Alignment[0], Alignment[1], Alignment[2], Alignment[3], Alignment[4]);
	getch();
}