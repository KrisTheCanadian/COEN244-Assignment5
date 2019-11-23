#include "Point.h"

Point::Point():m_x_coor(0), m_y_coor(0) {};
Point::Point(double a, double b):m_x_coor(a), m_y_coor(b) {};
double Point::getx() const { return m_x_coor; }
void Point::setx(double x) { m_x_coor = x; }
double Point::gety() const { return m_y_coor; }
void Point::sety(double y) { m_y_coor = y; }

void Point::save(std::string name, std::string filename, std::ofstream& ostrm) {
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
	ostrm << "Point"; //typeid(*this).name() returns class point (which is not what we actually want)
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << m_x_coor;
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << m_y_coor;
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << std::endl; //dump buffers in file
	ostrm.close();
}


void Point::print() 
{
	std::cout << "(" << this->m_x_coor << "," << this->m_y_coor << ")" << std::endl;
}
