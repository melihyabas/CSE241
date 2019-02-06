/*This program contains auto, decltype, inline, constant etc. C++ features.*/
#include <iostream>
#include <fstream>
#include <cmath>
#include"composedShape.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#define PI 3.1415
using namespace std;

ComposedShape::ComposedShape(Rectangle contR, Rectangle smallR)	
					:cR(contR), sR(smallR)			
{ }
ComposedShape::ComposedShape(Rectangle contR, Triangle smallT)
					:cR(contR), sT(smallT)			
{ }	/*Here, there are ComposedShape constructors. The are starting to composition.*/
ComposedShape::ComposedShape(Rectangle contR, Circle smallC)
					:cR(contR), sC(smallC)			
{ }
ComposedShape::ComposedShape(Triangle contT, Rectangle smallR)
					:cT(contT), sR(smallR)			
{ }
ComposedShape::ComposedShape(Triangle contT, Triangle smallT)
					:cT(contT), sT(smallT)
{ }

ComposedShape::ComposedShape(Triangle contT, Circle smallC)
					:cT(contT), sC(smallC)
{ }

ComposedShape::ComposedShape(Circle contC, Rectangle smallR)
					:cC(contC), sR(smallR)
{ }

ComposedShape::ComposedShape(Circle contC, Triangle smallT)
					:cC(contC), sT(smallT)
{ }

ComposedShape::ComposedShape(Circle contC, Circle smallC)
					:cC(contC), sC(smallC)
{ }

vector<Rectangle> ComposedShape::getVrec()
{
	return rec;
}				/*These are getter functions to get vectors from the class.*/
vector<Circle> ComposedShape::getVcirc()
{
	return circ;
}
vector<Triangle> ComposedShape::getVtri()
{
	return tri;
}


void ComposedShape::optimalFit(Rectangle contR, Rectangle smallR)
{
	ComposedShape::shapeElem s;
	s.shape = new Rectangle();
	s.shape = &smallR;
	s.width = smallR.getWidth();
	s.height = smallR.getHeight();
	s.x = smallR.getX();
	s.y = smallR.getY();

	int widthC = contR.getWidth(), heightC = contR.getHeight(), widthS = smallR.getWidth(); 

	decltype(widthC) heightS = smallR.getHeight();
	
	auto x=0, y=0,temp=0,count=0, count2=0, A=0;

	while(y+heightS<=heightC)/*The function that calculate how to compose a rectangle in a rectangle.*/
	{	
		count = 0;
		while(x+widthS<=widthC)
		{		
			smallR.setCoordinates(smallR,x,y);

			rec.push_back(smallR);
			x+=widthS;
			count++;
			A++;
		}
		y+=heightS;
		x = 0;	
		count2++;	
	}

	if((widthC-count*widthS<=widthC)&&(heightC>=heightS))
	{
		x=count*widthS;
		temp=widthS;
		widthS=heightS;	/*There may are some rotation for maximize our rectangles.*/
		heightS=temp;
		if(widthS<heightS)
		{
			while(x+widthS<=widthC)
			{
					y=0;
					while(y+heightS<=heightC)
					{
						smallR.setCoordinates(smallR,x,y);

						rec.push_back(smallR);				
						y+=heightS;
					A++;
					}	
				x+=widthS;

			}
			y+=heightS;
		}
		y=count2*widthS;
		if(widthS>heightS)
		{
			while(y+heightS<=heightC)
			{
				x=0;
				while(x+widthS<=widthC)
				{
					smallR.setCoordinates(smallR,x,y);

					rec.push_back(smallR);	/*All small rectangles keeped in a vector.*/
					x+=widthS;
					A++;
				}
				y+=heightS;

			}
		}
	
	}

}
void ComposedShape::optimalFit(Rectangle contR, Triangle smallT)
{

	shapeElem s;
	
	s.shape = &	smallT;
	s.q = shapes::Triangle;
	s.side = smallT.getSide();
	s.x1 = smallT.getX1();
	s.x2 = smallT.getX2();
	s.x3 = smallT.getX3();
	s.y1 = smallT.getY1();
	s.y2 = smallT.getY2();
	s.y3 = smallT.getY3();
	
	int side, wid, hei;
	auto A=0, x=0, y=0;
	double x1,y1,x2,y2,x3,y3;/*Coordinates to draw a triangle*/
	decltype(x1)xr1,yr1,xr2,yr2,xr3,yr3;
	wid = contR.getWidth();
	hei = contR.getHeight();
	side = smallT.getSide();	
	smallT.setCoord(smallT,x1,y1,x2,y2,x3,y3);

	if(side>wid||side>hei)
	{
		cout<<"Your triangle is too big for the rectangle!\n";
	}
	x1=(double)side/2;
	y1=0;	/*This function calculates how to draw maximum rectangle in another rectangle.*/
	x2=0;
	y2=((double)side/2)*pow(3,0.5);
	x3=side;
	y3=(((double)side/2)*pow(3,0.5));
	
	xr1=(double)side/2;
	yr1=0;	//r means "reverse"
	xr2=side;
	yr2=((double)side/2)*pow(3,0.5);
	xr3=side+(double)side/2;/*Double coordinates used all the time for triangles.*/
	yr3=0;
	
	while((hei-y2)>=0)
	{
	
		while((wid-x3)>=0)
		{	smallT.setCoord(smallT,x1,y1,x2,y2,x3,y3);

			tri.push_back(smallT);			
			x1+=side;
			x2+=side;
			x3+=side;
			A++;
		}
		x1=(double)side/2;
		x2=0;
		x3=side;
		y1+=((double)side/2)*pow(3,0.5);
		y2+=((double)side/2)*pow(3,0.5);
		y3+=((double)side/2)*pow(3,0.5);
	}
	while(hei-yr2>=0)
	{
		while((wid-xr3)>=0)
		{	smallT.setCoord(smallT,xr1,yr1,xr2,yr2,xr3,yr3);

			tri.push_back(smallT);/*All small triangles keeped in a vector.*/
			xr1+=side;
			xr2+=side;
			xr3+=side;
			A++;
		}
		xr1=(double)side/2;
		xr2=side;		/*reversed triangles coordinates.*/
		xr3=side+(double)side/2;
		yr1+=(double)(side/2)*pow(3,0.5);
		yr2+=(double)(side/2)*pow(3,0.5);
		yr3+=(double)(side/2)*pow(3,0.5);
	}

}

void ComposedShape::optimalFit(Rectangle contR, Circle smallC)
{
	shapeElem s;

	s.shape = &	smallC;
	s.q = shapes::Circle;
	s.radius = smallC.getRadius();
	s.cx = smallC.getX();
	s.cy = smallC.getY();

	int radius, cx, cy, wid, hei;
 	auto A=0, x=0, y=0;

	wid = contR.getWidth();
	hei = contR.getHeight();
	radius = smallC.getRadius();	/*This functions purpose is calculate how many circle could draw in a rectangle.*/

	if(radius*2>wid||radius>hei)
	{
		cout<<"Your radius input is too big for the rectangle!";
		return;
	}
	auto a = 0, c1=0, c2=0;
  cx = radius;
  cy = radius;
	while(cy+radius<=hei)
	{
		a++;
		while(cx+radius<=wid)
		{
			cx+=2*radius;
			c1++;
		} 
		if(a%2==0)
		{
			cy+=radius*2;
			cx=radius;
		}
		else
		{
			cy+=radius*pow(3,0.5);
			cx=2*radius;	
		}	
		
	}				/*First two loops are necessary to control which situation is better to draw maximum circle.*/
  cx = radius;
  cy = radius;

	c2=0;

	while(cy+radius<=hei)
	{
		while(cx+radius<=wid)
		{
			cx+=2*radius;
			c2++;
		} 
		cy+=2*radius;
		cx=radius;
		
	}
 	 cx = radius;
	 cy = radius;

	if(c1>c2)
	{
	a=0;
	int e=0;
	while(cy+radius<=hei)
	{
		a++;
		while(cx+radius<=wid)
		{

			smallC.setCoord(smallC,cx,cy);
			circ.push_back(smallC);
			cx+=2*radius;
				c1++;		/*This is our first situation.*/
				A++;	
			} 
			if(a%2==0)
			{	
				cx=radius;
			}
			else	/*Center coordinates of circle is changed.*/
			{
			
				cx=2*radius;	
			}	
			cy+=radius*pow(3,0.5);
			e++;
			
		}
	}
	else
	{
	while(cy+radius<=hei)
	{
		while(cx+radius<=wid)
		{

			smallC.setCoord(smallC,cx,cy);
			circ.push_back(smallC);
			cx+=2*radius;
			c2++;
			A++;
		} 
		cy+=2*radius;
		cx=radius;

	}
	}
}

void ComposedShape::optimalFit(Triangle contT, Rectangle smallR)
{

	shapeElem s;

	s.shape = &	smallR;
	s.q = shapes::Rectangle;
	s.width = smallR.getWidth();
	s.height = smallR.getHeight();
	s.x = smallR.getX();
	s.y = smallR.getY();

	int width, height, side;
	auto count=0, floor=1, A=0;
	double x, y, x1, y1, x2, y2, x3, y3;

	side = contT.getSide();
	
	width = smallR.getWidth();
	height = smallR.getHeight();

	x1=(double)side/2;
	y1=0;
	x2=0;		/*Determined coordinates of the container triangle. */
	y2=((double)side/2)*pow(3,0.5);
	x3=side;
	y3=(((double)side/2)*pow(3,0.5));

	
	if(width>=(x3-x2)/2||height>=(x3-x2)/2)
	{
		cout<<"Your rectangle is too big for the triangle!";
		return;
	}

	while(width<=(2*(y2-(height*floor))/(pow(3,0.5))))
	{
		y=y2-(height*floor);
		x = height/(double)(pow(3,0.5));
		x*=floor;
		count = 0;
		while(width*count+width<(2*(y2-(height*floor))/(pow(3,0.5))) )
		{	smallR.setCoordinates(smallR,x,y);

			rec.push_back(smallR);

			A++;
			x+=width;
			count++;
		}
		floor++;
	}

}

void ComposedShape::optimalFit(Triangle contT, Triangle smallT)
{
	shapeElem s;

	s.shape = &	smallT;
	s.q = shapes::Triangle;
	s.side = smallT.getSide();

	double side,sideC, xn1, yn1, xn2, yn2, xn3, yn3, xr1, yr1, xr2, yr2, xr3, yr3,x1,y1,x2,y2,x3,y3;
	auto A=0;
	
	sideC = contT.getSide();	

	x1=(double)sideC/2;
	y1=0;
	x2=0;	/*Container triangle's coordinates.*/
	y2=((double)sideC/2)*pow(3,0.5);
	x3=sideC;
	y3=(((double)sideC/2)*pow(3,0.5));

	side = smallT.getSide();

	if(side>(2*y2)/(pow(3,0.5)))
	{
		cout<<"Your side input is too big for the container shape!";
		return;
	}
	xn1=x1, yn1=0;
	xn2=(double)(x1-((double)side/2));/*To draw maximum triangle we have to rotate some triangle.*/
	yn2=(double)(((double)side/2)*pow(3,0.5));
	xn3=(double)(x1+(double)side/2);
	yn3=(double)(((double)side/2)*pow(3,0.5));
	/*xn is normal small triangle. xr is reverse triangle*/
	if(side*pow(3,0.5)>=y2 && (side/2)*pow(3,0.5)<=y2)
	{
		smallT.setCoord(smallT,xn1,yn1,xn2,yn2,xn3,yn3);

		tri.push_back(smallT);
		A++;	
	}

	if(side>(2*y2)/(pow(3,0.5)))
	{	smallT.setCoord(smallT,xn1,yn1,xn2,yn2,xn3,yn3);

		tri.push_back(smallT);
		A++;	
	}
	int i, n=1;
	while(yn2<=y2)
	{	smallT.setCoord(smallT,xn1,yn1,xn2,yn2,xn3,yn3);/*setting the coordinates of triangle.*/

		tri.push_back(smallT);	
		A++;
		for(i=1; i<n; i++)
		{
			xn1+=side;
			xn2+=side;
			xn3+=side;
		smallT.setCoord(smallT,xn1,yn1,xn2,yn2,xn3,yn3);

		tri.push_back(smallT);	
			A++;		
		}
		for(i=1; i<n; i++)
		{
			xn1-=side;
			xn2-=side;/*To put small triangles we have to chance coordinates.*/
			xn3-=side;
		}		
		n++;
		yn1+=(double)((side/2)*pow(3,0.5));
		yn2+=(double)((side/2)*pow(3,0.5));
		yn3+=(double)((side/2)*pow(3,0.5));
		xn1-=(double)	side/2;
		xn2-=(double)side/2;
		xn3-=(double)side/2;
	}								/*Written the coordinates of triangles.*/
	xr1=x1, yr1=(double)(side*pow(3,0.5));
	xr2=(double)(x1+((double)side/2));
	yr2=(double)((double)side/2)*pow(3,0.5);
	xr3=(double)(x1-(double)side/2);
	yr3=(double)(((double)side/2)*pow(3,0.5));

	 n=1;
	if(side*pow(3,0.5)<=y2)
	{
		while(yr1<=y2)
		{	smallT.setCoord(smallT,xr1,yr1,xr2,yr2,xr3,yr3);

			tri.push_back(smallT);
			A++;

			for(i=1; i<n; i++)
			{
				xr1+=side;
				xr2+=side;
				xr3+=side;

			smallT.setCoord(smallT,xr1,yr1,xr2,yr2,xr3,yr3);
			tri.push_back(smallT);	
				A++;		
			}
			for(i=1; i<n; i++)
			{
				xr1-=side;	/*The coordinates of reverse triangle are changed.*/
				xr2-=side;
				xr3-=side;
			}		
			n++;
			yr1+=(double)((side/2)*pow(3,0.5));
			yr2+=(double)((side/2)*pow(3,0.5));
			yr3+=(double)((side/2)*pow(3,0.5));
			xr1-=(double)(side/2);
			xr2-=(double)(side/2);
			xr3-=(double)(side/2);
		
		}

	}
}

void ComposedShape::optimalFit(Triangle contT, Circle smallC)
{
	shapeElem s;

	s.shape = &	smallC;
	s.q = shapes::Circle;
	s.radius = smallC.getRadius();

	double x1,y1,x2,y2,x3,y3;
	int radius, count=0, floor=1, oldcount=0, i, A=0, sideC;
	sideC = contT.getSide();
	radius = smallC.getRadius();
	x1=(double)sideC/2;
	y1=0;	/*Determined the container shape's coordinates*/
	x2=0;
	y2=((double)sideC/2)*pow(3,0.5);
	x3=sideC;
	y3=(((double)sideC/2)*pow(3,0.5));

	double cx,cy;

	if((x3-x2)<6*radius/(pow(3,0.5)))
	{
		cout<<"Your circle is too big for the triangle!\n";
	}
	
	cx=radius*(pow(3,0.5));
	cy=y2-radius;
	
	while(count*2*radius<=2*(y2-(floor*2*radius+radius))/(pow(3,0.5)))
	{
		smallC.setCoord(smallC,cx,cy);
		circ.push_back(smallC);
		
		count++;
		cx+=2*radius;
	}
	count+=1;
	oldcount=count;
	count=0;
	cx=radius*(pow(3,0.5));
	cy=y2-radius;
	
	
	/*This function written to draw maximum count of circle in a triangle.*/
	while(floor*radius*(pow(3,0.5))<=y2)
	{
		for(i=0;i<oldcount-1;i++)
		{

			smallC.setCoord(smallC,cx,cy);
			circ.push_back(smallC);
			A++;
			count++;
			cx+=2*radius;

		}
		oldcount=count;
		count=0;
		cx=radius*(pow(3,0.5))+floor*radius;
		cy-=radius*pow(3,0.5);
		floor++;
	}
}

void ComposedShape::optimalFit(Circle contC, Rectangle smallR)
{
	shapeElem s;

	s.shape = &	smallR;
	s.q = shapes::Rectangle;
	s.width = smallR.getWidth();
	s.height = smallR.getHeight();
	s.x = smallR.getX();
	s.y = smallR.getY();

	int width, height, count = 1,i,j,A=0,radius, x,y,oldx;

	radius = contC.getRadius();

	width = smallR.getWidth();
	height = smallR.getHeight();
	x = smallR.getX();
	y = smallR.getY();

	/*Circle is too hard to use a container. So we had to determine our start point better.*/
	x=radius-width/2;
	y=radius-(pow((pow(radius,2)-pow((width/2),2)),0.5));
	

	while(y+height<2*radius&& y<radius)
	{	
			while(pow(((x+width-radius)*(x+width-radius)+(y-radius)*(y-radius)),0.5)<radius)
			{
			smallR.setCoordinates(smallR,x,y);

			rec.push_back(smallR);
			A++;
			x+=width;
			count++;
			}
			y+=height;
			smallR.setCoordinates(smallR,x,y);

		x=radius-pow(pow(radius,2)-pow((y-radius),2),0.5);
		smallR.setCoordinates(smallR,x,y);
	}
	x+=width/2;
	oldx=x;
	smallR.setCoordinates(smallR,x,y);
	while(y>radius && y<2*radius+height+height)
	{	
	
		
		while(pow(((x+width-radius)*(x+width-radius)+(y-radius)*(y-radius)),0.5)+width<radius)
		{
			smallR.setCoordinates(smallR,x,y);

			rec.push_back(smallR);
			A++;
			x+=width;
			smallR.setCoordinates(smallR,x,y);			
		}
		y+=height;
		x=oldx+width/2;	
		oldx+=width;	
		smallR.setCoordinates(smallR,x,y);
	}		

}

void ComposedShape::optimalFit(Circle contC, Triangle smallT)
{
	shapeElem s;

	s.shape = &	smallT;
	s.q = shapes::Triangle;
	s.side = smallT.getSide();
	s.x1 = smallT.getX1();
	s.x2 = smallT.getX2();
	s.x3 = smallT.getX3();
	s.y1 = smallT.getY1();
	s.y2 = smallT.getY2();
	s.y3 = smallT.getY3();

	int wid, hei, side, x1,y1,x2,y2,x3,y3,xr1,yr1,xr2,yr2,xr3,yr3, A=0, radius;
	radius = contC.getRadius();
	side = smallT.getSide();

	if(side>=radius*3/2)
	{
		cout<<"Your triangle is too big for the circle!";
		return;
	}
	wid=radius*pow(2,0.5);
	hei=radius*pow(2,0.5);
	x1=(double)((radius-wid/2)+(double)side/2);
	y1=(double)(radius-wid/2);
	x2=(double)(radius-wid/2);/*These are normal and rotated triangles all coordinates.*/
	y2=(double)((side/2)*pow(3,0.5)+(radius-wid/2));
	x3=(double)(side+(radius-wid/2));
	y3=(double)((side/2)*pow(3,0.5)+(radius-wid/2));
/*To make a true work, some we did some type castings here.*/
	xr1=(double)((radius-wid/2)+(double)side/2);
	yr1=(double)(radius-wid/2);	//r means "reverse"
	xr2=(double)(side+(radius-wid/2));
	yr2=(double)((radius-wid/2)+((double)side/2)*pow(3,0.5));
	xr3=(double)((radius-wid/2)+side+(double)side/2);
	yr3=(double)(radius-wid/2);

	while(y3<=radius+wid/2)
	{
	
		while(x3<=radius+wid/2)
		{

			smallT.setCoord(smallT,x1,y1,x2,y2,x3,y3);
			tri.push_back(smallT);
			
			A++;
			x1+=side;
			x2+=side;
			x3+=side;
		}
		x1=(double)((radius-wid/2)+(double)side/2);
		x2=(double)((radius-wid/2));
		x3=(double)(side+(radius-wid/2));
		y1+=(double)((side/2)*pow(3,0.5));	/*The coordinates determined again.*/
		y2+=(double)((side/2)*pow(3,0.5));
		y3+=(double)((side/2)*pow(3,0.5));
	}
	while(yr3<=radius+wid/2)
	{
		while(xr3<=radius+wid/2)
		{

			smallT.setCoord(smallT,xr1,yr1,xr2,yr2,xr3,yr3);
			tri.push_back(smallT);
			A++;
			xr1+=side;
			xr2+=side;
			xr3+=side;
		}
	
		xr1=(double)((radius-wid/2)+(double)side/2);
		xr2=(double)(side+(radius-wid/2));
		xr3=(double)((radius-wid/2)+side+(double)side/2);/*The reversed coordinates determined again.*/
		yr1+=(double)((side/2)*pow(3,0.5));
		yr2+=(double)((side/2)*pow(3,0.5));
		yr3+=(double)((side/2)*pow(3,0.5));
	}

}

void ComposedShape::optimalFit(Circle contC, Circle smallC)
{
	shapeElem s;

	s.shape = &	smallC;
	s.q = shapes::Circle;
	s.radius = smallC.getRadius();

	int r,radius, cx, cy, wid, hei, A=0;
	radius = contC.getRadius();
	r = smallC.getRadius();
	if(r>radius)
	{
		cout<<"Your circle is too big for the circle\n";
		return;
	}

	hei = radius*(pow(2,0.5));
	wid = radius*(pow(2,0.5));

	cx = radius-(wid/2)+r;
	cy = radius-(wid/2)+r;
	
/*This is the last part of our program. This function written to calculate how many times circle draws in a circle*/
	
	if(2*r>radius)
	{
		cx=radius;
		cy= radius;

		smallC.setCoord(smallC,cx,cy);
		circ.push_back(smallC);
		A++;/*Here our svg circle code.*/
		return;
	}
	if(4*r>radius)
	{
		while(cy<=hei)
		{
			while(cx<=wid)
			{

				smallC.setCoord(smallC,cx,cy);
				circ.push_back(smallC);
				A++;
				cx+=2*r;
			} 
			cy+=2*r;
			cx = radius-(wid/2)+r;	
		}
	}
	else
	{
		while(cy-2*r<=hei)
		{
			while(cx-2*r<=wid)
			{

				smallC.setCoord(smallC,cx,cy);
				circ.push_back(smallC);
				A++;
				cx+=2*r;
			} 
			cy+=2*r;
			cx = radius-(wid/2)+r;	
		}
	}
}

void ComposedShape::draw(vector<Rectangle> rec, ofstream &res)
{

	int width, height, x, y, i;
	for(i=0 ; i<rec.size() ; i++)
	{
		x = rec[i].getX();	/*The function draws rectangle type vector's members*/
		y = rec[i].getY();
		width = rec[i].getWidth();
		height=	rec[i].getHeight();

		res<<"<rect x=\""<<x<<"\" y=\""<<y<<"\" stroke=\"Black\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"green\"></rect>"<<endl;	
	}
}
	
void ComposedShape::draw(vector<Circle> circ, ofstream &res)
{
	double cx, cy;
	int radius, i;
	
	
	for(i=0 ; i<circ.size() ; i++)/*The function draws circle type vector's members*/
	{
		cx = circ[i].getX();
		cy = circ[i].getY();
		radius = circ[i].getRadius();

		res<<"<circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"green\" />\n";
	}
}

void ComposedShape::draw(vector<Triangle> tri, ofstream &res)
{
	double x1,y1,x2,y2,x3,y3;
	int i;

	for(i=0 ; i<tri.size() ; i++)
	{
		x1 = tri[i].getX1();
		y1 = tri[i].getY1();
		x2 = tri[i].getX2();	/*The function draws triangle type vector's members*/
		y2 = tri[i].getY2();
		x3 = tri[i].getX3();
		y3 = tri[i].getY3();
		res<<"\n<polygon points=\""<<x1<<" "<<y1<<" "<< x2 <<" "<< y2 <<" "<< x3 <<" "<< y3 <<" \" stroke = \"black\" fill=\"green\"></polygon>";
	}
}

double ComposedShape::shapeElem::perimeter()
{
	if(q==shapes::Rectangle)
		return 2*(width+height);
	if(q==shapes::Circle)
		return PI*2*radius;
	if(q==shapes::Triangle)
		return side*3;
}

double ComposedShape::shapeElem::area()
{
	if(q==shapes::Rectangle)
		return width*height;
	if(q==shapes::Circle)
		return PI*radius*radius;
	if(q==shapes::Triangle)
		return side*side*pow(3,0.5)/4;
}

ostream& ComposedShape::shapeElem::operator<<(ostream &res)
{
	if(q==shapes::Rectangle)
	{
		res<<"<svg version=\"1.1\"\nbaseProfile=\"full\"\n  width=\""<<width<<"\" height=\""<<height<<"\"\nxmlns=\"http://www.w3.org/2000/svg\">\n";
		res<<"<rect x=\""<<x<<"\" y=\""<<y<<"\" stroke=\"Black\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"red\"></rect>"<<endl;
	}
	if(q==shapes::Circle)
	{
		res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";		
		res<<"<circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"red\" />\n";		
	}
	if(q==shapes::Triangle)
	{
		res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
		res<<"\n<polygon points=\""<<x1<<" "<<y1<<" "<<x2 <<" "<<y2 <<" "<<x3 <<" "<<y3<<" \" stroke = \"black\" fill=\"red\"></polygon>";			
	}		
	
	return res;
}

