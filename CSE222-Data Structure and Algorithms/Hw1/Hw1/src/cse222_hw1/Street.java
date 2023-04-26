package cse222_hw1;
import cse222_hw1.Buildings;
/**
 * Street class for street .
 * @author Eray_Alcin_1801042687
 */
public class Street {
	
	/**
     * @param length length of street
     * @param builds array of objects [houses,markets,offices,playgrounds]
     */
	private int length;
	Buildings[][] builds; 
	 /**
     * Constructor for the street.
     * @param lengthStreet length of street
     */
	public Street(int lengthStreet)
	{
		length=lengthStreet;
		builds=new Buildings[2][length];
	}
	/**
     * Setter function for the setting street's length.
     * @param lengthStreet new street length.
     */
	public void setLength(int lengthStreet)
	{
		length=lengthStreet;
	}
	 /**
     * Getter function for the street length.
     * @return length of the street.
     */
	public int getLength()
	{
		return length;
	}
	/**
     * add the newly created house object to the array where we hold the objects.
     * Checking if the position is empty or occupied.
     * @param Object h is the new building to be added to the array 
     * @return returns true if added, false if not
     */
	public boolean setBuildHouse(Houses h)
	{
		if(positionIsFull(h.getPosition(),h.getLength(),h.getStreetNumber())==true)
		{
			for(int i=h.getPosition();i<h.getLength()+h.getPosition();i++)
			{
				builds[h.getStreetNumber()-1][i-1]=h;		
			}
			return true;
		}
		else return false;
	}
	/**
     * add the newly created office object to the array where we hold the objects.
     * Checking if the position is empty or occupied.
     * @param Object h is the new building to be added to the array 
     * @return returns true if added, false if not
     */
	public boolean setBuildOffice(Offices h)
	{
		if(positionIsFull(h.getPosition(),h.getLength(),h.getStreetNumber())==true)
		{
			for(int i=h.getPosition();i<h.getLength()+h.getPosition();i++)
			{
				builds[h.getStreetNumber()-1][i-1]=h;	
				
			}
			return true;
		}
		else return false;
	}
	/**
     * add the newly created market object to the array where we hold the objects.
     * Checking if the position is empty or occupied.
     * @param Object h is the new building to be added to the array 
     * @return returns true if added, false if not
     */
	public boolean setBuildMarket(Markets h)
	{
		if(positionIsFull(h.getPosition(),h.getLength(),h.getStreetNumber())==true)
		{
			for(int i=h.getPosition();i<h.getLength()+h.getPosition();i++)
			{
				builds[h.getStreetNumber()-1][i-1]=h;		
			}
			return true;
		}
		else return false;
	}
	/**
     * add the newly created house object to the array where we hold the objects.
     * Checking if the position is empty or occupied.
     * @param Object h is the new building to be added to the array 
     * @return returns true if added, false if not
     */
	public boolean setBuildPlayground(Playgrounds h)
	{
		if(positionIsFull(h.getPosition(),h.getLength(),h.getStreetNumber())==true)
		{
			for(int i=h.getPosition();i<h.getLength()+h.getPosition();i++)
			{
				builds[h.getStreetNumber()-1][i-1]=h;		
			}
			return true;
		}
		else return false;
	}
	/**
     * It prints all the structures on the street with toString method
     */
	public void showBuildings()
	{
		int counter=0;
		for(int j=0;j<2;j++)
		{
		 for(int i=0;i<getLength();i++)
         {
			 if(builds[j][i]!=null)
			 {
				 counter++;
				 System.out.print("\n"+counter+")  Street :"+builds[j][i].getStreetNumber()+" / "+"Position :"+builds[j][i].getPosition()+" / ");
				
				 System.out.print(builds[j][i]);
				 i=builds[j][i].getPosition()+builds[j][i].getLength();	
			 }
         }
		}
	}
	/**
     * display the total remaining length of lands on the street
     */
	public int remainingLand() {
		int remainingLength=0;
		for(int j=0;j<2;j++){
		for(int i=0;i<builds[j].length;i++)
		{
			if(builds[j][i]==null) remainingLength++;
		}
		}
		return remainingLength;
		
	}
	/**
     * calculate the total length of street occupied by the markets, houses or offices.

     */
	public int occupiedBuildings()
	{
		
		int occupiedLength=0;
		for(int j=0;j<2;j++){
		for(int i=0;i<builds[j].length;i++)
		{
			
			if(builds[j][i]!=null && builds[j][i].getClass().getName() != "cse222_hw1.Playgrounds") occupiedLength++;
		}
		}
		return occupiedLength;
	}
	/**
     * Deletes the building at the selected location.
     * @param streetNum is street number
     * @param position is building position
     * @return returns true if removed, false if not
     */
	public boolean removeBuild(int streetNum,int position)
	{
		int lengthRemove=builds[streetNum-1][position-1].getLength();
		if(positionIsFull(position-1,lengthRemove,streetNum)==false)
		{
			for(int i=position-1;i<lengthRemove+position;i++)
			{
				builds[streetNum-1][i]=null;	
			}
			return true;
		}
		else return false;
	}
	/**
     * Checks if there is a building in the position
     * @param streetNum is street number
     * @param position is building position
     * @return returns true if removed, false if not
     */
	public boolean positionIsFull(int position,int length,int street)
	{
		Boolean check=true;
		
		for(int i=position;i<position+length;i++)
		{
			if(builds[street-1][i]!=null)
			{
				check=false;
			}	
		}	
		return check;	
	}	
	public double ratioPlayground()
	{
		double playLength=0.0;
		double result;
		for(int j=0;j<2;j++){
		for(int i=0;i<builds[j].length;i++)
		{
			if(builds[j][i]!=null && builds[j][i].getClass().getName() == "cse222_hw1.Playgrounds" ) 
			{
				playLength+=1.0;
			}
		}
		}
		result=playLength/(getLength()*2);
		return result;
		
	}
}
