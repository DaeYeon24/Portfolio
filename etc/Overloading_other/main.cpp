#include "quiz.h"

void main()
{
	quiz Q;
	int iNum1;
	int iNum2;
	char chLetter; // 1��
	char charrChar[MAX];
	string strString1;
	string strString2; // 2��
	int iarrNum[5];
	char charrLetter[5]; // 3��
	cout << "1-1. ���� 2�� �Է� :";
	while (1)
	{
		cin >> iNum1 >> iNum2;
		if (iNum2 < 1)
		{
			cout << "�������� 1���� �۽��ϴ�." << endl;
			continue;
		}
		else
		{
			Q.Quiz1(iNum1, iNum2);
			break;
		}			
	}
	cout << "1-2. ���Ϲ��ڿ� ���� �Է� : ";
	cin >> chLetter >> iNum1;
	Q.Quiz1(chLetter, iNum1);
	cout << "2-1. ���ڿ� �ϳ� �Է� : ";
	cin >> charrChar;
	Q.Quiz2(charrChar);
	cout << "2-2. ���ڿ� �ΰ� �Է� : ";
	cin >> strString1 >> strString2;
	Q.Quiz2(strString1, strString2);
	cout << "3-1. ���� 5�� �Է� : ";
	cin >> iarrNum[0] >> iarrNum[1] >> iarrNum[2] >> iarrNum[3] >> iarrNum[4];
	Q.Quiz3(iarrNum);
	cout << "3-2. ���Ϲ��� 5�� �Է� : ";
	cin >> charrLetter[0] >> charrLetter[1] >> charrLetter[2] >> charrLetter[3] >> charrLetter[4];
	Q.Quiz3(charrLetter);
	system("pause");
}