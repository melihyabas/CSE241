#include <fstream>
#include "shape.h"
#ifndef rectangle_h
#define rectangle_h
using namespace std;

class Rectangle : public Shape{
public:
	typedef Shape Base;
	Rectangle(double w, double h)noexcept;
	Rectangle()noexcept;
	Rectangle(int objX, int objY)noexcept;

	void setWidth(Rectangle &r, const double w);
	void setHeight(Rectangle &r, const double h);/*This is the header file of rectangle class.*/
	inline int getWidth() const{ return width;}/*These are some kind of constant inline functions*/
	inline int getHeight()const{ return height;};
	int getX()noexcept;
	int getY()noexcept;
	void setCoordinates(Rectangle &r,int x,int y);
	virtual void draw(ostream &res)noexcept;

	double perimeter()noexcept;
	double area()noexcept;

	void setX(int xn){x = xn;}
	void setY(int yn){y = yn;}

	virtual Shape& operator++()noexcept
	{
		x++; y++;
		return *this;
	}
	virtual Rectangle& operator--()
	{

			x--; y--;

		return *this;
	}
	
	virtual Shape& operator++(int dummy)noexcept;
	virtual Shape& operator--(int dummy);
	

	const Rectangle operator+(double val)noexcept;
	const Rectangle operator-(double val)noexcept;

	bool operator==(Rectangle &ra)noexcept;

	static double calcPerimeters(Rectangle rn, double piece);
	static double calcAreas(Rectangle rn, double piece);

private:
	double width;
	double height;
	int x;
	int y;

};


#endif
