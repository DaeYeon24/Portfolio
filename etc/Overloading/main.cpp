#include "Point.h"
// 단항 연산자(!, &, ~, *, +, -, --)를 연산자 오버로딩 기능을 구현하자.
// 이항 연산자(+, -, *, / , < , <= )를 연산자 오버오딩 기능을 구현하자.

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
		cout << "a가 b보다 작다" << endl;
	else
		cout << "a가 b보다 크다" << endl;
}




