#include <fstream>
#ifndef rectangle_h
#define rectangle_h

class Rectangle{
public:
	Rectangle(int w, int h);
	Rectangle();
	void setWidth(Rectangle &r, const int w);
	void setHeight(Rectangle &r, const int h);/*This is the header file of rectangle class.*/
	inline int getWidth() const{ return width;}/*These are some kind of constant inline functions*/
	inline int getHeight()const{ return height;};
	int getX();
	int getY();
	void setCoordinates(Rectangle &r,int x,int y);
	void draw(Rectangle &r,int color,int x, int y, std::ofstream &res);
//private:
	int width;
	int height;
	int x;
	int y;

};

#endif


