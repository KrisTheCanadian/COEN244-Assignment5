#include "Line.h"
Line::Line(){}//set both points to 0
Line::Line(Point a, Point b) :m_p1(a), m_p2(b) {};
Point Line::getp1() const { return m_p1;}
void Line::setp1(Point p1) { m_p1 = p1; }
Point Line::getp2() const { return m_p2; }
void Line::setp2(Point p2) { m_p2 = p2; }