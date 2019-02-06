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

	Rectangle r0,r1,r2,r3;
	Triangle t0,t1,t2,t3;	/*Objects of 3 shapes classes*/
	Circle c0,c1,c2,c3;

	Rectangle r[4];	
	r[0] = r0;
	r[1] = r1;
	r[2] = r2;
	r[3] = r3;

	Triangle t[4];	
	t[0] = t0;
	t[1] = t1;
	t[2] = t2;
	t[3] = t3;

	Circle c[4];	
	c[0] = c0;
	c[1] = c1;
	c[2] = c2;
	c[3] = c3;

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
//	cout<<"Rectangles:"<<(r[1]==r[0]);							//Test their equality.	
	std::ofstream res;
	res.open("output.svg");

	cout<<"\nA sample perimeter of a  rectangle:\t"<<r[1].perimeter()<<endl;
	cout<<"A sample area of a rectangle:\t"<<r[1].area()<<endl;	


	r[0]<<res;
	s1.draw(s1.getVrec(), res);

	res<<"</svg>";
	res.close();
/*----------------------------------------------------------------*/

	r[2].setWidth(r[2],750);
	r[2].setHeight(r[2],600);
	c[0].setRadius(c[0],45);
	r[2].setCoordinates(r[2],0,0);		/*In this scope, circles in a rectangle are written.*/
	
	c[0].setCoord(c[0],c[0].getRadius(),c[0].getRadius());
	cout<<"\nA sample perimeter of a circle:\t"<<c[0].perimeter()<<endl;
	cout<<"A sample area of a circle:\t"<<c[0].area()<<endl;

	ComposedShape s2(r[2],c[0]);

	s2.optimalFit(r[2],c[0]);
	

	res.open("output2.svg");
	r[2]<<res;
	s2.draw(s2.getVcirc(), res);

	res<<"</svg>";
	res.close();
/*----------------------------------------------------------------*/
	r[3].setWidth(r[3],750);
	r[3].setHeight(r[3],600);
	r[3].setCoordinates(r[3],0,0);		/*In this scope, triangles in a rectangle are written.*/
	t[0].setSide(t[0],50);

	c[0].setRadius(c[0],69);	
		
	ComposedShape s3(r[3],t[0]);

	s3.optimalFit(r[3],t[0]);
	

	res.open("output3.svg");
	cout<<"\nA sample perimeter of a triangle:\t"<<t[0].perimeter()<<endl;
	cout<<"A sample area of a triangle:\t"<<t[0].area()<<endl;
	r[3]<<res;

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
	t[1]<<res;
	cout<<"<< operator is testing."<<endl;
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
	t[2]<<res;
	
	s5.draw(s5.getVcirc(), res);

	res<<"</svg>";
	res.close();
/*----------------------------------------------------------------*/
	t[3].setSide(t[3],850);
	t[3].setCoord(t[3],(double)(850/2),0,0,(double)(850/2)*pow(3,0.5),850,(double)(850/2)*pow(3,0.5));
	t[0].setSide(t[0],84);
	t[0].setCoord(t[0],(double)(84/2),0,0,(double)(84/2)*pow(3,0.5),84,(double)(84/2)*pow(3,0.5));

	c[0].setRadius(c[0],69);	
	
						/*In this scope, triangles in a triangle are written.*/
	ComposedShape s6(t[2],t[0]);
	s6.optimalFit(t[2],t[0]);
	res.open("output6.svg");
	t[3]<<res;
	s6.draw(s6.getVtri(), res);

	res<<"</svg>";
	res.close();																		
/*----------------------------------------------------------------*/
	c[0].setRadius(c[0],700);
	c[0].setCoord(c[0],700,700);
	
	r[0].setWidth(r[0],75);	
	r[0].setHeight(r[0],80);				
									/*In this scope, rectangles in a circle are written.*/
	ComposedShape s7(c[0],r[0]);
	s7.optimalFit(c[0],r[0]);
	res.open("output7.svg");
	c[0]<<res;
	s7.draw(s7.getVrec(), res);

	res<<"</svg>";
	res.close();
/*----------------------------------------------------------------*/
	c[1].setRadius(c[1],910);
	c[1].setCoord(c[1],910,910);	

	t[0].setSide(t[0],59);		
			
									/*In this scope, triangles in a circle are written.*/
	ComposedShape s8(c[1],t[0]);
	s8.optimalFit(c[1],t[0]);
	res.open("output8.svg");
	c[1]<<res;
	s8.draw(s8.getVtri(), res);
	
	res<<"</svg>";
	res.close();

/*----------------------------------------------------------------*/
	c[2].setRadius(c[2],874);
	c[2].setCoord(c[2],874,874);
	c[0].setRadius(c[0],87);
	cout<<"\n==, != , + , - Operators are testing:"<<endl;
	cout<<"Circles:"<<(c[2]==c[0])<<endl;							//Test their equality.
	cout<<"874+75:"<<(c[2]+75).getRadius()<<endl;		//Test '+' operator.
	cout<<"874-75:"<<(c[2]-75).getRadius()<<endl;		//Test '-' operator.

	cout<<"\n++ , -- Operators are testing:"<<endl;
	cout<<"\nx:"<<c[2].getX()<<" y:"<<c[2].getY();
	c[2]++;
	cout<<"\nx:"<<c[2].getX()<<" y:"<<c[2].getY();
	--c[2];
	cout<<"\nx:"<<c[2].getX()<<" y:"<<c[2].getY();
	
	
									/*In this scope, circles in a circle are written.*/
	ComposedShape s9(c[2],c[0]);

	ComposedShape::shapeElem ex;
	ex.shape = new Triangle;
	ex.shape = &t[0];
	ex.width = t[0].getSide();

	ex.x1 = t[0].getX1();
	ex.y1 = t[0].getY1();	
	ex.x2 = t[0].getX2();
	ex.y2 = t[0].getY2();	
	ex.x3 = t[0].getX3();
	ex.y3 = t[0].getY3();
	cout<<"\nFunctions of shapeElem are testing."<<endl;
	ex.area();
	ex.perimeter();	

	s9.optimalFit(c[2],c[0]);
	res.open("output9.svg");
	c[2]<<res;
	s9.draw(s9.getVcirc(), res);

	res<<"</svg>";
	res.close();
	cout<<"\n\nShapes are drawn!";

	return 0;
}



