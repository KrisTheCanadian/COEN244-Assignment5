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

void Circle::save(std::string name, std::string filename, std::ofstream& ostrm) {
	ostrm.open(filename, ostrm.binary | std::ios::app | ostrm.in); //std::ios::app means end of file
	if (!ostrm)
	{
		std::cout << "This file cannot be read." << std::endl;
		exit(1);
	}
	ostrm << std::setw(8);
	ostrm << name;
	ostrm.put(' ');

	ostrm << std::setw(15);
	ostrm << "Circle"; 
	ostrm.put(' ');

	ostrm << std::setw(15);
	ostrm << this->getp().getx();
	ostrm.put(' ');

	ostrm << std::setw(15);
	ostrm << this->getp().gety();
	ostrm.put(' ');

	ostrm << std::setw(15);
	ostrm << this->m_radius;
	ostrm.put(' ');

	ostrm << std::setw(15);
	ostrm << std::endl; //dump buffers in file
	ostrm.close();
}

bool Circle::check(std::string name)
{
	if (name == "Triangle")
	{
		return true;
	}
	else
		return false;
}