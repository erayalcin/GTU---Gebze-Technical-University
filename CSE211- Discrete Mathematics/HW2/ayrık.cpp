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
void find(int relation,char rel[][2],int element,char el[20],ofstream& resultfile)
{

	int symmetric=0,antisymmetric=0;
	char result[element];
	char ac[relation*3][2];
	int countresult=0;
	//First, we check whether it is reflexive or not.
	cout<<relation<<"\n";
	resultfile<<relation<<"\n";

	for(int i=0;i<relation;i++)
	{
		cout<<"("<<rel[i][0]<<","<<rel[i][1]<<")";
		resultfile<<"("<<rel[i][0]<<","<<rel[i][1]<<")";
	}
	cout<<endl;
	resultfile<<endl;
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





			}

		}




	}

	if(reflex==element)
	{
		cout<<"Reflexive: Yes, all elements are present.\n";
		resultfile<<"Reflexive: Yes, all elements are present.\n";
	}
	else
	{
		cout<<"Reflexive: No, all elements are  not present.";
		resultfile<<"Reflexive: No, all elements are  not present.";

		for(int i=0;i<element;i++)
		{
			if(result[i]!=el[i])
				{
				cout<<"("<<el[i]<<","<<el[i]<<")";
				resultfile<<"("<<el[i]<<","<<el[i]<<")";
				break;
				}



		}






		cout<<"  not found\n";
		resultfile<<"  not found\n";
	}
	//Then we check whether it is symmetrical or not.
	reflex=0;
	for(int i=0;i<relation;i++)
		{
				for(int j=0;j<relation;j++)
				{
					if(rel[i][0]==rel[j][1] && rel[i][1]==rel[j][0])
					{

						symmetric++;

					}

				}
		}
	if(symmetric==relation)
	{
		cout<<"Symmetric: Yes, all elements are present.\n";
		resultfile<<"Symmetric: Yes, all elements are present.\n";
	}
	else
	{
		symmetric=0;
		cout<<"Symmetric: No,";
		resultfile<<"Symmetric: No,";
		for(int i=0;i<relation;i++)
				{
						for(int j=0;j<relation;j++)
						{
							if(rel[i][0]==rel[j][1] && rel[i][1]==rel[j][0])
							{
								symmetric++;

							}
						}

						if(symmetric==0)
						{
							cout<<"("<<rel[i][1]<<","<<rel[i][0]<<")"<<" ";
							resultfile<<"("<<rel[i][1]<<","<<rel[i][0]<<")"<<" ";

						}
						symmetric=0;
				}

		cout<<"is not found whereas ";
		resultfile<<"is not found whereas ";
		symmetric=0;
		for(int i=0;i<relation;i++)
						{
								for(int j=0;j<relation;j++)
								{
									if(rel[i][0]==rel[j][1] && rel[i][1]==rel[j][0])
									{
										symmetric++;

									}
								}
								if(symmetric==0)
								{
									cout<<"("<<rel[i][0]<<","<<rel[i][1]<<")"<<" ";
									resultfile<<"("<<rel[i][0]<<","<<rel[i][1]<<")"<<" ";
								}
								symmetric=0;
						}
		cout<<"is found"<<endl;
		resultfile<<"is found"<<endl;


	}
	//Here, we check whether it is antisymmetric or not.
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
			cout<<"Antisymmetric: No,";
			resultfile<<"Antisymmetric: No,";
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

			cout<<" are found "<<endl;
			resultfile<<" are found "<<endl;
		}
		else
		{
			//We explain to the screen  poset showing yes or no reason why.
			antisymmetric=0;
			cout<<"Antisymmetric: Yes,";
			resultfile<<"Antisymmetric: Yes,";
			for(int i=0;i<relation;i++)
					{
							for(int j=0;j<relation;j++)
							{
								if(rel[i][0]==rel[j][1] && rel[i][1]==rel[j][0])
								{
									antisymmetric++;

								}
							}

							if(antisymmetric==0)
							{
								cout<<"("<<rel[i][1]<<","<<rel[i][0]<<")"<<" ";
								resultfile<<"("<<rel[i][1]<<","<<rel[i][0]<<")"<<" ";

							}
							antisymmetric=0;
					}

			cout<<"is not found whereas";
			resultfile<<"is not found whereas";
			antisymmetric=0;
			for(int i=0;i<relation;i++)
							{
									for(int j=0;j<relation;j++)
									{
										if(rel[i][0]==rel[j][1] && rel[i][1]==rel[j][0])
										{
											antisymmetric++;

										}
									}
									if(antisymmetric==0)
									{
										cout<<"("<<rel[i][0]<<","<<rel[i][1]<<")"<<" ";
										resultfile<<"("<<rel[i][0]<<","<<rel[i][1]<<")"<<" ";
									}
									antisymmetric=0;
							}
			cout<<"is found"<<endl;
			resultfile<<"is found"<<endl;
		}
		//Then we check the transitive status
		cout<<"Transitive:";
		resultfile<<"Transitive:";
		int tran=0;
		int temp=0;
		int a,b;
		for(int i=0;i<relation;i++)
		{
			for(int j=0;j<relation;j++)
			{

				if(rel[i][1]==rel[j][0])
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
					if(ac[i][0]==rel[j][0] && ac[i][1]==rel[j][1])
					{
						count++;
						a=i;
						b=j;
						break;
					}
				}

					//cout<<ac[i][0]<<"-"<<ac[i][1]<<endl;
				}


		if(count==temp)
		{
			temp=0;
			cout<<"Yes, it is transitive\n";
			resultfile<<"Yes, it is transitive\n";




		}
		else
		{
			cout<<"No,it is not transitive\n";
			resultfile<<"No,it is not transitive\n";
			count=0;


		}



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


			find(relation,rel,element-(element/2),el,resultfile);
			}
	}
	}




}
int main()
{
	readFile();
}
