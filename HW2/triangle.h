#include <fstream>
#ifndef triangle_h
#define triangle_h

class Triangle{
public:
	Triangle(int s);/*This is the header file of triangle class.*/
	Triangle();
	void setSide(Triangle &t, const int s);
	void setCoord(Triangle &t,double a1, double b1, double a2, double b2, double a3, double b3);
	void draw(Triangle t,int color, double x1, double y1, double x2, double y2, double x3, double y3,std::ofstream &res);
	int getSide();
	inline int getX1()const{return x1;}
	inline int getY1()const{return y1;}/*These are some kind of constant inline functions*/
	inline int getX2()const{return x2;}
	inline int getY2()const{return y2;}
	inline int getX3()const{return x3;}
	inline int getY3()const{return y3;}
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


