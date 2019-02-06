	/*There are some libraries here. We need all of these. Some libraries occured by us.*/
#include "composedShape.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
#include "shape.h"
#include <typeinfo>
using namespace std;
namespace{ /*This is an unnamed namespace.*/
	int i;
	Rectangle r0,r1,r2,r3,r4;
	Triangle t0,t1,t2,t3,t4;	/*Objects of 3 shapes classes*/
	Circle c0,c1,c2,c3,c4;
	ComposedShape cs0,cs1,cs2,cs3,cs4;
	PolygonDyn p0,p1,p2,p3,p4;
};


vector<Shape*> convertAll(vector<Shape*> v)
{
	int i = 0;
	vector<Shape*> v2;
	for(i=0 ; i<v.size() ; i++)
	{
		if(Rectangle* r = dynamic_cast<Rectangle*>(v[i]))
		{
			PolygonDyn obj(*r);
			v2.push_back(&obj);
		}
		if(Triangle* t = dynamic_cast<Triangle*>(v[i]))
		{
			PolygonDyn obj(*t);
			v2.push_back(&obj);
		}
		if(Circle* c = dynamic_cast<Circle*>(v[i]))
		{
			PolygonDyn obj(*c);
			v2.push_back(&obj);
		}		
	}

	return v2;
}

void printPoly(vector<Shape*> v)
{
	int i; 
	ofstream res;
	res.open("PolygonPrints.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	

	for(i=0 ; i<v.size() ; i++)
	{
		if(PolygonDyn *pd = dynamic_cast<PolygonDyn*>(v[i]))
		{
			res<<*(pd);
		}
		else if(PolygonVect *pv = dynamic_cast<PolygonVect*>(v[i]))
		{
			res<<*(pd);
		}
	}

	res<<"</svg>";
	res.close();
}

void sortShapes(vector<Shape*>& v)
{
	Shape* temp;
	int i,j;
	for(i=0 ; i<v.size() ; i++)
	{
		for(j=0 ; j<v.size() ; j++)
		{
			if(v[i]->area() < v[j]->area())
			{
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}	
}

int main()
{
	Rectangle denemeR;
	double A = 987;
	PolygonDyn denemeplg;
	PolygonDyn denemeplg2;

	ComposedShape* mlh = new ComposedShape;
	Rectangle* smallPtr = new Rectangle;
	Circle* circPtr = new Circle;
	Triangle* ttest = new Triangle;
	ttest->setSide(*ttest,750);
	ttest->setCoord(*ttest,(double)(750/2),0,0,(double)(750/2)*pow(3,0.5),750,(double)(750/2)*pow(3,0.5));	
	PolygonDyn ptest(*ttest);

	smallPtr->setWidth(*smallPtr,500);		//Test Global Functions
	smallPtr->setHeight(*smallPtr,650);
	smallPtr->setCoordinates(*smallPtr,0,0);
	circPtr->setRadius(*circPtr,424);
	circPtr->setCoord(*circPtr, 0, 0);
	vector<Shape*> vec;
	vec.push_back(smallPtr);
	vec.push_back(&ptest);
	vec.push_back(circPtr);

	printPoly(vec);
	sortShapes(vec);
	convertAll(vec);									/*All global functions have tested*/
	printAll(vec);
	cout<<"printPoly function has tested.\n\nsortShapes function has tested.\n\nconvertAll function has tested.\n\nprintAll function has tested.";

	vec[0]->area();
	vec[0]->perimeter();
	
	cout<<"Area functon of Shape has tested."<<endl;
	cout<<"Perimeter functon of Shape has tested."<<endl;
	Triangle denemeT;

	ComposedShape CSA(denemeT, denemeR);
	++CSA;
	CSA++;	
	Rectangle rD, rD2;
	cout<<"first, x coord of a shape:"<<rD.getX()<<endl;
	cout<<"first, y coord of a shape:"<<rD.getY()<<endl;

	rD++;
	++rD;
	cout<<"now, x coord of shape:"<<rD.getX()<<endl;
	cout<<"now, y coord of shape:"<<rD.getY()<<endl;


	rD--;
	--rD;
	Triangle tD, tD2;
	tD++;
	++tD;
	tD--;
	--tD;
	Circle cD, cD2;
	cD++;
	++cD;
	cD--;
	--cD;
	cout<<"All Pre-Increment, Post-Increment, Pre-Decrement, Post-Decrement have tested."<<endl;
	if(cD<cD2 || cD>cD2 || cD!=cD2 || tD>tD2 || tD<tD2 || tD!=tD2 || rD!=rD2 || rD<rD2 || rD>rD2)
	cout<<"ERROR!"<<endl;
	if(cD==cD2 && tD==tD2 && rD==rD2)
		cout<<"Boolean operators have succesfully tested."<<endl;
	cout<<"Global << operator have tested in printAll function."<<endl;
	PolygonDyn pD(*ttest);
	PolygonDyn pD2(*ttest);

	PolygonVect pvD(*ttest);
	PolygonVect pvD2(*ttest);

	if(pvD<pvD2)
		cout<<"ERROR!";
	if(pD<pD2)
		cout<<"ERROR!";	

	if(pD == pD2)
		cout<<"PolygonDyn Constructors and Boolean operators have tested."<<endl;
	if(pvD == pvD2)
		cout<<"PolygonVect Constructors and Boolean operators have tested."<<endl;

	cout<<"\n\n**ALL SHAPES DRAWN TO THE FILE ON SVG FORMAT**";

	denemeR.setWidth(denemeR,450);
	denemeR.setHeight(denemeR,450);

/*---------------------------------------------------------------------*/	



	cout<<"\n\n\n";

	Rectangle r[5];	
	r[0] = r0;
	r[1] = r1;
	r[2] = r2;
	r[3] = r3;
	r[4] = r4;

	Triangle t[5];	
	t[0] = t0;
	t[1] = t1;
	t[2] = t2;
	t[3] = t3;		/*These are arrays written to use.*/
	t[4] = t4;

	Circle c[5];	
	c[0] = c0;
	c[1] = c1;
	c[2] = c2;
	c[3] = c3;
	c[4] = c4;

	ComposedShape cs[5];
	cs[0] = cs0;
	cs[1] = cs1;
	cs[2] = cs2;
	cs[3] = cs3;
	cs[4] = cs4;



/*Here we are starting to composition.*/
/*----------------------------------------------------------------*/
	r[1].setWidth(r[1],750);					
	r[1].setHeight(r[1],800);
	r[0].setWidth(r[0],127);					/*In this scope, rectangles in a rectangle are written.*/
	r[0].setHeight(r[0],200);

	ComposedShape s10(r[1],r[0]);
	
	s10.optimalFit(r[1],r[0]);

/*----------------------------------------------------------------*/

	r[2].setWidth(r[2],750);
	r[2].setHeight(r[2],600);
	c[0].setRadius(c[0],45);
	r[2].setCoordinates(r[2],0,0);		/*In this scope, circles in a rectangle are written.*/
	
	c[0].setCoord(c[0],c[0].getRadius(),c[0].getRadius());

	ComposedShape s2(r[2],c[0]);

	s2.optimalFit(r[2],c[0]);

/*----------------------------------------------------------------*/
	r[3].setWidth(r[3],750);
	r[3].setHeight(r[3],600);
	r[3].setCoordinates(r[3],0,0);		/*In this scope, triangles in a rectangle are written.*/
	t[0].setSide(t[0],50);

	c[0].setRadius(c[0],69);	
	
	ComposedShape s3(r[3],t[0]);

	s3.optimalFit(r[3],t[0]);
	
/*----------------------------------------------------------------*/
	t[1].setSide(t[1],750);
	t[1].setCoord(t[1],(double)(750/2),0,0,(double)(750/2)*pow(3,0.5),750,(double)(750/2)*pow(3,0.5));


	r[0].setWidth(r[0],75);					/*In this scope, rectangles in a triangle are written.*/
	r[0].setHeight(r[0],100);

	ComposedShape s4(t[1],r[0]);
	
	s4.optimalFit(t[1],r[0]);
/*----------------------------------------------------------------*/
	t[2].setSide(t[2],850);
	t[2].setCoord(t[2],(double)(850/2),0,0,(double)(850/2)*pow(3,0.5),850,(double)(850/2)*pow(3,0.5));

	c[1].setRadius(c[1],47);					/*In this scope, circles in a triangle are written.*/

	
	ComposedShape s5(t[2],c[1]);
	s5.optimalFit(t[2],c[1]);

/*----------------------------------------------------------------*/
	t[3].setSide(t[3],850);
	t[3].setCoord(t[3],(double)(850/2),0,0,(double)(850/2)*pow(3,0.5),850,(double)(850/2)*pow(3,0.5));
	t[0].setSide(t[0],84);
	t[0].setCoord(t[0],(double)(84/2),0,0,(double)(84/2)*pow(3,0.5),84,(double)(84/2)*pow(3,0.5));

	c[0].setRadius(c[0],69);	
	
						/*In this scope, triangles in a triangle are written.*/
	ComposedShape s6(t[2],t[0]);
	s6.optimalFit(t[2],t[0]);
																	
/*----------------------------------------------------------------*/
	c[0].setRadius(c[0],700);
	c[0].setCoord(c[0],700,700);
	
	r[0].setWidth(r[0],75);	
	r[0].setHeight(r[0],80);				
									/*In this scope, rectangles in a circle are written.*/
	ComposedShape s7(c[0],r[0]);
	s7.optimalFit(c[0],r[0]);
/*----------------------------------------------------------------*/
	c[0].setRadius(c[0],700);
	c[0].setCoord(c[0],700,700);
	
	t[0].setSide(t[0],84);
	t[0].setCoord(t[0],(double)(84/2),0,0,(double)(84/2)*pow(3,0.5),84,(double)(84/2)*pow(3,0.5));
				
									//In this scope, triangles in a circle are written.
	ComposedShape s8(c[0],t[0]);
	s8.optimalFit(c[0],t[0]);

//----------------------------------------------------------------
	c[0].setRadius(c[0],700);
	c[0].setCoord(c[0],700,700);
	
	c[0].setRadius(c[1],69);
	c[0].setCoord(c[1],69,69);				
									//In this scope, circles in a circle are written.
	ComposedShape s9(c[0],c[1]);
	s9.optimalFit(c[0],c[1]);


	return 0;
}


