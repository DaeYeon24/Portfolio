#include "Point.h"
// ���� ������(!, &, ~, *, +, -, --)�� ������ �����ε� ����� ��������.
// ���� ������(+, -, *, / , < , <= )�� ������ �������� ����� ��������.

void main()
{
	Point a(5, 5), b(3, 3);
	Point c;

	a.Print();
	b.Print();
	c.Print();
	cout << endl;
	!a;
	a.Print();
	cout << &a << endl;
	c = a + b;
	c.Print();
	cout << endl;
	c = a * b;
	c.Print();
	if (a < b)
		cout << "a�� b���� �۴�" << endl;
	else
		cout << "a�� b���� ũ��" << endl;
}




