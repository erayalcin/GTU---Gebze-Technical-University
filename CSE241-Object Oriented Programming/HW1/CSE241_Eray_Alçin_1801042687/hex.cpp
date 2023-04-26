//============================================================================
// Name        : hexgame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int select_menu(int hex[12][12]);
void printTable(int size,int hextable[12][12]);
void firstFillTable(int size,int hextable[12][12]) ;
int determineWin(int x,int y,int user,int hexTable[12][12],int size,int solve[12][12]);
int computerSteps(int size,int hextable[12][12],int count,int store[2]);
int UservsUser(int size,int hextable[12][12],char x,int y,int userCheck);
int isFull(int hex[12][12],int size);
//In this function, I print the table of the hex game on the screen.
void printTable(int size,int hextable[12][12])
{
	cout << "\n";
	cout << "\n";
	//I do not include the coordinates in the hex array.
	char alpha[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	//In this for loop, I print the coordinates of the letters in the first line to the screen.
	for(int i=0;i<size;i++)
	{
		cout << "  " << alpha[i];
	}

	cout << "\n";
	//Then It prints table of hex game on screen
	//I use nested for loops because my array is 2d array.
	for(int i=0;i<size;i++)
	{
		cout << i+1 ;
		for(int k=0;k<i+1;k++)
		{
			cout << "  ";
		}
		for(int j=0;j<size;j++)
		{
			//The reason I use it as char in this line is because the array is integer,
			//save the data with asci codes and print it as char on the screen.
			cout << char(hextable[i][j]) << "  "; 
		}
		cout << "\n";
	}
	cout << "\n";
}
//In this function, I first fill the array with dots. We have to do this because the empty state of the table is formed with dots.
void firstFillTable(int size,int hextable[12][12]) 
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			hextable[i][j]	=	46;
		}

	}
}
//In this function, we control which user the user is, our vertical and horizontal operations. If the user is 1 I am sending 0, if the user is 2, I am sending 1.
int determineWin(int x,int y,int user,int hexTable[12][12],int size,int solve[12][12])
{

	if(user	==	0)
	{
		/*I have my winning situation checked here. In order to win, I start horizontally from the left and check 
		if there is an X in the first column and then evaluate the 6 movements, 
		if it cannot find a place to go, it leaves the loop and then looks to see if there is a spike x in that column.
		To win, she must go to the last position and horizontally to the position before the table size. */
		
		if ( y	==	size-1  && hexTable[x][y] == 120){	solve[x][y]	=	1; return 1; }  
		
		else
		{
			/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place 
			I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
			solve[x][y]=1;
			/*Since we have 6 cases, I check these cases with if conditions. In this if condition, 
			I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
			if (hexTable[x][y+1]	==	120 && solve[x][y+1]	==	0)
			{
				return determineWin(x, y+1, 0,hexTable,size,solve);
			}
			if (hexTable[x-1][y+1]	==	120 && solve[x-1][y+1]	==	0)
			{

				return determineWin(x-1, y+1, 0,hexTable,size,solve);
			}
			if (hexTable[x+1][y]	==	120 && solve[x+1][y]	==	0)
			{

				return determineWin( x + 1, y, 0,hexTable,size,solve);
			}
			if (hexTable[x+1][y-1]	==	120 && solve[x+1][y-1]	==	0 )
			{

				return determineWin(x+1, y-1, 0,hexTable,size,solve);
			}
			if (hexTable[x-1][y]	==	120 && solve[x-1][y]	==	0 )
			{

				return determineWin(x-1, y, 0,hexTable,size,solve);}
			if (hexTable[x][y-1]	==	120 && solve[x][y-1]	==	0)
			{

				return determineWin(x, y-1, 0,hexTable,size,solve);
			}
			else return 0;
		}

	}
	//We vertically control the same actions for the second user. We do the same operations that we do on User 1. This second user will also be a computer for us.
	if(user==1)
		{
			if ( x	==	size-1  && hexTable[x][y] == 111){solve[x][y]	=	1; return 1;}

			else
			{
				solve[x][y]	=	1;
				//cout<<x<<y;
				if (hexTable[x][y+1]	==	111 && solve[x][y+1]	==	0)
				{

					return determineWin(x, y+1, 1,hexTable,size,solve);
				}
				if (hexTable[x-1][y+1]	==	111 && solve[x-1][y+1]	==	0)
				{

					return determineWin(x-1, y+1, 1,hexTable,size,solve);
				}
				if (hexTable[x+1][y]	==	111 && solve[x+1][y]	==	0)
				{

					return determineWin( x + 1, y, 1,hexTable,size,solve);
				}
				if (hexTable[x+1][y-1]	==	111 && solve[x+1][y-1]	==	0 )
				{

					return determineWin(x+1, y-1, 1,hexTable,size,solve);
				}
				if (hexTable[x-1][y]	==	111 && solve[x-1][y]	==	0 )
				{

					return determineWin(x-1, y, 1,hexTable,size,solve);}
				if (hexTable[x][y-1]	==	111 && solve[x][y-1]	==	0)
				{
					return determineWin(x, y-1, 1,hexTable,size,solve);
				}
				else return 0;
			}

		}
}
/*In this function, I create the computer steps. 
 For this I need to save the coordinates and for this I keep the previous coordinates. 
 First, I look for an empty place in the first line and create the points according to that location. While creating these points, 
 I consider 6 situations as I did in the winning case I look at these 6 cases one by one and then the computer puts O in the first empty place.*/
int computerSteps(int size,int hextable[12][12],int count,int store[2])
{
	int x,y,consty,result=0;
	int solve[12][12];
	//Here I fill the sequence where I control my steps in case of winning with 0.
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			solve[i][j]	=	0;
		}
	}
	/*While the computer is working, I throw the first position to the first empty line and since this first operation is different, 
	 * I put it in a separate condition. Then I increment this condition by one, and then I look at the 6 states in order, 
	 * enter whatever it provides, and assign O to that position, and then store this position in the store array and use this position in the next move.*/
	if(count	==	1)
	{

		for(int i=0;i<size;i++)
		{
			if(hextable[0][i]	==	46)
			{
				x	=	0;
				hextable[x][i]=111;
				store[0]	=	0;
				store[1]	=	i;
				break;
			}
		}

		printTable(size,hextable);
	}
	//It looks at 6 situations in turn and enters whichever is appropriate and does not look at the others.(diş
	else
	{
		x	=	store[0];
		y	=	store[1];
		if (hextable[x+1][y]	==	46)
		{
			hextable[x+1][y]=111;
			store[0]=x+1;
			store[1]=y;
		}
		else if (hextable[x-1][y+1]	==	46)
		{
			hextable[x-1][y+1]	=	111;
			store[0]	=	x-1;
			store[1]	=	y+1;
		}
		else if (hextable[x+1][y-1]==46)
		{
			hextable[x+1][y-1]	=	111;
			store[0]	=	x+1;
			store[1]	=	y-1;
		}
		else if (hextable[x][y-1]	==	46)
		{
			hextable[x][y-1]	=	111;
			store[0]	=	x;
			store[1]	=	y-1;
		}
		else if (hextable[x][y+1]==46)
		{
			hextable[x][y+1]	=	111;
			store[0]	=	x;
			store[1]	=	y+1;
		}
		else if (hextable[x-1][y]	==	46)
		{
			hextable[x-1][y]	=	111;
			store[0]			=	x-1;
			store[1]			=	y;
		}
		else
		{
			//If these six cases don't work, I put an O in the first empty place with a for loop.
			for(int i=0;i<size;i++)
			{
				if(hextable[0][i]	==	46)
				{
					x	=	0;
					hextable[x][i]	=	111;
					store[0]		=	0;
					store[1]		=	i;
					break;
				}
			}
		}
		//Here I am doing the winning situation. Since there is a 2nd user on the computer, I send the same function as the 2nd user.
		for(int i=0;i<size;i++)
		{
			if(hextable[0][i]	==	111)
			{
				consty	=	i;
				solve[0][consty]	=	1;
				result	=	determineWin(0,consty,1,hextable,size,solve);
			}
		}
		
		if(result==1)
				{
			
					for(int i=0;i<size;i++)
					{
						for(int j=0;j<size;j++)
						{
							if(solve[i][j]==1)
							{
								hextable[i][j] = 79 ;
							}
						}
						
					}
				}
		return result;
		}
}
/*In this function, the user plays against the user and each user marks the position they want to throw. 
 * First, I convert the positions it throws to an integer value. I set the alphabet as a string and compare it with the data entered by the user. 
 * I convert the letter the user has entered into a number and place it in my hex array accordingly.*/
int UservsUser(int size,int hextable[12][12],char x,int y,int userCheck)
{
	char alpha[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	int x1,result=0;
	int consty;
	int solve[12][12];
	//First, I reset the sequence in which I recorded the steps, the reason I do this is because it does not overlap every time the program runs.
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			solve[i][j]	=	0;
		}
	}
	for(int i=0;i<12;i++)//I'm converting the coordinates to integers.
	{
		if(alpha[i]	==	x)
		{
			x1	=	i;
		}
	}
	//We check whether every user wins when they log in. We do the control process from left to right for horizontal. For vertical, we do it from top to bottom.
	if(userCheck	==	0)
	{
		hextable[y-1][x1]=120;
		for(int i=0;i<size;i++)
			{
				if(hextable[i][0]	==	120 && result	==	0)
				{
					y	=	i;
					result=determineWin(y,0,0,hextable,size,solve);
				}
			}
		if(result==1)
				{
				
					for(int i=0;i<size;i++)
					{
						for(int j=0;j<size;j++)
						{
							if(solve[i][j]==1)
							{
								hextable[i][j] = 88 ;
							}
						}
						
					}
				}
		return result;
	}
	//We check whether every user wins when they log in. We do the control process from left to right for horizontal. For vertical, we do it from top to bottom.
	if(userCheck	==	1)
	{
		hextable[y-1][x1]=111;
		for(int i=0;i<size;i++)
		{
			if(hextable[0][i]	==	111 && result	==	0)
			{

				result	=	determineWin(0,i,1,hextable,size,solve);
			}
		}
		
		if(result==1)
		{
			for(int i=0;i<size;i++)
			{
				
				for(int j=0;j<size;j++)
				{
					if(solve[i][j]==1)
					{
							hextable[i][j] = 79 ;
					}
				}
				
			}
		}
		return result;
	}
}
/*In the function of checking whether the table is full or not, I keep a counter and I increase 1 at each point where you see it, if not,
   I check it lastly. If the counter is 0, it shows that all its coordinates are filled.*/
int isFull(int hex[12][12],int size)
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(hex[i][j]	==	46)
			{
				count++;
			}
		}
	}
	if(count	==	0)
	{
		return 1;
	}
	else return 0;
}

int select_menu(int hex[12][12])
{
	//I do the selection functions in this menu.
	/*I do the data entry control in the same menu. If it is trying to enter data in the existing location, 
	 * I log in again. If the table is full, I end the game. When the winner is, 
	 * I press the screen here. In short, I do applications such as screen printing, data entry, data entry control in this menu.*/
	int y,check	=0,check1=0,control=0,count=0,selection;
	int store[2];
	int size;
	char x;
	char alpha[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	cout << "Welcome. Please enter the table size :";
	cin >> size;
	if(size<6 || size>12)
	{
		cout<<"Wrong size. Please enter correct size \n ";
		return 0;
	}
	else {
	cout << "\n1 - > User vs User :\n";
	cout << "2 - > User vs Computer :\n";
	cout << "Select - >";
	cin >> selection;
	firstFillTable(size,hex);
	printTable(size,hex);
	
	if(selection	 == 	1)
	{
		while(control	==	0 && isFull(hex,size)==0)
		{
			while(check	!=	1 || check1	!=	1)
			{
				cout << "Please User1 enters coordinate :";
				cin >> x >> y;
				for(int i=0;i<size;i++)
				{
					if(alpha[i]	==	x)
					{
						if(hex[y-1][i]	==	46) check	=	1;
					}
				}
				if(y	>	0 && y	<=	size )
				{
					check1	=	1;
				}
				if(check	!=	1 || check1	!=	1)
				{
					cout << "User1 tekrar giriniz...\n";
				}
			}	
			
			if(UservsUser(size,hex,x,y,0)	==	1)
			{
				printTable(size,hex);
				cout << "1.User  Win\n";
				control	=	1;
			}
			else
			{
				printTable(size,hex);
				check	=	0;
				check1	=	0;
				while(check	!=	1 || check1	!=	1)
				{
					cout << "Please User2 enters coordinate :";
					cin >> x >> y;
					for(int i=0;i<size;i++)
					{
						if(alpha[i]==x)
						{
							if(hex[y-1][i]==46) check=1;
						}
					}
					if(y	>	0 && y	<=	size)
					{
						check1	=	1;
					}
					if(check	!=	1 || check1		!=	1)
					{
						cout << "User2 tekrar giriniz...\n";
					}
				}
				if(UservsUser(size,hex,x,y,1)==1)
				{
					printTable(size,hex);
					cout << "2.User Win\n";
					control=1;
				}
				else
				{
					printTable(size,hex);
				}
				check	=	0;
				check1	=	0;
			}
		}

	}
	if(selection	==	2)
	{
		while(control	==	0)
		{
			while(check	!=	1 || check1	!=	1)
			{
				cout << "Please User1 enters coordinate :";
				cin >> x >> y;
				for(int i=0;i<size;i++)
				{
					if(alpha[i]	==	x)
					{
						if(hex[y-1][i]	==	46) check	=	1;
					}
				}
				if(y	>	0 && y	<=	size )
				{
					check1	=	1;
				}
				if(check	!=	1 || check1	!=	1)
				{
					cout << "User1 tekrar giriniz...\n";
				}
			}

			if(UservsUser(size,hex,x,y,0)	==	1)
			{
				printTable(size,hex);
				cout << "1.User Win\n";
				control	=	1;
			}
			else
			{
				check	=	0;
				check1	=	0;
				count++;
				if(computerSteps(size,hex,count,store)==1)
				{
					printTable(size,hex);
					cout << "Computer Win\n";
					control=1;
				}
				else 
				{
					printTable(size,hex);
				}
					check	=	0;
					check1	=	0;
			}
		}
	}
	}
}
int main() {

	int hex[12][12];
	select_menu(hex);
}
