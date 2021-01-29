#include "Point.h"

const Point Point::operator!()
{
	if (m_truth == true)
		m_truth = false;
	else
		m_truth = true;
	return *this;
}

const Point Point::operator+()
{
	return *this;
}

const Point Point::operator-()
{
	return Point(-m_x, -m_y);
}

const Point* Point::operator&()
{
	return this;
}

const Point Point::operator*()
{
	return *this;
}

const Point& Point::operator++()
{
	m_x++;
	m_y++;
	return *this;
}

const Point Point::operator++(int)
{
	Point temp(m_x, m_y);
	m_x++;
	m_y++;
	return temp;
}

const Point& Point::operator--()
{
	m_x--;
	m_y--;
	return *this;
}

const Point Point::operator--(int)
{
	Point temp(m_x, m_y);
	m_x--;
	m_y--;
	return temp;
}

const Point Point::operator+(const Point arg) const
{
	Point temp;
	temp.m_x = m_x + arg.m_x;
	temp.m_y = m_y + arg.m_y;
	return temp;
}

const Point Point::operator-(const Point arg) const
{
	Point temp;
	temp.m_x = m_x - arg.m_x;
	temp.m_y = m_y - arg.m_y;
	return temp;
}

const Point Point::operator*(const Point arg) const
{
	Point temp;
	temp.m_x = m_x * arg.m_x;
	temp.m_y = m_y * arg.m_y;
	return temp;
}

const Point Point::operator/(const Point arg) const
{
	Point temp;
	temp.m_x = m_x / arg.m_x;
	temp.m_y = m_y / arg.m_y;
	return temp;
}
const bool Point::operator<(const Point arg) const
{
	if (m_x < arg.m_x && m_y < arg.m_y)
		return true;
	else
		return false;
}

const bool Point::operator<=(const Point arg) const
{
	if (m_x <= arg.m_x && m_y <= arg.m_y)
		return true;
	else
		return false;
}
