import java.awt.Color;
import java.awt.Graphics;
import java.util.Vector;
/**
 * This is a class that include some static methods for all the program.
 * @author melih
 *
 */
public class staticMethods {
	/**
	 * This class takes some objects and convert them to polygon.
	 * @param v This parameter is a vector that includes Shape objects.
	 * @return Returns a new vector for converted objects.
	 */
	public static Vector<Shape> convertAll(Vector<Shape> v)
	{
		int i = 0;
		Vector<Shape> v2 = new Vector<Shape>();
		for(i=0 ; i<v.size() ; i++)
		{
	
			if(v.get(i) instanceof Rectangle)
			{
				Rectangle r = new Rectangle();
				r = (Rectangle)(v.get(i));
	
				PolygonDyn obj = new PolygonDyn(r);
				v2.add(obj);
			}
			if(v.get(i) instanceof Triangle)
			{
				Triangle t = new Triangle();
				t = (Triangle)(v.get(i));
	
				PolygonDyn obj = new PolygonDyn(t);
				v2.add(obj);
			}
			if(v.get(i) instanceof Circle)
			{
				Circle c = new Circle();
				c = (Circle)(v.get(i));
	
				PolygonDyn obj = new PolygonDyn(c);
				v2.add(obj);
			}		
		}
	
		return v2;
	}
	/**
	 * This method just draw the shapes that is take on the screen.
	 * @param v A vector that contains shapes.
	 * @param g A Graphics object for drawing.
	 */
	public static void drawAll(Vector<Shape> v, Graphics g)
	{
		int i; 

		for(i=0 ; i<v.size() ; i++)
		{
			double random = Math.random()*(v.size());
			int num = (int)random;			
			if(i==0)
				g.setColor(Color.GREEN);
			else if(num%5==0)
				g.setColor(Color.ORANGE);
			else if(num%8==0)
				g.setColor(Color.BLUE);
			else if(num%7==0)
				g.setColor(Color.RED);
			else if(num%9==0)
				g.setColor(Color.GRAY);
			
			else
			{
				if(i%3==0)
					g.setColor(Color.CYAN);
				else if(i%4 == 0)
					g.setColor(Color.magenta);
				else
					g.setColor(Color.LIGHT_GRAY);
	
			}
			
			(v.get(i)).draw(g);
		}

	}

	/**
	 * This class sorts the shapes with respect their area.
	 * @param v A vector that include shapes.
	 */
	public static void sortShapes(Vector<Shape> v)
	{
		Shape temp;
		int i,j;
		for(i=0 ; i<v.size() ; i++)
		{
			for(j=0 ; j<v.size() ; j++)
			{
				if((v.get(i)).area() < (v.get(j)).area())
				{
					temp = v.get(i);
					v.set(i,v.get(j));
					v.set(j,temp);
				}
			}
		}	
	}	

}
