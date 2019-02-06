#include <fstream>
#ifndef triangle_h
#define triangle_h
using namespace std;
class Triangle{
public:
	Triangle(double s);/*This is the header file of triangle class.*/
	Triangle();
	void setSide(Triangle &t, const double s);
	void setCoord(Triangle &t,double a1, double b1, double a2, double b2, double a3, double b3);
	void draw(Triangle t,int color, double x1, double y1, double x2, double y2, double x3, double y3,std::ofstream &res);
	int getSide() const{return side;};
	inline int getX1()const{return x1;}
	inline int getY1()const{return y1;}/*These are some kind of constant inline functions*/
	inline int getX2()const{return x2;}
	inline int getY2()const{return y2;}
	inline int getX3()const{return x3;}
	inline int getY3()const{return y3;}
	double perimeter();
	double area();
	ostream& operator<<(ostream &res);
	inline const Triangle operator++()
	{	x1++;		y1++;	x2++;		y2++;	x3++;		y3++; return *this;}
	inline const Triangle operator--()
	{	x1--;	    y1--;	x2--;	    y2--;	x3--;	    y3--; return *this;}

	inline const Triangle operator++(int dummy)
	{	x1++;		y1++;	x2++;		y2++;	x3++;		y3++; return *this;}
	inline const Triangle operator--(int dummy)
	{	x1--;	    y1--;	x2--;	    y2--;	x3--;	    y3--; return *this;}

	const Triangle operator+(double val);
	const Triangle operator-(double val);

	bool operator==(Triangle &ta);

	static double calcPerimeters(Triangle tn, double piece);
	static double calcAreas(Triangle tn, double piece);


private:
	int side;
	int x1;
	int y1;
	int x2;/*These are coordinates of triangle.*/
	int y2;
	int x3;
	int y3;

};

#endif


