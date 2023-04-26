//============================================================================
// Name        : ayrık.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
//We examine the status of the data we read from the file here.
void simetric(int relation,char rel[][2],int element,char el[20],ofstream& resultfile);
void reflex(int relation,char rel[][2],int element,char el[20],ofstream& resultfile)
{

	char result[element];
	int check=0;
	int countresult=0;
	//First, we check whether it is reflexive or not.
	int reflex=0;
	int countt=0;
	for(int i=0;i<element;i++)
		{
			result[i]=0;
		}
	for(int i=0;i<20;i++)
	{


		for(int j=0;j<relation;j++)
		{
			if(el[i]==rel[j][0] && el[i]==rel[j][1])
			{


				reflex++;
				result[countt]=el[i];
				countt++;

				break;

			}

		}

		check=0;




	}

	for(int i=0;i<element;i++)
	{
		if(result[i]!=el[i])
		{
			rel[relation][0]=el[i];
			rel[relation][1]=el[i];
			relation++;
		}

	}


simetric(relation,rel,element,el,resultfile);
}
void transitive(int relation,char rel[][2],int element,char el[20],ofstream& resultfile)
{
	int tran=0;
	char ac[relation*3][2];
		int temp=0;
		int a,b;
		for(int i=0;i<relation;i++)
		{
			for(int j=0;j<relation;j++)
			{

				if(rel[i][1]==rel[j][0] && rel[i][0]!=rel[i][1])
				{

					ac[temp][0]=rel[i][0];
					ac[temp][1]=rel[j][1];
					temp++;
				}

			}

		}
		int count=0;

		for(int i=0;i<temp;i++)
				{

				for(int j=0;j<relation;j++)
				{
					if(ac[i][0]==rel[j][0] && ac[i][1]==rel[j][1] )
					{
						count++;
					}

				}
				if(count==0)
				{
					rel[relation][0]=ac[i][0];
					rel[relation][1]=ac[i][1];
					relation++;

				}
				count=0;


				}




					reflex(relation,rel,element,el,resultfile);
}
void refreshItem(int relation,char rel[][2],int element,char el[20],ofstream& resultfile)
{
	int check=0;
	for(int i=0;i<relation;i++)
	{
		for(int j=0;j<relation;j++)
		{
				if(rel[i][0]==rel[j][0] && rel[i][1]==rel[j][1] && i!=j)
				{

					check=1;
				}
		}
		if(check==1)
		{
			rel[i][0]=rel[relation-1][0];
		rel[i][1]=rel[relation-1][1];
			relation--;
			break;
		}
	}
	cout<<"\nn\n";
	resultfile<<"\nn\n";
	cout<<"POSET : ";
	resultfile<<"POSET : ";
	for(int i=0;i<relation;i++)
					{

						cout<<"("<<rel[i][0]<<","<<rel[i][1]<<")"<<" ";
						resultfile<<"("<<rel[i][0]<<","<<rel[i][1]<<")"<<" ";
					}
					cout<<endl;
					resultfile<<endl;

}
void simetric(int relation,char rel[][2],int element,char el[20],ofstream& resultfile)
{
	int symmetric=0;
	int check=0;
	for(int i=0;i<relation;i++)
			{
		symmetric=0;
					for(int j=0;j<relation;j++)
					{
						if(rel[i][0]==rel[j][1] && rel[i][1]==rel[j][0] && rel[i][0]!=rel[i][1] && rel[i][0] != rel[i][1])
						{

							symmetric++;

						}

					}

					if(check==0)
					{
						if(symmetric!=0)
						{
								rel[i][0]=rel[relation-1][0];
								rel[i][1]=rel[relation-1][1];
								relation--;
								check=1;
						}
					}
					else check=0;




			}

	refreshItem(relation,rel,element,el,resultfile);
}

void antysimetric(int relation,char rel[][2],int element,char el[20],ofstream& resultfile)
{
	char ac[relation*3][2];
	int antisymmetric=0;
	for(int i=0;i<relation;i++)
				{
						for(int j=0;j<relation;j++)
						{
							if(rel[i][0]==rel[j][1] && rel[i][1]==rel[j][0])
							{

								antisymmetric++;

							}

						}
				}

			if(antisymmetric==relation)
			{

				for(int i=0;i<relation;i++)
									{
											for(int j=0;j<relation;j++)
											{
												if(rel[i][0]==rel[j][1] && rel[i][1]==rel[j][0])
												{
													antisymmetric++;

												}
											}

											if(antisymmetric!=0)
											{
												cout<<"("<<rel[i][1]<<","<<rel[i][0]<<")"<<" ";
												resultfile<<"("<<rel[i][1]<<","<<rel[i][0]<<")"<<" ";

											}

											antisymmetric=0;
									}


			}
			refreshItem(relation,rel,element,el,resultfile);

}

//Here we are reading the file. I wanted to read the file one by one.
//I could read it line by line. I read it one by one because this was easier for me.
void readFile()
{
	ofstream resultfile("output.txt");
	char c;
	int i=0;
	int a=0;

	int relation;
	int element=0;
	char el[20];
	ifstream readFile("input.txt");
	if (readFile.is_open()) {
		//I trade by line one by one.
	while(!readFile.eof()){
		for(int i=0;i<20;i++)
		{
			el[i]=0;
		}
		element=0;
			readFile.get(c);
			if(c=='\n')
			{
				readFile.get(c);
			}
			else
			{


			relation=(int)c-48;
			//Since I read row by row, if the relation number has 2 digits,
			//I used this because I had a problem while converting it to an integer value.
			readFile.get(c);
			if (c != '\n') {
						relation = (relation * 10) + ((int) c - 48);
						readFile.get(c);

					}
			//cout<<relation;
			//cout<<c;
			readFile.get(c);

			char rel[relation][2];
			while(c!='\n')
			{

				if(c!=',')
				{
					el[element-(element/2)]=c;

				}
				readFile.get(c);

				element++;

			}
			for(int k=0;k<relation;k++)
			{

				readFile.get(c);
				rel[k][0]=c;
				readFile.get(c);
				readFile.get(c);
				rel[k][1]=c;
				readFile.get(c);



			}


			//reflex(relation,rel,element-(element/2),el,resultfile);
			transitive(relation,rel,element-(element/2),el,resultfile);
			}
	}
	}




}
int main()
{
	readFile();
}
