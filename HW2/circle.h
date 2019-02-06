#include <fstream>
#ifndef circle_h
#define circle_h

class Circle{
public:
	Circle(int r);
	Circle();
	void setRadius(Circle &c, int const r);
	int getRadius();	/*This is the header file of circle class.*/
	inline int getX(){return cx;};/*These are some kind of inline functions*/
	inline int getY(){return cy;};
	void setCoord(Circle &c, int a, int b);
	void draw(Circle &c, int color,int x, int y, std::ofstream &res);
private:
	int radius;
	int cx;
	int cy;

};

#endif


