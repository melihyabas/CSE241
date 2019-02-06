#include "rectangle.h"
#include<iostream>
#include<fstream>

using namespace std;


Rectangle::Rectangle(int w, int h)
			:width(w), height(h)
{ }

Rectangle::Rectangle()
			:x(0), y(0)
{ }


void Rectangle::setWidth(Rectangle &r, int w)
{
	r.width = w;
}
/*Some getter and setter functions that included by rectangle class.*/
void Rectangle::setHeight(Rectangle &r, int h)
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

void Rectangle::draw(Rectangle &r,int color, int x, int y, ofstream &res)
{
/*This drawing function written to draw container rectangle shape. */
	setCoordinates(r,x, y);

	res<<"<svg version=\"1.1\"\nbaseProfile=\"full\"\n  width=\""<<width<<"\" height=\""<<height<<"\"\nxmlns=\"http://www.w3.org/2000/svg\">\n";
	if(color==1)
	{
		res<<"<rect x=\""<<x<<"\" y=\""<<y<<"\" stroke=\"Black\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"red\"></rect>"<<endl;
	}

	else
	{
		res<<"<rect x=\""<<x<<"\" y=\""<<y<<"\" stroke=\"Black\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"green\"></rect>"<<endl;
	}
	
}




