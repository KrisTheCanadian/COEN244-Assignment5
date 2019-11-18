#pragma once
#include "Shape.h"
#include "Point.h"

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
private:
	Point m_p;
	double m_radius;
};
