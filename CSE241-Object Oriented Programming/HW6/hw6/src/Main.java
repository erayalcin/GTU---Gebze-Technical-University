/**
	 * @author Eray Alçin
	*/
public class Main
{
	public static void hashset()
	{
		System.out.println(" __________________________________________________________ ");
		System.out.println("|____________________test hashset class____________________|");
		
		HashSet<Integer> hashset = new HashSet<Integer>();
		hashset.add(1);
		hashset.add(2);
		hashset.add(3);
		hashset.add(4);
		hashset.add(5);
		hashset.add(6);
		hashset.add(7);
		hashset.add(8);
		System.out.println("Hashset -------->");
		Iterator<Integer> begin = hashset.iterator();
		
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}
		ArrayList<Integer> arraylist = new ArrayList<Integer>();
		
		
		arraylist.add(9);
		arraylist.add(10);
		arraylist.add(11);
		arraylist.add(12);
		arraylist.add(13);
		arraylist.add(14);
		arraylist.add(15);
		arraylist.add(16);
		hashset.addAll(arraylist);
		
		begin = hashset.iterator();
		System.out.println("\nArrayList added into Hashset-------->");
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		if(hashset.containsAll(arraylist))
			System.out.println("\nHashset contains ArrayList!");

		hashset.add(17);
		hashset.add(18);
		hashset.add(19);
		hashset.add(20);

		System.out.println("Updated Hashset-------->");
		begin = hashset.iterator();
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		hashset.retainAll(arraylist);
		System.out.println("\nArrayList retained from HashSet-------->");
		begin = arraylist.iterator();
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		hashset.removeAll(arraylist);
		begin = hashset.iterator();
		System.out.println("\nArrayList removed from Hashset-------->");
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		

		HashSet<String> str_hashset = new HashSet<String>();
		ArrayList<String> str_arraylist = new ArrayList<String>();
		

		str_hashset.add("Eray");
		str_hashset.add("Alçin");
		str_hashset.add("Test1");
		str_hashset.add("Test2");
		str_hashset.add("Test3");
		//I create array list for testing Hashset
		str_arraylist.addAll(str_hashset);
		str_arraylist.add("Test4");
		str_arraylist.add("Test5");
		str_arraylist.add("Test6");
		str_arraylist.add("Test7");
		str_arraylist.add("Test8");
		str_arraylist.add("Test9");
		System.out.println("\nString Hashset-------->");
		Iterator<String> str_begin = str_hashset.iterator();
		while(str_begin.hasNext())
		{
			System.out.printf("%s ", str_begin.next());
		}
		System.out.println("\nString ArrayList-------->");
		str_begin = str_arraylist.iterator();
		while(str_begin.hasNext())
		{
			System.out.printf("%s ", str_begin.next());
		}
		if(str_hashset.contains("Eray"))
			System.out.println("\nHashset contains 'Eray'");
		if(str_hashset.contains("Deneme")==false)
			System.out.println("nHashset does not contain 'Deneme'");
		System.out.println("Size of HashSet: " + str_hashset.size());
		if(!str_hashset.isEmpty())
			System.out.println("Hashset is not empty!");
		str_hashset.clear();
		System.out.println("Clearing the Hashset!");
		if(str_hashset.isEmpty())
			System.out.println("Hashset is empty!");
	}
	public static void linkedlist()
	{
		System.out.println(" __________________________________________________________ ");
		System.out.println("|____________________test linkedlist class____________________|");
		
		LinkedList<Integer> linked = new LinkedList<Integer>();
		linked.add(1);
		linked.add(2);
		linked.add(3);
		
		System.out.println("LinkedList -------->");
		Iterator<Integer> begin = linked.iterator();
		
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}
		ArrayList<Integer> arraylist = new ArrayList<Integer>();
		
		
		arraylist.add(9);
		arraylist.add(10);
		arraylist.add(11);
		
		arraylist.add(16);
		linked.addAll(arraylist);
		
		begin = linked.iterator();
		System.out.println("\nArrayList added into LinkedList-------->");
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		if(linked.containsAll(arraylist))
			System.out.println("\nLinkedList contains ArrayList!");

		linked.add(17);
		linked.add(18);
		

		System.out.println("Updated LinkedList-------->");
		begin = linked.iterator();
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		linked.retainAll(arraylist);
		System.out.println("\nArrayList retained from LinkedList-------->");
		begin = arraylist.iterator();
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		linked.removeAll(arraylist);
		begin = linked.iterator();
		System.out.println("\nArrayList removed from LinkedList-------->");
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		

		LinkedList<String> str_linkedlist = new LinkedList<String>();
		ArrayList<String> str_arraylist = new ArrayList<String>();
		

		str_linkedlist.add("Eray");
		str_linkedlist.add("Alçin");
		str_linkedlist.add("Test1");
		str_linkedlist.add("Test2");
		str_linkedlist.add("Test3");
		//I create array list for testing Hashset
		str_arraylist.addAll(str_linkedlist);
		str_arraylist.add("Test4");
		str_arraylist.add("Test5");
		str_arraylist.add("Test6");
		str_arraylist.add("Test7");
		str_arraylist.add("Test8");
		str_arraylist.add("Test9");
		System.out.println("\nString LinkedList-------->");
		Iterator<String> str_begin = str_linkedlist.iterator();
		while(str_begin.hasNext())
		{
			System.out.printf("%s ", str_begin.next());
		}
		System.out.println("\nString ArrayList-------->");
		str_begin = str_arraylist.iterator();
		while(str_begin.hasNext())
		{
			System.out.printf("%s ", str_begin.next());
		}
		if(str_linkedlist.contains("Eray"))
			System.out.println("\nLinkedList contains 'Eray'");
		if(str_linkedlist.contains("Deneme")==false)
			System.out.println("nLinkedList does not contain 'Deneme'");
		System.out.println("Size of LinkedList: " + str_linkedlist.size());
		if(!str_linkedlist.isEmpty())
			System.out.println("LinkedList is not empty!");
		str_linkedlist.clear();
		System.out.println("Clearing the LinkedList!");
		if(str_linkedlist.isEmpty())
			System.out.println("LinkedList is empty!");
	}
	public static void arraylist()
	{
		System.out.println(" __________________________________________________________ ");
		System.out.println("|____________________test arraylist class____________________|");
		
		ArrayList<Integer> array = new ArrayList<Integer>();
		array.add(1);
		array.add(2);
		array.add(3);
		array.add(4);
		
		System.out.println("ArrayList  -------->");
		Iterator<Integer> begin = array.iterator();
		
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}
		HashSet<Integer> hashset = new HashSet<Integer>();
		
		
		hashset.add(5);
		hashset.add(6);
		hashset.add(7);
		
		array.addAll(hashset);
		
		begin = array.iterator();
		System.out.println("\nArrayList added into Hashset-------->");
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		if(array.containsAll(hashset))
			System.out.println("\nArrayList contains HashSet!");

		array.add(8);
		array.add(9);
		array.add(10);

		System.out.println("Updated Hashset-------->");
		begin = array.iterator();
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		array.retainAll(hashset);
		System.out.println("\nHashset retained from ArrayList-------->");
		begin = hashset.iterator();
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		array.removeAll(hashset);
		begin = array.iterator();
		System.out.println("\nHashset removed from ArrayList-------->");
		while(begin.hasNext())
		{
			System.out.printf("%s  ", begin.next());
		}

		

		HashSet<String> str_hashset = new HashSet<String>();
		ArrayList<String> str_arraylist = new ArrayList<String>();
		

		str_arraylist.add("Eray");
		str_arraylist.add("Alçin");
		str_arraylist.add("Test1");
		str_arraylist.add("Test2");
		str_arraylist.add("Test3");
		//I create array list for testing Hashset
		str_hashset.add("Test4");
		str_hashset.add("Test5");
		str_hashset.add("Test6");
		str_arraylist.addAll(str_hashset);
		

		System.out.println("\nString ArrayList-------->");
		Iterator<String> str_begin = str_arraylist.iterator();
		while(str_begin.hasNext())
		{
			System.out.printf("%s ", str_begin.next());
		}
		System.out.println("\nString Hashset-------->");
		str_begin = str_hashset.iterator();
		while(str_begin.hasNext())
		{
			System.out.printf("%s ", str_begin.next());
		}
		if(str_arraylist.contains("Eray"))
			System.out.println("\nArrayList contains 'Eray'");
		if(str_arraylist.contains("Deneme")==false)
			System.out.println("ArrayList does not contain 'Deneme'");
		System.out.println("Size of ArrayList: " + str_arraylist.size());
		if(!str_arraylist.isEmpty())
			System.out.println("ArrayList is not empty!");
		str_arraylist.clear();
		System.out.println("ArrayList the Hashset!");
		if(str_arraylist.isEmpty())
			System.out.println("ArrayList is empty!");
	}
	public static void main(String[] args)
	{
		
		hashset();
		arraylist();
		linkedlist();


	} 

}