#include <iostream>
using namespace std;

class A
{
private:
	int x, y;
public:
	A(int a = 0, int b = 0);
	void Print();
	A operator /(A a);
};

A::A(int a, int b)
{
	x = a;
	y = b;
}

void A::Print()
{
	cout << "x = " << x << " y = " << y << endl;
}

A A::operator /(A a)
{
	if (this->x >= a.x)
		a.x = this->x / a.x;
	else
		a.x = a.x / this->x;
	if (this->y >= a.y)
		a.y = this->y / a.y;
	else
		a.y = a.y / this->y;
	return a;
}

void main()
{
	A a(3, 120);
	A b(9, 20);
	A c;
	a.Print();
	b.Print();
	cout << endl;
	c = a / b;
	c.Print();
}