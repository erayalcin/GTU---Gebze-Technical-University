//I describe the libraries I use
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
int test_addition(string ppm_filename1,string ppm_filename2,string ppm_filename3);
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
		int save_ppmFile(string fileName);
		int read_ppmFile(string fileName);
		int get_x()const;
		int get_y()const;
		void set_x(int a);
		friend ppmImage operator +(ppmImage& obj1,ppmImage& obj2);
		friend ppmImage operator-(ppmImage& obj1,ppmImage& obj2);
		friend ostream& operator << (ostream& out,ppmImage& obj);
		friend ofstream& operator << (ofstream& out,ppmImage& obj);
		int operator()(int x,int y,int pixel);
		void set_y(int b);
		void printPPM();
		string get_ppmFileName()const;
		void set_ppmFileName(string filename);
		void first_fillppm();
		
	private:
		int x,y;
		string ppl_filename;
		vector<vector<pixel>> ppm;
		
		
};
//We find the color we want in the index given in this function with operator() and return it.
int ppmImage::operator()(int x,int y,int pixel)
{
	//1-> Red
	//2-> Green
	//3-> Blue
	if(pixel==1) return ppm[x][y].get_Red();
	if(pixel==2) return ppm[x][y].get_Green();
	if(pixel==3) return ppm[x][y].get_Blue();
}
//In this function,I do the writing to the file with operator overloading.
ofstream& operator << (ofstream& out,ppmImage& obj)
{
	out<<"P3\n";
	out<<obj.get_x()<<" "<<obj.get_y()<<"\n";
	out<<"255\n";
	for(int i=0;i<obj.get_x();i++)
	{
		for (int j = 0; j < obj.get_y(); j++)
		{
			out<<obj.get_ppm_r(i,j)<<" "<<obj.get_ppm_g(i,j)<<" "<<obj.get_ppm_b(i,j)<<" ";
		}
		out<<"\n";
	}
	return out;
}
//In this function,I print the ppm file to the terminal with operator overloading.
ostream& operator <<(ostream& out,ppmImage& obj)
{
	out<<endl;
	out<<"P3"<<endl;
	out<<obj.get_x()<<" "<<obj.get_y();
	out<<endl;
	out<<"255";
	
	out<<endl;
	for(int i=0;i<obj.get_x();i++)
	{
		for (int j = 0; j < obj.get_y(); ++j)
		{
			out<<obj.get_ppm_r(i,j)<<" "<<obj.get_ppm_g(i,j)<<" "<<obj.get_ppm_b(i,j)<<" ";
		}
		out<<endl;
		
	}
	out<<endl;
	out<<endl;
	return out;
}
//We add the pixel values of the given 2 files and change it to 255 if it is more than 255.We return it with a new ppm object.
//We check the number of rows in the files,if they are equal,we do this.
ppmImage operator+(ppmImage& obj1,ppmImage& obj2)
{
	
	
	if(obj1.get_x()==obj2.get_x() && obj1.get_y()==obj2.get_y())
	{
		ppmImage tmp(obj1.get_x(),obj1.get_y());
		for(int i=0;i<obj1.get_x(); i++)
		{
			for(int j=0;j<obj1.get_y(); j++)
			{
				if(obj1.get_ppm_b(i,j)+obj2.get_ppm_b(i,j)>255)
				{
					tmp.set_ppm_b(i,j,255);
				}
				else
				{
					tmp.set_ppm_b(i,j,obj1.get_ppm_b(i,j)+obj2.get_ppm_b(i,j));
				}
				if(obj1.get_ppm_r(i,j)+obj2.get_ppm_r(i,j)>255)
				{
					tmp.set_ppm_r(i,j,255);
				}
				else
				{
					tmp.set_ppm_r(i,j,obj1.get_ppm_r(i,j)+obj2.get_ppm_r(i,j));
				}
				if(obj1.get_ppm_g(i,j)+obj2.get_ppm_g(i,j)>255)
				{
					tmp.set_ppm_g(i,j,255);
				}
				else
				{
					tmp.set_ppm_g(i,j,obj1.get_ppm_g(i,j)+obj2.get_ppm_g(i,j));
				}
			}
		}
		return tmp;
	}
	else
	{
		exit(1);
	}
	
}
//We substract the pixel values of the given 2 files and change it to 255 if it is more than 255.We return it with a new ppm object.
//We check the number of rows in the files,if they are equal,we do this.
ppmImage operator-(ppmImage& obj1,ppmImage& obj2)
{
	
	
	if(obj1.get_x()==obj2.get_x() && obj1.get_y()==obj2.get_y())
	{
		ppmImage tmp(obj1.get_x(),obj1.get_y());
		for(int i=0;i<obj1.get_x(); i++)
		{
			for(int j=0;j<obj1.get_y(); j++)
			{
				if(obj1.get_ppm_b(i,j)-obj2.get_ppm_b(i,j)<0)
				{
					tmp.set_ppm_b(i,j,0);
				}
				else
				{
					tmp.set_ppm_b(i,j,obj1.get_ppm_b(i,j)-obj2.get_ppm_b(i,j));
				}
				if(obj1.get_ppm_r(i,j)-obj2.get_ppm_r(i,j)<0)
				{
					tmp.set_ppm_r(i,j,0);
				}
				else
				{
					tmp.set_ppm_r(i,j,obj1.get_ppm_r(i,j)-obj2.get_ppm_r(i,j));
				}
				if(obj1.get_ppm_g(i,j)-obj2.get_ppm_g(i,j)<0)
				{
					tmp.set_ppm_g(i,j,0);
				}
				else
				{
					tmp.set_ppm_g(i,j,obj1.get_ppm_g(i,j)-obj2.get_ppm_g(i,j));
				}
			}
		}
		return tmp;
	}
	else
	{
		exit(1);
	}
	
}
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

//We do the process of saving our file here,we create the file with the first ofstream,then we write the pixel value 
//and our values into the file.
int ppmImage::save_ppmFile(string fileName)
{
	ofstream saveFile(fileName);
	saveFile<<*this;
	return 1;
}

void ppmImage::printPPM()
{
	cout<<*this;
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
int write_ppm(const string destination_ppm_file_name, ppmImage& source_object)
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
//In this function,we test the printing of the file to the screen with operator overloading.
int test_print(const string filename_image1)
{
	ppmImage testprint;
	if(read_ppm(filename_image1,testprint)==1)
	{
		cout<<testprint;
		return 1;
	}
	else return 0;
}
//In this function,we test adding the 2 ppm file with operator overloading.
int test_addition(string ppm_filename1,string ppm_filename2,string ppm_filename3)
{
	ppmImage obj1,obj2,obj3;
	if(read_ppm(ppm_filename1,obj1)==1 && read_ppm(ppm_filename2,obj2)==1)
	{
		obj3 = obj1 + obj2;
		write_ppm(ppm_filename3,obj3);

	}
}
//In this function,we test substracting the 2 ppm file with operator overloading.
int test_substraction(string ppm_filename1,string ppm_filename2,string ppm_filename3)
{
	ppmImage obj1,obj2,obj3;
	if(read_ppm(ppm_filename1,obj1)==1 && read_ppm(ppm_filename2,obj2)==1)
	{
		obj3 = obj1 - obj2;
		write_ppm(ppm_filename3,obj3);
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
					temp=image_object_to_be_modified(i,j,2);
					image_object_to_be_modified.set_ppm_g(i,j,image_object_to_be_modified(i,j,1));
					image_object_to_be_modified.set_ppm_r(i,j,temp);
					
					
				}
				else if(swap_choice==2)
				{
					temp=image_object_to_be_modified(i,j,3);
					image_object_to_be_modified.set_ppm_b(i,j,image_object_to_be_modified(i,j,1));
					image_object_to_be_modified.set_ppm_r(i,j,temp);
					
				}
				else if(swap_choice==3)
				{
					temp=image_object_to_be_modified(i,j,3);
					image_object_to_be_modified.set_ppm_b(i,j,image_object_to_be_modified(i,j,2));
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
ppmImage single_color( ppmImage& source,int color_choice)
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
					tmp.set_ppm_r(i,j,source(i,j,1));
					
				}
				if(color_choice==2)
				{
					tmp.set_ppm_g(i,j,source(i,j,2));
					
				}
				if(color_choice==3)
				{
					tmp.set_ppm_b(i,j,source(i,j,3));
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
	
	
	//If no data is sent,the program exits.
	if(argv[2]==NULL || argv[3]==NULL) exit(1);
	else
	{
	string file_name=argv[2];
	string ppl_file_name2=argv[3];
	
	if(choose==1)
	{
		if(argv[4]==NULL) exit(1);
		else
		{
			
			string file_name3=argv[4];
			test_addition(file_name,ppl_file_name2,file_name3);
		}
	}
	//read ppm_file_name using function read_ppm
	//swap red and green channels
	//write the updated data to a file named "o2.ppm". use write_ppm function.
	if(choose==2)
	{
		if(argv[4]==NULL) exit(1);
		else
		{	
			
			string file_name3=argv[4];
			test_substraction(file_name,ppl_file_name2,file_name3);
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
				if(write_ppm(ppl_file_name2,test)==1)
				{
					cout<<ppl_file_name2<<" created.\n";
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
				if(write_ppm(ppl_file_name2,test)==1)
				{
					cout<<ppl_file_name2<<" created.\n";
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
				if(write_ppm(ppl_file_name2,newObj)==1)
				{
					cout<<ppl_file_name2<<" created.\n";
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
			if(write_ppm(ppl_file_name2,newObj)==1)
			{	
				cout<<ppl_file_name2<<" created.\n";
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
			if(write_ppm(ppl_file_name2,newObj)==1)
			{
				cout<<ppl_file_name2<<"created.\n";
			}
		}
	}
	}
}	