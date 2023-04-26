import java.util.Arrays;

public class KWArrayList<E> {
    
    private static final int INITIAL_CAPACITY = 10;
    private E[] theData;
    private int size = 0;
    private int capacity = 0;
    
    public KWArrayList() {
        capacity = INITIAL_CAPACITY;
        theData = (E[]) new Object[capacity];
    }
    
    public int size() {
        return size;
    }
        
    public boolean add(E anEntry) {
        if(size == capacity) {
            reallocate(); //doubles the capacity
        }
        theData[size] = anEntry;
        size++;
        return true;
    }
    
    public void add(int index, E anEntry) {
        if(index<0 || index>=size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        if(size == capacity) {
            reallocate();
        }
        for(int i=size; i>index; i--) {
            theData[i] = theData[i-1];
        }
        theData[index] = anEntry;
        size++;
    }
    
    
    public E get(int index) {
        if(index<0 || index>=size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        return theData[index];
    }
    
    public E set(int index, E newValue) {
        //System.out.println("sa from set");
        if(index<0 || index>=size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        E oldValue = theData[index];
        theData[index] = newValue;
        return oldValue;
    }
    
    public E remove(int index) {
        if(index<0 || index>=size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        E returnValue = theData[index];
        for(int i=index+1; i<size; i++) {
            theData[i-1] = theData[i];
        }
        size--;
        return returnValue;
    }
    
    private void reallocate() {
        capacity = 2 * capacity;
        theData = Arrays.copyOf(theData, capacity);
    }

}