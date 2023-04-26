//I have defined the libraries I use.
#include <iostream>  
using namespace std;
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
////I have defined the functions I use.
int generate_number(const int numberofdigit,int arr[]);
bool error_check(int number,int numberofdigit);
int findFirstCount(int array[],int number,int numberofdigit);
int findDigit(int secretNumber);
//I find out how many digits the number has.I keep dividing the number by 10 until the number is equal to 0.
int findDigit(int secretNumber)
{
	int count=0;
	do
	{
		secretNumber=secretNumber/10;
		count++;
	} while (secretNumber!=0);
	
	return count;
}
//In this function, I find value of firstcount and second count.
//Here I check the array one by one,if it is equal to the number entered, I increment the first count in that step.
//If t is not equal, I see if that number exists in the array and if it does, I increase the second count.
int findFirstCount(int array[],int number,int numberofdigit)
{
	int i;
	int firstCount=0;
	int secondCount=0;
	for(i=numberofdigit-1;i>=0;i--)
	{
		if(array[i]==number%10)
		{
			firstCount++;
			
		}
		else
		{
			for (int j = 0; j < numberofdigit; ++j)
			{
				if(number%10==array[j])
				{
					secondCount++;
				}
			}
		}
		number=number/10;
		
	}
	//When the user finds the number,I write on the screen that it was found and how many steps it took.
	if(firstCount==numberofdigit) cout<<"FOUND";
	else cout<<firstCount<<" "<<secondCount<<endl;
	return firstCount;
}
//I have the error check of the entered number here.
bool error_check(int number,int numberofdigit)
{
	int k=0;
	int check=0;
	int check1=0;
	int arr[numberofdigit];
	int temp=number;
	int temp1=number;
	//I do the error checks on the entered number in this function,I split the number entered first and throw it into the array.
	


	for (int i = 0; i < numberofdigit; ++i)
	{
		
		arr[i]=temp%10;
		temp=temp/10;
	}
	//First I check to see if the number of digits is equal.Then I see if it's recurring.
	do
	{

		if(number%10>=0 && number%10<=9 )
		{
			
			check++;
		}
		
		number=number/10;
		k++;	
	} while (number!=0);
	//Recurring check 
	for (int i = 0; i < numberofdigit; ++i)
		{
			for(int j=0;j<numberofdigit;j++)
			{
				if(arr[i]==arr[j] && i!=j)
				{
					check1=1;
				}
			}
		}
	if(number>0 || check1!=1)
	{
		
	if(check==1)
	{
		cout<<"E2"<<endl;
		return false;
	}
	else
	{
		if(k==numberofdigit && temp1>0)
		{

			return true;
		}
		else 
			{
				
				cout<<"E1"<<endl;
				return false;

			}
	}
	}
	else 
	{
			cout<<"E0"<<endl;
			return false;
	}

	
}
//I am generating a random number. I build between 1 and 9 for the first digit.
//I choose the other digits between 0-9 and assign them to the array.
//I am generating a random number again and checking if it's in the array.
int generate_number(const int numberofdigit,int arr[])
{
	int i=0,j;
	int random;
	
	do
	{
		
		if(i==0)
		{
			random=rand()%10+1;
			arr[i]=random;
			i++;
		}
		else
		{
			int check=0;
			random=rand()%10;
			for(j=0;j<numberofdigit;j++)
			{
				if(random==arr[j])
				{
					check++;
				}
			}
			if(check==0) 
			{
				arr[i]=random;
				i++;
			}
		}

	} while (i!=numberofdigit);
	
	
}
int main(int argc, char const *argv[])
{

	int finish;
	int counter=0;
	//If the parameters are sent empty,we will give an error.
	if(argv[1]==NULL)
	{
		cout<<"E0"<<endl;
		exit(1);
	}
	//We check the -r command and if -r is entered,we get the number of digits.The number of digits can be between 1 and 9. That's why we check.
	if(argv[1][0]=='-' && argv[1][1]=='r' && argv[2]!=NULL)
	{
		
		int numberofdigit=atoi(argv[2]);
		if(numberofdigit>0 && numberofdigit<=9)
		{
			string num;
			srand(static_cast<int>(time(NULL)));
		
			int array[numberofdigit];
			generate_number(numberofdigit,array);

			//I get a number from the first user,convert it from a string to an integer and have an error check.Then I send it to my findFirstcount function.
			do
			{
				//I check the case of being 0 at the beginning of the number with a string,then convert it to an integer and create a random number.
				cin>>num;
				if(num[0]=='0')
				{
					cout<<"E1"<<endl;
					exit(1);
				}
				stringstream input(num);
				int number=0;
				input >> number;

			if(!error_check(number,numberofdigit))
			{
				exit(1);
			}
			else
			{	
				finish=findFirstCount(array,number,numberofdigit);
				
			}
			//The user has to guess 100,if not,the program will be over.
			if(counter<100)
			{
				counter++;

			}
			else
			{
				cout<<"FAILED"<<endl;
				exit(1);
			}
			} while (finish!=numberofdigit);
			cout<<" "<<counter<<endl;
			exit(1);
		}
		else
			{
				cout<<"E0"<<endl;
				exit(1);
			}
		
		
	}
	if(argv[1][0]=='-' && argv[1][1]=='u' && argv[2]!=NULL)
	{
		//The number cannot start with 0 so I check it and if it starts with 0 the program terminates.
		

		if(argv[2][0]=='0')
		{
			cout<<"E0"<<endl;
			exit(1);
		}
		string num;
		int number;
		int secretNumber=atoi(argv[2]);
		
		int digit=findDigit(secretNumber);
		int arr[digit];
		int temp=secretNumber;

		if(secretNumber<0 || digit>9)
		{
			cout<<"E0"<<endl;
			exit(1);
		}
		for (int i = digit-1; i >= 0; i--)
		{
			
			arr[i]=temp%10;
			temp=temp/10;
			
		}
		//I get a number from the first user,convert it from a string to an integer and have an error check.Then I send it to my findFirstcount function.
		do
			{
				cin>>num;
				//I check the case of being 0 at the beginning of the number with a string,then convert it to an integer and create a random number.
				if(num[0]=='0')
				{
					cout<<"E1"<<endl;
					exit(1);
				}
				stringstream input(num);
				int number=0;
				input >> number;
				
			if(!error_check(number,digit))
			{
				exit(1);
			}
			else
			{	
				finish=findFirstCount(arr,number,digit);
				
			}
			//The user has to guess 100,if not,the program will be over.
			if(counter<100)
			{
				counter++;

			}
			else
			{
				cout<<"FAILED"<<endl;
				exit(1);
			}
			} while (finish!=digit);
			cout<<" "<<counter<<endl;
		exit(1);
	}
	else
	{
		cout<<"E0"<<endl;
	}
	return 0;
	
}