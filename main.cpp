#include <fstream>
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "Shape.h"
#include "Triangle.h"

int main()
{
	Point p1(4.1, 3.2);
	Point p2(9.3, 4.7);
	Point p3(5.8, 7.3);
	Point p(2.5, 8.4);

	Line line(p1, p2);

	Triangle triangle(p1, p2, p3);

	Circle circle(p, 2.9);
}