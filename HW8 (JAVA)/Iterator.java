/**
 * Iterator class helps the other class like an index.
 * @author melih yabas
 *
 * @param <E> a generic type
 */
public class Iterator<E>
{
    private E[] Container;
	private int indicator;
	private Collection<E> cl;
	/**
	 * No parameter constructor.
	 */
	public Iterator()
	{ }
	/**
	 * Takes an array and assigns it to the Container.
	 * @param obj a generic array
	 */
	public Iterator(E[] obj)
	{
		Container = obj;
		indicator = 0;
	}

	/**
	 * Takes a Collection object and controls it what its type.
	 * And then convert it to the type.
	 * @param obj
	 */
	public Iterator(Collection<E> obj)
	{
		cl = obj;
		if(obj instanceof HashSet)
		{
			Container = ((HashSet<E>) obj).getContainer();
		}
		else if(obj instanceof ArrayList)
		{
			Container = ((ArrayList<E>) obj).getContainer();
		}
		else if(obj instanceof LinkedList)
		{
			Container = ((LinkedList<E>) obj).getContainer();
		}				
		indicator = 0;	
	}
	/**
	 * 
	 * @return Container Array
	 */
	public E[] getCont()
	{
		return Container;
	}

	/**
	 * Control if the collection has any other element
	 * @return a boolean variable
	 */
	public boolean hasNext()
	{	

		if(Container.length>indicator)
			return true;
		else
			return false;
	}
	/**
	 * 
	 * @return next element
	 * @throws ArrayIndexOutOfBoundsException throws if the collection does not have a next element
	 */
	public E next() throws ArrayIndexOutOfBoundsException
	{
		if(Container[indicator+1] == null)
			throw new ArrayIndexOutOfBoundsException();
		indicator++;
		E x;
		x = Container[indicator];

		return x;
	}
	/**
	 * Removes the element and set the new array to the collection.
	 */
 	@SuppressWarnings("unchecked") public void remove()
	{
		E[] temp = (E[])new Object[Container.length-1];
		int i,j=0;
		for(i=0 ; i<Container.length ; i++)
		{
			if(i!=indicator)
			{
				temp[j] = Container[i];
			}
			if(i==indicator)
				j--;
			j++;
		}
		Container = temp;


		if(cl instanceof HashSet)
		{
			((HashSet<E>) cl).setContainer(Container);
		}	
		else if(cl instanceof ArrayList)
		{
			((ArrayList<E>) cl).setContainer(Container);
		}	
		else if(cl instanceof LinkedList)
		{
			((LinkedList<E>) cl).setContainer(Container);
		}						

	}

}
