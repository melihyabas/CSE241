import java.awt.Graphics;

public class Circle implements Shape
{
 
	private	int radius;
	private double x;
	private double y;
	
	/**
	 * Takes the radius and creates a circle object
	 * @param r radius
	 */
	public Circle(int r)
	{ radius = r;}
	/**
	 * No parameter constructor.
	 */
	public Circle()
	{ }
	
	/**
 	 * @return area of the shape
	 */
	public double area()
	{ return (Math.PI)*radius*radius; }
	/**
 	 * @return perimeter of the shape
	 */
	public double perimeter()
	{ return 2*(Math.PI)*radius;}

	/**
	 * compares two shapes with recpect to their areas
	 * @param obj
	 */
	public int compareTo(Shape obj)
	{ 
		if(obj.area()>area())
			return 1;
		else if(obj.area()<area())
			return -1;
		else
			return 0;
	}
	/**
	 * incremets the coordinates
	 */		
	public void increment()
	{x++; y++;}
	/**
	 * decrements the coordinates
	 * 
	 */	
	public void decrement()
	{x--; y--;}
	/**
	 * This method draws the shapes.
	 * @param g Graphics object for drawing
	 */	
	public void draw(Graphics g)
	{

		g.fillArc((int)x, (int)y, 2*radius, 2*radius, 0, 360);
		
	}
	/**
	 * Sets the radius
	 * @param r radius
	 */
	public void setRadius(int r) throws IllegalArgumentException
	{ 
		if(r<0)
			throw new IllegalArgumentException();
		radius=r;
	}
	/**
	 * sets coordinates
	 * @param a coordinate x
	 * @param b coordinate y
	 */
	public void setCoordinates(double a, double b) throws IllegalArgumentException
	{
		if(a<0 || b<0)
			throw new IllegalArgumentException(); 
		x=a; y=b;
	}
	/**
	 * sets only x coordinate
	 * @param xn x coordinate
	 */
	public void setX(double xn) throws IllegalArgumentException
	{
		if(xn<0)
			throw new IllegalArgumentException();
		x = xn;
	}
	/**
	 * sets only y coordinate
	 * @param yn y coordinate
	 */
	public void setY(double yn) throws IllegalArgumentException
	{
		if(yn<0)
			throw new IllegalArgumentException();
		y = yn;
	}
	/**
	 * 
	 * @return radius
	 */
	public int getRadius()
	{return radius;}
	/**
	 * 
	 * @return x
	 */
	public double getX() 
	{return x;}
	/**
	 * 
	 * @return y
	 */
	public double getY() 
	{return y;}


}