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
ComposedShape::ComposedShape()
{ 

	Rectangle cR;
	Rectangle sR;/*c is Container. s is small*/
	Triangle cT;
	Triangle sT;
	Circle cC;
	Circle sC;
	cR.setX(0);
	cR.setY(0);

	sR.setX(0);
	sR.setY(0);

	cC.setX(0);
	cC.setY(0);

	sC.setX(0);
	sC.setY(0);

	cT.setX1(0);
	cT.setY1(0);
	cT.setX2(0);
	cT.setY2(0);
	cT.setX3(0);
	cT.setY3(0);

	sT.setX1(0);
	sT.setY1(0);
	sT.setX2(0);
	sT.setY2(0);
	sT.setX3(0);
	sT.setY3(0);

}
ComposedShape::ComposedShape(Rectangle& contR, Rectangle& smallR)	
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


ComposedShape ComposedShape::operator +=(const PolygonDyn& obj)
{
	vec.push_back(obj);
}

void ComposedShape::draw(ostream& res)
{
	cR.draw(res);
	sR.draw(res);
	cT.draw(res);
	sT.draw(res);
	cC.draw(res);
	sC.draw(res);

}	

void ComposedShape::optimalFit(Rectangle& contR, Rectangle& smallR)
{
	PolygonDyn contP(contR);
	vec.push_back(contP);

	Rectangle* RecPtr = new Rectangle;
	RecPtr->setCoordinates(*RecPtr, contR.getX(), contR.getY());
	RecPtr->setWidth(*RecPtr, contR.getWidth());
	RecPtr->setHeight(*RecPtr, contR.getHeight());
	shapeVec.push_back(RecPtr);	


	Rectangle* smallPtr = new Rectangle(smallR);
	smallPtr->setCoordinates(*smallPtr,0,0);
	smallPtr->setWidth(*smallPtr, contR.getWidth());
	smallPtr->setHeight(*smallPtr, contR.getHeight());
	shapeVec.push_back(smallPtr);	

	int widthC = contR.getWidth(), heightC = contR.getHeight(), widthS = smallR.getWidth(); 

	decltype(widthC) heightS = smallR.getHeight();
	
	auto x=0, y=0,temp=0,count=0, count2=0, A=0;

	while(y+heightS<=heightC)/*The function that calculate how to compose a rectangle in a rectangle.*/
	{	
		count = 0;
		while(x+widthS<=widthC)
		{		
			smallR.setCoordinates(smallR,x,y);
			PolygonDyn smallP(smallR);
			vec.push_back(smallP);			
			smallPtr = new Rectangle(smallR);
			smallPtr->setCoordinates(*smallPtr,x,y);
			shapeVec.push_back(smallPtr);	
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
						smallPtr = new Rectangle(smallR);
						smallR.setCoordinates(smallR,x,y);
						PolygonDyn smallP(smallR);
						vec.push_back(smallP);	

						smallPtr->setCoordinates(*smallPtr,x,y);
						shapeVec.push_back(smallPtr);
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
					smallPtr = new Rectangle(smallR);
					smallR.setCoordinates(smallR,x,y);
					PolygonDyn smallP(smallR);
					vec.push_back(smallP);
					smallPtr->setCoordinates(*smallPtr,x,y);
					shapeVec.push_back(smallPtr);
	
					x+=widthS;
					A++;
				}
				y+=heightS;

			}
		}
	
	}
	ofstream res;
	res.open("RectangleInRectangle.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	Rectangle* r = dynamic_cast<Rectangle*>(shapeVec[0]);

	r->draw(res);
	int i;
	for(i=1 ; i<vec.size() ; i++)
	{
		Rectangle* r = dynamic_cast<Rectangle*>(shapeVec[i]);

		r->draw(res);
	}
	res<<"</svg>";
	res.close();


	//printAll(shapeVec);
}
void ComposedShape::optimalFit(Rectangle contR, Triangle smallT)
{
	Triangle* smallPtr = new Triangle;
	Rectangle* RecPtr = new Rectangle;
	vec.push_back(contR);
	RecPtr->setCoordinates(*RecPtr, contR.getX(), contR.getY());
	RecPtr->setWidth(*RecPtr, contR.getWidth());
	RecPtr->setHeight(*RecPtr, contR.getHeight());
	shapeVec.push_back(RecPtr);	
	smallPtr->setCoord(*smallPtr,smallT.getX1(),smallT.getY1(),smallT.getX2(),smallT.getY2(),smallT.getX3(),smallT.getY3());

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
		{	
			smallPtr = new Triangle;
			smallT.setCoord(smallT,x1,y1,x2,y2,x3,y3);
			PolygonDyn smallP(smallT);
			vec.push_back(smallT);	
			smallPtr->setCoord(*smallPtr,x1,y1,x2,y2,x3,y3);
			shapeVec.push_back(smallPtr);				
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
		{	
			smallPtr = new Triangle;
			smallT.setCoord(smallT,x1,y1,x2,y2,x3,y3);
			PolygonDyn smallP(smallT);
			vec.push_back(smallT);
			smallPtr->setCoord(*smallPtr,x1,y1,x2,y2,x3,y3);
			shapeVec.push_back(smallPtr);				
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

	ofstream res;
	res.open("TriangleInRectangle.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	Rectangle* r = dynamic_cast<Rectangle*>(shapeVec[0]);
	r->draw(res);

	int i;
	for(i=1 ; i<vec.size() ; i++)
	{
		Triangle* t = dynamic_cast<Triangle*>(shapeVec[i]);

		t->draw(res);
	}
	res<<"</svg>";
	res.close();


}

void ComposedShape::optimalFit(Rectangle contR, Circle smallC)
{
	Rectangle* RecPtr = new Rectangle;
	RecPtr->setCoordinates(*RecPtr, contR.getX(), contR.getY());
	RecPtr->setWidth(*RecPtr, contR.getWidth());
	RecPtr->setHeight(*RecPtr, contR.getHeight());
	shapeVec.push_back(RecPtr);

	Circle* smallPtr = new Circle;
	smallPtr->setCoord(*smallPtr,smallC.getX(),smallC.getY());
	smallPtr->setRadius(*smallPtr,smallC.getRadius());

	PolygonDyn contP(contR);
	vec.push_back(contP);



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
			smallPtr = new Circle;
			smallC.setCoord(smallC,cx,cy);
			PolygonDyn smallP(smallC);
			vec.push_back(smallP);
			smallPtr->setCoord(*smallPtr,cx,cy);
			smallPtr->setRadius(*smallPtr,smallC.getRadius());
	
			shapeVec.push_back(smallPtr);			
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
		{	smallPtr = new Circle;
			smallC.setCoord(smallC,cx,cy);
			PolygonDyn smallP(smallC);
			smallPtr->setCoord(*smallPtr,cx,cy);
			smallPtr->setRadius(*smallPtr,smallC.getRadius());
	
			shapeVec.push_back(smallPtr);				
			vec.push_back(smallP);
			cx+=2*radius;
			c2++;
			A++;
		} 
		cy+=2*radius;
		cx=radius;

	}
	}

	ofstream res;
	res.open("CircleInRectanle.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	Rectangle* r = dynamic_cast<Rectangle*>(shapeVec[0]);
	r->draw(res);	
	int i;
	for(i=0 ; i<vec.size() ; i++)
	{
		vec[i]<<res;
	}
	res<<"</svg>";
	res.close();

}

void ComposedShape::optimalFit(Triangle contT, Rectangle smallR)
{
	PolygonDyn contP(contT);
	vec.push_back(contT);

	Triangle* triPtr = new Triangle;
	triPtr->setCoord(*triPtr,contT.getX1(),contT.getY1(),contT.getX2(),contT.getY2(),contT.getX3(),contT.getY3());
	shapeVec.push_back(triPtr);
	Rectangle* smallPtr = new Rectangle;
	smallPtr->setCoordinates(*smallPtr, smallR.getX(), smallR.getY());
	smallPtr->setWidth(*smallPtr,smallR.getWidth());
	smallPtr->setHeight(*smallPtr,smallR.getHeight());
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
		{	smallPtr = new Rectangle;	
			smallR.setCoordinates(smallR,x,y);
			PolygonDyn smallP(smallR);
			vec.push_back(smallR);
			smallPtr->setCoordinates(*smallPtr,x,y);
			smallPtr->setWidth(*smallPtr,smallR.getWidth());
			smallPtr->setHeight(*smallPtr,smallR.getHeight());		
			shapeVec.push_back(smallPtr);	
			A++;
			x+=width;
			count++;
		}
		floor++;
	}
	ofstream res;
	res.open("RectangleInTriangle.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	int i;
	Triangle* t = dynamic_cast<Triangle*>(shapeVec[0]);
	t->draw(res);
	for(i=1 ; i<vec.size() ; i++)
	{
		Rectangle* r = dynamic_cast<Rectangle*>(shapeVec[i]);
		r->draw(res);
	}
	res<<"</svg>";
	res.close();
}

void ComposedShape::optimalFit(Triangle contT, Triangle smallT)
{
	PolygonDyn contP(contT);
	vec.push_back(contT);

	Triangle* triPtr = new Triangle;
	triPtr->setCoord(*triPtr,contT.getX1(),contT.getY1(),contT.getX2(),contT.getY2(),contT.getX3(),contT.getY3());
	shapeVec.push_back(triPtr);

	Triangle* smallPtr = new Triangle;
	smallPtr->setCoord(*smallPtr,smallT.getX1(),smallT.getY1(),smallT.getX2(),smallT.getY2(),smallT.getX3(),smallT.getY3());

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
	{	smallPtr = new Triangle;
		smallT.setCoord(smallT,xn1,yn1,xn2,yn2,xn3,yn3);
		PolygonDyn smallP(smallT);
		smallPtr->setCoord(*smallPtr,xn1,yn1,xn2,yn2,xn3,yn3);
		shapeVec.push_back(smallPtr);			
		vec.push_back(smallT);
		A++;	
	}

	if(side>(2*y2)/(pow(3,0.5)))
	{	smallPtr = new Triangle;
		smallT.setCoord(smallT,xn1,yn1,xn2,yn2,xn3,yn3);
		PolygonDyn smallP(smallT);
		vec.push_back(smallT);
		smallPtr->setCoord(*smallPtr,xn1,yn1,xn2,yn2,xn3,yn3);
		shapeVec.push_back(smallPtr);			
		A++;	
	}
	int i, n=1;
	while(yn2<=y2)
	{	smallT.setCoord(smallT,xn1,yn1,xn2,yn2,xn3,yn3);/*setting the coordinates of triangle.*/
		smallPtr = new Triangle;
		PolygonDyn smallP(smallT);
		vec.push_back(smallT);	
		smallPtr->setCoord(*smallPtr,xn1,yn1,xn2,yn2,xn3,yn3);
		shapeVec.push_back(smallPtr);			
		A++;
		for(i=1; i<n; i++)
		{
			xn1+=side;
			xn2+=side;
			xn3+=side;
		smallT.setCoord(smallT,xn1,yn1,xn2,yn2,xn3,yn3);
		smallPtr = new Triangle;
		PolygonDyn smallP(smallT);
		vec.push_back(smallT);	
		smallPtr->setCoord(*smallPtr,xn1,yn1,xn2,yn2,xn3,yn3);
		shapeVec.push_back(smallPtr);			
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
		{	
		smallPtr = new Triangle;	
		smallT.setCoord(smallT,xr1,yr1,xr2,yr2,xr3,yr3);
		PolygonDyn smallP(smallT);
		vec.push_back(smallT);
		smallPtr->setCoord(*smallPtr,xn1,yn1,xn2,yn2,xn3,yn3);
		shapeVec.push_back(smallPtr);			

			A++;

			for(i=1; i<n; i++)
			{
				xr1+=side;
				xr2+=side;
				xr3+=side;
		smallPtr = new Triangle;
		smallT.setCoord(smallT,xr1,yr1,xr2,yr2,xr3,yr3);
		PolygonDyn smallP(smallT);
		vec.push_back(smallT);
		smallPtr->setCoord(*smallPtr,xn1,yn1,xn2,yn2,xn3,yn3);
		shapeVec.push_back(smallPtr);				
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
	ofstream res;
	res.open("TriangleInTriangle.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	Triangle* t1 = dynamic_cast<Triangle*>(shapeVec[0]);
	t1->draw(res);
	for(i=1 ; i<vec.size() ; i++)
	{
		Triangle* t = dynamic_cast<Triangle*>(shapeVec[i]);
		t->draw(res);
	}
	res<<"</svg>";
	res.close();
}

void ComposedShape::optimalFit(Triangle contT, Circle smallC)
{

	Triangle* triPtr = new Triangle;
	triPtr->setCoord(*triPtr,contT.getX1(),contT.getY1(),contT.getX2(),contT.getY2(),contT.getX3(),contT.getY3());
	shapeVec.push_back(triPtr);

	PolygonDyn contP(contT);
	vec.push_back(contT);

	Circle* smallPtr = new Circle;
	smallPtr->setCoord(*smallPtr,smallC.getX(),smallC.getY());
	smallPtr->setRadius(*smallPtr,smallC.getRadius());

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
		smallPtr = new Circle;
		smallC.setCoord(smallC,cx,cy);
		PolygonDyn smallP(smallC);
		vec.push_back(smallP);
		smallPtr->setCoord(*smallPtr,cx,cy);
		smallPtr->setRadius(*smallPtr,smallC.getRadius());

		shapeVec.push_back(smallPtr);		
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
		{	smallPtr = new Circle;
			smallC.setCoord(smallC,cx,cy);
			PolygonDyn smallP(smallC);
			vec.push_back(smallP);
			smallPtr->setCoord(*smallPtr,cx,cy);
			smallPtr->setRadius(*smallPtr,smallC.getRadius());
	
			shapeVec.push_back(smallPtr);				
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
	ofstream res;
	res.open("CircleInTriangle.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	


	for(i=0 ; i<vec.size() ; i++)
	{
		vec[i]<<res;
	}
	res<<"</svg>";
	res.close();

}

void ComposedShape::optimalFit(Circle contC, Rectangle smallR)
{
	PolygonDyn contP(contC);
	vec.push_back(contC);
	Circle* circPtr = new Circle;
	circPtr->setCoord(*circPtr,contC.getX(),contC.getY());
	circPtr->setRadius(*circPtr,contC.getRadius());
	shapeVec.push_back(circPtr);				

	Rectangle* smallPtr = new Rectangle;
	smallPtr->setCoordinates(*smallPtr,smallR.getX(),smallR.getY());
	smallPtr->setWidth(*smallPtr,smallR.getWidth());
	smallPtr->setHeight(*smallPtr,smallR.getHeight());
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
			smallPtr = new Rectangle;
			smallR.setCoordinates(smallR,x,y);
			PolygonDyn smallP(smallR);
			vec.push_back(smallP);
			smallPtr->setCoordinates(*smallPtr,x,y);

			smallPtr->setWidth(*smallPtr,smallR.getWidth());
			smallPtr->setHeight(*smallPtr,smallR.getHeight());

			shapeVec.push_back(smallPtr);				
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
		{	smallPtr = new Rectangle;
			smallR.setCoordinates(smallR,x,y);

			PolygonDyn smallP(smallR);
			vec.push_back(smallP);
			A++;
			x+=width;
			smallR.setCoordinates(smallR,x,y);
			smallPtr->setCoordinates(*smallPtr,x,y);
			smallPtr->setWidth(*smallPtr,smallR.getWidth());
			smallPtr->setHeight(*smallPtr,smallR.getHeight());	
			shapeVec.push_back(smallPtr);						
		}
		y+=height;
		x=oldx+width/2;	
		oldx+=width;	
		smallR.setCoordinates(smallR,x,y);
	}		
	ofstream res;
	res.open("RectangleInCircle.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	
	for(i=0 ; i<vec.size() ; i++)
	{
		vec[i]<<res;
	}
	res<<"</svg>";
	res.close();
}

void ComposedShape::optimalFit(Circle contC, Triangle smallT)
{
	PolygonDyn contP(contC);
	vec.push_back(contP);
	Circle* circPtr = new Circle;
	circPtr->setCoord(*circPtr,contC.getX(),contC.getY());
	circPtr->setRadius(*circPtr,contC.getRadius());
	shapeVec.push_back(circPtr);				

	Triangle* smallPtr = new Triangle;
	smallPtr->setCoord(*smallPtr,smallT.getX1(),smallT.getY1(),smallT.getX2(),smallT.getY2(),smallT.getX3(),smallT.getY3());
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
		{	smallPtr = new Triangle;
			smallT.setCoord(smallT,x1,y1,x2,y2,x3,y3);
			PolygonDyn smallP(smallT);
			vec.push_back(smallP);
			smallPtr->setCoord(*smallPtr,x1,y1,x2,y2,x3,y3);
			shapeVec.push_back(smallPtr);			
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
		{	smallPtr = new Triangle;
			smallT.setCoord(smallT,xr1,yr1,xr2,yr2,xr3,yr3);
			PolygonDyn smallP(smallT);
			vec.push_back(smallP);
			smallPtr->setCoord(*smallPtr,xr1,yr1,xr2,yr2,xr3,yr3);
			shapeVec.push_back(smallPtr);				
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
	ofstream res;
	res.open("TriangleInCircle.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	int i;
	
	for(i=0 ; i<vec.size() ; i++)
	{
		vec[i]<<res;
	}
	res<<"</svg>";
	res.close();
}

void ComposedShape::optimalFit(Circle contC, Circle smallC)
{
	PolygonDyn contP(contC);
	vec.push_back(contP);
	Circle* circPtr = new Circle;
	circPtr->setCoord(*circPtr,contC.getX(),contC.getY());
	circPtr->setRadius(*circPtr,contC.getRadius());
	shapeVec.push_back(circPtr);				

	Circle* smallPtr = new Circle;
	smallPtr->setCoord(*smallPtr,smallC.getX(),smallC.getY());
	smallPtr->setRadius(*smallPtr,smallC.getRadius());

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
		smallPtr = new Circle;
		smallC.setCoord(smallC,cx,cy);
		PolygonDyn smallP(smallC);
		vec.push_back(smallP);
		smallPtr->setCoord(*smallPtr,cx,cy);
		smallPtr->setRadius(*smallPtr,smallC.getRadius());

		shapeVec.push_back(smallPtr);			
		A++;/*Here our svg circle code.*/
		return;
	}
	if(4*r>radius)
	{
		while(cy<=hei)
		{
			while(cx<=wid)
			{	smallPtr = new Circle;
				smallC.setCoord(smallC,cx,cy);
				PolygonDyn smallP(smallC);
				vec.push_back(smallP);
				smallPtr->setCoord(*smallPtr,cx,cy);
				smallPtr->setRadius(*smallPtr,smallC.getRadius());
	
				shapeVec.push_back(smallPtr);					
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
			{	smallPtr = new Circle;
				smallC.setCoord(smallC,cx,cy);
				PolygonDyn smallP(smallC);
				vec.push_back(smallP);
				smallPtr->setCoord(*smallPtr,cx,cy);
				smallPtr->setRadius(*smallPtr,smallC.getRadius());
	
				shapeVec.push_back(smallPtr);					
				A++;
				cx+=2*r;
			} 
			cy+=2*r;
			cx = radius-(wid/2)+r;	
		}
	}
	ofstream res;
	res.open("CircleInCircle.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	

	int i;
	for(i=0 ; i<vec.size() ; i++)
	{
		vec[i]<<res;
	}
	res<<"</svg>";
	res.close();
}

Shape& ComposedShape::operator++()
{

	cR.setX(1+cR.getX());
	cR.setY(1+cR.getY());

	sT.setX1(1+sT.getX1());
	sT.setY1(1+sT.getY1());
	sT.setX2(1+sT.getX2());
	sT.setY2(1+sT.getY2());
	sT.setX3(1+sT.getX3());
	sT.setY3(1+sT.getY3());

	cC.setX(1+cC.getX());
	sC.setY(1+sC.getY());

	return *this;
}

Shape& ComposedShape::operator--()
{
	cR.setX(cR.getX()-1);
	cR.setY(cR.getY()-1);

	sT.setX1(sT.getX1()-1);
	sT.setY1(sT.getY1()-1);
	sT.setX2(sT.getX2()-1);
	sT.setY2(sT.getY2()-1);
	sT.setX3(sT.getX3()-1);
	sT.setY3(sT.getY3()-1);

	cC.setX(cC.getX()-1);
	sC.setY(sC.getY()-1);	
	return *this;
}

Shape& ComposedShape::operator++(int dummy)
{
	ComposedShape* temp;
	temp = new ComposedShape;

	temp->cR.setX(cR.getX());
	temp->cR.setY(cR.getY());

	temp->sT.setX1(sT.getX1());
	temp->sT.setY1(sT.getY1());
	temp->sT.setX2(sT.getX2());
	temp->sT.setY2(sT.getY2());
	temp->sT.setX3(sT.getX3());
	temp->sT.setY3(sT.getY3());

	temp->cC.setX(cC.getX());	
	temp->sC.setY(sC.getY());

	cR.setX(cR.getX()+1);
	cR.setY(cR.getY()+1);

	sT.setX1(sT.getX1()+1);
	sT.setY1(sT.getY1()+1);
	sT.setX2(sT.getX2()+1);
	sT.setY2(sT.getY2()+1);
	sT.setX3(sT.getX3()+1);
	sT.setY3(sT.getY3()+1);

	cC.setX(cC.getX()+1);
	sC.setY(sC.getY()+1);

	return *temp;

}

Shape& ComposedShape::operator--(int dummy)
{

	ComposedShape* temp;
	temp = new ComposedShape;

	temp->cR.setX(cR.getX());
	temp->cR.setY(cR.getY());

	temp->sT.setX1(sT.getX1());
	temp->sT.setY1(sT.getY1());
	temp->sT.setX2(sT.getX2());
	temp->sT.setY2(sT.getY2());
	temp->sT.setX3(sT.getX3());
	temp->sT.setY3(sT.getY3());

	temp->cC.setX(cC.getX());	
	temp->sC.setY(sC.getY());

	cR.setX(cR.getX()-1);
	cR.setY(cR.getY()-1);

	sT.setX1(sT.getX1()-1);
	sT.setY1(sT.getY1()-1);
	sT.setX2(sT.getX2()-1);
	sT.setY2(sT.getY2()-1);
	sT.setX3(sT.getX3()-1);
	sT.setY3(sT.getY3()-1);

	cC.setX(cC.getX()-1);
	sC.setY(sC.getY()-1);

	return *temp;

}

ComposedShape::ComposedShape(const ComposedShape& obj)
{
	int i;

	for (i=0 ; i<obj.shapeVec.size() ; i++)
	{	
		//shapeVec[i] = new ComposedShape;
		shapeVec.push_back(obj.shapeVec[i]);
		vec.push_back(obj.vec[i]);
	}

	cR = obj.cR;
	sR = obj.sR;
	cT = obj.cT;
	sT = obj.sT;
	cC = obj.cC;
	sC = obj.sC;

}

ComposedShape::~ComposedShape() 
{ 
	
	int i;
	
	for(i=0 ; i<shapeVec.size() ; i++)
		delete(shapeVec[i]);

	shapeVec.clear();
	/*

	for ( vector<Shape*>::iterator i = shapeVec.begin(); i != shapeVec.end(); ++i )
	    delete *i;
	    	shapeVec.clear();
	*/
}

ComposedShape& ComposedShape::operator =(const ComposedShape& rightSide)
{
	int i;
	if(shapeVec.size() != rightSide.shapeVec.size())
	{
		for(i=0 ; i<shapeVec.size() ; i++)
			delete[](shapeVec[i]);	
		shapeVec.clear();
		vec.clear();
	}
	for (i=0 ; i<rightSide.shapeVec.size() ; i++)
	{	
		//shapeVec[i] = new ComposedShape;
		shapeVec.push_back(rightSide.shapeVec[i]);
		vec.push_back(rightSide.vec[i]);
	}	

	return * this;
}

