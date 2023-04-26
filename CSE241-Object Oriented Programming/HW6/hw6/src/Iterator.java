/**
	 * @author Eray Alçin
	*/


public class Iterator<E>
{
	private E[][] temp ; 
	private int location; 
	private E last_element; 

	public Iterator(E[][] arr)
	{
		temp = arr;
		location = 0;
	}

	/** 
	 * Returns true if the iteration has more elements.
	 * @return true if iteration has more elements.
	*/
	public boolean hasNext()
	{
		return location<temp[0].length;
	}

	/**
	 * Returns the next element in the iteration and advances the iterator.
 	*/
	public E next()
	{
		last_element = temp[0][location++];
		return last_element;
	}
	
	/**
	 * Removes from the underlying collection the last element returned by this iterator.
	*/
	public void remove()
	{
		@SuppressWarnings("unchecked")
		E[] newArr = (E[]) new Object[temp[0].length -1];

		for(int i=0, k=0;i<newArr.length;++i)
		{

			if(last_element == temp[0][i])
				continue;
			
			newArr[k++] = temp[0][i];
		}

		temp[0] = newArr; 
	}


}

