#include<iostream>
#include<fstream>/*Necessary libraries for our program.*/
#include<cmath>
#include "source.h"
#define PI 3.1415

using namespace std;

void rectangle()
{
	int width, height;
	char small;
	cout<<"Please enter the width\n";
	cin>>width;

	cout<<"Please enter the height\n";
	cin>>height;/*This function created to draw a container rectangle*/

ofstream res;
	
	res.open("output.svg");
	
	res<<"<svg version=\"1.1\"\nbaseProfile=\"full\"\n  width=\""<<width<<"\" height=\""<<height<<"\"\nxmlns=\"http://www.w3.org/2000/svg\">\n<rect x=\"0\" y=\"0\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"red\"></rect>";

	res.close();/*svg code be written in "output.svg"*/
	
	cout<<"Please enter the small shape (R, C, T)\n";
	cin>>small;

	switch(small)
	{
		case'R':
			recInRec(width, height);
			break;
		case'C':
			circleInRec(width, height);/*User choose the shape that will occur in the container shape.*/
			break;
		case'T':
			triInRec(width, height);
			break;
	}

}

void circle()
{
	int radius;
	char small;
	cout<<"Please enter the radius\n";
	cin>>radius;	
	
	ofstream res;		/*Like the previous function, the container circle function created.*/
	res.open("output.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\"><circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<radius<<"\" fill=\"red\" />\n";

	res.close();
	cout<<"Please enter the small shape (R, C, T)\n";
	cin>>small;	

	switch(small)
	{
		case'R':
			rectInCirc(radius);
			break;	
		case'T':
			triInCirc(radius);
			break;
		case'C':
			circInCirc(radius);

	}
}

void triangle()
{
	int side;
	char small;
	cout<<"Please enter a side of triangle\n";
	cin>>side;
	ofstream res;	/*This is the container triangle function.*/

	res.open("output.svg");
	double x1=(double)(side/2),  y1=0, x2=0, y2=(double)((double)(side/2)*pow(3,0.5)), x3=(double)side, y3=(double)(((double)side/2)*pow(3,0.5));	/*The coodinates of triangle.*/

	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\"><polygon points=\""<<x1<<" "<<"0 0 "<<y2<<" "<<x3<<" "<<y3<<" \" fill=\"green\"></polygon>\n ";
	
	res<<"\n\n\n\n\n\n\n\n";
	res.close();
	cout<<"Please enter the small shape (R, C, T)\n";
	cin>>small;	

	switch(small)
	{
		case'R':
			recInTri(x1,y1,x2,y2,x3,y3);
			break;	
		case'T':	/*The coordinates of triangle send the function that user choose.*/
			triInTri(x1,y1,x2,y2,x3,y3);
			break;
		case'C':
			circInTri(x1,y1,x2,y2,x3,y3);
	}
}

void circleInRec(int wid, int hei)
{
	int radius, cx, cy, A=0;
	cout<<"Please enter the radius"<<endl;
	cin>>radius;
	if(radius*2>wid||radius>hei)
	{
		cout<<"Your radius input is too big for the rectangle!";
		return;
	}
  std::ofstream res;/*This function written to draw maximum circle in a rectangle*/
  res.open("output.svg", std::ios_base::app);
	
	int a = 0, c1=0, c2=0;
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
			res << "\n<circle stroke=\"black\" cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"green\" />";
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
			res << "\n<circle stroke=\"black\" cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"green\" />";
			cx+=2*radius;
			c2++;
			A++;
		} 
		cy+=2*radius;
		cx=radius;
		
	}
	}
	cout.setf(ios::fixed);
	cout<<"I can fit at most "<<A<< " small shapes into the main container. The empty area (red) in container is "<<(double)(wid*hei-A*PI*radius*radius);

  res << "</svg>";

	res.close();
}

void recInRec(int wid, int hei)
{
	int width, height, x=0, y=0,temp=0,count=0, count2=0, A=0;
 	std::ofstream res;

  	res.open("output.svg", std::ios_base::app);	
	cout<<"Please enter the width\n";
	cin>>width;
				/*This function written to draw maximum rectangle in a rectangle*/
	cout<<"Please enter the height\n";
	cin>>height;	
	if(width>wid||width>hei||height>hei||height>wid)
	{
		cout<<"Your small rectangle is too big for container rectangle!";
		return;
	}

	while(y+height<=hei)
	{	
		count = 0;
		while(x+width<=wid)
		{	

			res<<"\n <rect width=\""<<width<<"\" height=\""<<height<<"\" stroke=\"black\" x=\""<<x<<"\" y=\""<<y<<"\"  fill=\"green\"></rect> \n";	
			x+=width;
			count++;
			A++;
		}
		y+=height;
		x = 0;	
		count2++;	
	}

	if((wid-count*width<=wid)&&(hei>=height))
	{
		x=count*width;
		temp=width;
		width=height;	/*There may are some rotation for maximize our rectangles.*/
		height=temp;
		if(width<height)
		{
			while(x+width<=wid)
			{
					y=0;
					while(y+height<=hei)
					{
						res<<"\n <rect width=\""<<width<<"\" height=\""<<height<<"\" stroke=\"black\" x=\""<<x<<"\" y=\""<<y<<"\"  fill=\"green\"></rect> \n";				
						y+=height;
					A++;
					}	
				x+=width;

			}
			y+=height;
		}
		y=count2*width;
		if(width>height)
		{
			while(y+height<=hei)
			{
				x=0;
				while(x+width<=wid)
				{
					res<<"\n <rect width=\""<<width<<"\" height=\""<<height<<"\" stroke=\"black\" x=\""<<x<<"\" y=\""<<y<<"\"  fill=\"green\"></rect> \n";		
					x+=width;
					A++;
				}
				y+=height;

			}
		}
	
	}


	cout.setf(ios::fixed);
	cout<<"I can fit at most "<<A<< " small shapes into the main container. The empty area (red) in container is "<<(wid*hei)-(A*width*height);	/*And then again the red area and shapes count is calculated.*/

	res<<"\n</svg>";
	res.close();
}

void triInRec(int wid, int hei)
{
	std::ofstream res;
	int side, x1,y1,x2,y2,x3,y3,xr1,yr1,xr2,yr2,xr3,yr3, A=0;
	
  	res.open("output.svg", std::ios_base::app);	
	cout<<"Please enter the side\n";
	cin>>side;/*This function written to draw maximum triangle in a rectangle.*/
	if(side>wid||side>hei)
	{
		cout<<"Your triangle is too big for the rectangle!\n";
	}
	x1=(double)side/2;
	y1=0;
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
			res<<"<polygon points=\""<<x1<<" "<<y1<<" "<< x2 <<" "<< y2 <<" "<< x3 <<" "<< y3 <<" \" stroke = \"black\" fill=\"green\"></polygon>";
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
			res<<"<polygon points=\""<<xr1<<" "<<yr1<<" "<< xr2 <<" "<< yr2 <<" "<< xr3 <<" "<< yr3 <<" \" stroke = \"black\" fill=\"green\"></polygon>";
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

	cout.setf(ios::fixed);
	cout<<"I can fit at most "<<A<< " small shapes into the main container. The empty area (red) in container is "<<(wid*hei)-(A*side*side*(pow(3,0.5))/4);

	res<<"\n</svg>";
	res.close();

}

void triInTri(double x1, double y1, double x2, double y2, double x3, double y3)
{
	std::ofstream res;
	double side, xn1=x1, yn1, xn2, yn2, xn3, yn3, xr1, yr1, xr2, yr2, xr3, yr3;
	
	int A=0;

  	res.open("output.svg", std::ios_base::app);	
	cout<<"Please enter the side\n";
	cin>>side;
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
				res<<"\n<polygon points=\""<<xn1<<" "<<" "<<yn1<<" "<<xn2<<" "<<yn2<<" "<<xn3<<" "<<yn3<<"\" stroke=\"black\"  fill=\"red\"></polygon>";	
		A++;	
	}

	if(side>(2*y2)/(pow(3,0.5)))
	{
		res<<"\n<polygon points=\""<<xn1<<" "<<" "<<yn1<<" "<<xn2<<" "<<yn2<<" "<<xn3<<" "<<yn3<<"\" stroke=\"black\"  fill=\"red\"></polygon>";
		A++;
			
	}
	int i, n=1;
	while(yn2<=y2)
	{
		res<<"\n<polygon points=\""<<xn1<<" "<<" "<<yn1<<" "<<xn2<<" "<<yn2<<" "<<xn3<<" "<<yn3<<"\" stroke=\"black\"  fill=\"red\"></polygon>";
		A++;
		for(i=1; i<n; i++)
		{
			xn1+=side;
			xn2+=side;
			xn3+=side;
		res<<"\n<polygon points=\""<<xn1<<" "<<" "<<yn1<<" "<<xn2<<" "<<yn2<<" "<<xn3<<" "<<yn3<<"\" stroke=\"black\"  fill=\"red\"></polygon>";	
			A++;		
		}
		for(i=1; i<n; i++)
		{
			xn1-=side;
			xn2-=side;/*To put small triangles we have to chance coordinates.*/
			xn3-=side;
		}		
		n++;
		yn1+=((double)side/2)*pow(3,0.5);
		yn2+=((double)side/2)*pow(3,0.5);
		yn3+=((double)side/2)*pow(3,0.5);
		xn1-=(double)side/2;
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
			res<<"<polygon points=\""<<xr1<<" "<<" "<<yr1<<" "<<xr2<<" "<<yr2<<" "<<xr3<<" "<<yr3<<"\" stroke=\"black\" fill=\"red\"></polygon>";	
			A++;

			for(i=1; i<n; i++)
			{
				xr1+=side;
				xr2+=side;
				xr3+=side;
			res<<"<polygon points=\""<<xr1<<" "<<" "<<yr1<<" "<<xr2<<" "<<yr2<<" "<<xr3<<" "<<yr3<<"\" stroke=\"black\" fill=\"red\"></polygon>";	
				A++;		
			}
			for(i=1; i<n; i++)
			{
				xr1-=side;	/*The coordinates of reverse triangle are changed.*/
				xr2-=side;
				xr3-=side;
			}		
			n++;
			yr1+=((double)side/2)*pow(3,0.5);
			yr2+=((double)side/2)*pow(3,0.5);
			yr3+=((double)side/2)*pow(3,0.5);
			xr1-=(double)side/2;
			xr2-=(double)side/2;
			xr3-=(double)side/2;
		
		}

	}

	cout.setf(ios::fixed);
	cout<<"I can fit at most "<<A<< " small shapes into the main container. The empty area (red) in container is "<<((x3-x2)*(x3-x2)*pow(3,0.5)/4)-(A*side*side*pow(3,0.5)/4);

	res<<"</svg>";

	res.close();

}


void recInTri(double x1, double y1, double x2, double y2, double x3, double y3)
{
	int width, height, count, floor=1, A=0;
	double x, y;
	std::ofstream res;

  	res.open("output.svg", std::ios_base::app);	

	cout<<"Please enter the width\n";
	cin>>width;
/*The user entered the width and height of small rectangles.*/
	cout<<"Please enter the height\n";
	cin>>height;
	
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
		{
			res<<"\n <rect width=\""<<width<<"\" height=\""<<height<<"\"  x=\""<<x<<"\" y=\""<<y<<"\" stroke=\"black\" fill=\"red\"></rect> \n";
			A++;
			x+=width;
			count++;
		}
		floor++;
	}

	res<<"</svg>";
	cout.setf(ios::fixed);
	cout<<"I can fit at most "<<A<< " small shapes into the main container. The empty area (red) in container is "<<((x3-x2)*(x3-x2)*pow(3,0.5)/4)-A*width*height;

	res.close();
}

void circInTri(double x1, double y1, double x2, double y2, double x3, double y3)
{
	int radius, count=0, floor=1, oldcount=0, i, A=0;
	double cx,cy;
	std::ofstream res;/*This is necessary for file functions.*/

  	res.open("output.svg", std::ios_base::app);	

	cout<<"Please enter the radius\n";
	cin>>radius;
	if((x3-x2)<6*radius/(pow(3,0.5)))
	{
		cout<<"Your circle is too big for the triangle!\n";
	}
	
	cx=radius*(pow(3,0.5));
	cy=y2-radius;
	
	while(count*2*radius<=2*(y2-(floor*2*radius+radius))/(pow(3,0.5)))
	{
		res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\"><circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"red\" /></svg>";
		
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
			res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\"><circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<radius<<"\" fill=\"red\" /></svg>";
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
	
	cout.setf(ios::fixed);
	cout<<"I can fit at most "<<A<< " small shapes into the main container. The empty area (red) in container is "<<((x3-x2)*(x3-x2)*pow(3,0.5)/4)-(A*PI*radius*radius);

	res<<"</svg>";
/*The </svg all the time written last of code.*/
	res.close();

}

void rectInCirc(int radius)
{
	int width, height, count = 1,i,j,A=0;
	double x,y,oldx;
	ofstream res;

  	res.open("output.svg", std::ios_base::app);	
	
	cout<<"Please enter the width\n";
	cin>>width;

	cout<<"Please enter the height\n";
	cin>>height;	


	/*Circle is too hard to use a container. So we had to determine our start point better.*/
	x=radius-width/2;
	y=radius-(pow((pow(radius,2)-pow((width/2),2)),0.5));
	

	while(y+height<2*radius&& y<radius)
	{	
			while(pow(((x+width-radius)*(x+width-radius)+(y-radius)*(y-radius)),0.5)<radius)
			{

			res<<"<rect stroke = \"black\" x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"green\"></rect>";
			A++;
			x+=width;
			count++;
			}
			y+=height;

		x=radius-pow(pow(radius,2)-pow((y-radius),2),0.5);
	}
	cout<<"y:"<<y;	cout<<"y:"<<y;
	x+=width/2;
	oldx=x;
	while(y>radius && y<2*radius+height+height)
	{	
	
		
		while(pow(((x+width-radius)*(x+width-radius)+(y-radius)*(y-radius)),0.5)+width<radius)
		{
			
			res<<"<rect stroke = \"black\" x=\""<<x<<"\" y=\""<<y<<"\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"green\"></rect>";
			A++;
			x+=width;
		}
		y+=height;
		x=oldx+width/2;	
		oldx+=width;	
	}		
	cout.setf(ios::fixed);
	cout<<"I can fit at most "<<A<< " small shapes into the main container. The empty area (red) in container is "<< PI*radius*radius-A*width*height;
	res<<"</svg>";

	res.close();

}


void triInCirc(int radius)
{
	std::ofstream res;
	int wid, hei, side, x1,y1,x2,y2,x3,y3,xr1,yr1,xr2,yr2,xr3,yr3, A=0;
	
  	res.open("output.svg", std::ios_base::app);	
	cout<<"Please enter the side\n";
	cin>>side;
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
			res<<"<polygon points=\""<<x1<<" "<<y1<<" "<< x2 <<" "<< y2 <<" "<< x3 <<" "<< y3 <<" \" stroke = \"black\" fill=\"green\"></polygon>";
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
			res<<"<polygon points=\""<<xr1<<" "<<yr1<<" "<< xr2 <<" "<< yr2 <<" "<< xr3 <<" "<< yr3 <<" \" stroke = \"black\" fill=\"green\"></polygon>";
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

	res<<"\n</svg>";
	res.close();	


	cout.setf(ios::fixed);
	cout<<"I can fit at most "<<A<< " small shapes into the main container. The empty area (red) in container is "<<(PI*radius*radius)-(A*(x3-x2)*(x3-x2)*pow(3,0.5)/4);


}

void circInCirc(int radius)
{

	int r, cx, cy, wid, hei, A=0;
	cout<<"Please enter the radius"<<endl;
	cin>>r;
	
	if(r>radius)
	{
		cout<<"Your circle is too big for the circle\n";
		return;
	}
	hei = radius*(pow(2,0.5));
	wid = radius*(pow(2,0.5));
  std::ofstream res;
  res.open("output.svg", std::ios_base::app);

	cx = radius-(wid/2)+r;
	cy = radius-(wid/2)+r;
	
/*This is the last part of our program. This function written to calculate how many times circle draws in a circle*/
	
	if(2*r>radius)
	{
		cx=radius;
		cy= radius;
		res << "\n<circle stroke=\"black\" cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<r<<"\" fill=\"green\" /></svg>";
		A++;/*Here our svg circle code.*/
		return;
	}
	if(4*r>radius)
	{
		while(cy<=hei)
		{
			while(cx<=wid)
			{
				res << "\n<circle stroke=\"black\" cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<r<<"\" fill=\"green\" />";
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
				res << "\n<circle stroke=\"black\" cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<r<<"\" fill=\"green\" />";
				A++;
				cx+=2*r;
			} 
			cy+=2*r;
			cx = radius-(wid/2)+r;	
		}
	}
	cout.setf(ios::fixed);
	cout<<"I can fit at most "<<A<< " small shapes into the main container. The empty area (red) in container is "<<PI*radius*radius-A*PI*r*r;

  res << "</svg>";

	res.close();	
}
