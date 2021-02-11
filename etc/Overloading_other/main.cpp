#include "quiz.h"

void main()
{
	quiz Q;
	int iNum1;
	int iNum2;
	char chLetter; // 1번
	char charrChar[MAX];
	string strString1;
	string strString2; // 2번
	int iarrNum[5];
	char charrLetter[5]; // 3번
	cout << "1-1. 정수 2개 입력 :";
	while (1)
	{
		cin >> iNum1 >> iNum2;
		if (iNum2 < 1)
		{
			cout << "제곱수가 1보다 작습니다." << endl;
			continue;
		}
		else
		{
			Q.Quiz1(iNum1, iNum2);
			break;
		}			
	}
	cout << "1-2. 단일문자와 정수 입력 : ";
	cin >> chLetter >> iNum1;
	Q.Quiz1(chLetter, iNum1);
	cout << "2-1. 문자열 하나 입력 : ";
	cin >> charrChar;
	Q.Quiz2(charrChar);
	cout << "2-2. 문자열 두개 입력 : ";
	cin >> strString1 >> strString2;
	Q.Quiz2(strString1, strString2);
	cout << "3-1. 숫자 5개 입력 : ";
	cin >> iarrNum[0] >> iarrNum[1] >> iarrNum[2] >> iarrNum[3] >> iarrNum[4];
	Q.Quiz3(iarrNum);
	cout << "3-2. 단일문자 5개 입력 : ";
	cin >> charrLetter[0] >> charrLetter[1] >> charrLetter[2] >> charrLetter[3] >> charrLetter[4];
	Q.Quiz3(charrLetter);
	system("pause");
}