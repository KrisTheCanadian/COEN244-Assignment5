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

	Shape** shapeArray = new Shape*[7]; 
	for (int i = 0; i < 7; i++) 
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
			Point q1 = newl->getp1();
			istrm >> holder1;
			q1.setx(holder1);
			istrm >> holder1;
			q1.sety(holder1);
			newl->setp1(q1);
			q1 = newl->getp2();
			istrm >> holder1;
			q1.setx(holder1);
			istrm >> holder1;
			q1.sety(holder1);
			newl->setp2(q1);
		}
		else if (triangle.check(holder))
		{
			Triangle* newt = new Triangle;
			shapeArray[i] = newt;
			Point q1 = newt->getp1();
			istrm >> holder1;
			q1.setx(holder1);
			istrm >> holder1;
			q1.sety(holder1);
			newt->setp1(q1);
			q1 = newt->getp2();
			istrm >> holder1;
			q1.setx(holder1);
			istrm >> holder1;
			q1.sety(holder1);
			newt->setp2(q1);
			q1 = newt->getp3();
			istrm >> holder1;
			q1.setx(holder1);
			istrm >> holder1;
			q1.sety(holder1);
			newt->setp3(q1);
		}
		else if (circle.check(holder))
		{
			Circle* newc = new Circle;
			shapeArray[i] = newc;
			Point q1 = newc->getp();
			istrm >> holder1;
			q1.setx(holder1);
			istrm >> holder1;
			q1.sety(holder1);
			newc->setp(q1);
			istrm >> holder1;
			newc->setradius(holder1);
		}
		istrm >> holder;
	}
	istrm.close();
	for (int i = 0; i < 7; i++)
	{
		shapeArray[i]->print();
	}
}