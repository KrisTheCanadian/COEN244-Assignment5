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
	virtual ~Point();
	double getx() const;
	void setx(double);
	double gety() const;
	void sety(double);
	void print() ;
	void save(std::string, std::string, std::ofstream&);
	bool check(std::string);
private:
	double m_x_coor;
	double m_y_coor;
};