#include "Circle.h"
#include <iostream>
#include <string>
#include <fstream>
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
std::ofstream& Circle::save(std::string filename, std::ofstream& ostrm) {
	ostrm.open(filename, ostrm.binary | ostrm.trunc | ostrm.in | ostrm.out);
	if (!ostrm)
	{
		std::cout << "This file cannot be read." << std::endl;
		exit(1);
	}
	ostrm << "Circle";
	ostrm << this->m_p.getx();
	ostrm << this->m_p.gety();
	ostrm << this->m_radius;
	ostrm.flush(); //dump buffers in file
	ostrm.close();
	return ostrm;
}