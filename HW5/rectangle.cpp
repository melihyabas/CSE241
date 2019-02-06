#include "rectangle.h"
#include<iostream>
#include<fstream>

Rectangle::Rectangle(double w, double h)noexcept
			:width(w), height(h)
{ }

Rectangle::Rectangle()noexcept
			:x(0), y(0)
{ }
Rectangle::Rectangle(int objX, int objY)noexcept
			:x(objX), y(objY)
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

int Rectangle::getX()noexcept
{
	return x;
}
int Rectangle::getY()noexcept
{
	return y;
}
void Rectangle::setCoordinates(Rectangle &r,int a, int b)
{

		r.x=a;		
		r.y=b;


}
double Rectangle::perimeter()noexcept
{	
	Perimeter = 2*width+2*height;
	return Perimeter;
}
double Rectangle::area()noexcept
{
	Area = width*height;
	return Area;
}

void Rectangle::draw(ostream &res)noexcept
{
	res<<"<rect x=\""<<x<<"\" y=\""<<y<<"\" stroke=\"Black\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"red\"></rect>"<<endl;
}	

const Rectangle Rectangle::operator+(double val)noexcept
{
	return Rectangle(width+val,height+val);
}

const Rectangle Rectangle::operator-(double val)noexcept
{
	return Rectangle(width-val,height-val);
}

bool Rectangle::operator==(Rectangle &ra)noexcept
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

Shape& Rectangle::operator++(int dummy)noexcept
{
	Rectangle* temp;
	temp = new Rectangle;

	temp->x=x;
	temp->y=y;
	temp->width = width;
	temp->height = height;

	x++; y++;
	return *temp;
}

Shape& Rectangle::operator--(int dummy)
{

		Rectangle* temp;
		temp = new Rectangle;

		temp->x=x;
		temp->y=y;
		temp->width = width;
		temp->height = height;
			
		x--;		y--; 

}

