/**
	 * @author Eray Alçin
	*/

public interface List<E> extends Collection<E>
{

	public Iterator<E> iterator();
	public void add(E e);
	public void addAll(Collection<E> c);
	public void clear();
	public boolean contains(E e);
	public boolean containsAll(List<E> c);
	public boolean isEmpty();
	public void remove(E e);
	public void removeAll(Collection<E> c);
	public void retainAll(Collection<E> c);
	public int size();
} 