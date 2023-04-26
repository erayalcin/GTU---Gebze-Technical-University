import java.util.Scanner;

import cse222_hw1.*;
public class Test {
	
	public void houseTest(Street test)
	{
		Houses temp=new Houses("Red","Eray Alçin",4,15,20,5,1);
		Houses temp1=new Houses("Green","Alçin",3,15,20,5,2);
		test.setBuildHouse(temp1);
		if(test.setBuildHouse(temp)==true)
		{
			System.out.println("\nThe house was created.");
			System.out.println(temp);
			
			test.showBuildings();
			if(test.removeBuild(1,5)==true)
			{
				System.out.println("\nThe house has been deleted.");
				test.showBuildings();
			}
			else System.out.println("\nThe house was not found.");
		}
		else System.out.println("\nThe entered position is occupied.");
		test.removeBuild(2,5);
		
		
	}
	public void officeTest(Street test)
	{
		Offices temp=new Offices("Service","Eray Alçin",15,25,15,2);
		Offices temp1=new Offices("Bank","Alçin",10,15,40,1);
		test.setBuildOffice(temp1);
		if(test.setBuildOffice(temp)==true)
		{
			System.out.println("\nThe office was created.");
			System.out.println(temp);
			test.showBuildings();
			if(test.removeBuild(2,15)==true)
			{
				System.out.println("\nThe office has been deleted.");
				test.showBuildings();
			}
			else System.out.println("\nThe office was not found.");
		}
		else System.out.println("\nThe entered position is occupied.");
		test.removeBuild(1,40);
		
	}
	public void marketTest(Street test)
	{
		Markets temp=new Markets("09.00","21.00","Eray Alçin",10,15,15,1);
		Markets temp1=new Markets("09.00","22.00","Alçin",10,15,5,2);
		test.setBuildMarket(temp1);
		if(test.setBuildMarket(temp)==true)
		{
			System.out.println("\nThe market was created.");
			System.out.println(temp);
			test.showBuildings();
			if(test.removeBuild(1,15)==true)
			{
				System.out.println("\nThe market has been deleted.");
			}
			else System.out.println("\nThe market was not found.");
		}
		else System.out.println("\nThe entered position is occupied.");
		test.removeBuild(2,5);
		
	}
	public void playgroundTest(Street test)
	{
		Playgrounds temp=new Playgrounds(10,15,15,1);
		
		if(test.setBuildPlayground(temp)==true)
		{
			System.out.println("\nThe playground was created.");
			System.out.println(temp);
			test.showBuildings();
			if(test.removeBuild(1,15)==true)
			{
				System.out.println("\nThe playground has been deleted.");
			}
			else System.out.println("\nThe playground was not found.");
		}
		else System.out.println("\nThe entered position is occupied.");
		
		
	}
	public void displayTest(Street test)
	{
		Houses temp=new Houses("Red","Eray Alçin",4,15,20,5,1);
		Playgrounds temp2=new Playgrounds(10,15,3,2);
		Playgrounds temp3=new Playgrounds(10,15,25,2);
		test.setBuildHouse(temp);
		test.setBuildPlayground(temp2);
		test.setBuildPlayground(temp3);
		int remaining=test.remainingLand();
        System.out.println("\nTotal remaining length of land on street : "+remaining);
        System.out.println("\nTotal length of street occupied by the markets, houses or offices : "+test.occupiedBuildings());
        System.out.println("\nDisplay all buildings in the street.");
        test.showBuildings();
        
	}
	public void occupiedPositionTest(Street test)
	{
		Houses temp=new Houses("Red","Eray Alçin",4,15,20,5,1);
		Playgrounds temp2=new Playgrounds(10,15,3,1);
		test.setBuildHouse(temp);
		if(test.setBuildPlayground(temp2)==true)
		{
			System.out.println("\nThe playground was created.");
		}
		else System.out.println("\nThe entered position is occupied.");
		
	}
	
	
}
