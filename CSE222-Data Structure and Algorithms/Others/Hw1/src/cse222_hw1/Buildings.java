package cse222_hw1;
public class Buildings{
private int heightOfBuilding;
private int lengthOfBuilding;
private int positionOfBuilding;
private int streetNumber;
/**
 * Constructor for the buildings with its openTime,closeTime,owner,length,height,position and street.
 * @param length building's length
 * @param height building's height
 * @param position building's position
 * @param street which street is it on
 */
public Buildings(int length,int height,int position,int street)
{
	
	lengthOfBuilding=length;
	heightOfBuilding=height;
	positionOfBuilding=position;
	streetNumber=street;
}
/**
 * Setter function for the setting building's height
 * @param height building's height.
*/ 
public void setHeight(int height)
{
	heightOfBuilding=height;
}
public int getHeight()
{
	return heightOfBuilding;
}
/**
* Setter function for the setting building's length
 * @param length building's length.
*/ 
public void setLength(int length)
{
	lengthOfBuilding=length;
}
/**
* Setter function for the setting building's length
 * @param lengthOfBuilding building's length.
*/ 
public int getLength()
{
	return lengthOfBuilding;
}
/**
* Setter function for the setting building's position
 * @param position building's position.
*/ 
public void setPosition(int position)
{
	positionOfBuilding=position;
}
/**
 * Getter function for the building's position.
 * @return positionOfBuilding of the buildings.
 */
public int getPosition()
{
	return positionOfBuilding;
}
/**
 * Setter function for the setting building's street number.
 * @param street building's street number.
*/ 
public void setStreetNumber(int street)
{
	streetNumber=street;
}
/**
 * Getter function for the building's street number.
 * @return streetNumber of the buildings.
 */
public int getStreetNumber()
{
	return streetNumber;
}



}
