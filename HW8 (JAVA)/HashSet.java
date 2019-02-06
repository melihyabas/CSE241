/**
 * HashSet class represents a kind of set.
 * @author melih
 *
 * @param <E> a generic parameter
 */
public class HashSet<E> implements Set<E>
{	
    private E[] Container;
    /**
     * No parameter constructor.
     */
	public HashSet()
	{ }
	/**
	 * Takes a generic array and assings it to Container.
	 * @param obj Generic array object
	 */
	public HashSet(E[] obj)
	{
		Container = obj;
	}
	/**
	 * 
	 * @return Container array.
	 */
	public E[] getContainer()
	{
		return Container;
	}
	/**
	 * Takes an array and sets it to Container.
	 * @param obj
	 */
	public void setContainer(E[] obj)
	{
		Container = obj;
	}
	/**
	 * Creates an Iterator object with Container array.
	 */
	@SuppressWarnings("unchecked") public Iterator<E> iterator ()
	{
		Iterator<E> p = new Iterator(Container);

		return p;
	}	

	/**
	 * Checks if the Container contains the element.
	 * @param e A generic element
	 */
	public boolean contains(E e)
	{
		int i;

		for(i=0 ; i<Container.length ; i++)
			if(Container[i]==e)
				return true;
		return false;
	}	
	/**
	 * Adds an element to the Container's end.
	 */
	@SuppressWarnings("unchecked") public void add(E e)
	{
		int i;
		E[] temp = (E[])new Object[Container.length+1];

		if(!(contains(e)))
		{	
			for(i=0 ; i<Container.length ; i++)
				temp[i] = Container[i];
			temp[Container.length] = e;
			Container = temp;
			temp = null;
		}
	}
	/**
	 *  Adds all the element to the container from the giver collection.
	 *  @param c is another collection like HashSet
	 */
	@SuppressWarnings("unchecked") public void addAll(Collection<E> c)
	{
		int i;
		E[] arr = (c.iterator()).getCont();
		int count = 0;

		for(i=0 ; i<arr.length ; i++)
			add(arr[i]);

	}	
	/**
	 * Clears all the elements.
	 */
	public void clear()
	{
		Container = null;
	}

	/**
	 * Removes the specified element from the collection.
	 * @param e is a generic variable.
	 */
	@SuppressWarnings("unchecked") public void remove(E e)
	{
		int i,k=0,count = 0;
		for(i=0 ; i<Container.length ; i++)
		{
			if(Container[i]==e)
				count++;
		}
		
		E[] temp = (E[])new Object[Container.length-count];

		for(i=0 ; i<Container.length ; i++)
		{
			if(Container[i]!=e)
			{
				temp[k] = Container[i];
				k++;
			}

		}

		Container = temp;
		temp = null;

	}

	/**
	 * Removes all the elements if the given collection has these elements
	 */
	@SuppressWarnings("unchecked") public void removeAll(Collection<E> c)
	{	
		
		int i,j,k,count = 0;

		E[] arr = (c.iterator()).getCont();
	
		for(i=0 ; i<arr.length ; i++)
		{
			for(j=0 ; j<Container.length ; j++)
			{
				if(arr[i] == Container[j])
					count++;
			}
		}
		E[] temp = (E[])new Object[Container.length-count];
		
		count=0;
		k=0;
		for(j=0 ; j<Container.length ; j++)
		{
			for(i=0 ; i<arr.length ; i++)
				if(arr[i]==Container[j])
					count++;

			if(count==0)
			{
				temp[k]=Container[j];
				k++;		
			}
				count=0;
		}

		Container = temp;
		temp = null;
		arr = null;

	}   
	/**
	 * Retains the given elements and deletes the other ones.
	 */
	@SuppressWarnings("unchecked") public void retainAll(Collection<E> c)
	{
		int i,j,k, count=0;
		E[] arr = (c.iterator()).getCont();

		for(i=0 ; i<Container.length ; i++)
		{
			for(j=0 ; j<arr.length ; j++)
			{
				if(Container[i] == arr[j])
					count++;
			}
		}

		E[] temp = (E[])new Object[count];
		k=0;
		for(i=0 ; i<Container.length ; i++)
		{
			for(j=0 ; j<arr.length ; j++)
			{
				if(Container[i] == arr[j])
				{
					temp[k]=Container[i];
					k++;
				}
			}
		}
		Container = temp;	
		temp = null;
		arr = null;
	}
	/**
	 * @return Container's size
	 */
	public int size()
	{
		return Container.length;
	}

	/**
	 * Checks if the Container have all the given elements
	 */
	public boolean containsAll(Collection<E> c)
	{
		int i, j, count = 0;

		E[] temp = (c.iterator()).getCont();

		for(i=0 ; i<Container.length ; i++)
		{
			for(j=0 ; j<temp.length ; j++)
			{
				if(Container[i]==temp[j])
					count++;
			}
		}
		return (count==temp.length);
	}
	
	/**
	 * Returns true if the collection is empty.
	 */
	public boolean isEmpty()
	{
		return (Container.length==0);
	}	

}
