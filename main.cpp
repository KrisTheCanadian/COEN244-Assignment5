#include <iostream>
#include <fstream>
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "Shape.h"
#include "Triangle.h"
#include <string>
#include <filesystem>
#include <iomanip>


void init_ofile(std::string filename, std::ofstream& ostrm) {

	ostrm.open(filename, ostrm.binary | ostrm.trunc | ostrm.in);
	if (!ostrm)
	{
		std::cout << "This file cannot be read." << std::endl;
		exit(1);
	}
	ostrm << std::setw(8);
	ostrm << "Object";
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << "field I";
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << "field II";
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << "field III";
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << "field IV";
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << "field V";
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << "field VI";
	ostrm.put(' ');
	ostrm << std::setw(15);
	ostrm << "field VII";
	ostrm.put(' ');
	ostrm << std::endl; //dump buffers in file
	ostrm.close();
}

void init_ifile(std::string location, std::ifstream& istrm)
{
	std::string skip;
	istrm.open(location, istrm.binary);
	if (!istrm)
	{
		std::cout << "This file cannot be read." << std::endl;
		exit(1);
	}
	for (int i = 0; i < 16; i++)
	{
		istrm >> skip;
	}
}

int main()
{

	std::string location = "./data/file.txt";
	std::ofstream ostrm;
	init_ofile(location, ostrm);


	Point p1(4.1, 3.2);
	Point p2(9.3, 4.7);
	Point p3(5.8, 7.3);
	Point p(2.5, 8.4);
	Line line(p1, p2);
	Triangle triangle(p1, p2, p3);
	Circle circle(p, 2.9);

	p1.save("p1", location, ostrm);
	p2.save("p2",location, ostrm);
	line.save("line", location, ostrm);
	p3.save("p2", location, ostrm);
	triangle.save("triangle", location, ostrm);
	p.save("p", location, ostrm);
	circle.save("circle", location, ostrm);
	//TODO: Get a pointer to all existing objects using a data structure
	//get the list objects and write to file
	//make sure to do typeof() when storing the data.
	Shape* shapeArray[7]; //instructions only mention to create a pointer array
	for (int i = 0; i < 7; i++) // so i assumed it would be of size 7 since we only have 7 objects
	{
		shapeArray[i] = nullptr;
	}

	std::string holder;
	double holder1;
	std::ifstream istrm;
	init_ifile(location, istrm);
	for (int i = 0; i < 7; i++)
	{
		istrm >> holder;
		if (p.check(holder))
		{
			Point* newp = new Point;
			shapeArray[i] = newp;
			istrm >> holder1;
			newp->setx(holder1);
			istrm >> holder1;
			newp->sety(holder1);
		}
		else if (line.check(holder))
		{
			Line* newl = new Line;
			shapeArray[i] = newl;
			istrm >> holder1;
			newl->getp1.setp1(holder1);
			istrm >> holder1;
			newl->getp1.setp2(holder1);
			istrm >> holder1;
			newl->getp2.setp1(holder1);
			istrm >> holder1;
			newl->getp2.setp2(holder1);
		}
		else if (triangle.check(holder))
		{
			Triangle* newt = new Triangle;
			shapeArray[i] = newt;
			istrm >> holder1;
			newt->getp1.setp1(holder1);
			istrm >> holder1;
			newt->getp1.setp2(holder1);
			istrm >> holder1;
			newt->getp2.setp1(holder1);
			istrm >> holder1;
			newt->getp2.setp2(holder1);
			istrm >> holder1;
			newt->getp3.setp1(holder1);
			istrm >> holder1;
			newt->getp3.setp2(holder1);
		}
		else if (circle.check(holder))
		{
			Circle* newc = new Circle;
			shapeArray[i] = newc;
			istrm >> holder1;
			newc->getp.setp1(holder1);
			istrm >> holder1;
			newc->getp.setp2(holder1);
			istrm >> holder1;
			newc->setradius(holder1);
		}
		istrm >> holder;
	}
	for (int i = 0; i < 7; i++)
	{
		
	}
}