

import java.io.IOException;
/**
 * This interface represents a queue collection.
 * @author melih
 *
 * @param <E> a generic parameter
 */
public interface Queue<E> extends Collection<E>
{

	public abstract E element(); //Retrieves, but does not remove, the head of this queue.
	public abstract void offer(E e);	//Inserts the specified element into this queue
	public abstract E poll() throws ArrayIndexOutOfBoundsException;
}