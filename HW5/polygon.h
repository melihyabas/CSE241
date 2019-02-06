#include<iostream>
#include<cmath>
#include "rectangle.h"
#include "triangle.h"/*Some necessary libraries.*/
#include "circle.h"
#include "shape.h"
#include <vector>

#ifndef polygon_h
#define polygon_h
#define PI 3.1415
using namespace std;
using namespace gtu; 	
using namespace istanbul;
class polygon : public Shape{
public:
	class point2d{
	public:
		int getX() const;
		int getY() const;/*This class hold a 2 dimentional point.*/
		void setX(int a);
		void setY(int b);
		int x;
		int y;
	};
	polygon();





};

#endif

