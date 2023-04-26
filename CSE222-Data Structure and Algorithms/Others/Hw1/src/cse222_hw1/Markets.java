package cse222_hw1;
/**
 * Markets class for street. Extends Buildings. 
 * @author Eray_Alcin_1801042687
 */
public class Markets extends Buildings {

	/**
	 * @param openingTime is market's opening time
	 * @param closingTime is market's closing time
	 * @param ownerOfMarket is market's owner
	 */
	private String openingTime;
	private String closingTime;
	private String ownerOfMarket;
	/**
     * Constructor for the markets with its openTime,closeTime,owner,length,height,position and street.
     * @param openTime market's opening time
     * @param closeTime market's closing time
     * @param owner market's owner.
     * @param length market's length
     * @param height market's height
     * @param position market's position
     * @param street which street is it on
     */
	public Markets(String openTime,String closeTime,String owner,int length, int height, int position,int street) {
		super(length,height,position,street);
		setOpeningTime(openTime);
		setClosingTime(closeTime);
		setOwnerOfMarket(owner);
	}
	/**
     * Getter function for the market's opening time.
     * @return openingTime of the market.
     */
	public String getOpeningTime() {
		return openingTime;
	}
	/**
     * Setter function for the setting market's opening time.
     * @param openTime market's opening time.
     */
	public void setOpeningTime(String openTime) {
		openingTime = openTime;
	}
	/**
     * Getter function for the market's closing time.
     * @return closingTime of the market.
     */
	public String getClosingTime() {
		return closingTime;
	}
	/**
     * Setter function for the setting market's closing time.
     * @param closeTime market's closing time.
     */
	public void setClosingTime(String closeTime) {
		closingTime = closeTime;
	}
	/**
     * Getter function for the market's owner
     * @return ownerOfMarket of the market.
     */
	public String getOwnerOfMarket() {
		return ownerOfMarket;
	}
	/**
     * Setter function for the setting market's owner.
     * @param owner market's owner.
     */
	public void setOwnerOfMarket(String owner) {
		ownerOfMarket = owner;
	}
	/**
     * Create a string representation of the market.
     * @return a string representation of the market.
     */
	
	@Override
	public String toString() {
		return "Markets [openingTime=" + openingTime + ", closingTime="
				+ closingTime + ", ownerOfMarket=" + ownerOfMarket + "]";
	}
	
	
	
}
