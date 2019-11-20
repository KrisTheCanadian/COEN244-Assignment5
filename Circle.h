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
	Point getp() const;
	void setp(Point);
	double getradius() const;
	void setradius(double);
	void print() override;
	std::ofstream& save(std::string, std::ofstream&);
private:
	Point m_p;
	double m_radius;
};


