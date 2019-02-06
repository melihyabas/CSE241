#include "shape.h"

Shape::Shape()
{ }

bool Shape::operator==(Shape &obj){
	return(Area==obj.Area);
}
bool Shape::operator!=(Shape &obj){
	return(Area!=obj.Area);
}
bool Shape::operator>(Shape &obj){
	return(Area>obj.Area);
}
bool Shape::operator<(Shape &obj){
	return(Area<obj.Area);
}
bool Shape::operator>=(Shape &obj){
	return(Area>=obj.Area);
}
bool Shape::operator<=(Shape &obj){
	return(Area<=obj.Area);
}

ostream& operator <<(ostream& res, Shape& obj)
{
	obj.draw(res);
	return res;
}

void printAll(vector<Shape*> v)
{
	int i; 
	ofstream res;
	res.open("printALL.svg");
	res<<"<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">";	
	Shape* x;
	for(i=0 ; i<v.size() ; i++)
	{
		res<<*(v[i]);
	}
	res<<"</svg>";
	res.close();
}
