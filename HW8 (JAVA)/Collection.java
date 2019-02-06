
/**
 * This is an interface that contains many collection.
 * @author melih yabas
 *
 * @param <E>
 */
public interface Collection<E>
{
	public abstract Iterator<E> iterator();
	public abstract boolean contains(E e);
	public abstract boolean containsAll(Collection<E> c);
	public abstract boolean isEmpty();
	public abstract void add(E e);
	public abstract void addAll(Collection<E> c);
	public abstract void clear();
	public abstract void remove(E e);
	public abstract void removeAll(Collection<E> c);
	public abstract void retainAll(Collection<E> c);
	public abstract int size();



}

