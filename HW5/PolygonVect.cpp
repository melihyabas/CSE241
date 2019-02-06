#include "PolygonVect.h"

PolygonVect::PolygonVect()
{
	point2d point;
	point.x=0;
	point.y=0;
	Area = 0;

	v.push_back(point);
}

PolygonVect::PolygonVect(vector<polygon::point2d> vec)
{
	int i;
	for(i=0 ; i<vec.size() ; i++)
	{
		v.push_back(vec[i]);
	}
	Area = 0;
}

PolygonVect::PolygonVect(point2d& point)
{
	v.push_back(point);	
	Area = 0;

}

PolygonVect::PolygonVect(Rectangle& r)
{
	point2d p;
	p.x = r.getX();
	p.y = r.getY();
	v.push_back(p);

	p.x = r.getX();
	p.y = r.getY()+r.getHeight();	
	v.push_back(p);

	p.x = r.getX()+r.getWidth();
	p.y = r.getY()+r.getHeight();
	v.push_back(p);		

	p.x = r.getX()+r.getWidth();
	p.y = r.getY();
	v.push_back(p);	
	Area = (r.getWidth())*(r.getHeight());	
}

PolygonVect::PolygonVect(Triangle& t)
{
	point2d p;
	p.x = t.getX1();
	p.y = t.getY1();
	v.push_back(p);
	
	p.x = t.getX2();
	p.y = t.getY2();
	v.push_back(p);

	p.x = t.getX3();
	p.y = t.getY3();
	v.push_back(p);

	Area = (t.getSide())*(t.getSide())*(pow(3,0.5))/4;
}

PolygonVect::PolygonVect(Circle& c)
{
	point2d p;
	int i;
	int r = c.getRadius();/*Circle convertion constructor. Converts it a polygon.*/
	double a;

	a=2*PI/99;

	for(i=0 ; i<99 ; i++)
	{	
		p.x = r*cos(a)+c.getX();
		p.y = r*sin(a)+c.getY();

		v.push_back(p);		
		a+=(2*PI/99);
	}

	Area = PI*(c.getRadius())*(c.getRadius());
}


Shape& PolygonVect::operator++(int dummy)
{
	PolygonVect* temp;
	temp = new PolygonVect;

	int i;
	for(i=0 ; i<v.size() ; i++)
	{
		temp->v[i].x = v[i].x;
		temp->v[i].y = v[i].y;
	}

	for(i=0 ; i<v.size() ; i++)
	{
		(v[i].x)++;
		(v[i].y)++;
	}
	return *temp;
}

Shape& PolygonVect::operator--(int dummy)
{
	PolygonVect* temp;
	temp = new PolygonVect;

	int i;
	for(i=0 ; i<v.size() ; i++)
	{
		temp->v[i].x = v[i].x;
		temp->v[i].y = v[i].y;		
	}

	for(i=0 ; i<v.size() ; i++)
	{
		(v[i].x)++;
		(v[i].y)++;		
	}
	return *temp;
}

void PolygonVect::draw(ostream& res)
{
	int i;

	res<<"\n<polygon points=\"";      /*This function necessary to draw the given polygon shape. */ 	

	for(i=0 ; i<v.size() ; i++)
			 res<<" "<<v[i].x<<" "<<v[i].y;
	
	res<<"\" stroke = \"black\" fill=\"red\"></polygon>";

}


bool PolygonVect::operator ==(const PolygonVect& obj)
{	int i, count=0;
	if(v.size() == obj.v.size())
	{
		for(i=0 ; i<v.size() ; i++)
		{	
			if((v[i].x!=obj.v[i].x)||(v[i].y!=obj.v[i].y))
				count++;	
		}
	}
	if(count!=0)
		return false;
	else
		return true;
 /*Boolean operators to control equality.*/
} 

bool PolygonVect::operator !=(const PolygonVect& obj)
{
	int i, count=0;
	if(v.size() != obj.v.size())
			return true;
	if(v.size() == obj.v.size())
	{
		for(i=0 ; i<v.size() ; i++)
		{	
			if((v[i].x!=obj.v[i].x)||(v[i].y!=obj.v[i].y))
				return true;	
		}
	}

	return false;
 /*Boolean operators to control equality.*/
} 

polygon::point2d PolygonVect::operator [](int index)
{
    if (index>v.size() || index<0)
        exit(0);
	return v[index];
}
/*Index operators gives the value of given index.*/

const polygon::point2d PolygonVect::operator [](int index) const
{
    if (index>v.size() || index<0)
        cout<<"This index is invalid";
	return v[index];
}


