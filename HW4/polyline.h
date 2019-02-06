#include"polygon.h"
#ifndef polyline_h
#define polyline_h

class polyline{
public:
	polyline();
	polyline(Rectangle& r);
	polyline(Triangle& t);//convertion constructors
	polyline(Circle& c);	
	polyline(polygon::point2d& point);
	polyline(vector<polygon::point2d> vec);

	ostream& operator <<(ostream& res);
	bool operator ==(const polyline& obj);
	bool operator !=(const polyline& obj);
	const polyline operator +( const polyline& obj) const;	
	polygon::point2d operator [](int index);
	const polygon::point2d operator [](int index) const;
	
private:
	polygon pl;
};

#endif

