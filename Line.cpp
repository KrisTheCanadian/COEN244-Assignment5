#include "Line.h"
Line::Line():m_p1(Point()), m_p2(Point()) {}//set both points to 0
Line::Line(Point a, Point b) :m_p1(a), m_p2(b) {};
Line::~Line() {};
Point Line::getp1() const { return m_p1;}
void Line::setp1(Point p1) { m_p1 = p1; }
Point Line::getp2() const { return m_p2; }
void Line::setp2(Point p2) { m_p2 = p2; }

void Line::save(std::string name, std::string filename, std::ofstream& ostrm) {
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

	ostrm << "Line"; 
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

	ostrm << std::endl; //dump buffers in file
	ostrm.close();
}


void Line::print()
{
	this->m_p1.print();
	this->m_p2.print();
}

bool Line::check(std::string name)
{
	if (name == "Line")
	{
		return true;
	}
	else
		return false;
}