import cse222_hw1.*;

import java.util.Scanner;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		
		
		Test test1=new Test();
		Street testDriver= new Street(60);
		test1.houseTest(testDriver);
		test1.officeTest(testDriver);
		test1.marketTest(testDriver);
		test1.playgroundTest(testDriver);
		test1.displayTest(testDriver);
		test1.occupiedPositionTest(testDriver);
		mainMenu();
		
		
	}
	 public static void mainMenu()
	    {
		 	
			int len;
			System.out.print("\nPlease enter the length of streeet : ");
			Scanner scanner = new Scanner(System.in);
			len = scanner.nextInt();
			Street street= new Street(len);
			
		 	
		 	int choice=0;
		 	while(choice != -1)
	        {
		 		System.out.println("(1) Editing mode");
	            System.out.println("(2) Viewing mode");
	            System.out.print ("Choice :  ");
	            choice = scanner.nextInt();
	            switch(choice)
	            {
	                case 1:
	                	int edit_choice=0;
	        	        
	        	        while(edit_choice != -1)
	        	        {
	        	        	System.out.println("\n");
	        	            System.out.println("(1) Add a house");
	        	            System.out.println("(2) Add an office");
	        	            System.out.println("(3) Add a market");
	        	            System.out.println("(4) Add a playground");
	        	            System.out.println("(5) Remove a building");
	        	            System.out.println("(-1) Exit\n");
	        	            System.out.print ("Choice : ");
	        	            edit_choice = scanner.nextInt();
	        	            switch(edit_choice)
	        	            {
	        	                case 1:
	        	                	int houseLength,houseHeight,housePosition,houseRooms,streetNumber;
	        	                	String houseColor,houseOwner;
	        	                	System.out.print("Enter the length,heigth,street number,position, number of room, color and owner of house    :");
	        	                	try {
	        	                		houseLength = scanner.nextInt();
		        	                	houseHeight = scanner.nextInt();
		        	                	streetNumber = scanner.nextInt();
		        	                	housePosition = scanner.nextInt();
		        	                	houseRooms = scanner.nextInt();
		        	                	houseColor = scanner.next();
		        	                	houseOwner = scanner.next();
		        	                	Houses house1=new Houses(houseColor,houseOwner,houseRooms,houseLength,houseHeight,housePosition,streetNumber);
		        	                	if(street.setBuildHouse(house1)==true)
		        	                	{
		        	                		System.out.println("\nAdded.");
		        	                	}
		        	                	else System.out.println("\nNot added. Position is full");
	        	            		
	        	                	}
	        	            		catch(Exception e){
	        	            			System.out.println("You entered the wrong entry.....  ");	
	        	            			System.exit(0);
	        	            		}
	        	                	
	        	                	
	        	                    break;
	        	                case 2:
	        	                	int officeLength,officeHeight,officePosition;
	        	                	String jobType,officeOwner;
	        	                	System.out.print("Enter the length,heigth,street number,position, job type and owner of office    			:");
	        	                	try {
	        	                	officeLength = scanner.nextInt();
	        	                	officeHeight = scanner.nextInt();
	        	                	streetNumber = scanner.nextInt();
	        	                	officePosition = scanner.nextInt();
	        	                	jobType = scanner.next();
	        	                	officeOwner = scanner.next();
	        	                	
	        	                	Offices office1=new Offices(jobType,officeOwner,officeLength,officeHeight,officePosition,streetNumber);
	        	                	if(street.setBuildOffice(office1)==true)
	        	                	{
	        	                		System.out.println("\nAdded.");
	        	                	}
	        	                	else System.out.println("\nNot added. Position is full");
	        	                	}
	        	                	catch(Exception e){
	        	            			System.out.println("You entered the wrong entry.....  ");	
	        	            			System.exit(0);
	        	            		}
	        	                    break;
	        	                    
	        	                case 3:
	        	                	int marketLength,marketHeight,marketPosition;
	        	                	String openTime,closeTime,ownerMarket;
	        	                	System.out.print("Enter the length,heigth,street number,position, opening time,closing time and owner of market    			:");
	        	                	try {
	        	                	marketLength = scanner.nextInt();
	        	                	marketHeight = scanner.nextInt();
	        	                	streetNumber = scanner.nextInt();
	        	                	marketPosition = scanner.nextInt();
	        	                	openTime = scanner.next();
	        	                	closeTime = scanner.next();
	        	                	ownerMarket = scanner.next();
	        	                	
	        	                	Markets market1=new Markets(openTime,closeTime,ownerMarket,marketLength,marketHeight,marketPosition,streetNumber);
	        	                	if(street.setBuildMarket(market1)==true)
	        	                	{
	        	                		System.out.println("\nAdded.");
	        	                	}
	        	                	else System.out.println("\nNot added. Position is full");
	        	                	}
	        	                	catch(Exception e){
	        	            			System.out.println("You entered the wrong entry.....  ");	
	        	            			System.exit(0);
	        	            		}
	        	                    break; 
	        	                case 4:
	        	                	try {
	        	                    int positionPlayground,lengthPlayground,streetPlayground;
	        	                    System.out.print("Enter the length,street number,position of playground    			:");
	        	                    lengthPlayground = scanner.nextInt();
	        	                    streetPlayground = scanner.nextInt();
	        	                    positionPlayground = scanner.nextInt();
	        	                	Playgrounds play1=new Playgrounds(lengthPlayground,10,positionPlayground,streetPlayground);
	        	                	if(street.setBuildPlayground(play1)==true)
	        	                	{
	        	                		System.out.println("\nAdded.");
	        	                	}
	        	                	else System.out.println("\nNot added. Position is full");
	        	                	}
	        	                    catch(Exception e){
	        	                    	System.out.println("You entered the wrong entry.....  ");	
	        	            			System.exit(0);
	        	                    }
	        	                    
	        	                    break;
	        	                case 5:
	        	                   street.showBuildings();
	        	                   int position,streetNum;
	        	                   System.out.print("\nSelect  street number and position to remove building  :");
	        	                   try {
	        	                   streetNum=scanner.nextInt();
	        	                   position=scanner.nextInt();
	        	                   street.removeBuild(streetNum,position);
	        	                   }
	        	                   catch(Exception e){
	        	            			System.out.println("You entered the wrong entry.....  ");	
	        	            			System.exit(0);
	        	            		}
	        	                    break;
	        	               
	        	               
	        	                case -1:
	        	                    System.out.println("Exiting...");
	        	                    break;
	        	                default:
	        	                    System.out.println("Wrong choice! Try again!");
	        	                    break;
	        	            }
	        	        }
	                    break;
	                case 2:
	                	int view_choice=0;
	        	        
	        	        while(view_choice != -1)
	        	        {
	        	        	System.out.println("\n");
	        	            System.out.println("(1) Display the total remaining length of lands on the street.");
	        	            System.out.println("(2) Display the list of buildings on the street.");
	        	            System.out.println("(3) Display the number and ratio of length of playgrounds in the street.");
	        	            System.out.println("(4) Calculate the total length of street occupied by the markets, houses or offices.");
	        	            System.out.println("(5) Display the skyline silhouette of the street");
	        	            System.out.println("(-1) Exit\n");
	        	            System.out.print ("Choice : ");
	        	            view_choice = scanner.nextInt();
	        	            
	        	            switch(view_choice)
	        	            {
	        	                case 1:
	        	                	int remaining=street.remainingLand();
	        	                    System.out.println("Total remaining length of land on street : "+remaining);
	        	                    break;
	        	                case 2:
	        	                	street.showBuildings();
	        	                    break;
	        	                case 3:
	        	                	double result;
	        	                	result=street.ratioPlayground();
	        	                	System.out.println("The number and ratio of length of playgrounds in the street   :  "+result);
	        	                    break;
	        	                case 4:
	        	                	System.out.println("Total length of street occupied by the markets, houses or offices : "+street.occupiedBuildings());
	        	                    break;
	        	                case 5:
	        	                	
	        	                    break;
	        	                case -1:
	        	                    System.out.println("Exiting...");
	        	                    break;
	        	                default:
	        	                    System.out.println("Wrong choice! Try again!");
	        	                    break;
	        	            }
	        	        }
	                    break;
	                
	                case -1:
	                    System.out.println("Exiting...");
	                    break;
	                default:
	                    System.out.println("Wrong choice! Try again!");
	                    break;
	            }
	        }
	        
	    }
	

}
