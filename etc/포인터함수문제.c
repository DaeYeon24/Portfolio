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

	printf("1. 문자열을 입력하세요 : ");
	gets(problem_one);
	printf("함수 호출 전 = %s\n", problem_one);
	ConverToUpper(problem_one);
	printf("함수 호출 후 = %s\n\n", problem_one); // 1번끝
	printf("2. 두 정수를 입력하세요 : ");
	scanf("%d%d", &problem_two_max, &problem_two_min);
	printf("%d와 %d중 큰 수는 ", problem_two_max, problem_two_min);
	Bigger(&problem_two_max, &problem_two_min);
	printf("%d\n\n", problem_two_max); // 2번 끝
	printf("3. 정수를 입력하세요 : ");
	scanf("%d", &problem_three);
	printf("1 ~ %d의 총 합 : ", problem_three);
	Gauss(&problem_three, &sum);
	printf("%d\n\n", sum); // 3번 끝
	printf("4. 오름차순 정렬\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("[%d]번째 정수 입력 : ", i + 1);
		scanf("%d", &Alignment[i]);
	}
	printf("정렬 전 : %d %d %d %d %d\n", Alignment[0], Alignment[1], Alignment[2], Alignment[3], Alignment[4]);
	DoAlignment(Alignment);
	printf("정렬 후 : %d %d %d %d %d\n", Alignment[0], Alignment[1], Alignment[2], Alignment[3], Alignment[4]);
	getch();
}