#pragma once
#include "Shape.h"
#include "Point.h"

class Triangle :
	public Shape
{
public:
	Triangle();
	Triangle(Point, Point, Point);
	virtual ~Triangle();
	Point getp1() const;
	void setp1(Point);
	Point getp2() const;
	void setp2(Point);
	Point getp3() const;
	void setp3(Point);
	void print();
	void save(std::string, std::string, std::ofstream&);
	bool check(std::string);
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;
};