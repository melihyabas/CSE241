#include "rectangle.h"
#include<iostream>
#include<fstream>

using namespace std;


Rectangle::Rectangle(double w, double h)
			:width(w), height(h)
{ }

Rectangle::Rectangle()
			:x(0), y(0)
{ }


void Rectangle::setWidth(Rectangle &r, double w)
{
	r.width = w;
}
/*Some getter and setter functions that included by rectangle class.*/
void Rectangle::setHeight(Rectangle &r, double h)
{
	r.height = h;
}

int Rectangle::getX()
{
	return x;
}
int Rectangle::getY()
{
	return y;
}
void Rectangle::setCoordinates(Rectangle &r,int a, int b)
{
	r.x=a;
	r.y=b;
	
}
double Rectangle::perimeter()
{	
	return 2*width+2*height;
}
double Rectangle::area()
{
	return width*height;
}

ostream& Rectangle::operator<<(ostream &res)
{

	res<<"<svg version=\"1.1\"\nbaseProfile=\"full\"\n  width=\""<<width<<"\" height=\""<<height<<"\"\nxmlns=\"http://www.w3.org/2000/svg\">\n";
	res<<"<rect x=\""<<x<<"\" y=\""<<y<<"\" stroke=\"Black\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"red\"></rect>"<<endl;
	return res;
}

const Rectangle Rectangle::operator+(double val)
{
	return Rectangle(width+val,height+val);
}

const Rectangle Rectangle::operator-(double val)
{
	return Rectangle(width-val,height-val);
}

bool Rectangle::operator==(Rectangle &ra)
{
	return(this->width==ra.width&&this->height==ra.height);
}

double Rectangle::calcPerimeters(Rectangle rn, double piece)
{
	return piece*rn.perimeter();
}

double Rectangle::calcAreas(Rectangle rn, double piece)
{
	return piece*rn.area();
}


