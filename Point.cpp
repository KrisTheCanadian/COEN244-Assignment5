#include "Point.h"
#include <iostream>
Point::Point():m_x_coor(0), m_y_coor(0) {};
Point::Point(double a, double b):m_x_coor(a), m_y_coor(b) {};
double Point::getx() const { return m_x_coor; }
void Point::setx(double x) { m_x_coor = x; }
double Point::gety() const { return m_y_coor; }
void Point::sety(double y) { m_y_coor = y; }
void Point::print() 
{
	std::cout << "(" << this->m_x_coor << "," << this->m_y_coor << ")" << std::endl;
}
