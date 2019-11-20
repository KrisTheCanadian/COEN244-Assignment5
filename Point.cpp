#include "Point.h"
#include <fstream>
Point::Point():m_x_coor(0), m_y_coor(0) {};
Point::Point(double a, double b):m_x_coor(a), m_y_coor(b) {};
double Point::getx() const { return m_x_coor; }
void Point::setx(double x) { m_x_coor = x; }
double Point::gety() const { return m_y_coor; }
void Point::sety(double y) { m_y_coor = y; }
std::ofstream& Point::save(std::string filename, std::ofstream& ostrm) {
	ostrm.open(filename, std::ios::out | std::ios::app | std::ios::binary);
	if (!ostrm)
	{
		std::cout << "This file cannot be read." << std::endl;
		exit(1);
	}
	ostrm.write(reinterpret_cast<char*>(this), sizeof std::string);
	ostrm.write(reinterpret_cast<char*>(&m_y_coor), sizeof &m_y_coor);
	ostrm.write(reinterpret_cast<char*>(&m_x_coor), sizeof &m_x_coor);
	ostrm.close();
	return ostrm;
}
void Point::print() 
{
	std::cout << "(" << this->m_x_coor << "," << this->m_y_coor << ")" << std::endl;
}
