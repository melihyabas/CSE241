#include <fstream>
#include<iostream>
#include<vector>

using namespace std;
#ifndef shape_h
#define shape_h

class Shape
{
public:
	Shape();
	virtual double perimeter( ){ return Perimeter; }	
	virtual double area( ){ return Area; }		
	virtual Shape& operator--() = 0;
	virtual Shape& operator++() = 0;
	virtual Shape& operator--(int dummy) = 0;
	virtual Shape& operator++(int dummy) = 0;
	virtual void draw(ostream& res) = 0;	
	
	virtual bool operator==(Shape &obj);
	virtual bool operator!=(Shape &obj);	
	virtual bool operator<(Shape &obj);
	virtual bool operator>(Shape &obj);
	virtual bool operator<=(Shape &obj);
	virtual bool operator>=(Shape &obj);
	
//protected:
	double Area;
	double Perimeter;
	
};

ostream& operator <<(ostream& res, Shape& obj);
void printAll(vector<Shape*> v);

//vector<Shape*> convertAll(vector<Shape*> v);

/*Function printAll takes a vector of Shape pointers and prints all shapes to an SVG file*/

// bir tane << operatörü yazılmalı. bu da draw fonksiyonunu cagıracak ve o da pure virtual olacak.
//her fonksiyonun draw fonksiyonu yok?

#endif
	