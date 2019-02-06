#include <fstream>
#include "shape.h"
#ifndef triangle_h
#define triangle_h
using namespace std;

namespace gtu{


class Triangle : public Shape{
public:
	Triangle(double s)noexcept;/*This is the header file of triangle class.*/
	Triangle()noexcept;
	void setSide(Triangle &t, const double s);
	void setCoord(Triangle &t,double a1, double b1, double a2, double b2, double a3, double b3);
	void draw(Triangle t,int color, double x1, double y1, double x2, double y2, double x3, double y3,std::ofstream &res);
	int getSide() const noexcept{return side;};
	inline int getX1()const noexcept{return x1;}
	inline int getY1()const noexcept{return y1;}/*These are some kind of constant inline functions*/
	inline int getX2()const noexcept{return x2;}
	inline int getY2()const noexcept{return y2;}
	inline int getX3()const noexcept{return x3;}
	inline int getY3()const noexcept{return y3;}
	double perimeter();
	double area();

	virtual void draw(ostream& res)noexcept;	
	void setX1(int x1n)noexcept{x1 = x1n;}
	void setY1(int y1n)noexcept{y1 = y1n;}
	void setX2(int x2n)noexcept{x2 = x2n;}
	void setY2(int y2n)noexcept{y2 = y2n;}
	void setX3(int x3n)noexcept{x3 = x3n;}
	void setY3(int y3n)noexcept{y3 = y3n;}		
	virtual Shape& operator++()noexcept
	{	x1++;		y1++;	x2++;		y2++;	x3++;		y3++; return *this;}	
	virtual Shape& operator--()
	{

			x1--;	    y1--;	x2--;	    y2--;	x3--;	    y3--; return *this;
 
	}
	
	virtual Shape& operator++(int dummy)noexcept;
	virtual Shape& operator--(int dummy);


	const Triangle operator+(double val)noexcept;
	const Triangle operator-(double val)noexcept;

	bool operator==(Triangle &ta);

	static double calcPerimeters(Triangle tn, double piece)noexcept;
	static double calcAreas(Triangle tn, double piece)noexcept;

private:
	int side;
	int x1;
	int y1;
	int x2;/*These are coordinates of triangle.*/
	int y2;
	int x3;
	int y3;

};

};

#endif


