//I describe the libraries I use
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
//I use nested class logic here. I derive my inner class from the public class with a vector.
class ppmImage
{
	//I keep only the color values in the interior class.
	public:
		class pixel
		{
 			public:
 				int get_Red()const;
 				int get_Green()const;
 				int get_Blue()const;
 				void set_Red(int value);
 				void set_Green(int value);
 				void set_Blue(int value);
			private:
				int r,g;
				int b;	
		};
		//I define my constructor.
		ppmImage(){};
		ppmImage(string filename);
		ppmImage(int a,int b);
		//I define my member functions in the public section of the class.Getters and setters are here as well.
		int get_ppm_r(int a,int b)const;
		int get_ppm_g(int a,int b)const;
		int get_ppm_b(int a,int b)const;
		void set_ppm_r(int a,int b,int c);
		void set_ppm_g(int a,int b,int c);
		void set_ppm_b(int a,int b,int c);
		int save_ppmFile(string fileName)const;
		int read_ppmFile(string fileName);
		int get_x()const;
		int get_y()const;
		void set_x(int a);
		void set_y(int b);
		void printPPM()const;
		int findColorValue(int a,int b,char r)const;
		string get_ppmFileName()const;
		void set_ppmFileName(string filename);
		void first_fillppm();
		
	private:
		int x,y;
		string ppl_filename;
		vector<vector<pixel>> ppm;
		
		
};
//I get the filename with getter.
string ppmImage::get_ppmFileName()const
{
	return  ppl_filename;
}
//I set filename with this function
void ppmImage::set_ppmFileName(string filename)
{
	ppl_filename=filename;
}
//From the 2-dimensional vector we defined,we get the color values of our inner class in that pixel.
//My inner class getters and setters
//Since it is an inner class,we can access it from within the ppm Image,so we make ppm Image pixel.
int ppmImage::pixel::get_Blue()const
{
	return b;
}
void ppmImage::pixel::set_Blue(int value)
{
	b=value;
}
int ppmImage::pixel::get_Green()const
{
	return g;
}
void ppmImage::pixel::set_Green(int value)
{
	g=value;
}
int ppmImage::pixel::get_Red()const
{
	return r;
}
void ppmImage::pixel::set_Red(int value)
{
	r=value;
}
//Pixel getters and setters
int ppmImage::get_x()const
{
	return x;
}
int ppmImage::get_y()const
{
	return y;
}
void ppmImage::set_x(int a)
{
	x=a;
}
void ppmImage::set_y(int b)
{
	y=b;
}
//We reach inside the pixel object that we created with the vector.
void ppmImage::set_ppm_r(int a,int b,int c)
{
	ppm[a][b].set_Red(c);
}
void ppmImage::set_ppm_g(int a,int b,int c)
{
	ppm[a][b].set_Green(c);
}
void ppmImage::set_ppm_b(int a,int b,int c)
{
	ppm[a][b].set_Blue(c);
}
//If we want to reach the given index information and the value of the c olor in that index,we find it with this function.
int ppmImage::findColorValue(int a,int b,char r)const
{
	if(r=='r')
	return ppm[a][b].get_Red();
	if(r=='g')
	return ppm[a][b].get_Green();
	if(r=='b')
	return ppm[a][b].get_Blue();
}
//We do the process of saving our file here,we create the file with the first ofstream,then we write the pixel value 
//and our values into the file.
int ppmImage::save_ppmFile(string fileName)const
{
	ofstream saveFile(fileName);
	saveFile<<"P3\n";
	saveFile<<get_x()<<" "<<get_y()<<"\n";
	saveFile<<"255\n";
	for(int i=0;i<get_x();i++)
	{
		for (int j = 0; j < get_y(); j++)
		{
			saveFile<<get_ppm_r(i,j)<<" "<<get_ppm_g(i,j)<<" "<<get_ppm_b(i,j)<<" ";
		}
		saveFile<<"\n";
	}
	return 1;
}

void ppmImage::printPPM()const
{
	cout<<endl;
	cout<<get_x()<<" "<<get_y();
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout<<get_ppm_r(i,j)<<" "<<get_ppm_g(i,j)<<" "<<get_ppm_b(i,j)<<" ";
		}
		cout<<endl;
		
	}
	cout<<endl;
	cout<<endl;
}
//In this function,we print everything in our file to the screen.
int ppmImage::read_ppmFile(string fileName)
{

	string a,b,c,d,e,f,g;
	int x, y,red,green,blue;
	ifstream readFile(fileName);
	if(readFile.is_open())
	{
		readFile >> a;
		if(a=="P3")
		{
			readFile >> b >> c;
			int x=stoi(b);
			int y=stoi(c);
			set_x(x);
			set_y(y);
			readFile >> g;
			first_fillppm();
			for(int i=0;i<x;i++)
			{
				for (int j = 0; j < y; ++j)
				{
					readFile >> d >> e >> f;
					red=stoi(d);
					green=stoi(e);
					blue=stoi(f);
					set_ppm_r(i,j,red);
					set_ppm_g(i,j,green);
					set_ppm_b(i,j,blue);
					

				}
			}
		}
		return 1;
	}
	else
	{
		cout<<"Dosya açılamadı... ";
		return 0;
	}

}
//getters setters
int ppmImage::get_ppm_r(int a,int b)const
{
	return ppm[a][b].get_Red();
}
int ppmImage::get_ppm_g(int a,int b)const
{
	return ppm[a][b].get_Green();
}
int ppmImage::get_ppm_b(int a,int b)const
{
	return ppm[a][b].get_Blue();
}
//We make all the colors of and object with index values white.
//Constructor
ppmImage::ppmImage(int a,int b)
{
		x=a;
		y=b;
		pixel tmp;
		for(int j=0;j<y;j++)
		{
			vector<pixel>p1;
			for(int i=0;i<x;i++)
			{
				tmp.set_Red(255);
				tmp.set_Green(255);
				tmp.set_Blue(255);
				p1.push_back(tmp);
				
			 }
			ppm.push_back(p1);	
		}
}
//Constructor that creates objects with this filename
ppmImage::ppmImage(string filename)
{
	set_ppmFileName(filename);
}
//I fill the vector with 0 first,and the reason I do this is to create the vector first and have trouble.
void ppmImage::first_fillppm()
{
	pixel tmp;
		for(int j=0;j<y;j++)
		{
			vector<pixel>p1;
			for(int i=0;i<x;i++)
			{
				tmp.set_Red(0);
				tmp.set_Green(0);
				tmp.set_Blue(0);
				p1.push_back(tmp);
				
			 }
			ppm.push_back(p1);	
		}	
}
//This saves the data in the object sent to the function to the file.
int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object)
{
	
	if(source_object.save_ppmFile(destination_ppm_file_name)==1)
		return 1;
	else return 0;
}
//This function that reads the data in the file sent to this function and saves it to the object sent.
int read_ppm(const string source_ppm_file_name,ppmImage& destination_object)
{
	if(destination_object.read_ppmFile(source_ppm_file_name)==1)
	{
		
		return 1;
	}
	else 
	{	
		return 0;
	}
}

//this function swaps the color values of every pixel in a given ppm image.
//this function does not create a new object but modifies the given one.
//if swap_choice is 1: swaps red and green
//if swap_choice is 2: swaps red and blue
//if swap_choice is 3: swaps green and blue
//if swap_choice is not 1, 2 or 3: no swaps (this does not mean that the operation is not
//→
//successful. the function should return 1 in this case if everything is normal)
// returns 1 if the operation is successful. otherwise, returns 0.
int swap_channels( ppmImage& image_object_to_be_modified,int swap_choice)
{
	int temp;
	
		for(int i=0;i<image_object_to_be_modified.get_x();i++)
		{
			for(int j=0;j<image_object_to_be_modified.get_y();j++)
			{
				if(swap_choice==1)
				{
					temp=image_object_to_be_modified.get_ppm_g(i,j);
					image_object_to_be_modified.set_ppm_g(i,j,image_object_to_be_modified.get_ppm_r(i,j));
					image_object_to_be_modified.set_ppm_r(i,j,temp);
					
					
				}
				else if(swap_choice==2)
				{
					temp=image_object_to_be_modified.get_ppm_b(i,j);
					image_object_to_be_modified.set_ppm_b(i,j,image_object_to_be_modified.get_ppm_r(i,j));
					image_object_to_be_modified.set_ppm_r(i,j,temp);
					
				}
				else if(swap_choice==3)
				{
					temp=image_object_to_be_modified.get_ppm_b(i,j);
					image_object_to_be_modified.set_ppm_b(i,j,image_object_to_be_modified.get_ppm_g(i,j));
					image_object_to_be_modified.set_ppm_g(i,j,temp);
					
				}
			}
		}
		return 1;
}
// creates and returns a copy of a new ppmImage object which stores only one color at each
//→
//pixel. This simply takes the source and copies only one color information and stores it in
//→
//a new object. The other color channels are simply going to be zeros.
//if color_choice is 1: red channel is preserved
//if color_choice is 2: green channel is preserved
//if color_choice is 3: blue channel is preserved
ppmImage single_color(const ppmImage& source,int color_choice)
{
	ppmImage tmp;
	tmp.set_x(source.get_x());
	tmp.set_y(source.get_y());
	tmp.first_fillppm();
	for(int i=0;i<source.get_x();i++)
		{
			for(int j=0;j<source.get_y();j++)
			{
				if(color_choice==1)
				{
					tmp.set_ppm_r(i,j,source.get_ppm_r(i,j));
					
				}
				if(color_choice==2)
				{
					tmp.set_ppm_g(i,j,source.get_ppm_g(i,j));
					
				}
				if(color_choice==3)
				{
					tmp.set_ppm_b(i,j,source.get_ppm_b(i,j));
				}

			}
		}
		return tmp;
}
int main(int argc,char **argv)
{
	ppmImage test;
	ppmImage p1("test.txt");
	//check for number of command line arguments
	//the first argument is going to be choice number
	//the second argument is going to be a ppm_file_name
	int choose=atoi(argv[1]);
	string file_name=argv[2];
	// read ppm_file_name using function read_ppm
	// write the same data without changing anything to a file named "o1.ppm". use write_ppm
	//function.
	if(choose==1)
	{
		//If the file reads, I am checking it because I will return 1. Then I save as a new file if it has been read.
		if(read_ppm(file_name,test)==1)
		{
			if(write_ppm("o1.ppm",test)==1)
			{
				cout<<"o1.ppm created.\n";
			}
		}
		else
		{
			cout<<"Operation wrong.\n";
		}
	}
	//read ppm_file_name using function read_ppm
	//swap red and green channels
	//write the updated data to a file named "o2.ppm". use write_ppm function.
	if(choose==2)
	{
		//If the file reads, I am checking it because I will return 1. I am changing the colors.Then I save as a new file if it has been read.
		if(read_ppm(file_name,test)==1)
		{
			
			if(swap_channels(test,1)==1)
			{
				if(write_ppm("o2.ppm",test)==1)
				{
					cout<<"o2.ppm created.\n";
				}
			}
		}	
	}

 	//if choice number is 3
	//read ppm_file_name using function read_ppm
	//swap red and blue channels
	//write the updated data to a file named "o3.ppm". use write_ppm function.
	if(choose==3)
	{
		//If the file reads, I am checking it because I will return 1. I am changing the colors.Then I save as a new file if it has been read.
		if(read_ppm(file_name,test)==1)
		{
			if(swap_channels(test,2)==1)
			{
				if(write_ppm("o3.ppm",test)==1)
				{
					cout<<"o3.ppm created.\n";
				}
			}
		}
	}
	//read ppm_file_name using function read_ppm
	//swap green and blue channels. use swap_channels function
	//write the updated data to a file named "o4.ppm". use write_ppm function.
	if(choose==4)
	{
		//If the file reads, I am checking it because I will return 1. I am changing the colors.Then I save as a new file if it has been read.
		if(read_ppm(file_name,test)==1)
		{
			if(swap_channels(test,3)==1)
			{
				if(write_ppm("o4.ppm",test)==1)
				{
					cout<<"o4.ppm created.\n";
				}
			}
		}
	}
	//read ppm_file_name using function read_ppm
	// create a new object which only contains red channel data of the file read. ue single_color
	//→
	//function
	// write the data of the new object to a file named "o5.ppm". use write_ppm function.
	if(choose==5)
	{
		//If the file reads, I am checking it because I will return 1. I make all the colors in one color according to my choice.
		//Then I save as a new file if it has been read.
			if(read_ppm(file_name,test)==1)
			{

				ppmImage newObj;
				newObj=single_color(test,1);
				if(write_ppm("o5.ppm",newObj)==1)
				{
					cout<<"o5.ppm created.\n";
				}
			}
	}
	//// read ppm_file_name using function read_ppm
	// create a new object which only contains green channel data of the file read. ue
	//single_color function
	// write the data of the new object to a file named "o6.ppm". use write_ppm function.
	if(choose==6)
	{
		//If the file reads, I am checking it because I will return 1. I make all the colors in one color according to my choice.
		//Then I save as a new file if it has been read.
		if(read_ppm(file_name,test)==1)
		{
			ppmImage newObj;
			newObj=single_color(test,2);
			if(write_ppm("o6.ppm",newObj)==1)
			{	
				cout<<"o6.ppm created.\n";
			}
		}	
	}

	//// read ppm_file_name using function read_ppm
	// create a new object which only contains blue channel data of the file read. ue single_color
	//function
	// write the data of the new object to a file named "o7.ppm". use write_ppm function.
	if(choose==7)
	{
		//If the file reads, I am checking it because I will return 1. I make all the colors in one color according to my choice.
		//Then I save as a new file if it has been read.
		if(read_ppm(file_name,test)==1)
		{
			ppmImage newObj;
			newObj=single_color(test,3);
			if(write_ppm("o7.ppm",newObj)==1)
			{
				cout<<"o7.ppm created.\n";
			}
		}
	}
}	