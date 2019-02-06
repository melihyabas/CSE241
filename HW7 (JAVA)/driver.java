/**
 * This class tests all the methods of the program. And it draw the shapes on the screen.
 * @author Melih Yabas
 */
import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Vector;

import javax.swing.JPanel;
import java.awt.Color;
import javax.swing.JComboBox;
import javax.swing.JTextField;
/**
 * 
 * This is a constructor for create a JFrame object.
 *
 */
public class driver {

	private JFrame frame;
	private JTextField txttestsMethodsOf;

	/**
	 * Launch the application.
	 */
	/**
	 * This is the main method of the program. It contains all of the test of methods.
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.printf("TEST OF RECTANGLE CLASS\n\n");
		Rectangle testR = new Rectangle();
		try
		{
			testR.setWidth(5);
		}
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");
		}
		try
		{
			testR.setHeight(10);
		}	
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");
		}

		Rectangle testR2 = new Rectangle();
		try
		{
		testR2.setWidth(7);
		}
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");
		}
		try
		{
			testR2.setHeight(10);
		}
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");			
		}
		Rectangle testR3 = new Rectangle();
		try
		{
			testR3.setWidth(7);
		}
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");						
		}
		try
		{
			testR3.setHeight(10);
		}
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");						
		}		
		System.out.printf("\nArea():\nwidth:%s height:%s area:%s",testR.getWidth(),testR.getHeight(),testR.area());
		System.out.printf("\n\nPerimeter():\nwidth:%s height:%s perimeter:%s",testR.getWidth(),testR.getHeight(),testR.perimeter());
		System.out.printf("\n\nIncrement():\nx:%s y:%s",testR.getX(),testR.getY());
		testR.increment();
		System.out.printf("\n\nAfter Increment x:%s y:%s",testR.getX(),testR.getY());
		
		System.out.printf("\n\nDecrement():\nx:%s y:%s",testR.getX(),testR.getY()); 
		testR.decrement();
		System.out.printf("\n\nAfter Decrement() x:%s y:%s",testR.getX(),testR.getY());
		
		System.out.printf("\n\nCompareTo():\nRectangle2 is bigger than Rectangle1: %s",	testR.compareTo(testR2));
		System.out.printf("\nRectangle1 is smaller than Rectangle2: %s",	testR2.compareTo(testR));
		System.out.printf("\nRectangle2 equals to Rectangle3: %s",	testR2.compareTo(testR3));
		System.out.printf("\n------------------------------------------\n");
		System.out.printf("\n\nTEST OF TRIANGLE CLASS\n\n");
		Triangle testT = new Triangle();
		try
		{
			testT.setSide(10);
		}
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");						
		}			
		Triangle testT2 = new Triangle();
		try
		{
			testT2.setSide(11);
		}
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");						
		}		
		Triangle testT3 = new Triangle();
		try
		{
			testT3.setSide(11);			
		}
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");						
		}	
		System.out.printf("\nArea():\nside:%s area:%s",testT.getSide(),testT.area());
		System.out.printf("\n\nPerimeter():\nside:%s perimeter:%s",testT.getSide(),testT.perimeter());
		System.out.printf("\n\nIncrement():\nx1:%s y1:%s x2:%s y2:%s x3:%s y3:%s",testT.getX1(),testT.getY1(),testT.getX2(),testT.getY2(),testT.getX3(),testT.getY3());
		testT.increment();
		System.out.printf("\n\nAfter Increment():\nx1:%s y1:%s x2:%s y2:%s x3:%s y3:%s",testT.getX1(),testT.getY1(),testT.getX2(),testT.getY2(),testT.getX3(),testT.getY3());
		
		System.out.printf("\n\nDecrement():\nx1:%s y1:%s x2:%s y2:%s x3:%s y3:%s",testT.getX1(),testT.getY1(),testT.getX2(),testT.getY2(),testT.getX3(),testT.getY3());
		testT.decrement();
		System.out.printf("\n\nAfter Decrement():\nx1:%s y1:%s x2:%s y2:%s x3:%s y3:%s",testT.getX1(),testT.getY1(),testT.getX2(),testT.getY2(),testT.getX3(),testT.getY3());
		
		System.out.printf("\n\nCompareTo():\nTriangle2 is bigger than Triangle1: %s",	testT.compareTo(testT2));
		System.out.printf("\nTriangle1 is smaller than Triangle2: %s",	testT2.compareTo(testT));
		System.out.printf("\nTriangle2 equals to Triangle3: %s",	testT2.compareTo(testT3));
		System.out.printf("\n------------------------------------------\n");

		System.out.printf("TEST OF CIRCLE CLASS\n\n");
		Circle testC = new Circle(5);
		Circle testC2 = new Circle(7);
		Circle testC3 = new Circle(7);
		
		System.out.printf("\nArea():\nradius:%s area:%s",testC.getRadius(),testC.area());
		System.out.printf("\nPerimeter():\nradius:%s perimeter:%s",testC.getRadius(),testC.perimeter());
		System.out.printf("\n\nIncrement():\nx:%s y:%s",testC.getX(),testC.getY());
		testC.increment();
		System.out.printf("\n\nAfter Increment x:%s y:%s",testC.getX(),testC.getY()); 
		
		System.out.printf("\n\nDecrement():\nx:%s y:%s",testC.getX(),testC.getY()); 
		testC.decrement(); 
		System.out.printf("\n\nAfter Decrement() x:%s y:%s",testC.getX(),testC.getY());
		
		System.out.printf("\n\nCompareTo():\nCircle2 is bigger than Circle1: %s",	testC.compareTo(testC2));
		System.out.printf("\nCircle1 is smaller than Circle2: %s",	testC2.compareTo(testC));
		System.out.printf("\nCircle2 equals to Circle3: %s",	testC2.compareTo(testC3));	
		System.out.printf("\n------------------------------------------\n");

		System.out.printf("TEST OF COMPOSEDSHAPE CLASS\n\n");		
		ComposedShape testCS = new ComposedShape(testR, testT);
		ComposedShape testCS2 = new ComposedShape(testR2, testT2);	
		ComposedShape testCS3 = new ComposedShape(testR3, testT3);
		System.out.printf("\nArea():\nArea of Rect1 + Area of Tri1: %s", testCS.area());
		System.out.printf("\n\nPerimeter():\nPerimeter of Rect1 + Perimeter of Tri1: %s", testCS.area());
		testCS.optimalFit(testR3, testR);
		testCS.increment();
		testCS.decrement();
		System.out.printf("Increment() and Decrement() functions have tested.");
		System.out.printf("\n\nCompareTo():\nComposedShape2 is bigger than ComposedShape1: %s",	testCS.compareTo(testCS2));
		System.out.printf("\nComposedShape1 is smaller than ComposedShape2: %s",	testCS2.compareTo(testCS));
		System.out.printf("\nComposedShape2 equals to ComposedShape3: %s",	testCS2.compareTo(testCS3));			
		System.out.printf("\n------------------------------------------\n");

		System.out.printf("\n\nTEST OF POLYGONDYN CLASS\n\n");	
		testR.setX(0);
		testR.setY(0);
		PolygonDyn testPd = new PolygonDyn(testC);
		PolygonDyn testPd2 = new PolygonDyn(testC2);
		PolygonDyn testPd3 = new PolygonDyn(testC3);

		
		System.out.printf("\nArea():\nradius of the polygon circle:%s area:%s",testC.getRadius(),testPd.area());
		System.out.printf("\nPerimeter():\nradius of the polyon circle:%s perimeter:%s",testC.getRadius(),testPd.perimeter());
		System.out.printf("\n\nIncrement() and Decrement() methods have tested.");
		testPd.increment();
		testPd.decrement(); 
		
		System.out.printf("\n\nCompareTo():\nPolygon2 is bigger than Polygon1: %s",	testPd.compareTo(testPd2));
		System.out.printf("\nPolygon1 is smaller than Polygon2: %s",	testPd2.compareTo(testPd));
		System.out.printf("\nPolygon2 equals to Polygon3: %s",	testPd2.compareTo(testPd3));	
		System.out.printf("\n------------------------------------------\n");

		System.out.printf("\n\nTEST OF POLYGONVECT CLASS\n\n");	
		try
		{
			testR.setCoordinates(0,0);
		}	
		catch(Exception e)
		{
			System.out.printf("This cannot be set.");						
		}			
		PolygonVect testPv = new PolygonVect(testC);
		PolygonVect testPv2 = new PolygonVect(testC2);
		PolygonVect testPv3 = new PolygonVect(testC3);

		
		System.out.printf("\nArea():\nradius of the polygon circle:%s area:%s",testC.getRadius(),testPv.area());
		System.out.printf("\nPerimeter():\nradius of the polyon circle:%s perimeter:%s",testC.getRadius(),testPv.perimeter());
		System.out.printf("\n\nIncrement() and Decrement() methods have tested.");
		testPv.increment();
		testPv.decrement(); 
		
		System.out.printf("\n\nCompareTo():\nPolygon2 is bigger than Polygon1: %s",	testPv.compareTo(testPv2));
		System.out.printf("\nPolygon1 is smaller than Polygon2: %s",	testPd2.compareTo(testPv));
		System.out.printf("\nPolygon2 equals to Polygon3: %s",	testPv2.compareTo(testPv3));	
		System.out.printf("\n------------------------------------------\n");

		System.out.printf("\n\nTEST OF STATICMETHODS CLASS\n\n");
		System.out.printf("drawAll() tested in ComposedShape draw() function.\n");
		System.out.printf("convertAll():\n");
	
		Vector<Shape> vT = new Vector<Shape>();
		Vector<Shape> vT2 = new Vector<Shape>();

		vT.add(testT);
		if(testT instanceof Triangle)
			System.out.printf("TestT is a Triangle.\n");
		
		vT2 = staticMethods.convertAll(vT);
		
		if(vT2.get(0) instanceof PolygonDyn)
		{
			System.out.printf("After convertAll(), TestT is a Polygon.\n");
		}
		System.out.printf("sortAll():\n");
		vT.add(testT2);
		System.out.printf("Shape 1:testT Shape 2:testT2\nTest2 is bigger.");
		staticMethods.sortShapes(vT);
		System.out.printf("After sortShapes(), Shape 1:testT2 Shape 2:testT1.");
		System.out.printf("\n------------------------------------------\n");

		System.out.printf("\n\nTEST OF SOME THROW LISTS \n\n");	
		try
		{
			testR.setWidth(-7);
		}	
		catch(Exception e)
		{
			System.out.printf("\nWidth of rectangle cannot be a negative value!\n");
		}
		try
		{
			testC.setRadius(-14);
		}
		catch(Exception e)
		{
			System.out.printf("\nRadius of a circle cannot be a negative value!\n");
		}
		try
		{
			testT.setSide(-77);
		}
		catch(Exception e)
		{
			System.out.printf("\nSide of a triangle cannot be a negative value!\n");
		}
		try
		{
			testT.setCoordinates(-4,1,5,7,-4,5);
		}
		catch(Exception e)
		{
			System.out.printf("\nCoordinates cannot be negative!\n");
		}
		try
		{
			testR.setCoordinates(-4,1);
		}
		catch(Exception e)
		{
			System.out.printf("\nCoordinates cannot be negative!\n");
		}
		try
		{
			testC.setCoordinates(88,-71);
		}
		catch(Exception e)
		{
			System.out.printf("\nCoordinates cannot be negative!\n");
		}				
		/**
		 * This is the run method of driver class.
		 */
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					driver window = new driver();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public driver() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	/**
	 * This is the initialize method. We create the all panel and tools etc. here. 
	 * Also, we decide want we want to do.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 375, 456);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		final JComboBox<String> comboBox = new JComboBox<String>();
		comboBox.addItem("Rectangle");
		comboBox.addItem("Circle"); 
		comboBox.addItem("Triangle");		
		comboBox.setBounds(20, 291, 90, 20);
		frame.getContentPane().add(comboBox);
		
		final JComboBox<String> comboBox2 = new JComboBox<String>();
		comboBox2.setBounds(123, 291, 90, 20);
		frame.getContentPane().add(comboBox2);
		comboBox2.addItem("Rectangle");
		comboBox2.addItem("Circle");
		comboBox2.addItem("Triangle");				
		final JPanel panel = new JPanel();
		panel.setBackground(Color.WHITE);
		panel.setBounds(10, 11, 310, 269);
		frame.getContentPane().add(panel);	
		
		JButton btnDrawIt = new JButton("Draw it!");
		btnDrawIt.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Rectangle r = new Rectangle();
				try
				{
					r.setWidth(225);
				}
		 		catch(Exception e)
				{
					System.out.printf("This cannot be set.");						
				}						
				try
				{
					r.setHeight(225);
				}
				catch(Exception e)
				{
					System.out.printf("This cannot be set.");						
				}						
				Rectangle r2 = new Rectangle();
				try
				{
					r2.setWidth(5);					
				}
				catch(Exception e)
				{
					System.out.printf("This cannot be set.");						
				}					
				try
				{
					r2.setHeight(5);
				}
				catch(Exception e)
				{
					System.out.printf("This cannot be set.");						
				}						
				Triangle t = new Triangle();
				t.setSide(280);
				Triangle t2 = new Triangle();
				t2.setSide(85);
				
				Circle c = new Circle();
				c.setRadius(120);
				Circle c2 = new Circle();
				c2.setRadius(20);
				

				if(comboBox.getSelectedItem() == "Rectangle"&&comboBox2.getSelectedItem() == "Rectangle")
				{
					ComposedShape cs = new ComposedShape(r,r2);	
					cs.optimalFit(r, r2);		
					
					final Graphics g = panel.getGraphics();			
					cs.draw(g);
				}
				if(comboBox.getSelectedItem() == "Rectangle"&&comboBox2.getSelectedItem() == "Triangle")
				{
					ComposedShape cs6 = new ComposedShape(r,t2); 
					cs6.optimalFit(r, t2);
					final Graphics g = panel.getGraphics();			
					cs6.draw(g);
				}
				if(comboBox.getSelectedItem() == "Triangle"&&comboBox2.getSelectedItem() == "Rectangle")
				{
					ComposedShape cs3 = new ComposedShape(t,r2); 
					cs3.optimalFit(t, r2);
					final Graphics g = panel.getGraphics();			
					cs3.draw(g);
				}		
				if(comboBox.getSelectedItem() == "Rectangle"&&comboBox2.getSelectedItem() == "Circle")
				{
					ComposedShape cs2 = new ComposedShape(r,c2);
					cs2.optimalFit(r, c2);
					final Graphics g = panel.getGraphics();			
					cs2.draw(g);
				}

				if(comboBox.getSelectedItem() == "Triangle"&&comboBox2.getSelectedItem() == "Triangle")
				{
					ComposedShape cs4 = new ComposedShape(t,t2); 
					cs4.optimalFit(t, t2);
					final Graphics g = panel.getGraphics();			
					cs4.draw(g);
				}
				if(comboBox.getSelectedItem() == "Triangle"&&comboBox2.getSelectedItem() == "Circle")
				{
					ComposedShape cs5 = new ComposedShape(t,c2); 
					cs5.optimalFit(t, c2);					
					final Graphics g = panel.getGraphics();			
					cs5.draw(g);
				}
				if(comboBox.getSelectedItem() == "Circle"&&comboBox2.getSelectedItem() == "Rectangle")
				{
					ComposedShape cs7 = new ComposedShape(c,r2);
					cs7.optimalFit(c, r2);		
					final Graphics g = panel.getGraphics();			
					cs7.draw(g);
				}
				if(comboBox.getSelectedItem() == "Circle"&&comboBox2.getSelectedItem() == "Triangle")
				{
					ComposedShape cs8 = new ComposedShape(c,t2);	
					cs8.optimalFit(c, t2);
					final Graphics g = panel.getGraphics();			
					cs8.draw(g);
				}
				if(comboBox.getSelectedItem() == "Circle"&&comboBox2.getSelectedItem() == "Circle")
				{
					ComposedShape cs9 = new ComposedShape(c,c2);  
					cs9.optimalFit(c, c2);	
					final Graphics g = panel.getGraphics();			
					cs9.draw(g);
				}
				
				
	
			}
		});
		btnDrawIt.setFont(new Font("Tahoma", Font.BOLD, 11));
		btnDrawIt.setBounds(247, 284, 82, 47);
		frame.getContentPane().add(btnDrawIt);
		
		JButton btnDelete = new JButton("Delete");
		btnDelete.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.WHITE); // from now on, use white color
				g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
				panel.paintComponents(g); // the panel will change when THIS function is executed
			}
		}); 
		btnDelete.setBounds(89, 322, 82, 29);
		frame.getContentPane().add(btnDelete);
		
		JButton btnTestPolygondyn = new JButton("Test PolygonDyn");
		btnTestPolygondyn.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.RED); // from now on, use white color
				Rectangle r = new Rectangle();
				r.setWidth(245);
				r.setHeight(300);
				r.setCoordinates(0, 0);
				
				PolygonDyn dy = new PolygonDyn(r);
				dy.draw(g);
				
			}
		});
		btnTestPolygondyn.setBounds(35, 371, 136, 23);
		frame.getContentPane().add(btnTestPolygondyn);
		
		JButton btnTestPolygonvect = new JButton("Test PolygonVect");
		btnTestPolygonvect.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				Graphics g = panel.getGraphics(); // get brush
				g.setColor(Color.BLUE); // from now on, use white color
				Circle c = new Circle();
				c.setRadius(100);
				PolygonVect vc = new PolygonVect(c);
				vc.draw(g);
				
			}
		});
		btnTestPolygonvect.setBounds(170, 371, 136, 23);
		frame.getContentPane().add(btnTestPolygonvect);
		
		txttestsMethodsOf = new JTextField();
		txttestsMethodsOf.setText("(Tests draw methods of these Polygon Classes)");
		txttestsMethodsOf.setBounds(35, 397, 285, 20);
		frame.getContentPane().add(txttestsMethodsOf);
		txttestsMethodsOf.setColumns(10);
		
		
		

	}
}
