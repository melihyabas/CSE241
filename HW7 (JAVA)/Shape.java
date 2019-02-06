/**
 * 
 */
import java.awt.Graphics;

public interface Shape extends Comparable<Shape>
{
	/**
	 * 
	 * @return area area of the shape
	 */
	public abstract double area();

	/**
	 * 
	 * @return perimeter of the shape
	 */
	public abstract double perimeter();
	/**
	 * incremets the coordinates
	 */
	public abstract void increment();
	/**
	 * decrements the coordinates
	 * 
	 */
	public abstract void decrement();
	/**
	 * This method draws the shapes.
	 * @param g Graphics object for drawing
	 */
	public abstract void draw(Graphics g);

	/**
	 * compares two shapes with recpect to their areas
	 * @param obj
	 */
	public abstract int compareTo(Shape obj);	

}