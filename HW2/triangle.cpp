#include "triangle.h"
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

Triangle::Triangle(int s)
			:side(s)
{ }

Triangle::Triangle()
			:x1(0), y1(0), x2(0),y2(0),x3(0),y3(0)
{ }


void Triangle::setSide(Triangle &t, int s)
{
	t.side = s;
 
}

int Triangle::getSide()
{
	return side;
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



