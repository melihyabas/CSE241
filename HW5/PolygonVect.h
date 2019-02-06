#include "polygon.h"
#include <vector>

#ifndef PolygonVect_h
#define PolygonVect_h

class PolygonVect : public polygon{
public:
	PolygonVect();
	PolygonVect(vector<polygon::point2d> vec);
	PolygonVect(point2d& point);	//Constructors
	PolygonVect(Rectangle& r);
	PolygonVect(Triangle& t);//These are convertion constructors for shapes.
	PolygonVect(Circle& c);	

	virtual Shape& operator++(int dummy);
	virtual Shape& operator--(int dummy);

	virtual Shape& operator++()
	{
		int i;
		for(i=0 ; i<v.size() ; i++)
		{
			v[i].x++;
			v[i].y++;			
		}
		return *this;
		
	}
	virtual Shape& operator--()
	{
		int i;
		for(i=0 ; i<v.size() ; i++)
		{
			v[i].x--;
			v[i].y--;
		}
		return *this;
	}	
	virtual void draw(ostream& res);		
	bool operator ==(const PolygonVect& obj);/*These functions control equality of objects.*/
	bool operator !=(const PolygonVect& obj);
	point2d operator [](int index); /*Converts from a 2 dimentional point.*/
	const point2d operator [](int index) const; /*Gives the value of given index.*/

private:
	vector<point2d> v;	

};





#endif

