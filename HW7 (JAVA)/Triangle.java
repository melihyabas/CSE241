import java.awt.Graphics;

public class Triangle implements Shape
{
	private int side;
	private double x1;
	private double y1;
	private double x2;
	private double y2;
	private double x3;
	private double y3;		 

	/**
	 * 
	 * @return area area of the shape
	 */
	public double area()
	{
		return side*side*(Math.pow(3,0.5))/2;
	}
	/**
	 * 
	 * @return perimeter of the shape
	 */
	public double perimeter()
	{
		return 3*side; 
	}
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
	{x1++; y1++; x2++; y2++; x3++; y3++;}
	/**
	 * decrements the coordinates
	 * 
	 */
	public void decrement()
	{x1--; y1--; x2--; y2--; x3--; y3--;}
	/**
	 * This method draws the shapes.
	 * @param g Graphics object for drawing
	 */
	public void draw(Graphics g)
	{ 
		int[] xPoints = {(int)x1,(int)x2,(int)x3};
		int[] yPoints = {(int)y1,(int)y2,(int)y3};
		g.fillPolygon(xPoints, yPoints, 3); 
	} 
	/**
	 * This constructor takes side and creates a triandle object.
	 * @param s
	 */
	public Triangle(int s)
	{ side = s;}
	/**
	 * No parameter constructor.
	 */
	public Triangle()
	{ }

	int getSide(){return side;};
	/**
	 * 
	 * @return coordinate x1
	 */
	public double getX1(){return x1;}
	/**
	 * 
	 * @return coordinate y1
	 */
	public double getY1(){return y1;}
	/**
	 * 
	 * @return coordinate x2
	 */
	public double getX2(){return x2;}
	/**
	 * 
	 * @return coordinate y2
	 */
	public double getY2(){return y2;}
	/**
	 * 
	 * @return coordinate x3
	 */
	public double getX3(){return x3;}
	/**
	 * 
	 * @return coordinate y3
	 */
	public double getY3(){return y3;}
	/**
	 * sets side
	 * @param s side
	 */
	public void setSide(int s) throws IllegalArgumentException
	{
		if(s<=0)
			throw new IllegalArgumentException();
		side = s; 
	}
	/**
	 * Takes all coordinates and set them in the object.
	 * @param a1 x1
	 * @param b1 y1
	 * @param a2 x2
	 * @param b2 y2
	 * @param a3 x3
	 * @param b3 y3
	 */
 	public void setCoordinates(double a1, double b1, double a2, double b2, double a3, double b3) throws IllegalArgumentException
	{
		if(a1<0 || b1<0 || a2<0 || b2<0 || a3<0 || b3<0)
			throw new IllegalArgumentException();
		x1=a1;	y1=b1;	x2=a2;	y2=b2;	x3=a3;	y3=b3;
	}
	public void setX1(double x1n){x1 = x1n;}
	public void setY1(double y1n){y1 = y1n;}
	public void setX2(double x2n){x2 = x2n;}
	public void setY2(double y2n){y2 = y2n;}
	public void setX3(double x3n){x3 = x3n;}
	public void setY3(double y3n){y3 = y3n;}


}