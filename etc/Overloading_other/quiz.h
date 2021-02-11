#pragma once
#include <iostream>
#include <string>
using namespace std;

#define MAX 50

class quiz
{
private:
	int m_iQuiz1Answer = 1;
	char m_charrQuiz2Answer[MAX];
	int m_iTemp;
	char m_chTemp;
	int m_iCount = 0;
public:
	void Quiz1(int inum1, int inum2);
	void Quiz1(char chLetter, int inum);
	void Quiz2(char charrChar[]);
	void Quiz2(string strSt1, string strSt2);
	void Quiz3(int iarrNum[]);
	void Quiz3(char charrLetter[]);
};