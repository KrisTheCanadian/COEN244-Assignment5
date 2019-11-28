#pragma once
#include "Shape.h"
#include "Point.h"
#include <ostream>

class Circle :
	public Shape
{
public:
	Circle();
	Circle(Point, double);
	virtual ~Circle();
	Point getp() const;
	void setp(Point);
	double getradius() const;
	void setradius(double);
	void print();
	void save(std::string name, std::string filename, std::ofstream& ostrm);
	bool check(std::string);
private:
	Point m_p;
	double m_radius;
};


