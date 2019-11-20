#pragma once
#include "Shape.h"
#include "Point.h"

class Line :
	public Shape
{
public:
	Line();
	Line(Point, Point);
	Point getp1() const;
	void setp1(Point);
	Point getp2() const;
	void setp2(Point);
	void print() override;
	std::ofstream& save(std::string, std::ofstream&);
	friend std::ofstream& operator<<(std::ofstream& out, Point& point);
private:
	Point m_p1;
	Point m_p2;
};
