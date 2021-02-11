#include <stdio.h>
#include <string.h>

#define MAX 50

int StrCmp(char str1[], char str2[])
{
	for (int i = 0; ; i++)
	{
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] < str2[i])
			return -1;
		else if (str1[i] == NULL && str2[i] == NULL)
			return 0;
	}
}

void main()
{
	char str1[10] = "String";
	char str2[10] = "String";

	printf("%s == %s : %d\n", str1, str2, StrCmp(str1, str2));
	//printf("%s == %s : %d\n", "abc", "abc", strcmp("abc", "abc"));
	//printf("%s == %s : %d\n", "adf", "awe", strcmp("adf", "awe"));
}

//void StrCat(char Original[], char Add[])
//{
//	int Count;
//	for (Count = 0; ; Count++)
//		if (Original[Count] == NULL)
//			break;
//	for (int i = 0; ; i++)
//	{
//		Original[Count] = Add[i];
//		Count++;
//		if (Add[i] == NULL)
//			break;
//	}
//}

//void StrCpy(char Copy[], char Original[])
//{
//	for (int i = 0; ; i++)
//	{
//		Copy[i] = Original[i];
//		if (Original[i] == NULL)
//			break;
//	}	
//}

//void Strlen(char str[MAX])
//{
//	int Count = 0;
//
//	while (str[Count])
//	{
//		if (str[Count] == NULL)
//			break;
//		Count++;
//	}
//	printf("입력한 문자열 %s의 길이는 %d\n", str, Count);
//}