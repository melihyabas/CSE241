#include "circle.h"
#include<iostream>
#include<fstream>

using namespace std;

Circle::Circle(int r)
			:radius(r)
{ }


Circle::Circle()
			:cx(0), cy(0)
{ }


void Circle::setRadius(Circle &c, int  r)
{
	c.radius = r;

}

int Circle::getRadius()
{
	return radius;
}

void Circle::setCoord(Circle &c, int a, int b)
{
	c.cx=a;
	c.cy=b;
}
/*Some getter and setter functions that included by circle class.*/
void Circle::draw(Circle &c, int color,int x, int y,ofstream &res)
{
	radius = Circle::getRadius();
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";		
	setCoord(c,x, y);
	
	if(color==1)
	{

			res<<"<circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<c.radius<<"\" fill=\"red\" />\n";
			
	}
	else
	{

			res<<"<circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<c.radius<<"\" fill=\"green\" />\n";
	}

	
}



