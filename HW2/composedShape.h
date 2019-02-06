#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <vector>
#ifndef composedShape_h
#define composedShape_h

using namespace std;

class ComposedShape{
public:
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
	
	vector<Rectangle> getVrec();
	vector<Circle> getVcirc();		/*These are vectors of shapes.*/
	vector<Triangle> getVtri();

private:
	Rectangle cR;
	Rectangle sR;/*c is Container. s is small*/
	Triangle cT;
	Triangle sT;
	Circle cC;
	Circle sC;

	vector<Rectangle> rec;	
	vector<Circle> circ;
	vector<Triangle> tri;
};

#endif
