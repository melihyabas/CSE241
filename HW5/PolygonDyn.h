#include "polygon.h"

#ifndef PolygonDyn_h
#define PolygonDyn_h

class PolygonDyn : public polygon{

public:
	PolygonDyn();
	PolygonDyn(vector<polygon::point2d> vec);
	PolygonDyn(point2d& point);
	PolygonDyn(Rectangle& r);
	PolygonDyn(Triangle& t);//These are convertion constructors for shapes.
	PolygonDyn(Circle& c);	

	PolygonDyn(const PolygonDyn& plObj); //copy constructor
	PolygonDyn& operator =(const PolygonDyn& rightSide);	//assignment operator
	~PolygonDyn();

	virtual Shape& operator++(int dummy);
	virtual Shape& operator--(int dummy);

	virtual Shape& operator++()
	{
		int i;
		for(i=0 ; i<dynamicArraySize ; i++)
		{
			(vecPoints[i].x)++;
			(vecPoints[i].y)++;	
		}
		return *this;
		
	}
	virtual Shape& operator--()
	{
		int i;
		for(i=0 ; i<dynamicArraySize ; i++)
		{
			(vecPoints[i].x)--;
			(vecPoints[i].y)--;
		}
		return *this;
	}	
	virtual void draw(ostream& res);		
	ostream& operator <<(ostream& res);  /*This operator writes svg code to the file.*/

	bool operator ==(const PolygonDyn& obj);/*These functions control equality of objects.*/
	bool operator !=(const PolygonDyn& obj);
	point2d operator [](int index); /*Converts from a 2 dimentional point.*/
	const point2d operator [](int index) const; /*Gives the value of given index.*/
	
	int getDynamicSize() const;
	void setDynamicSize(int sizeD);/*Necessary getter and setter functions.*/
	point2d* getVecPoints() const;
private:
	point2d* vecPoints;/*A dynamic array to keep 2 dimentional points.*/
	int dynamicArraySize; /* Size of dynamic array. */		
};


#endif

