package cse222_hw1;

public class Houses extends Buildings {

	
	private String colorOfRoom;
	private String ownerOfRoom;
	private int countOfRoom;
	/**
	 * Houses's constructor
	 * @param countOfRoom number of room
	 * @param colorOfRoom Room's color
	 * @param ownerOfRoom Room's owner
	 */
	
	 public Houses(String color, String owner, int count,int length,int height,int position,int street)
	 {
		 super(length,height,position,street);
	        colorOfRoom=color;
	        ownerOfRoom=owner;
	        countOfRoom=count;
	 }
	 /**
	     * Setter function for the setting house's color.
	     * @param color house's color.
	 */ 
	public void setColor(String color) {
		
		colorOfRoom=color;
	}
	/**
     * Setter function for the setting house's owner.
     * @param owner house's owner.
     */
	public void setOwner(String owner) {
	
		ownerOfRoom=owner;
	}
	/**
     * Setter function for the setting house's room count.
     * @param count house's room count.
     */
	public void setCount(int count) {
		countOfRoom=count;
		
	}
	/**
     * Getter function for the house's color.
     * @return colorOfRoom of the house.
     */
	public String getColor() {
		
		return colorOfRoom;
	}
	/**
     * Getter function for the house's owner.
     * @return ownerOfRoom of the house.
     */
	public String getOwner() {
	
		return ownerOfRoom;
	}
	/**
     * Getter function for the house's room count.
     * @return countOfRoom of the house.
     */
	public int getCount() {
		return countOfRoom;
		
	}
	/**
     * Create a string representation of the house.
     * @return a string representation of the house.
     */
	@Override
	public String toString() {
		return "Houses [colorOfRoom=" + colorOfRoom + ", ownerOfRoom="
				+ ownerOfRoom + ", countOfRoom=" + countOfRoom + "]";
	}
	

}
