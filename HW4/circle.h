#include <fstream>
#ifndef circle_h
#define circle_h
/*++ ve -- operatörlerinde set coordinates return edilmeli*/
/*Bunların alt satıra ve yana gitme durumlarını düşün.*/
using namespace std;

namespace istanbul{

class Circle{
public:
	Circle(double r);
	Circle();
	void setRadius(Circle &c, double const r);
	int getRadius() const{return radius;};	/*This is the header file of circle class.*/
	inline int getX() const{return cx;};/*These are some kind of inline functions*/
	inline int getY() const{return cy;};
	void setCoord(Circle &c, int a, int b);
	double perimeter();
	double area();
	ostream& operator<<(ostream &res);
	inline const Circle operator++()
	{	cx++;	cy++;   return *this;	}
	inline const Circle operator--()
	{	cx--;	cy--;	return *this; }

	const Circle operator++(int dummy);
	const Circle operator--(int dummy);
	
	const Circle operator+(double val);
	const Circle operator-(double val);
	bool operator==(Circle &ca);

	static double calcPerimeters(Circle cn, double piece);
	static double calcAreas(Circle cn, double piece);

private:
	double radius;
	int cx;
	int cy;

};

};

#endif


