

public interface Queue<E> extends Collection<E>
{


	
	public Iterator<E> iterator();
	public void add(E e);
	public void addAll(Collection<E> c);
	public void clear();
	public boolean contains(E e);
	public boolean containsAll(Collection<E> c);
	public boolean isEmpty();
	public void remove(E e);
	public void removeAll(Collection<E> c);
	public void retainAll(Collection<E> c);
	public int size();
	public E element()throws emptyQueue;
	public void offer(E e);
	public E poll()throws emptyQueue;
	public class emptyQueue extends Exception 
	{
		public String toString()
		{
			return "Empty Queue Error!";
		}
	}

}
