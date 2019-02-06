#include "circle.h"
#include<iostream>
#include<fstream>
#define PI 3.1415

using namespace std;

Circle::Circle(double r)
			:radius(r)
{ }


Circle::Circle()
			:cx(0), cy(0)
{ }

void Circle::setRadius(Circle &c, double  r)
{
	c.radius = r;

}

void Circle::setCoord(Circle &c, int a, int b)
{
	c.cx=a;
	c.cy=b;
}
/*Some getter and setter functions that included by circle class.*/
double Circle::perimeter()
{
	return 2*PI*radius;
}
double Circle::area()
{
	return PI*radius*radius;
}

ostream& Circle::operator<<(ostream &res)
{

	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";		
	
	res<<"<circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"red\" />\n";
			
	return res;
}

const Circle Circle::operator+(double val)
{
	return Circle(radius+val);
}

const Circle Circle::operator-(double val)
{
	return Circle(radius-val);
}

bool Circle::operator==(Circle &e)
{
	return(this->radius==e.radius);
}

double Circle::calcPerimeters(Circle cn, double piece)
{
	return piece*cn.perimeter();
}

double Circle::calcAreas(Circle cn, double piece)
{
	return piece*cn.area();
}



