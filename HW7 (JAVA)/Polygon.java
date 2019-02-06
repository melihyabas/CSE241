/**
 * This is an abstract polygon class.
 * It helps the exteded classes from it.
 * @author Melih Yabas
 */
import java.awt.Graphics;

public abstract class Polygon implements Shape
{
	protected double Area;
	protected double Perimeter;

	public abstract double area();
	public abstract double perimeter();
	public abstract void increment();
	public abstract void decrement();
	public abstract void draw(Graphics res);
	public abstract int compareTo(Shape obj);	
	
	public class point2d
	{
		/**
		 * 
		 * @return x value of the point.
		 */
		public double getX()
		{
			return x;
		}
		/**
		 * 
		 * @return y value of the point
		 */
		public double getY()
		{ return y;}

		protected double x;
		protected double y;
	};	

}