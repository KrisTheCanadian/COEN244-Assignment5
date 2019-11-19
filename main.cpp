#include <fstream>
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "Shape.h"
#include "Triangle.h"
#include <string>


void parseData(std::ofstream *ostrm) {

	
/*
	std::string filename = "Test.b";
	{
		std::ofstream ostrm(filename, std::ios::binary);
		double d = 3.14;
		ostrm.write(reinterpret_cast<char*>(&d), sizeof d); // binary output
		ostrm << 123 << "abc" << '\n';                      // text output
	}
	// read back
	std::ifstream istrm(filename, std::ios::binary);
	double d;
	istrm.read(reinterpret_cast<char*>(&d), sizeof d);
	int n;
	std::string s;
	istrm >> n >> s;
	std::cout << " read back: " << d << " " << n << " " << s << '\n';
*/
}

int main()
{

	//Start - Parsing Data - Writing to file//
	std::string filename = "data.bin";
	std::ofstream *ostrm = new std::ofstream(filename, std::ios::binary);
	//END - Parsing Data - Writing to file//

	Point p1(4.1, 3.2);
	Point p2(9.3, 4.7);
	Point p3(5.8, 7.3);
	Point p(2.5, 8.4);
	Line line(p1, p2);
	Triangle triangle(p1, p2, p3);
	Circle circle(p, 2.9);

	//TODO: Get a pointer to all existing objects using a data structure
	//get the list objects and write to file
	//make sure to do typeof() when storing the data.
}