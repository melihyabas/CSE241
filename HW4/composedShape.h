#include<iostream>
#include<cmath>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <vector>
#ifndef composedShape_h
#define composedShape_h
#define PI 3.1415
#include "polygon.h"
#include "polyline.h"
using namespace std;
using namespace melih; 
using namespace istanbul;

enum class shapes{
	Rectangle,
	Circle,
	Triangle
};

class ComposedShape{
/*Therefore, it has only a vector of Polygon objects in it.
All the other functions and operator overloads are the same as HW2 and HW3.*/
public:
	class shapeElem{ 	
	public:
		shapeElem(Rectangle* r);
		shapeElem(Triangle* t);
		shapeElem(Circle* c);
		shapes q;

		ostream& operator<<(ostream &res);
		/*This is a class in ComposedShape class that holds on a shape object.*/
		double perimeter();
		double area();
		void* getPtr() { return shape;}

	private:
		void* shape;

	};
	ComposedShape operator +=(const polygon& obj);
	ComposedShape();
	ComposedShape(Rectangle contR, Rectangle smallR);
	ComposedShape(Rectangle contR, Triangle smallT);
	ComposedShape(Rectangle contR, Circle smallC);/*These are overloaded constructors for composition*/

	ComposedShape(Triangle contT, Rectangle smallR);
	ComposedShape(Triangle contT, Triangle smallT);
	ComposedShape(Triangle contT, Circle smallC);

	ComposedShape(Circle contC, Rectangle smallR);
	ComposedShape(Circle contC, Triangle smallT);
	ComposedShape(Circle contC, Circle smallC);
/*First argument for container shape, Second argument for small shape*/
	void optimalFit(Rectangle contR, Rectangle smallR);
	void optimalFit(Rectangle contR, Triangle small);
	void optimalFit(Rectangle contR, Circle small);

	void optimalFit(Triangle contT, Rectangle smallR);/*These are overloaded optimal fit function. There are 9 situation.*/
	void optimalFit(Triangle contT, Triangle smallT);
	void optimalFit(Triangle contT, Circle smallC);

	void optimalFit(Circle contC, Rectangle smallR);
	void optimalFit(Circle contC, Triangle smallT);
	void optimalFit(Circle contC, Circle smallC);

	void draw(vector<Rectangle> rec, ofstream &res);
	void draw(vector<Triangle> tri, ofstream &res);
	void draw(vector<Circle> circ, ofstream &res);
	
	vector<polygon> getVec();
private:
	vector<polygon> vec;

	Rectangle cR;
	Rectangle sR;/*c is Container. s is small*/
	Triangle cT;
	Triangle sT;
	Circle cC;
	Circle sC;

};

#endif
