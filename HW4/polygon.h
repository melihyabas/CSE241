#include<iostream>
#include<cmath>
#include "rectangle.h"
#include "triangle.h"/*Some necessary libraries.*/
#include "circle.h"
#include <vector>

#ifndef polygon_h
#define polygon_h
#define PI 3.1415
using namespace std;
using namespace melih;/*Some necessary namespaces.*/
using namespace gtu; 	
using namespace istanbul;
class polygon{
public:
	class point2d{
	public:
		int getX() const;
		int getY() const;/*This class hold a 2 dimentional point.*/
		void setX(int a);
		void setY(int b);
		int x;
		int y;
	};
	polygon();
	polygon(point2d& point);	//Constructors
	polygon(vector<point2d> vec);	

	polygon(Rectangle& r);
	polygon(Triangle& t);//These are convertion constructors for shapes.
	polygon(Circle& c);

	polygon(const polygon& plObj); //copy constructor
	polygon& operator =(const polygon& rightSide);	//assignment operator
	~polygon();
	ostream& operator <<(ostream& res);  /*This operator writes svg code to the file.*/
	friend bool operator ==(const polygon& obj1,const polygon& obj2);/*These functions control equality of objects.*/
	friend bool operator !=(const polygon& obj1,const polygon obj2);
	const polygon operator +( const polygon& obj) const;	/*Creates a new object from given 2 object.*/
	point2d operator [](int index); /*Converts from a 2 dimentional point.*/
	const point2d operator [](int index) const; /*Gives the value of given index.*/

	int getDynamicSize() const;
	void setDynamicSize(int sizeD);/*Necessary getter and setter functions.*/
	point2d* getVecPoints() const;
	void setPoints(point2d* point);

  
private:
	point2d* vecPoints;/*A dynamic array to keep 2 dimentional points.*/
	int dynamicArraySize; /* Size of dynamic array. */
};

#endif

