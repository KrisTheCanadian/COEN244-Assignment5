#include "Circle.h"
#include <iostream>
Circle::Circle() :m_radius(0) {};//need to set point to 0
Circle::Circle(Point p, double radius) :m_p(p), m_radius(radius) {};
Point Circle::getp() const { return m_p;}
void Circle::setp(Point p) { m_p = p;}
double Circle::getradius() const { return m_radius;}
void Circle::setradius(double radius) { m_radius = radius;}
void Circle::print() {
	this->m_p.print();
	std::cout << "Radius: " << this->m_radius << std::endl;
}