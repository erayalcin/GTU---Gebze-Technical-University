package cse222_hw1;

public class Playgrounds extends Buildings {
	/**
     * Constructor for the playground with its length,height,position and street.
     * @param length market's length
     * @param height market's height
     * @param position market's position
     * @param street which street is it on
     */
	
	public Playgrounds(int length, int height, int position, int street) {
		super(length, 10, position, street);
		
	}
	/**
     * Create a string representation of the Playgrounds.
     * @return a string representation of the Playgrounds.
     */
	@Override
	public String toString() {
		return "Playgrounds []";
	}
}
