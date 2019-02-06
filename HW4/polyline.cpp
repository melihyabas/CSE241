#include "polyline.h"
polyline::polyline()
{ }
polyline::polyline(vector<polygon::point2d> vec)
{ 
	pl = polygon(vec);
}
	
polyline::polyline(polygon::point2d& point)
{
	pl = polygon(point);
}

polyline::polyline(Rectangle& r)
{
	pl = polygon(r);
}

polyline::polyline(Triangle& t)
{
	pl = polygon(t);
}

polyline::polyline(Circle& c)
{
	pl = polygon(c);
}

polygon::point2d polyline::operator [](int index)
{
	return pl[index];
}

polygon::point2d const polyline::operator [](int index) const
{
	return pl[index];
}

bool polyline::operator == (const polyline& obj)
{
	return (pl == obj.pl);
}

bool polyline::operator != (const polyline& obj)
{
	return (pl == obj.pl);
}

polyline const polyline::operator +( const polyline& obj) const
{
	int i;
	
	vector<polygon::point2d> v;
	
	for(i=0 ; i<pl.getDynamicSize() ; i++)
	{
		v.push_back(pl[i]);
	}
	for(i=0 ; i<obj.pl.getDynamicSize() ; i++)
	{
		v.push_back(obj.pl[i]);
	}

	return polyline(v);	
}

ostream& polyline::operator <<(ostream& res)
{
	int i;
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	res<<"\n<polyline points=\"";       	

	for(i=0 ; i<pl.getDynamicSize() ; i++)
			 res<<" "<<pl[i].x<<" "<<pl[i].y;
	res<<"\" stroke = \"blue\" stroke-width=\"5\" fill=\"red\"></polyline>";

	return res;

}


