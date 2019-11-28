#include "Triangle.h"
Triangle::Triangle():m_p1(Point()), m_p2(Point()), m_p3(Point()) {};//set all points to 0
Triangle::Triangle(Point a, Point b, Point c) :m_p1(a), m_p2(b), m_p3(c) {}
Triangle::~Triangle() {};
Point Triangle::getp1() { return m_p1; }
void Triangle::setp1(Point p1) { m_p1 = p1; }
Point Triangle::getp2() { return m_p2; }
void Triangle::setp2(Point p2) { m_p2 = p2; }
Point Triangle::getp3() { return m_p3; }
void Triangle::setp3(Point p3) { m_p3 = p3; }

void Triangle::print()
{
	std::cout << "[Triangle] First Point: ";
	this->m_p1.print();
	std::cout << "Second Point: ";
	this->m_p2.print();
	std::cout << "Third Point: ";
	this->m_p3.print();
}

void Triangle::save(std::string name, std::string filename, std::ofstream& ostrm) {
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

	ostrm << "Triangle"; 
	ostrm.put(' ');
	ostrm << std::setw(15);

	ostrm << this->getp1().getx();
	ostrm << std::setw(15);
	ostrm.put(' ');

	ostrm << this->getp1().gety();
	ostrm.put(' ');
	ostrm << std::setw(15);

	ostrm << this->getp2().getx();
	ostrm.put(' ');
	ostrm << std::setw(15);

	ostrm << this->getp2().gety();
	ostrm.put(' ');
	ostrm << std::setw(15);

	ostrm << this->getp3().getx();
	ostrm.put(' ');
	ostrm << std::setw(15);

	ostrm << this->getp3().gety();
	ostrm.put(' ');
	ostrm << std::setw(15);

	ostrm << std::endl; //dump buffers in file
	ostrm.close();
}

bool Triangle::check(std::string name)
{
	if (name == "Triangle")
	{
		return true;
	}
	else
		return false;
}