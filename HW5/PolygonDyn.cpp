#include "PolygonDyn.h"
PolygonDyn::PolygonDyn()
{
	vecPoints = new point2d[1];
	setDynamicSize(1);
	vecPoints[0].x = 0;	/*There is a default constructor if it needed.*/
	vecPoints[0].y	= 0;	
}
PolygonDyn::PolygonDyn(vector<polygon::point2d> vec)
{	

	vecPoints = new point2d[2*(vec.size())+1];
	setDynamicSize(2*(vec.size())+1);	/*This gets a vector of point2d and keep in this points in the dynamic memory. */

	int i = 0;
	while(i<vec.size())
	{
		vecPoints[i].x = vec[i].x;
		vecPoints[i].y = vec[i].y;
		i++;
	}
	Area = 0;
}

PolygonDyn::PolygonDyn(point2d& point)
{
	vecPoints = new point2d[1];	/*Gets a point and keep them in the dynamic memory.*/
	setDynamicSize(1);
	vecPoints[0].x = point.x;
	vecPoints[0].y	= point.y;		
	Area = 0;
			
}

PolygonDyn::PolygonDyn(Rectangle& r)
{
	vecPoints = new point2d[4];
	//x1=x, y1=y, x2=x, y2=y+height, x3=x+width, y3=y+height, x4=x+width, y4=y
	setDynamicSize(4);	

	vecPoints[0].x = r.getX();
	vecPoints[0].y = r.getY();	/*Rectangle convertion constructor. Converts it a polygon.*/
	vecPoints[1].x = r.getX();
	vecPoints[1].y = r.getY()+r.getHeight();
	vecPoints[2].x = r.getX()+r.getWidth();
	vecPoints[2].y = r.getY()+r.getHeight();
	vecPoints[3].x = r.getX()+r.getWidth();
	vecPoints[3].y = r.getY();
	Area = (r.getWidth())*(r.getHeight());

}

PolygonDyn::PolygonDyn(Triangle& t)
{
	vecPoints = new point2d[3];
	setDynamicSize(3);

	vecPoints[0].x = t.getX1();/*Triangle convertion constructor.*/
	vecPoints[0].y = t.getY1();
	vecPoints[1].x = t.getX2();
	vecPoints[1].y = t.getY2();
	vecPoints[2].x = t.getX3();
	vecPoints[2].y = t.getY3();	
	Area = (t.getSide())*(t.getSide())*(pow(3,0.5))/4;
}

PolygonDyn::PolygonDyn(Circle& c)
{
	int i;
	int r = c.getRadius();/*Circle convertion constructor. Converts it a polygon.*/
	double a;


	vecPoints = new point2d[99];
	setDynamicSize(99);

	a=2*PI/99;

	for(i=0 ; i<99 ; i++)
	{	
		vecPoints[i].x = r*cos(a)+c.getX();
		vecPoints[i].y = r*sin(a)+c.getY();
		
		a+=(2*PI/99);
	}
	Area = PI*(c.getRadius())*(c.getRadius());
}

Shape& PolygonDyn::operator++(int dummy)
{
	PolygonDyn* temp;
	temp = new PolygonDyn;

	int i;
	for(i=0 ; i<dynamicArraySize ; i++)
	{
		temp->vecPoints[i].x = (vecPoints[i].x);
		temp->vecPoints[i].y = (vecPoints[i].y);

	}

	for(i=0 ; i<dynamicArraySize ; i++)
	{
		(vecPoints[i].x)++;
		(vecPoints[i].y)++;

	}
	return *temp;
}

Shape& PolygonDyn::operator--(int dummy)
{
	PolygonDyn* temp;
	temp = new PolygonDyn;

	int i;
	for(i=0 ; i<dynamicArraySize ; i++)
	{
		temp->vecPoints[i].x = (vecPoints[i].x);
		temp->vecPoints[i].y = (vecPoints[i].y);
		
	}

	for(i=0 ; i<dynamicArraySize ; i++)
	{
		(vecPoints[i].x)--;
		(vecPoints[i].y)--;
	
	}
	return *temp;
}

int PolygonDyn::getDynamicSize() const
{
	return dynamicArraySize;	/*A getter function to get size of dynamic array.*/
}
void PolygonDyn::setDynamicSize(int sizeD)
{
	dynamicArraySize = sizeD;		/*A setter function to give size of dynamic array.*/
}


PolygonDyn::point2d* PolygonDyn::getVecPoints() const
{
	return vecPoints;		/*A getter function to get pointer.*/
}

PolygonDyn::PolygonDyn(const PolygonDyn& plObj)
	 :dynamicArraySize(plObj.dynamicArraySize)
{
	int i;
	vecPoints = new point2d[dynamicArraySize];/*This is a copy constructor. It needed for big three.*/
	for (i=0 ; i<dynamicArraySize ; i++)
		vecPoints[i] = plObj.vecPoints[i];
}

PolygonDyn& PolygonDyn::operator =(const PolygonDyn& rightSide)
{
	int i;
	if (dynamicArraySize != rightSide.dynamicArraySize)	/*Assignment operator to create big three.*/
	{
		delete [] vecPoints;
		vecPoints = new point2d[rightSide.dynamicArraySize];
	}

	dynamicArraySize = rightSide.dynamicArraySize;
	for(i=0 ; i<dynamicArraySize ; i++)
		vecPoints[i] = rightSide.vecPoints[i];

	return * this;
}

PolygonDyn::~PolygonDyn() 
{ 
    delete []vecPoints ; 
} 

void PolygonDyn::draw(ostream& res)
{
	int i;

	res<<"\n<polygon points=\"";      /*This function necessary to draw the given polygon shape. */ 	

	for(i=0 ; i<dynamicArraySize ; i++)
			 res<<" "<<vecPoints[i].x<<" "<<vecPoints[i].y;
	
	res<<"\" stroke = \"black\" fill=\"red\"></polygon>";

	
}

ostream& PolygonDyn::operator<<(ostream& res)
{
	int i;

	res<<"\n<polygon points=\"";      /*This function necessary to draw the given polygon shape. */ 	

	for(i=0 ; i<dynamicArraySize ; i++)
			 res<<" "<<vecPoints[i].x<<" "<<vecPoints[i].y;
	
	res<<"\" stroke = \"black\" fill=\"red\"></polygon>";

	return res;
}


bool PolygonDyn::operator ==(const PolygonDyn& obj)
{	int i, count=0;
	if(getDynamicSize() == obj.getDynamicSize())
	{
		for(i=0 ; i<getDynamicSize() ; i++)
		{	
			if((vecPoints[i].x!=obj.vecPoints[i].x)||(vecPoints[i].y!=obj.vecPoints[i].y))
				count++;	
		}
	}
	if(count!=0)
		return false;
	else
		return true;
 /*Boolean operators to control equality.*/
} 

bool PolygonDyn::operator !=(const PolygonDyn& obj)
{
	int i, count=0;
	if(getDynamicSize() != obj.getDynamicSize())
			return true;
	if(getDynamicSize() == obj.getDynamicSize())
	{
		for(i=0 ; i<getDynamicSize() ; i++)
		{	
			if((vecPoints[i].x!=obj.vecPoints[i].x)||(vecPoints[i].y!=obj.vecPoints[i].y))
				return true;	
		}
	}

	return false;
 /*Boolean operators to control equality.*/
} 

polygon::point2d PolygonDyn::operator [](int index)
{
    if (index>dynamicArraySize || index<0)
        exit(0);
	return vecPoints[index];
}
/*Index operators gives the value of given index.*/

const polygon::point2d PolygonDyn::operator [](int index) const
{
    if (index>dynamicArraySize || index<0)
        cout<<"This index is invalid";
	return vecPoints[index];
}

