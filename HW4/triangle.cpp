#include "triangle.h"
#include<iostream>
#include<fstream>
#include<cmath>

using namespace gtu;
Triangle::Triangle(double s)
			:side(s)
{ }

Triangle::Triangle()
			:x1(0), y1(0), x2(0),y2(0),x3(0),y3(0)
{ }


void Triangle::setSide(Triangle &t, double s)
{
	t.side = s;
 
}

/*Some getter and setter functions that included by triangle class.*/
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
	return 3*side;
}
double Triangle::area()
{
	return side*side*pow(3,0.5)/4;
}
/*
void Triangle::draw(Triangle t,int color, double x1, double y1, double x2, double y2, double x3, double y3,ofstream &res)
{

	setCoord(t, x1,y1,x2,y2,x3,y3);
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";


	
	if(color==1)
	{
		res<<"\n<polygon points=\""<<t.x1<<" "<<t.y1<<" "<< t.x2 <<" "<< t.y2 <<" "<< t.x3 <<" "<< t.y3 <<" \" stroke = \"black\" fill=\"red\"></polygon>";		
	}

	if(color==0)
	{
		res<<"\n<polygon points=\""<<t.x1<<" "<<t.y1<<" "<< t.x2 <<" "<< t.y2 <<" "<< t.x3 <<" "<< t.y3 <<" \" stroke = \"black\" fill=\"green\"></polygon>";
	}
}
*/
ostream& Triangle::operator<<(ostream &res)
{
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	res<<"\n<polygon points=\""<<x1<<" "<<y1<<" "<<x2 <<" "<<y2 <<" "<<x3 <<" "<<y3<<" \" stroke = \"black\" fill=\"red\"></polygon>";		
	return res;
}

const Triangle Triangle::operator+(double val)
{
	return Triangle(side+val);
}

const Triangle Triangle::operator-(double val)
{
	return Triangle(side-val);
}

bool Triangle::operator==(Triangle &ta)
{
	return (this->side==ta.side);	
}

double Triangle::calcPerimeters(Triangle tn, double piece)
{
	return piece*tn.perimeter();
}

double Triangle::calcAreas(Triangle tn, double piece)
{
	return piece*tn.area();
}

const Triangle Triangle::operator++(int dummy)
{
	Triangle temp;
	temp.x1=x1;
	temp.y1=y1;
	temp.x2=x2;
	temp.y2=y2;
	temp.x3=x3;
	temp.y3=y3;	 
	x1++;		y1++;	x2++;		y2++;	x3++;		y3++; 
	return temp;	
}

const Triangle Triangle::operator--(int dummy)
{
	Triangle temp;
	temp.x1=x1;
	temp.y1=y1;
	temp.x2=x2;
	temp.y2=y2;
	temp.x3=x3;
	temp.y3=y3;
	x1--;	    y1--;	x2--;	    y2--;	x3--;	    y3--;
	return temp;	
}


