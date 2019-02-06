#include "rectangle.h"	
#include "circle.h"
#include "triangle.h"	/*There are some libraries here. We need all of these. Some libraries occured by us.*/
#include "composedShape.h"
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;


int main()
{
	int i;
	//int w,h,r,s,w2,h2;
	//char cont,small, c1,c2;
	
	Rectangle r0,r1,r2,r3;
	Triangle t0,t1,t2,t3;	/*Objects of 3 shapes classes*/
	Circle c0,c1,c2,c3;

	Rectangle r[4];	
	r[0] = r0;
	r[1] = r1;
	r[2] = r2;
	r[3] = r3;

	for(i=0 ; i<4 ; i++)
	{
		r[i].setWidth(r[i],700);
		r[i].setHeight(r[i],800);	/*This part of driver file is doing some test the members of classes.*/
		r[i].getWidth();
		r[i].getHeight();
		r[i].setCoordinates(r[i],2,3);
		r[i].getX();
		r[i].getY();
		r[i].setCoordinates(r[i],0,0);
	}


	Triangle t[4];	
	t[0] = t0;
	t[1] = t1;
	t[2] = t2;
	t[3] = t3;

	for(i=0 ; i<4 ; i++)
	{
		t[i].setSide(t[i],700);
		t[i].getSide();

		t[i].setCoord(t[i],3, 5, 1, 6, 3, 9);
		t[i].getX1();
		t[i].getY1();
		t[i].getX2();
		t[i].getY2();
		t[i].getX3();
		t[i].getY3();
		
	}

	Circle c[4];	
	c[0] = c0;
	c[1] = c1;
	c[2] = c2;
	c[3] = c3;

	for(i=0 ; i<4 ; i++)
	{
		c[i].setRadius(c[i],877);
		c[i].getRadius();
		c[i].setCoord(c[i],5,10);
	
	}

/*Here we are starting to composition.*/
/*----------------------------------------------------------------*/
	r[0].setWidth(r[0],700);
	r[0].setHeight(r[0],800);
	r[1].setWidth(r[1],55);
	r[1].setHeight(r[1],75);	
	r[0].setCoordinates(r[0],0,0);		/*In this scope, rectangles in a rectangle are written.*/
	r[1].setCoordinates(r[1],0,0);	
	ComposedShape s1(r[0],r[1]);

	s1.optimalFit(r[0],r[1]);
	
	std::ofstream res;
	res.open("output.svg");
	r[0].draw(r[0],1,r[0].getX(),r[0].getY(),res);

	s1.draw(s1.getVrec(), res);

	res<<"</svg>";
	res.close();
/*----------------------------------------------------------------*/

	r[2].setWidth(r[2],750);
	r[2].setHeight(r[2],600);
	c[0].setRadius(c[0],45);
	r[2].setCoordinates(r[2],0,0);		/*In this scope, circles in a rectangle are written.*/
	
	c[0].setCoord(c[0],c[0].getRadius(),c[0].getRadius());
	
	ComposedShape s2(r[2],c[0]);

	s2.optimalFit(r[2],c[0]);
	

	res.open("output2.svg");
	r[2].draw(r[2],1,r[2].getX(),r[2].getY(),res);

	s2.draw(s2.getVcirc(), res);

	res<<"</svg>";
	res.close();
/*----------------------------------------------------------------*/
	r[3].setWidth(r[3],750);
	r[3].setHeight(r[3],600);
	r[3].setCoordinates(r[3],0,0);		/*In this scope, triangles in a rectangle are written.*/
	t[0].setSide(t[0],50);
	
	ComposedShape s3(r[3],t[0]);

	s3.optimalFit(r[3],t[0]);
	

	res.open("output3.svg");
	r[3].draw(r[3],1,r[3].getX(),r[3].getY(),res);

	s3.draw(s3.getVtri(), res);

	res<<"</svg>";
	res.close();


/*----------------------------------------------------------------*/
	t[1].setSide(t[1],750);
	t[1].setCoord(t[1],(double)(750/2),0,0,(double)(750/2)*pow(3,0.5),750,(double)(750/2)*pow(3,0.5));


	r[0].setWidth(r[0],75);					/*In this scope, rectangles in a triangle are written.*/
	r[0].setHeight(r[0],100);
	
	ComposedShape s4(t[1],r[0]);
	
	s4.optimalFit(t[1],r[0]);
	res.open("output4.svg");
	t[1].draw(t[1],1,(double)(750/2),0,0,(double)(750/2)*pow(3,0.5),750,(double)(750/2)*pow(3,0.5),res);
	
	s4.draw(s4.getVrec(), res);

	res<<"</svg>";
	res.close();

/*----------------------------------------------------------------*/
	t[2].setSide(t[2],850);
	t[2].setCoord(t[2],(double)(850/2),0,0,(double)(850/2)*pow(3,0.5),850,(double)(850/2)*pow(3,0.5));


	c[1].setRadius(c[1],47);					/*In this scope, circles in a triangle are written.*/

	
	ComposedShape s5(t[2],c[1]);
	s5.optimalFit(t[2],c[1]);
	res.open("output5.svg");
	t[2].draw(t[2],1,(double)(850/2),0,0,(double)(850/2)*pow(3,0.5),850,(double)(850/2)*pow(3,0.5),res);
	
	s5.draw(s5.getVcirc(), res);

	res<<"</svg>";
	res.close();
/*----------------------------------------------------------------*/
	t[3].setSide(t[3],850);
	t[3].setCoord(t[3],(double)(750/2),0,0,(double)(750/2)*pow(3,0.5),750,(double)(750/2)*pow(3,0.5));
	t[0].setSide(t[0],84);
	t[0].setCoord(t[0],(double)(84/2),0,0,(double)(84/2)*pow(3,0.5),84,(double)(84/2)*pow(3,0.5));

						/*In this scope, triangles in a triangle are written.*/
	ComposedShape s6(t[2],t[0]);
	s6.optimalFit(t[2],t[0]);
	res.open("output6.svg");
	t[3].draw(t[3],1,(double)(850/2),0,0,(double)(850/2)*pow(3,0.5),850,(double)(850/2)*pow(3,0.5),res);
	
	s6.draw(s6.getVtri(), res);

	res<<"</svg>";
	res.close();																		
/*----------------------------------------------------------------*/
	c[0].setRadius(c[0],700);
	
	r[0].setWidth(r[0],75);	
	r[0].setHeight(r[0],80);				
									/*In this scope, rectangles in a circle are written.*/
	ComposedShape s7(c[0],r[0]);
	s7.optimalFit(c[0],r[0]);
	res.open("output7.svg");
	c[0].draw(c[0], 1,c[0].getRadius(), c[0].getRadius(), res);
	s7.draw(s7.getVrec(), res);

	res<<"</svg>";
	res.close();
/*----------------------------------------------------------------*/
	c[1].setRadius(c[1],910);
	t[0].setSide(t[0],59);				
									/*In this scope, triangles in a circle are written.*/
	ComposedShape s8(c[1],t[0]);
	s8.optimalFit(c[1],t[0]);
	res.open("output8.svg");
	c[1].draw(c[1], 1,c[1].getRadius(), c[1].getRadius(), res);
	s8.draw(s8.getVtri(), res);

	res<<"</svg>";
	res.close();

/*----------------------------------------------------------------*/
	c[2].setRadius(c[2],874);
	c[0].setRadius(c[0],69);				
									/*In this scope, triangles in a circle are written.*/
	ComposedShape s9(c[2],c[0]);
	s9.optimalFit(c[2],c[0]);
	res.open("output9.svg");
	c[2].draw(c[2], 1,c[2].getRadius(), c[2].getRadius(), res);
	s9.draw(s9.getVcirc(), res);

	res<<"</svg>";
	res.close();
	cout<<"Shapes are drawn!";
	return 0;
}



