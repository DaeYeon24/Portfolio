#include <iostream>
using namespace std;

int Problem1(int n)
{
	if (n <= 0)
		return 0;
	else
		n = n + Problem1(n - 1);
	return n;
}

int Problem2(int n, int binary, int digit)
{
	if (n == 1)
		return 1;
	binary += (n % 2) * digit; // �������� �ڿ������� �ְ�
	digit *= 10;
	n = n / 2;
	if (n <= 1)
	{
		binary += n * digit;
		return binary;
	}
	else
		binary = Problem2(n, binary, digit);
}

void main()
{
	int su, Binary = 0, Digit = 1;
	cout << "1. ���� �Է� : ";
	cin >> su;
	cout << "1 ~ " << su << " : ";
	su = Problem1(su);
	cout << su << endl;
	cout << "2. ���� �Է� : ";
	cin >> su;
	cout << su << "�� ������ : ";
	Binary = Problem2(su, Binary, Digit);
	cout << Binary;
}