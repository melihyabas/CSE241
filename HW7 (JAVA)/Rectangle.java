/**
 * Rectangle class contains all of the features of a rectangle.
 * @author Melih Yabas
 */
import java.awt.Graphics;


public class Rectangle implements Shape
{
	private int width;
	private int height;
	private double x;
	private double y;

	/**
	 * This constructor takes width and height. And then creates an object.
	 * @param w width
	 * @param h height
	 */
	public Rectangle(int w, int h)
	{
		x=0;
		y=0;
		width = w;
		height = h;
	}
	/**
	 * No parameter constructor.
	 */
	public Rectangle()
	{
		x=0;
		y=0;
		width = 100;
		height = 100;
	}
	/**
	 * This constructor takes x, y width and height. And then creates an object.
	 * @param objX x coordinate
	 * @param objY y coordinate
	 * @param w width
	 * @param h height
	 */
	public Rectangle(int objX, int objY, int w, int h)
	{
		x=objX;
		y=objY;
		width=w;
		height=h;
	}
	/**
	 * This method draws the shapes.
	 * @param g Graphics object for drawing
	 */
	public void draw(Graphics g)  
	{

		g.fillRect((int)x, (int)y, width, height);		
	}
	/**
	 * incremets the coordinates
	 */
	public void increment()
	{
		x++;		y++;
	}
	/**
	 * decrements the coordinates
	 * 
	 */
	public void decrement()
	{
		x--;		y--; 
	}
	/**
	 * 
	 * @return area area of the shape
	 */
	public double area()
	{ return width*height; }
	/**
	 * 
	 * @return perimeter of the shape
	 */
	public double perimeter()
	{ return 2*(width+height);}	
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
	 * sets the width
	 * @param w width
	 */
	public void setWidth(int w)throws IllegalArgumentException
	{	
		if(w<=0)
		{
			throw new IllegalArgumentException();
		}
		width = w;
	}
	/**
	 * sets the height
	 * @param h height
	 */
	public void setHeight(int h)throws IllegalArgumentException
	{
		if(h<=0)
			throw new IllegalArgumentException();
		height = h;
	}
	/**
	 * sets the coordinates
	 * @param a x coordinate
	 * @param b y coordinate
	 */
	public void setCoordinates(double a,double b) throws IllegalArgumentException
	{
		if(a<0||b<0)
			throw new IllegalArgumentException();
		x=a; y=b; 
	}
	public void setX(double xn){x = xn;}
	public void setY(double yn){y = yn;}

	
	/**
	 * 
	 * @return width
	 */
	public int getWidth()
	{ return width; }
	/**
	 * 
	 * @return height
	 */
	public int getHeight()
	{ return height; }
	/**
	 * 
	 * @return x
	 */
	public double getX()
	{ 
		return x;
	}
	/**
	 * 
	 * @return y
	 */
	public double getY()
	{ return y;}


}