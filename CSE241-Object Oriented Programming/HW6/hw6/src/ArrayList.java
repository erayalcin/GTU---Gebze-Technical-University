

public class ArrayList<E> implements Set<E>
{
	private E[] buffer; // underlying container.
	private int buf_size;
	

	
	public ArrayList()
	{
		buf_size = 0;
	}
	

	/**
	 
	 * @return Iterator over a ArrayList.
	 */
	@Override
	public Iterator<E> iterator()
	{
		@SuppressWarnings("unchecked")
		E[][] temp = (E[][]) new Object[1][buf_size];
		temp[0] = buffer;

		return new Iterator<E>(temp);
	}


	/**
	 * Inserts the specified element into this ArrayList
	**/
	@Override
	public void add(E e)
	{
		if(isEmpty())
		{
			@SuppressWarnings("unchecked")
			E[] temp = (E[]) new Object[1];
			buffer = temp;
			buffer[0] = e;
			setSize(size()+1);
		}
		else
		{
			setSize(size()+1); // grow the size.
			@SuppressWarnings("unchecked")
			E[] temp = (E[]) new Object[size()]; 

			for(int i=0;i<buffer.length;++i) // copy the previous.
				temp[i] = buffer[i];

			temp[size()-1] = e; // add the new.
			buffer = temp;

		}
	}

	
	/** 
	 * Ensures that ArrayList contains all of the elements in the 
	 * specified collection.
	**/
	@Override
	public void addAll(Collection<E> c)
	{
		Iterator<E> begin = c.iterator();
		while(begin.hasNext())
			add(begin.next());
	}

	/**
	 * Removes all of the elements from ArrayList 
	**/
	@Override
	public void clear()
	{
		buffer = null;
		setSize(0);
	}

	/**
	 * Returns true if the ArrayList contains the specified element
	 * at least one time. 
	**/
	public boolean contains(E e)
	{
		boolean found = false;

		if(isEmpty())
			found = false;
		else
		{
			for(int i=0;i<size() && !found;++i) // linear search.
			{
				if(buffer[i] == e)
					found = true;
			}
		}

		return found;
	}

	
	/** 
	* Returns true if this ArrayList contains all of the elements in the
	* specified collection. 
	**/
	@Override
	public boolean containsAll(Collection<E> c)
	{
		boolean found = true;
		Iterator<E> begin = c.iterator();
		while(begin.hasNext())
			found = found && contains(begin.next());
		
		return found;
	}

	/**
	 * Returns true if the ArrayList contains no element. 
	 **/
	@Override
	public boolean isEmpty()
	{
		return size()==0;
	}

	/**
	 * Removes the specified element from the ArrayList.
	**/
	@Override
	public void remove(E e)
	{
		while(contains(e))
		{
			setSize(size()-1);
			@SuppressWarnings("unchecked")
			E[] temp = (E[])new Object[size()];


			for(int i=0,j=0;i<buffer.length;++i) // linear search.
			{
				if(buffer[i] != e)
				{
					temp[j++] = buffer[i];
				}
			}

			buffer = temp;
		}
		
	}


	
	/**
	 * Removes all duplicates of ArrayList's elements that are also contained in the specified collection.  
	**/
	@Override
	public void removeAll(Collection<E> c)
	{
		Iterator<E> begin = c.iterator();
		while(begin.hasNext())
			remove(begin.next());
	}

	
	
	/**
	 * Retains only the elements hashset that are contained in the specified collection. 
	**/
	@Override
	public void retainAll(Collection<E> c)
	{	
		Iterator<E> begin = c.iterator();
		while(begin.hasNext())
		{
			E temp = begin.next();
			if(!contains(temp))
				c.remove(temp);
		}
	}

	/**
	 * Returns the number of elements in ArrayList
	**/
	public int size()
	{	
		return buf_size;
	}

	private void setSize(int s)
	{
		buf_size = s;
	}	
}