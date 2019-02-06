import java.awt.Graphics;


 public class PolygonDyn extends Polygon{

	private	point2d[] vecPoints;

	public PolygonDyn()
	{ }


	PolygonDyn(double a, double b)
	{
		point2d p = new point2d();

		vecPoints = new point2d[1];	
		p.x = a;
		p.y = b;
		vecPoints[0] = p;
		
		Area = 0;	
		Perimeter = 0;	
	}
	/**
	 * Takes a rectangle and convert to a polygon.
	 * @param r Rectangle object.
	 */
	PolygonDyn(Rectangle r)
	{
		vecPoints = new point2d[4];

		point2d p = new point2d();
		p.x = (r.getX());
		p.y = (r.getY());
		vecPoints[0] = p;

		p = new point2d();
		p.x = (r.getX());
		p.y = (r.getY()+r.getHeight());
		vecPoints[1] = p;
	
		p = new point2d();
		p.x = (r.getX()+r.getWidth());
		p.y = (r.getY()+r.getHeight());
		vecPoints[2] = p;

		p = new point2d();
		p.x = (r.getX()+r.getWidth());
		p.y = (r.getY());
		
		vecPoints[3] = p;
		
		Area = (r.getWidth())*(r.getHeight());
		Perimeter = 2*(r.getWidth()+r.getHeight());
	}
	/**
	 * Takes a triangle and convert to a polygon.
	 * @param t triangle object.
	 */
	PolygonDyn(Triangle t)
	{
		vecPoints = new point2d[3];
		point2d p = new point2d();
		
		p.x = (t.getX1());
		p.y = (t.getY1());
		
		vecPoints[0] = p;

		p = new point2d();
		p.x = (t.getX2());
		p.y = (t.getY2());
		
		vecPoints[1] = p;
	
		p = new point2d();

		p.x = (t.getX3());
		p.y = (t.getY3());
		
		vecPoints[2] = p;
		
		Area = (t.getSide())*(t.getSide())*(Math.pow(3,0.5))/4;
		Perimeter = 3*(t.getSide());		
	}
	/**
	 * Takes a circle and convert to a polygon.
	 * @param c circle object.
	 */
	PolygonDyn(Circle c)
	{
		int i;
		int r = c.getRadius();
		double a;

		vecPoints = new point2d[99];
		point2d p = new point2d();

		a=2*Math.PI/99;

		for(i=0 ; i<99 ; i++)
		{	
			p = new point2d();
			p.x = (r*Math.cos(a)+c.getX());
			p.y = (r*Math.sin(a)+c.getY());
			
			vecPoints[i] = p;
			
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
		for(i=0 ; i<vecPoints.length ; i++)
		{
			vecPoints[i].x = ((vecPoints[i].getX())+1);
			vecPoints[i].y = ((vecPoints[i].getY())+1); 
		}
	}
	/**
	 * decrements the coordinates
	 * 
	 */
	public void decrement()
	{
		int i;
		for(i=0 ; i<vecPoints.length ; i++)
		{
			vecPoints[i].x = ((vecPoints[i].getX())-1);
			vecPoints[i].y = ((vecPoints[i].getY())-1);
		}
	}
	
	/**
	 * This method draws the shapes.
	 * @param g Graphics object for drawing
	 */
	public void draw(Graphics g)
	{
		
		int[] xPoints = new int[vecPoints.length];
		int[] yPoints = new int[vecPoints.length];

		int i;
		for(i=0 ; i<vecPoints.length ; i++)
		{
			xPoints[i] = (int)(vecPoints[i].x);
			yPoints[i] = (int)(vecPoints[i].y);
			
		}
		
		g.fillPolygon(xPoints, yPoints, vecPoints.length); 
		
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

};


