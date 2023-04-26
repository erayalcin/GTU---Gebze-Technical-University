#include <iostream>
using namespace std;



int main()
{
	const int a=100;
	const int b=3;
	int count=0,i,j;
	for(i=b;i<a;i++)
	{
		for(j=2;j<a-1;j++)
		{
			if(i%j==0 && i!=j)
			{
				count++;
			}
		}

		if(count==0)
		{
			cout<<i<<" is a prime number. "<<endl;
		}
		count=0;
	}
}