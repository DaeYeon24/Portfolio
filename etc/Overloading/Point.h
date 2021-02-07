#pragma once
#include <iostream>
#include <crtdbg.h>
using namespace std;

class Point
{
private:
	bool m_truth;
	int m_x;
	int m_y;
public:
	Point(int x = 0, int y = 0) :m_x(x), m_y(y), m_truth(true) {}
	inline void Print()
	{
		cout << m_x << ", " << m_y << " " << m_truth << endl;
	}
	// 단항 연산자(!, &, ~, *, +, -, --)를 연산자 오버로딩 기능을 구현하자.
	const Point operator!();
	const Point* operator&();
	 //const Point operator~();
	const Point operator*();
	const Point operator+();
	const Point operator-();
	const Point& operator++();
	const Point operator++(int);
	const Point& operator--();
	const Point operator--(int);
	// 이항 연산자(+, -, *, / , < , <= )를 연산자 오버오딩 기능을 구현하자.
	const Point operator+(const Point arg) const;
	const Point operator-(const Point arg) const;
	const Point operator*(const Point arg) const;
	const Point operator/(const Point arg) const;
	const bool operator<(const Point arg) const;
	const bool operator<=(const Point arg) const;
};

