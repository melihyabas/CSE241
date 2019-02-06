/**
*  A <code>driver</code> is a driver.
 * This class tests the other class. 
 * <p>
 * This class has a main method to test the methods of classes.
 *
 * @author Melih Yabas
 * @since 1.15.2019
 */


public class driver
{	
	/**
	 * main function of the program
	 * @param args a standart string argument for the main
	 */
	public static void main(String[] args)
	{
		System.out.printf("\nWe will use these arrays for all the program:\n\n");		
		int i;
		Integer[] myArray = {12,32,41,71,5,1,2,11};
		Integer[] myArray2 = {12,11,2,1};
		Integer[] myArray3 = {12,5,32,8,9};
		String[] myStr = {"Newyork","Chicago","Washington","Madrid","Barcelona"};
		String[] myStr2 = {"Barcelona","Newyork"};
		String[] myStr3 = {"Trabzon","Manisa","Rize","Washington"};

		System.out.printf("Integer Array1: ");
		for(i=0 ; i<myArray.length ; i++)
			System.out.printf("%s ",myArray[i]);
		System.out.printf("\n");

		System.out.printf("Integer Array2: ");
		for(i=0 ; i<myArray2.length ; i++)
			System.out.printf("%s ",myArray2[i]);
		System.out.printf("\n");

		System.out.printf("Integer Array3: ");
		for(i=0 ; i<myArray3.length ; i++)
			System.out.printf("%s ",myArray3[i]);
		System.out.printf("\n");

		System.out.printf("String Array1: ");
		for(i=0 ; i<myStr.length ; i++)
			System.out.printf("%s ",myStr[i]);
		System.out.printf("\n");

		System.out.printf("String Array2: ");
		for(i=0 ; i<myStr2.length ; i++)
			System.out.printf("%s ",myStr2[i]);
		System.out.printf("\n");

		System.out.printf("String Array3: ");
		for(i=0 ; i<myStr3.length ; i++)
			System.out.printf("%s ",myStr3[i]);	

		System.out.printf("\n\n\n\n");
		
		System.out.printf("TEST OF ITERATOR CLASS:\n");
		Iterator<Integer> intItr = new Iterator<Integer>(myArray);
		Iterator<Integer> intItr2 = new Iterator<Integer>(myArray2);
		Iterator<Integer> intItr3 = new Iterator<Integer>(myArray3);
		Iterator<String> strItr = new Iterator<String>(myStr);
		Iterator<String> strItr2 = new Iterator<String>(myStr2);
		Iterator<String> strItr3 = new Iterator<String>(myStr3);

		System.out.printf("\nTest of hasNext for Integer Array1: %s\n",intItr.hasNext());
		System.out.printf("Test of hasNext for Integer Array2: %s\n",intItr2.hasNext());
		System.out.printf("Test of hasNext for Integer Array3: %s\n",intItr3.hasNext());

		System.out.printf("\nTest of hasNext for String Array1: %s\n",strItr.hasNext());		
		System.out.printf("Test of hasNext for String Array2: %s\n",strItr2.hasNext());
		System.out.printf("Test of hasNext for String Array3: %s\n\n",strItr3.hasNext());

		try
		{
			System.out.printf("Test of next for Integer Array1: %s\n",intItr.next());
			System.out.printf("Test of next for Integer Array2: %s\n",intItr2.next());
			System.out.printf("Test of next for String Array1: %s\n",strItr.next());
			System.out.printf("Test of next for String Array2: %s\n",strItr2.next());
		}
		catch(Exception e)
		{
			System.out.printf("The array does not have a next element!\n");
		}	

		Object[] temp;
		System.out.printf("\nTest of remove function for Integer Array1:");
		intItr.remove();
		temp = (Object[])(intItr.getCont());
		System.out.printf("\nAfter remove function for Integer Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);
		System.out.printf("\nTest of remove function for Integer Array2:");
		intItr2.remove();
		temp = (Object[])(intItr2.getCont());
		System.out.printf("\nAfter remove function Integer Array2: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);
		System.out.printf("\nTest of remove function for String Array1:");
		strItr.remove();
		temp = (Object[])(strItr.getCont());
		System.out.printf("\nAfter remove function String Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);
		System.out.printf("\nTest of remove function for String Array2:");
		strItr2.remove();
		temp = (Object[])(strItr2.getCont());
		System.out.printf("\nAfter remove function String Array2: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);							
		System.out.printf("\n----------------------------------------------------------\n");
		System.out.printf("\nTEST OF HASHSET CLASS:\n\n");
		System.out.printf("Integer Array1: ");
		for(i=0 ; i<myArray.length ; i++)
			System.out.printf("%s ",myArray[i]);
		System.out.printf("\n");

		System.out.printf("Integer Array2: ");
		for(i=0 ; i<myArray2.length ; i++)
			System.out.printf("%s ",myArray2[i]);
		System.out.printf("\n");

		System.out.printf("Integer Array3: ");
		for(i=0 ; i<myArray3.length ; i++)
			System.out.printf("%s ",myArray3[i]);
		System.out.printf("\n");

		System.out.printf("String Array1: ");
		for(i=0 ; i<myStr.length ; i++)
			System.out.printf("%s ",myStr[i]);
		System.out.printf("\n");

		System.out.printf("String Array2: ");
		for(i=0 ; i<myStr2.length ; i++)
			System.out.printf("%s ",myStr2[i]);
		System.out.printf("\n");

		System.out.printf("String Array3: ");
		for(i=0 ; i<myStr3.length ; i++)
			System.out.printf("%s ",myStr3[i]);	
		HashSet<Integer> hi = new HashSet<Integer>(myArray);
		HashSet<Integer> hi2 = new HashSet<Integer>(myArray2);
		HashSet<Integer> hi3 = new HashSet<Integer>(myArray3);

		HashSet<String> hs = new HashSet<String> (myStr);
		HashSet<String> hs2 = new HashSet<String> (myStr2);
		HashSet<String> hs3 = new HashSet<String> (myStr3);

		System.out.printf("\n\nTest of Add function for Integer Array1 (456 added):");
		hi.add(456);
		temp = (Object[])(hi.getContainer());
		System.out.printf("\nAfter add function Integer Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		
		
		System.out.printf("\n\nTest of Add function for Integer Array2 (79 added):");
		hi2.add(79);
		temp = (Object[])(hi2.getContainer());
		System.out.printf("\nAfter add function Integer Array2: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	
	
		System.out.printf("\n\nTest of Add function for Integer Array3 (123 added):");
		hi3.add(123);
		temp = (Object[])(hi3.getContainer());
		System.out.printf("\nAfter add function Integer Array3: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	
	
		System.out.printf("\n\nTest of Add function for String Array1 (\"Lviv\" added):");
		hs.add("Lviv");
		temp = (Object[])(hs.getContainer());
		System.out.printf("\nAfter add function String Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of Add function for String Array2 (\"Kiev\" added):");
		hs2.add("Kiev");
		temp = (Object[])(hs2.getContainer());
		System.out.printf("\nAfter add function String Array2: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of Add function for String Array3 (\"Moscow\" added):");
		hs3.add("Moscow");
		temp = (Object[])(hs3.getContainer());
		System.out.printf("\nAfter add function String Array3: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		
	
		System.out.printf("\n\n\nTest of addAll function(Integer Array2 added to Integer Array1):");
		hi.addAll(hi2);
		temp = (Object[])(hi.getContainer());
		System.out.printf("\nAfter addAll function Integer Array1:");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		

		System.out.printf("\n\n\nTest of addAll function(String Array2 added to String Array1):");
		hs.addAll(hs2);
		temp = (Object[])(hs.getContainer());
		System.out.printf("\nAfter addAll function String Array1:");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		

		System.out.printf("\n\nTest of contains function for Integer Array1 (2,5,100):");
		System.out.printf("\n%s %s %s ",hi.contains(2),hi.contains(5),hi.contains(100));
		System.out.printf("\nTest of contains function for Integer Array2 (777,17,79):");
		System.out.printf("\n%s %s %s ",hi2.contains(77),hi2.contains(17),hi2.contains(79));
		System.out.printf("\nTest of contains function for Integer Array3 (1,2,3):");
		System.out.printf("\n%s %s %s ",hi3.contains(2),hi3.contains(5),hi3.contains(100));	

		System.out.printf("\n\nTest of contains function for String Array1 (Newyork,Tokyo,Istanbul):");
		System.out.printf("\n%s %s %s ",hs.contains("Newyork"),hs.contains("Tokyo"),hs.contains("Istanbul"));
		System.out.printf("\nTest of contains function for String Array2 (Chicago,Newyork,Ankara):");
		System.out.printf("\n%s %s %s ",hs2.contains("Chicago"),hs2.contains("Newyork"),hs2.contains("Ankara"));
		System.out.printf("\nTest of contains function for String Array3 (Lviv,Bursa,Newyork):");
		System.out.printf("\n%s %s %s ",hs3.contains("Lviv"),hs3.contains("Bursa"),hs3.contains("Newyork"));

		System.out.printf("\n\nTest of containsAll function:");
		System.out.printf("\nInteger Array1 contains Integer Array2: %s",hi.containsAll(hi2));	
		System.out.printf("\nInteger Array3 does not contain Integer Array2: %s",hi3.containsAll(hi2));	
		System.out.printf("\nString Array1 contains String Array2: %s",hs.containsAll(hs2));	
		System.out.printf("\nString Array3 does not contain String Array2: %s",hs3.containsAll(hs2));	

		System.out.printf("\nTest of isEmpty function for Integer Array1: %s",hi.isEmpty());
		System.out.printf("\nTest of isEmpty function for Integer Array3: %s",hi3.isEmpty());
		System.out.printf("\nTest of isEmpty function for String Array1: %s",hs.isEmpty());
		System.out.printf("\nTest of isEmpty function for String Array3: %s",hs3.isEmpty());

		System.out.printf("\n\nTest of remove function for Integer Array1:");
		System.out.printf("\nInteger Array1:");
		temp = (Object[])(hi.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		System.out.printf("\nInteger Array1 after deleting 12: ");
		hi.remove(12);	
		temp = (Object[])(hi.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nTest of remove function for String Array1:");
		System.out.printf("\nString Array1:");
		temp = (Object[])(hs.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		System.out.printf("\nString Array1 after deleting Madrid: ");
		hs.remove("Madrid");	
		temp = (Object[])(hs.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nNow, Integer Array1:");
		temp = (Object[])(hi.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);		
		System.out.printf("\nNow, Integer Array2:");
		temp = (Object[])(hi2.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		System.out.printf("\nNow, String Array1:");
		temp = (Object[])(hs.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
			System.out.printf("\nNow, String Array2:");
		temp = (Object[])(hs2.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);				

		System.out.printf("\n\nTest of removeAll function:\n");
		System.out.printf("Deletes Integer Array2's elements from Integer Array1.\n Integer Array1 after removing:");
		hi.removeAll(hi2);
		temp = (Object[])(hi.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nDeletes String Array2's elements from String Array1.\n String Array1 after removing:");
		hs.removeAll(hs2);
		temp = (Object[])(hs.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);	

		System.out.printf("\nTest of retainAll function\nInteger Array1 keeps only Integer Array2's elements.):\n");
		hi.retainAll(hi3);
		System.out.printf("Array1 after removing other elements:");		
		temp = (Object[])(hi.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\nString Array1 keeps only String Array2's elements.):\n");
		hs.retainAll(hs3);
		System.out.printf("String Array1 after removing other elements:");		
		temp = (Object[])(hs.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nTest of size function for Integer Array1: %s",hi.size());
		System.out.printf("\nTest of size function for Integer Array2: %s",hi2.size());
		System.out.printf("\nTest of size function for String Array1: %s",hs.size());
		System.out.printf("\nTest of size function for String Array2: %s",hs2.size());
		hi.clear();
		hi2.clear();
		hi3.clear();
		hs.clear();
		hs2.clear();
		hs3.clear();
		System.out.printf("\nClear function tested. All String Arrays and Integer Arrays are empty.");		


		System.out.printf("\n----------------------------------------------------------\n");
		System.out.printf("\nTEST OF ARRAYLIST CLASS:\n\n");
		System.out.printf("Integer Array1: ");
		for(i=0 ; i<myArray.length ; i++)
			System.out.printf("%s ",myArray[i]);
		System.out.printf("\n");

		System.out.printf("Integer Array2: ");
		for(i=0 ; i<myArray2.length ; i++)
			System.out.printf("%s ",myArray2[i]);
		System.out.printf("\n");

		System.out.printf("Integer Array3: ");
		for(i=0 ; i<myArray3.length ; i++)
			System.out.printf("%s ",myArray3[i]);
		System.out.printf("\n");

		System.out.printf("String Array1: ");
		for(i=0 ; i<myStr.length ; i++)
			System.out.printf("%s ",myStr[i]);
		System.out.printf("\n");

		System.out.printf("String Array2: ");
		for(i=0 ; i<myStr2.length ; i++)
			System.out.printf("%s ",myStr2[i]);
		System.out.printf("\n");

		System.out.printf("String Array3: ");
		for(i=0 ; i<myStr3.length ; i++)
			System.out.printf("%s ",myStr3[i]);	
		ArrayList<Integer> ai = new ArrayList<Integer>(myArray);
		ArrayList<Integer> ai2 = new ArrayList<Integer>(myArray2);
		ArrayList<Integer> ai3 = new ArrayList<Integer>(myArray3);

		ArrayList<String> as = new ArrayList<String> (myStr);
		ArrayList<String> as2 = new ArrayList<String> (myStr2);
		ArrayList<String> as3 = new ArrayList<String> (myStr3);


		System.out.printf("\n\nTest of contains function for Integer Array1 (2,5,100):");
		System.out.printf("\n%s %s %s ",ai.contains(2),ai.contains(5),ai.contains(100));
		System.out.printf("\nTest of contains function for Integer Array2 (777,17,79):");
		System.out.printf("\n%s %s %s ",ai2.contains(77),ai2.contains(17),ai2.contains(79));
		System.out.printf("\nTest of contains function for Integer Array3 (1,2,3):");
		System.out.printf("\n%s %s %s ",ai3.contains(2),ai3.contains(5),ai3.contains(100));	

		System.out.printf("\n\nTest of contains function for String Array1 (Newyork,Tokyo,Istanbul):");
		System.out.printf("\n%s %s %s ",as.contains("Newyork"),as.contains("Tokyo"),as.contains("Istanbul"));
		System.out.printf("\nTest of contains function for String Array2 (Chicago,Newyork,Ankara):");
		System.out.printf("\n%s %s %s ",as2.contains("Chicago"),as2.contains("Newyork"),as2.contains("Ankara"));
		System.out.printf("\nTest of contains function for String Array3 (Lviv,Bursa,Newyork):");
		System.out.printf("\n%s %s %s ",as3.contains("Lviv"),as3.contains("Bursa"),as3.contains("Newyork"));

		System.out.printf("\n\nTest of containsAll function:");
		System.out.printf("\nInteger Array1 contains Integer Array2: %s",ai.containsAll(ai2));	
		System.out.printf("\nInteger Array3 does not contain Integer Array2: %s",ai3.containsAll(ai2));	
		System.out.printf("\nString Array1 contains String Array2: %s",as.containsAll(as2));	
		System.out.printf("\nString Array3 does not contain String Array2: %s",as3.containsAll(as2));	

		System.out.printf("\n\nTest of Add function for Integer Array1 (456 added):");
		ai.add(456);
		temp = (Object[])(ai.getContainer());
		System.out.printf("\nAfter add function Integer Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		
		
		System.out.printf("\n\nTest of Add function for Integer Array2 (79 added):");
		ai2.add(79);
		temp = (Object[])(ai2.getContainer());
		System.out.printf("\nAfter add function Integer Array2: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	
	
		System.out.printf("\n\nTest of Add function for Integer Array3 (123 added):");
		ai3.add(123);
		temp = (Object[])(ai3.getContainer());
		System.out.printf("\nAfter add function Integer Array3: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of Add function for String Array1 (\"Lviv\" added):");
		as.add("Lviv");
		temp = (Object[])(as.getContainer());
		System.out.printf("\nAfter add function String Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of Add function for String Array2 (\"Kiev\" added):");
		as2.add("Kiev");
		temp = (Object[])(as2.getContainer());
		System.out.printf("\nAfter add function String Array2: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of Add function for String Array3 (\"Moscow\" added):");
		as3.add("Moscow");
		temp = (Object[])(as3.getContainer());
		System.out.printf("\nAfter add function String Array3: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		
	
		System.out.printf("\n\n\nTest of addAll function(Integer Array2 added to Integer Array1):");
		ai.addAll(ai2);
		temp = (Object[])(ai.getContainer());
		System.out.printf("\nAfter addAll function Integer Array1:");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		

		System.out.printf("\n\n\nTest of addAll function(String Array2 added to String Array1):");
		as.addAll(as2);
		temp = (Object[])(as.getContainer());
		System.out.printf("\nAfter addAll function String Array1:");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		


		System.out.printf("\nTest of isEmpty function for Integer Array1: %s",ai.isEmpty());
		System.out.printf("\nTest of isEmpty function for Integer Array3: %s",ai3.isEmpty());
		System.out.printf("\nTest of isEmpty function for String Array1: %s",as.isEmpty());
		System.out.printf("\nTest of isEmpty function for String Array3: %s",as3.isEmpty());

		System.out.printf("\n\nTest of remove function for Integer Array1:");
		System.out.printf("\nInteger Array1:");
		temp = (Object[])(ai.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		System.out.printf("\nInteger Array1 after deleting 12: ");
		ai.remove(12);	
		temp = (Object[])(ai.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nTest of remove function for String Array1:");
		System.out.printf("\nString Array1:");
		temp = (Object[])(as.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		System.out.printf("\nString Array1 after deleting Madrid: ");
		as.remove("Madrid");	
		temp = (Object[])(as.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nNow, Integer Array1:");
		temp = (Object[])(ai.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);		
		System.out.printf("\nNow, Integer Array2:");
		temp = (Object[])(ai2.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		System.out.printf("\nNow, String Array1:");
		temp = (Object[])(as.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
			System.out.printf("\nNow, String Array2:");
		temp = (Object[])(as2.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);				

		System.out.printf("\n\nTest of removeAll function:\n");
		System.out.printf("Deletes Integer Array2's elements from Integer Array1.\n Integer Array1 after removing:");
		ai.removeAll(ai2);
		temp = (Object[])(ai.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nDeletes String Array2's elements from String Array1.\n String Array1 after removing:");
		as.removeAll(as2);
		temp = (Object[])(as.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);	

		System.out.printf("\nTest of retainAll function\nInteger Array1 keeps only Integer Array2's elements.):\n");
		ai.retainAll(ai3);
		System.out.printf("Array1 after removing other elements:");		
		temp = (Object[])(ai.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\nString Array1 keeps only String Array2's elements.):\n");
		as.retainAll(as3);
		System.out.printf("String Array1 after removing other elements:");		
		temp = (Object[])(as.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nTest of size function for Integer Array1: %s",ai.size());
		System.out.printf("\nTest of size function for Integer Array2: %s",ai2.size());
		System.out.printf("\nTest of size function for String Array1: %s",as.size());
		System.out.printf("\nTest of size function for String Array2: %s",as2.size());
		ai.clear();
		ai2.clear();
		ai3.clear();
		as.clear();
		as2.clear();
		as3.clear();
		System.out.printf("\nClear function tested. All String Arrays and Integer Arrays are empty.");		

		System.out.printf("\n----------------------------------------------------------\n");
		System.out.printf("\nTEST OF LINKEDLIST CLASS:\n\n");
		System.out.printf("Integer Array1: ");
		for(i=0 ; i<myArray.length ; i++)
			System.out.printf("%s ",myArray[i]);
		System.out.printf("\n");

		System.out.printf("Integer Array2: ");
		for(i=0 ; i<myArray2.length ; i++)
			System.out.printf("%s ",myArray2[i]);
		System.out.printf("\n");

		System.out.printf("Integer Array3: ");
		for(i=0 ; i<myArray3.length ; i++)
			System.out.printf("%s ",myArray3[i]);
		System.out.printf("\n");

		System.out.printf("String Array1: ");
		for(i=0 ; i<myStr.length ; i++)
			System.out.printf("%s ",myStr[i]);
		System.out.printf("\n");

		System.out.printf("String Array2: ");
		for(i=0 ; i<myStr2.length ; i++)
			System.out.printf("%s ",myStr2[i]);
		System.out.printf("\n");

		System.out.printf("String Array3: ");
		for(i=0 ; i<myStr3.length ; i++)
			System.out.printf("%s ",myStr3[i]);	
		LinkedList<Integer> li = new LinkedList<Integer>(myArray);
		LinkedList<Integer> li2 = new LinkedList<Integer>(myArray2);
		LinkedList<Integer> li3 = new LinkedList<Integer>(myArray3);

		LinkedList<String> ls = new LinkedList<String> (myStr);
		LinkedList<String> ls2 = new LinkedList<String> (myStr2);
		LinkedList<String> ls3 = new LinkedList<String> (myStr3);

		System.out.printf("\n\nTest of contains function for Integer Array1 (2,5,100):");
		System.out.printf("\n%s %s %s ",li.contains(2),li.contains(5),li.contains(100));
		System.out.printf("\nTest of contains function for Integer Array2 (777,17,79):");
		System.out.printf("\n%s %s %s ",li2.contains(77),li2.contains(17),li2.contains(79));
		System.out.printf("\nTest of contains function for Integer Array3 (1,2,3):");
		System.out.printf("\n%s %s %s ",li3.contains(2),li3.contains(5),li3.contains(100));	

		System.out.printf("\n\nTest of contains function for String Array1 (Newyork,Tokyo,Istanbul):");
		System.out.printf("\n%s %s %s ",ls.contains("Newyork"),ls.contains("Tokyo"),ls.contains("Istanbul"));
		System.out.printf("\nTest of contains function for String Array2 (Chicago,Newyork,Ankara):");
		System.out.printf("\n%s %s %s ",ls2.contains("Chicago"),ls2.contains("Newyork"),ls2.contains("Ankara"));
		System.out.printf("\nTest of contains function for String Array3 (Lviv,Bursa,Newyork):");
		System.out.printf("\n%s %s %s ",ls3.contains("Lviv"),ls3.contains("Bursa"),ls3.contains("Newyork"));

		System.out.printf("\n\nTest of containsAll function:");

		System.out.printf("\nInteger Array1 contains Integer Array2: %s",li.containsAll(li2));	
		System.out.printf("\nInteger Array3 does not contain Integer Array2: %s",li3.containsAll(li2));	
		System.out.printf("\nString Array1 contains String Array2: %s",ls.containsAll(ls2));	
		System.out.printf("\nString Array3 does not contain String Array2: %s",ls3.containsAll(ls2));
		System.out.printf("\n\nTest of Add function for Integer Array1 (456 added):");
		li.add(456);
		temp = (Object[])(li.getContainer());
		System.out.printf("\nAfter add function Integer Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		
		
		System.out.printf("\n\nTest of Add function for Integer Array2 (79 added):");
		li2.add(79);
		temp = (Object[])(li2.getContainer());
		System.out.printf("\nAfter add function Integer Array2: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of Add function for Integer Array3 (123 added):");
		li3.add(123);
		temp = (Object[])(li3.getContainer());
		System.out.printf("\nAfter add function Integer Array3: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of Add function for String Array1 (\"Lviv\" added):");
		ls.add("Lviv");
		temp = (Object[])(ls.getContainer());
		System.out.printf("\nAfter add function String Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of Add function for String Array2 (\"Kiev\" added):");
		ls2.add("Kiev");
		temp = (Object[])(ls2.getContainer());
		System.out.printf("\nAfter add function String Array2: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of Add function for String Array3 (\"Moscow\" added):");
		ls3.add("Moscow");
		temp = (Object[])(ls3.getContainer());
		System.out.printf("\nAfter add function String Array3: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		
	
		System.out.printf("\n\n\nTest of addAll function(Integer Array2 added to Integer Array1):");
		li.addAll(li2);
		temp = (Object[])(li.getContainer());
		System.out.printf("\nAfter addAll function Integer Array1:");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);		

		System.out.printf("\n\n\nTest of addAll function(String Array2 added to String Array1):");
		ls.addAll(ls2);
		temp = (Object[])(ls.getContainer());
		System.out.printf("\nAfter addAll function String Array1:");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	
	
		System.out.printf("\n\nTest of offer function for Integer Array1 (146 added):");
		li.offer(146);
		temp = (Object[])(li.getContainer());
		System.out.printf("\nAfter offer function Integer Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);	

		System.out.printf("\n\nTest of offer function for Integer String (Izmir added):");
		ls.offer("Izmir");
		temp = (Object[])(ls.getContainer());
		System.out.printf("\nAfter offer function String Array1: ");
		for(i=0 ; i<temp.length ; i++)
				System.out.printf("%s ",temp[i]);												

	

		System.out.printf("\nTest of isEmpty function for Integer Array1: %s",li.isEmpty());
		System.out.printf("\nTest of isEmpty function for Integer Array3: %s",li3.isEmpty());
		System.out.printf("\nTest of isEmpty function for String Array1: %s",ls.isEmpty());
		System.out.printf("\nTest of isEmpty function for String Array3: %s",ls3.isEmpty());

		System.out.printf("\n\nTest of remove function for Integer Array1:");
		System.out.printf("\nInteger Array1:");
		temp = (Object[])(li.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		System.out.printf("\nInteger Array1 after deleting 12: ");
		li.remove(12);	
		temp = (Object[])(li.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);		

		System.out.printf("\n\nTest of remove function for String Array1:");
		System.out.printf("\nString Array1:");
		temp = (Object[])(ls.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		System.out.printf("\nString Array1 after deleting Madrid: ");
		ls.remove("Madrid");	
		temp = (Object[])(ls.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		
		System.out.printf("\nTest of poll function for Integer Array1:");
		try
		{
			li.poll();	
		}	
		catch(Exception e)
		{
			System.out.printf("\nCollection is empty!");
		}
		System.out.printf("\nInteger Array1 after poll function: ");
		temp = (Object[])(li.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\nTest of poll function for String Array1:");
		try
		{
			ls.poll();	
		}	
		catch(Exception e)
		{
			System.out.printf("\nCollection is empty!");
		}
		System.out.printf("\nString Array1 after poll function: ");
		temp = (Object[])(ls.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nNow, Integer Array1:");
		temp = (Object[])(li.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);		
		System.out.printf("\nNow, Integer Array2:");
		temp = (Object[])(li2.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
		System.out.printf("\nNow, String Array1:");
		temp = (Object[])(ls.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);
			System.out.printf("\nNow, String Array2:");
		temp = (Object[])(ls2.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);				

		System.out.printf("\n\nTest of removeAll function:\n");
		System.out.printf("Deletes Integer Array2's elements from Integer Array1.\n Integer Array1 after removing:");
		li.removeAll(li2);
		temp = (Object[])(li.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nDeletes String Array2's elements from String Array1.\n String Array1 after removing:");
		ls.removeAll(ls2);
		temp = (Object[])(ls.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);	

		System.out.printf("\nTest of retainAll function\nInteger Array1 keeps only Integer Array2's elements.):\n");
		li.retainAll(li3);
		System.out.printf("Array1 after removing other elements:");		
		temp = (Object[])(li.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\nString Array1 keeps only String Array2's elements.):\n");
		ls.retainAll(ls3);
		System.out.printf("String Array1 after removing other elements:");		
		temp = (Object[])(ls.getContainer());
		for(i=0 ; i<temp.length ; i++)
			System.out.printf("%s ",temp[i]);

		System.out.printf("\n\nTest of size function for Integer Array1: %s",li.size());
		System.out.printf("\nTest of size function for Integer Array2: %s",li2.size());
		System.out.printf("\nTest of size function for String Array1: %s",ls.size());
		System.out.printf("\nTest of size function for String Array2: %s",ls2.size());

		System.out.printf("\nTest of element function for Integer Array1: %s",li.element());
		System.out.printf("\nTest of element function for String Array1: %s",ls.element());

		li.clear();
		li2.clear();
		li3.clear();
		ls.clear();
		ls2.clear();
		ls3.clear();
		System.out.printf("\nClear function tested. All String Arrays and Integer Arrays are empty.");		
	}
}	
