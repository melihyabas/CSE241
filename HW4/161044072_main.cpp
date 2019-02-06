	/*There are some libraries here. We need all of these. Some libraries occured by us.*/
#include "composedShape.h"

using namespace std;
namespace{ /*This is an unnamed namespace.*/
	int i;
	Rectangle r0,r1,r2,r3,r4;
	Triangle t0,t1,t2,t3,t4;	/*Objects of 3 shapes classes*/
	Circle c0,c1,c2,c3,c4;
	ComposedShape cs0,cs1,cs2,cs3,cs4;
	polygon p0,p1,p2,p3,p4;
	polyline pl0,pl1,pl2,pl3,pl4;

};

int main()
{
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




	cout<<"Compositions and << operator of polygon are testing..."<<endl;
/*Here we are starting to composition.*/
/*----------------------------------------------------------------*/
	r[0].setWidth(r[0],700);
	r[0].setHeight(r[0],800);
	r[1].setWidth(r[1],55);
	r[1].setHeight(r[1],75);	
	r[0].setCoordinates(r[0],0,0);		/*In this scope, rectangles in a rectangle are written.*/
	r[1].setCoordinates(r[1],0,0);
	
	cout<<"Polyline constructors and operator overloadings are tested."<<endl;
	cout<<"A polyline rectangle is drawn."<<endl;
	polyline plr(r[1]);
	ofstream res;
	res.open("PolylineRectangle.svg");
	plr<<res;

	res<<"</svg>";

	res.close();		
	ComposedShape s1(r[0],r[1]);
	s1.optimalFit(r[0],r[1]);

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
	c[1].setRadius(c[1],910);
	c[1].setCoord(c[1],910,910);	

	t[0].setSide(t[0],59);		
	polyline plt(t[0]);
	cout<<"A polyline triangle is drawn."<<endl;
	res.open("PolylineTriangle.svg");
	plt<<res;

	res<<"</svg>";

	res.close();				
									/*In this scope, triangles in a circle are written.*/
	ComposedShape s8(c[1],t[0]);
	s8.optimalFit(c[1],t[0]);

 
/*----------------------------------------------------------------*/
	c[2].setRadius(c[2],874);
	c[2].setCoord(c[2],874,874);
	c[0].setRadius(c[0],87);

	polyline plc(c[2]);
	cout<<"A polyline circle is drawn."<<endl;
	res.open("PolylineCircle.svg");
	plc<<res;

	res<<"</svg>";

	res.close();	
							/*In this scope, circles in a circle are written.*/
	ComposedShape s9(c[2],c[0]);

	s9.optimalFit(c[2],c[0]);
/*----------------------------------------------------------------*/
	polygon p[5];	
	p[0] = p0;	/*Test of Polygon Class*/
	p[1] = p1;
	p[2] = p2;
	p[3] = p3;
	p[4] = p4;

	cout<<"Methods of polygon are tested.";	
	cout<<"Methods of polygon class are testing...\n"<<endl;
	cout<<"Copy constructor tested."<<endl;
	polygon p0;
	Rectangle trec;
	polygon p1(trec);
	polygon p2(p0);
	p0 = p[2];
	cout<<"Assignment operator tested."<<endl;
	if(p0==p[0])
		cout<<"== operator successfully tested."<<endl;
	else
		cout<<(p0==p[0]);
	
	
	if(p1!=p[0])
		cout<<"!= operator successfully tested."<<endl;
	else
		cout<<(p1!=p[0]);

	cout<<"+ operator tested."<<endl;
	polygon p3 = p0+p[0];
	polygon p4(c[0]);
	cout<<"[] operator tested."<<endl;	
	p4[0];
	cout<<"Setter and Getter functions tested."<<endl;
	p4.getDynamicSize();
	p4.setDynamicSize(10);
	p4.getVecPoints();
/*----------------------------------------------------------------------------------------*/
	polyline pl[5];	
	pl[0] = pl0;
	pl[1] = pl1;
	pl[2] = pl2;		/*Test of Polyline Class.*/
	pl[3] = pl3;
	pl[4] = pl4;

	cout<<"\n\n\n\n";
	cout<<"Methods of polyline are tested.";	
	cout<<"Methods of polyline class are testing...\n"<<endl;
	cout<<"Copy constructor tested."<<endl;
	Rectangle trecl; 
	polyline pl1(trecl);
	polyline pl3(pl[0]);
	pl0 = pl[3];
	cout<<"Assignment operator tested."<<endl;
	if(pl[0]==pl[3])
		cout<<"== operator successfully tested."<<endl;
	else
		cout<<(pl[0]==pl[3]);
	
	
	if(pl[1]!=pl[3])
		cout<<"!= operator successfully tested."<<endl;
	else
		cout<<(pl[1]!=pl[3]);

	cout<<"+ operator tested."<<endl;
	polyline pl4 = pl[0]+pl[3];
	polyline pl5(c[0]);
	cout<<"[] operator tested."<<endl;	
	pl5[0];

		

	return 0;
}


