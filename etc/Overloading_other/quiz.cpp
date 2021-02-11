#include "quiz.h"

void quiz::Quiz1(int inum1, int inum2)
{
	cout << inum1 << "ÀÇ " << inum2 << "½Â : ";
	for (int i = 0; i < inum2; i++)
		m_iQuiz1Answer *= inum1;
	cout << m_iQuiz1Answer << endl;
}

void quiz::Quiz1(char chLetter, int inum)
{
	cout << chLetter << " >> " << inum << " : ";
	if (chLetter + (char)inum <= 'z')
		cout << (char)(chLetter + (char)inum) << endl;
	else
	{
		while (chLetter < 'z')
		{
			chLetter++;
			inum--;
		}
		chLetter = 'a';
		inum--;
		cout << (char)(chLetter + (char)inum) << endl;
	}
}

void quiz::Quiz2(char charrChar[])
{
	m_iCount = strlen(charrChar);
	for (int i = 0; i < m_iCount; i++)
	{
		m_charrQuiz2Answer[i] = charrChar[m_iCount - (i + 1)];
	}
	m_charrQuiz2Answer[m_iCount] = NULL;
	cout << charrChar << " -> " << m_charrQuiz2Answer << endl;
}

void quiz::Quiz2(string strSt1, string strSt2)
{
	cout << strSt1 << " + " << strSt2 << " : " << strSt1 + strSt2 << endl;
}

void quiz::Quiz3(int iarrNum[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (iarrNum[i] < iarrNum[j])
			{
				m_iTemp = iarrNum[i];
				iarrNum[i] = iarrNum[j];
				iarrNum[j] = m_iTemp;
			}
		}
	}
	cout << "===========iarr===========" << endl;
	for (int i = 0; i < 5; i++)
		cout << "iarr[" << i << "] : " << iarrNum[i] << endl;
}

void quiz::Quiz3(char charrLetter[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (charrLetter[i] > charrLetter[j])
			{
				m_chTemp = charrLetter[i];
				charrLetter[i] = charrLetter[j];
				charrLetter[j] = m_chTemp;
			}
		}
	}
	cout << "===========charr===========" << endl;
	for (int i = 0; i < 5; i++)
		cout << "charr[" << i << "] : " << charrLetter[i] << endl;
}