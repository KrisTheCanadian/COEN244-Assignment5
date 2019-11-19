#include "Triangle.h"
Triangle::Triangle() {};//set all points to 0
Triangle::Triangle(Point a, Point b, Point c) :m_p1(a), m_p2(b), m_p3(c) {};
Point Triangle::getp1() const { return m_p1; }
void Triangle::setp1(Point p1) { m_p1 = p1; }
Point Triangle::getp2() const { return m_p2; }
void Triangle::setp2(Point p2) { m_p2 = p2; }
Point Triangle::getp3() const { return m_p3; }
void Triangle::setp3(Point p3) { m_p3 = p3; }

void Triangle::print()
{
	this->m_p1.print();
	this->m_p2.print();
	this->m_p3.print();
}
