#pragma once
#include "Shape.h"
#include "Point.h"

class Line :
	public Shape
{
public:
	Line();
	Line(Point, Point);
	virtual ~Line();
	Point getp1() const;
	void setp1(Point);
	Point getp2() const;
	void setp2(Point);
	void print();
	void save(std::string, std::string, std::ofstream&);
	bool check(std::string);
private:
	Point m_p1;
	Point m_p2;
};
