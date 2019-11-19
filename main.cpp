#include <iostream>
#include <fstream>
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "Shape.h"
#include "Triangle.h"
#include <string>
#include <filesystem>


int main()
{

	//Start - Parsing Data - Writing to file//
	std::string location = "./bin/data.txt";
	std::ofstream ostrm(location, std::ios::out | std::ios::app | std::ios::binary);
	//END - Parsing Data - Writing to file//

	Point p1(4.1, 3.2);
	Point p2(9.3, 4.7);
	Point p3(5.8, 7.3);
	Point p(2.5, 8.4);
	Line line(p1, p2);
	Triangle triangle(p1, p2, p3);
	Circle circle(p, 2.9);

	p1.save(location, ostrm);
	//TODO: Get a pointer to all existing objects using a data structure
	//get the list objects and write to file
	//make sure to do typeof() when storing the data.
}