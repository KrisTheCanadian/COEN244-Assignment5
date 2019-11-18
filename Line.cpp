#include "Line.h"

Point Line::getp1() const { return m_p1;}
void Line::setp1(Point p1) { m_p1 = p1; }
Point Line::getp2() const { return m_p2; }
void Line::setp2(Point p2) { m_p2 = p2; }