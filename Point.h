#pragma once
#include "Shape.h"
#include <string>
#include <iostream>
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
	std::ofstream& save(std::string, std::ofstream&);
private:
	double m_x_coor;
	double m_y_coor;
};