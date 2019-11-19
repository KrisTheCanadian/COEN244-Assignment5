#pragma once
#include "Shape.h"
class Point :
	public Shape
{
public:
	Point();
	Point(double, double);
	double getx() const;
	void setx(double);
	double gety() const;
	void sety(double);
	void print() override;
private:
	double m_x_coor;
	double m_y_coor;
};