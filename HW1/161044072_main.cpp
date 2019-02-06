#include<iostream>
#include<fstream>	/*Necessary libraries for our program.*/
#include<cmath>
#include "source.h"
/*This is the main code of our program.*/
using namespace std;

int main(){	
	

	Shapes x;
	char cont;	

	cout<<"Please enter the main container shape (R, C, T)\n";
	cin>>cont;	
	switch(cont)
	{
		case 'R':
			x = Shapes::Rectangle;
			break;	/*Member of class enum is determined.*/
		case 'T':
			x = Shapes::Triangle;
			break;
		case 'C':
			x = Shapes::Circle;
			break;
	}

	if(x == Shapes::Rectangle)
		rectangle();
	if(x == Shapes::Triangle)	/*The shape that choosen by user is directed its function.*/
		triangle();
	if(x == Shapes::Circle)
		circle();
	
	return 0;
}

