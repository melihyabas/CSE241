#include <fstream>
#include "shape.h"
#ifndef circle_h
#define circle_h

using namespace std;

namespace istanbul{

class Circle : public Shape{
public:
	Circle(double r)noexcept;
	Circle()noexcept;
	void setRadius(Circle &c, double const r)throw(string);
	int getRadius() const{return radius;};	/*This is the header file of circle class.*/
	inline int getX() const{return x;};/*These are some kind of inline functions*/
	inline int getY() const{return y;};
	void setCoord(Circle &c, int a, int b);
	void setX(int xn){x = xn;}
	void setY(int yn){y = yn;}
	double perimeter();
	double area();
	ostream& operator<<(ostream &res);
	virtual void draw(ostream& res);	

	virtual Shape& operator++()
	{
		x++; y++;
		return *this;
	}
	virtual Shape& operator--()
	{
		x--; y--;
		return *this;
	}
	
	virtual Shape& operator++(int dummy);
	virtual Shape& operator--(int dummy);
	bool operator==(Circle &ca);
	
	const Circle operator+(double val);
	const Circle operator-(double val);

	static double calcPerimeters(Circle cn, double piece);
	static double calcAreas(Circle cn, double piece);

private:
	double radius;
	int x;
	int y;

};

};

#endif


