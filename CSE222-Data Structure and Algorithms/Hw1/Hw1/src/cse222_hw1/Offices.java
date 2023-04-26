package cse222_hw1;
/**
 * Offices class for street. Extends Buildings. 
 * @author Eray_Alcin_1801042687
 */
public class Offices extends Buildings {

	/**
	 * @param jobType is job type
	 * @param ownerOfOffice is office's owner
	 */
	private String jobType;
	private String ownerOfOffice;
	/**
     * Constructor for the offices with its job,owner,length,height,position and street.
     * @param job what kind of work is done
     * @param owner office's owner.
     * @param length office's length
     * @param height office's height
     * @param position office's position
     * @param street which street is it on
     */
	public Offices(String job,String owner,int length, int height, int position,int street) {
		super(length,height,position,street);
		setJobType(job);
		setOwnerOfOffice(owner);
	}
	
	/**
     * Getter function for the office's job type.
     * @return jobType of the office.
     */
	public String getJobType() {
		return jobType;
	}
	/**
     * Getter function for the office's owner.
     * @return owner of the office.
     */
	public String getOwnerOfOffice() {
		return ownerOfOffice;
	}
	/**
     * Setter function for the setting office's owner.
     * @param owner office's owner.
     */
	public void setOwnerOfOffice(String owner) {
		ownerOfOffice = owner;
	}
	/**
     * Setter function for the setting office's job type.
     * @param job office's job type.
     */
	public void setJobType(String job) {
		jobType = job;
	}
	/**
     * Create a string representation of the office.
     * @return a string representation of the office.
     */
	@Override
	public String toString() {
		return "Offices [jobType=" + jobType + ", ownerOfOffice="
				+ ownerOfOffice + "]";
	}
	
	
}
