#include <fstream>
#ifndef rectangle_h
#define rectangle_h
using namespace std;

namespace melih{

class Rectangle{
public:
	Rectangle(double w, double h);
	Rectangle();
	void setWidth(Rectangle &r, const double w);
	void setHeight(Rectangle &r, const double h);/*This is the header file of rectangle class.*/
	inline int getWidth() const{ return width;}/*These are some kind of constant inline functions*/
	inline int getHeight()const{ return height;};
	int getX();
	int getY();
	void setCoordinates(Rectangle &r,int x,int y);
	void draw(Rectangle &r,int color,int x, int y, std::ofstream &res);
	double perimeter();
	double area();
	ostream& operator<<(ostream &res);
	inline const Rectangle operator++()
	{	x++;		y++; return *this;	}
	inline const Rectangle operator--()
	{	x--;		y--; return *this;	}

	const Rectangle operator++(int dummy);

	const Rectangle operator--(int dummy);

	const Rectangle operator+(double val);
	const Rectangle operator-(double val);

	bool operator==(Rectangle &ra);

	static double calcPerimeters(Rectangle rn, double piece);
	static double calcAreas(Rectangle rn, double piece);

private:
	double width;
	double height;
	int x;
	int y;

};

};

#endif
