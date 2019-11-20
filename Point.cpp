#include "Point.h"

Point::Point():m_x_coor(0), m_y_coor(0) {};
Point::Point(double a, double b):m_x_coor(a), m_y_coor(b) {};
double Point::getx() const { return m_x_coor; }
void Point::setx(double x) { m_x_coor = x; }
double Point::gety() const { return m_y_coor; }
void Point::sety(double y) { m_y_coor = y; }
std::ofstream& Point::save(std::string filename, std::ofstream& ostrm) {
	ostrm.open(filename, ostrm.binary | ostrm.trunc | ostrm.in);
	if (!ostrm)
	{
		std::cout << "This file cannot be read." << std::endl;
		exit(1);
	}
	ostrm << "Point";
	ostrm << m_x_coor;
	ostrm << m_y_coor;
	ostrm.flush(); //dump buffers in file
	ostrm.close();
	return ostrm;
}
void Point::print() 
{
	std::cout << "(" << this->m_x_coor << "," << this->m_y_coor << ")" << std::endl;
}

/*std::ofstream& operator<<(std::ofstream& out, Point& point)
{
	out << "Point: ";
	out << point.getx();
	out << point.gety();
	return out;
}*/
