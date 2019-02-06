#include "triangle.h"
#include<iostream>
#include<fstream>
#include<cmath>

using namespace gtu;
Triangle::Triangle(double s)noexcept
			:side(s)
{ }

Triangle::Triangle()noexcept
			:x1(0), y1(0), x2(0),y2(0),x3(0),y3(0)
{ }


void Triangle::setSide(Triangle &t, double s)
{
	t.side = s;

}

/*Some getter and setter functionat included by triangle class.*/
void Triangle::setCoord(Triangle &t,double a1, double b1, double a2, double b2, double a3, double b3)
{

	t.x1=a1;
	t.y1=b1;
	t.x2=a2;
	t.y2=b2;
	t.x3=a3;
	t.y3=b3;



}

double Triangle::perimeter()
{
	Perimeter = 3*side;
	return Perimeter;
}
double Triangle::area()
{
	Area = side*side*pow(3,0.5)/4;
	return Area;
}

void Triangle::draw(ostream& res)noexcept
{
	res<<"\n<polygon points=\""<<x1<<" "<<y1<<" "<<x2 <<" "<<y2 <<" "<<x3 <<" "<<y3<<" \" stroke = \"black\" fill=\"red\"></polygon>";		
}

const Triangle Triangle::operator+(double val)noexcept
{
	return Triangle(side+val);
}

const Triangle Triangle::operator-(double val)noexcept
{
	return Triangle(side-val);
}

bool Triangle::operator==(Triangle &ta)
{
	return (this->side==ta.side);	
}

double Triangle::calcPerimeters(Triangle tn, double piece)noexcept
{
	return piece*tn.perimeter();
}

double Triangle::calcAreas(Triangle tn, double piece)noexcept
{
	return piece*tn.area();
}


Shape& Triangle::operator++(int dummy)noexcept
{
	Triangle* temp;
	temp = new Triangle;
	temp->x1=x1;
	temp->y1=y1;
	temp->x2=x2;
	temp->y2=y2;
	temp->x3=x3;
	temp->y3=y3;	 
	x1++;		y1++;	x2++;		y2++;	x3++;		y3++; 
	return *temp;	
}

Shape& Triangle::operator--(int dummy)
{
	Triangle* temp;
	temp = new Triangle;
	temp->x1=x1;
	temp->y1=y1;
	temp->x2=x2;
	temp->y2=y2;
	temp->x3=x3;
	temp->y3=y3;
	x1--;	    y1--;	x2--;	    y2--;	x3--;	    y3--;
	return *temp;

}	


