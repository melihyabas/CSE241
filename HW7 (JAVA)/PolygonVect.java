/**
 * This class keeps point in a vector.
 * @author melih
 */
import java.util.Vector;
import java.awt.Graphics;



public class PolygonVect extends Polygon
{
	private Vector<point2d>v = new Vector<point2d>();	
	/**
	 * No parameter constructor.
	 */
	public PolygonVect()
	{ }
	/**
	 * Takes a rectangle and convert to a polygon.
	 * @param r Rectangle object.
	 */	
	public PolygonVect(Rectangle r)
	{	
		point2d p = new point2d();
		p.x = (r.getX());
		p.y = (r.getY());
		v.add(p);
		
		p.x = (r.getX());
		p.y = (r.getY()+r.getHeight());
		v.add(p);
	
		p.x = (r.getX()+r.getWidth());
		p.y = (r.getY()+r.getHeight());
		v.add(p);
				
		p.x = (r.getX()+r.getWidth());
		p.y = (r.getY());
		v.add(p);
				
		Area = (r.getWidth())*(r.getHeight());	
		Perimeter = 2*(r.getHeight()+r.getWidth());

	}
	/**
	 * Takes a triangle and convert to a polygon.
	 * @param t triangle object.
	 */
	public PolygonVect(Triangle t)
	{
		point2d p = new point2d();		
		
		p.x = (t.getX1());
		p.y = (t.getY1());
		v.add(p);
		
		p.x = (t.getX2());
		p.y = (t.getY2());
		v.add(p);

		p.x = (t.getX3());
		p.y = (t.getY3());
		v.add(p);

		Area = (t.getSide())*(t.getSide())*(Math.pow(3,0.5))/4;	
		Perimeter = 3*(t.getSide());	
	}
	/**
	 * Takes a circle and convert to a polygon.
	 * @param c circle object.
	 */
	public PolygonVect(Circle c)
	{
		int i;
		int r = c.getRadius();/*Circle convertion constructor. Converts it a polygon.*/
		double a;

		a=2*Math.PI/99;

		for(i=0 ; i<99 ; i++)
		{	  
			point2d p = new point2d();		
			p.x = (r*Math.cos(a)+c.getX()+r);
			p.y = (r*Math.sin(a)+c.getY()+r);
			
			v.add(p);
			a+=(2*Math.PI/99);
		}

		Area = Math.PI*(c.getRadius())*(c.getRadius());
		Perimeter = 2*Math.PI*(c.getRadius());		

	}

	/**
	 * 
	 * @return area of the shape
	 */
	public double area()
	{ return Area;}
	/**
	 * 
	 * @return perimeter of the shape
	 */
	public double perimeter()
	{ return Perimeter;}
	/**
	 * incremets the coordinates
	 */
	public void increment()
	{	
		int i;
		for(i=0 ; i<v.size() ; i++)
		{
			point2d p = new point2d();
			p = v.get(i);
			p.x = (p.getX()+1);
			p.y = (p.getY()+1);
		
			v.set(i,p);
		}

	}
	/**
	 * decrements the coordinates
	 * 
	 */
	public void decrement()
	{
		int i;
		for(i=0 ; i<v.size() ; i++)
		{
			point2d p = new point2d();
			p = v.get(i);
			p.x = (p.getX()-1);
			p.y = (p.getY()-1);
		
			v.set(i,p);
		}
	}
	/**
	 * This method draws the shapes.
	 * @param g Graphics object for drawing
	 */
	public void draw(Graphics g)
	{

		int[] xPoints = new int[v.size()];
		int[] yPoints = new int[v.size()];

		int i;
		for(i=0 ; i<v.size() ; i++)
		{
			xPoints[i] = (int)(v.get(i).x);
			yPoints[i] = (int)(v.get(i).y);			
		}
		
		g.fillPolygon(xPoints, yPoints, v.size()); 
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

}












