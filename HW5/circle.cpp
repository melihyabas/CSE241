#include "circle.h"
#include<iostream>
#include<fstream>
#define PI 3.1415
using namespace istanbul;

Circle::Circle(double r)noexcept
			:radius(r)
{ }


Circle::Circle()noexcept
			:x(0), y(0)
{ }

void Circle::setRadius(Circle &c, double  r)throw(string)
{
	
	try
	{
		if(r<=0)
			throw("Radius cannot be negative!");
		c.radius = r;

	}
	catch(string obj)
	{
		cout<<obj;
	}		

}

void Circle::setCoord(Circle &c, int a, int b)
{
	c.x=a;
	c.y=b;
}
/*Some getter and setter functions that included by circle class.*/
double Circle::perimeter()
{	
	Perimeter = 2*PI*radius;
	return Perimeter;
}
double Circle::area()
{
	Area = PI*radius*radius;
	return Area;
}
void Circle::draw(ostream& res)
{
	
	res<<"<circle x=\""<<x<<"\" y=\""<<y<<"\" r=\""<<radius<<"\" stroke=\"black\" fill=\"red\" />\n";
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

Shape& Circle::operator++(int dummy)
{
	Circle* temp;
	temp = new Circle;
	temp->x=x;
	temp->y=y;
	temp->radius=radius;	 
	x++;		y++; 
	return *temp;
}

Shape& Circle::operator--(int dummy)
{
	Circle* temp;
	temp = new Circle;
	temp->x=x;
	temp->y=y;	
	temp->radius=radius;	 
	
	x--;		y--; 
	return *temp;	
}


