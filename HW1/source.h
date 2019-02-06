#ifndef source 
#define source
enum class Shapes {

	Rectangle,
	Triangle,
	Circle
};

void rectangle();	/*This is a liblary.*/
void circle();
void triangle();
void circleInRec(int wid, int hei);
void recInRec(int wid, int hei);	/*These are prototypes of functions*/
void triInRec(int wid, int hei);
void triInTri(double x1, double y1, double x2, double y2, double x3, double y3);
void recInTri(double x1, double y1, double x2, double y2, double x3, double y3);
void circInTri(double x1, double y1, double x2, double y2, double x3, double y3);
void rectInCirc(int radius);
void triInCirc(int radius);
void circInCirc(int radius);



 
#endif  
