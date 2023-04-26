#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
//I am creating my template classes. I created 3 separate template classes for books, music and movies.
//I only used setters and getters in my classes, I didn't need any extra functions. I did my file reading and writing operations in main.
//           ------------------------ MOVIE CLASS ----------------------------------------
template <class T1,class T2,class T3,class T4,class T5>
class movie {
	private:
    T1 title;
    T2 director;
    T3 year;
    T4 genre;
    T5 starring;
  public:
  	movie()
  	{

  	}
    movie (T1 n_Title, T2 n_director,T3 n_year,T4 n_genre,T5 n_starring)
      {title=n_Title; director=n_director; year=n_year; genre=n_genre; starring=n_starring;}
      //GETTERS
    T1 getTitle ();
    T2 getDirector ();
    T3 getYear ();
    T4 getGenre ();
    T5 getStarring();
    //SETTERS
    void setTitle (T1 n_Title);
    void setDirector (T2 n_director);
    void setYear (T3 n_year);
    void setGenre (T4 n_genre);
    void setStarring (T5 n_starring);
};
//GETTERS
template <class T1,class T2,class T3,class T4,class T5>
T1 movie<T1,T2,T3,T4,T5>::getTitle ()
{
  return title;
}
template <class T1,class T2,class T3,class T4,class T5>
T2 movie<T1,T2,T3,T4,T5>::getDirector ()
{
  return director;
}
template <class T1,class T2,class T3,class T4,class T5>
T3 movie<T1,T2,T3,T4,T5>::getYear ()
{
  return year;
}
template <class T1,class T2,class T3,class T4,class T5>
T4 movie<T1,T2,T3,T4,T5>::getGenre ()
{
  return genre;
}
template <class T1,class T2,class T3,class T4,class T5>
T5 movie<T1,T2,T3,T4,T5>::getStarring ()
{
  return starring;
}
//SETTERS 
template <class T1,class T2,class T3,class T4,class T5>
void movie<T1,T2,T3,T4,T5>::setTitle(T1 n_Title)
{
	title = n_Title;
}
template <class T1,class T2,class T3,class T4,class T5>
void movie<T1,T2,T3,T4,T5>::setDirector(T2 n_director)
{
    director = n_director;
}
template <class T1,class T2,class T3,class T4,class T5>
void movie<T1,T2,T3,T4,T5>::setYear(T3 n_year)
{
    year = n_year;
}
template <class T1,class T2,class T3,class T4,class T5>
void movie<T1,T2,T3,T4,T5>::setGenre(T4 n_genre)
{
	genre = n_genre;
}
template <class T1,class T2,class T3,class T4,class T5>
void movie<T1,T2,T3,T4,T5>::setStarring(T5 n_starring)
{
	starring = n_starring;
}
//I am creating my template classes. I created 3 separate template classes for books, music and movies.
//I only used setters and getters in my classes, I didn't need any extra functions. I did my file reading and writing operations in main.
//           ------------------------ MUSIC CLASS ----------------------------------------
template <class T1,class T2,class T3,class T4>
class music {
	private:
    T1 title;
    T2 artists;
    T3 year;
    T4 genre;
  public:
  	music()
  	{

  	}
    music (T1 n_Title, T2 n_artists,T3 n_year,T4 n_genre)
      {title=n_Title; artists=n_artists; year=n_year; genre=n_genre;}
      //GETTERS
    T1 getTitle ();
    T2 getArtists ();
    T3 getYear ();
    T4 getGenre ();
    //SETTERS
    void setTitle (T1 n_Title);
    void setArtists (T2 n_artists);
    void setYear (T3 n_year);
    void setGenre (T4 n_genre);
};
//GETTERS
template <class T1,class T2,class T3,class T4>
T1 music<T1,T2,T3,T4>::getTitle ()
{
  return title;
}
template <class T1,class T2,class T3,class T4>
T2 music<T1,T2,T3,T4>::getArtists ()
{
  return artists;
}
template <class T1,class T2,class T3,class T4>
T3 music<T1,T2,T3,T4>::getYear ()
{
  return year;
}
template <class T1,class T2,class T3,class T4>
T4 music<T1,T2,T3,T4>::getGenre ()
{
  return genre;
}
//SETTERS
template <class T1,class T2,class T3,class T4>
void music<T1,T2,T3,T4>::setTitle(T1 n_Title)
{
	title = n_Title;
}
template <class T1,class T2,class T3,class T4>
void music<T1,T2,T3,T4>::setArtists(T2 n_artists)
{
    artists = n_artists;
}
template <class T1,class T2,class T3,class T4>
void music<T1,T2,T3,T4>::setYear(T3 n_year)
{
    year = n_year;
}
template <class T1,class T2,class T3,class T4>
void music<T1,T2,T3,T4>::setGenre(T4 n_genre)
{
	genre = n_genre;
}
//I am creating my template classes. I created 3 separate template classes for books, music and movies.
//I only used setters and getters in my classes, I didn't need any extra functions. I did my file reading and writing operations in main.
//           ------------------------ BOOK CLASS ----------------------------------------
template <class T1,class T2,class T3,class T4>
class book {
	private:
    T1 title;
    T2 authors;
    T3 year;
    T4 tags;
  public:
  	book()
  	{

  	}
    book (T1 n_Title, T2 n_authors,T3 n_year,T4 n_tags)
      {title=n_Title; authors=n_authors; year=n_year; tags=n_tags;}
    //GETTERS
    T1 getTitle ();
    T2 getAuthors ();
    T3 getYear ();
    T4 getTags ();
    //SETTERS
    void setTitle (T1 n_Title);
    void setAuthors (T2 n_authors);
    void setYear (T3 n_year);
    void setTags (T4 n_tags);
};
//GETTERS
template <class T1,class T2,class T3,class T4>
T1 book<T1,T2,T3,T4>::getTitle ()
{
  return title;
}
template <class T1,class T2,class T3,class T4>
T2 book<T1,T2,T3,T4>::getAuthors ()
{
  return authors;
}
template <class T1,class T2,class T3,class T4>
T3 book<T1,T2,T3,T4>::getYear ()
{
  return year;
}
template <class T1,class T2,class T3,class T4>
T4 book<T1,T2,T3,T4>::getTags ()
{
  return tags;
}
//SETTERS
template <class T1,class T2,class T3,class T4>
void book<T1,T2,T3,T4>::setTitle(T1 n_Title)
{
	title = n_Title;
}
template <class T1,class T2,class T3,class T4>
void book<T1,T2,T3,T4>::setAuthors(T2 n_authors)
{
    authors = n_authors;
}
template <class T1,class T2,class T3,class T4>
void book<T1,T2,T3,T4>::setYear(T3 n_year)
{
    year = n_year;
}
template <class T1,class T2,class T3,class T4>
void book<T1,T2,T3,T4>::setTags(T4 n_tags)
{
	tags = n_tags;
}
   
int main()
{
	
	//I am creating separate objects within 3 classes. I decide which object I will use when processing according to the catalog name in the file.
	vector<book<string,string,int,string>> bookvector;
	vector<music<string,string,int,string>> musicvector;
	vector<movie<string,string,int,string,string>> movievector;
	string catalog_name;
	string temp;
	int counter=0;
	//Open Files
	ifstream readData("data.txt");
	ofstream writeOutput("output.txt");
	int count=0,check=0;
	if(readData.is_open())
	{
		
			getline(readData,catalog_name);
			//I am operating according to the catalogues, the first line says which catalog will work, 
			//and then I take that first line and check it with if, then I do the reading.
			if(catalog_name=="book")
			{
				
					bookvector.clear();
				while(!readData.eof())
				{
					book<string,string,int,string> test;
					//For example, since there are 4 data for the book, I take this forla and do the same operation 4 times.
					for(int i=0;i<4;i++)
					{
						getline(readData,temp,'"');
						getline(readData,temp,'"');
						//I'm doing error checking here, if the object I created exists in the object, I do exception handling.
						if(i==0)
						{
							test.setTitle(temp);
							try{
							if(temp == "")
							{
								throw(1);
							}
							else
							{

							
							try {
							for (int i = 0; i < bookvector.size(); ++i)
							{
								if (temp==bookvector[i].getTitle()  ) {

							   	throw(1);   
							    } 
							  
							}
							}
							//Duplicate entry
							catch(int num)
							{
								writeOutput<<"Exception:duplicate entry\n";
								check=1;
							}
							}
							}
							//missing field
							catch(int n)
							{
								writeOutput<<"Exception:missing field"<<endl;
								check=1;
							}
						}
						//Save Authors
						if(i==1)
						{
							test.setAuthors(temp);
						}//Save year
						if(i==2)
						{
							stringstream yrs(temp);
							int year=0;
							yrs>>year;
							test.setYear(year);
						}//Save tags
						if(i==3)
						{
							test.setTags(temp);
						}
						

					}//If we have no errors and it is not the end of the file, I save it to vector and print it to our output file.
					if(!readData.eof() && check==0 )
					{
						bookvector.push_back(test);
						writeOutput<<'"'<<bookvector[counter].getTitle()<<'"'<< " ";
						writeOutput<<'"'<<bookvector[counter].getAuthors()<<'"'<<" ";
						writeOutput<<'"'<<bookvector[counter].getYear()<<'"'<<" ";
						writeOutput<<'"'<<bookvector[counter].getTags()<<'"'<<" ";
						writeOutput<<endl;
						counter++;
					}
					check=0;
					
					
				}
				//I write number of entries 
				writeOutput<<bookvector.size()<<" unique entries"<<endl;
				
				
				
			}
			//I am operating according to the catalogues, the first line says which catalog will work, 
			//and then I take that first line and check it with if, then I do the reading.
			//We do the same operations in the Music catalog.
			if(catalog_name=="music")
			{
				writeOutput<<"Catalog Read:"<<catalog_name<<endl;
				musicvector.clear();
				while(!readData.eof())
				{
					music<string,string,int,string> test;
					for(int i=0;i<4;i++)//For example, since there are 4 data for the book, I take this forla and do the same operation 4 times.
					{
						getline(readData,temp,'"');
						getline(readData,temp,'"');
						
						if(i==0)
						{
							test.setTitle(temp);
							//I'm doing error checking here, if the object I created exists in the object, I do exception handling.
							try{
							if(temp == "")
							{
								throw(1);
							}
							else
							{

							
							try {
							for (int i = 0; i < musicvector.size(); ++i)
							{
								if (temp==musicvector[i].getTitle()  ) {

							   	throw(1);   
							    } 
							  
							}
							}
							catch(int num)
							{
								writeOutput<<"Exception:duplicate entry\n";
								check=1;
							}
							}
							}
							catch(int n)
							{
								writeOutput<<"Exception:missing field"<<endl;
								check=1;
							}
						}
						if(i==1)
						{
							test.setArtists(temp);
						}
						if(i==2)
						{
							stringstream yrs(temp);
							int year=0;
							yrs>>year;
							test.setYear(year);
						}
						if(i==3)
						{
							test.setGenre(temp);

						}
						

					}//If we have no errors and it is not the end of the file, I save it to vector and print it to our output file
					if(!readData.eof() && check==0 )
					{
							musicvector.push_back(test);
						writeOutput<<'"'<<musicvector[counter].getTitle()<<'"'<< " ";
						writeOutput<<'"'<<musicvector[counter].getArtists()<<'"'<<" ";
						writeOutput<<'"'<<musicvector[counter].getYear()<<'"'<<" ";
						writeOutput<<'"'<<musicvector[counter].getGenre()<<'"'<<" ";
						writeOutput<<endl;
						counter++;
					}
					check=0;

				
					
						
					
					
					
					
				}//I write number of entries
				writeOutput<<musicvector.size()<<" unique entries"<<endl;

				
			}
			//I am operating according to the catalogues, the first line says which catalog will work, 
			//and then I take that first line and check it with if, then I do the reading.
			//We do the same operations in the Movie catalog.
			if(catalog_name=="movie")
			{
				
				movievector.clear();
				while(!readData.eof())
				{
					movie<string,string,int,string,string> test;
					for(int i=0;i<5;i++)//For example, since there are 4 data for the movie, I take this forla and do the same operation 5 times.
					{
						getline(readData,temp,'"');
						getline(readData,temp,'"');
						
						if(i==0)
						{
							test.setTitle(temp);
							try{//I'm doing error checking here, if the object I created exists in the object, I do exception handling.
							if(temp == "")
							{
								throw(1);
							}
							else
							{

							
							try {
							for (int i = 0; i < movievector.size(); ++i)
							{
								if (temp==movievector[i].getTitle()  ) {

							   	throw(1);   
							    } 
							  
							}
							}
							catch(int num)
							{
								writeOutput<<"Exception:duplicate entry\n";
								check=1;
							}
							}
							}
							catch(int n)
							{
								writeOutput<<"Exception:missing field"<<endl;
								check=1;
							}
						}
						if(i==1)
						{
							test.setDirector(temp);
						}
						if(i==2)
						{
							stringstream yrs(temp);
							int year=0;
							yrs>>year;
							test.setYear(year);
						}
						if(i==3)
						{
							test.setGenre(temp);
						}
						if(i==4)
						{
							test.setStarring(temp);
						}
						

					}
					if(!readData.eof() && check==0 )//If we have no errors and it is not the end of the file, I save it to vector and print it to our output file
					{
							movievector.push_back(test);
						writeOutput<<'"'<<movievector[counter].getTitle()<<'"'<< " ";
						writeOutput<<'"'<<movievector[counter].getDirector()<<'"'<<" ";
						writeOutput<<'"'<<movievector[counter].getYear()<<'"'<<" ";
						writeOutput<<'"'<<movievector[counter].getGenre()<<'"'<<" ";
						writeOutput<<'"'<<movievector[counter].getStarring()<<'"'<<" ";
						writeOutput<<endl;
						counter++;
					}
					check=0;
					
					
				}
				writeOutput<<movievector.size()<<" unique entries"<<endl;
				
			}
		
		
	}
	//I'm reading the commands to do. I didn't do it because I couldn't train the sort command, but I did the search command.

	ifstream readCommand("command.txt");
	string command,word,field,new_tmp;
	if(readCommand.is_open())
	{

		readCommand>>command;
		
		if(command == "search")
		{
			getline(readCommand,new_tmp,'"');
			getline(readCommand,word,'"');
			getline(readCommand,new_tmp,'"');
			getline(readCommand,field,	'"');
		}
		
	}
	//After reading the command, I save the field and the word, and then we check the fields in our array one by one.
	try
	{
		//We are looking for the word to search in artists.
		if(field=="artists")
		{
			writeOutput<<command<<" "<<'"'<<word<<'"'<<" "<<"in "<<field<<endl;
			for (int i = 0; i < musicvector.size(); ++i)
			{
				
				if(musicvector[i].getArtists().find(word) !=std::string::npos) //If there is, I print whichever line is in the output file by pulling it from the vector.
				{
					writeOutput<<'"'<<musicvector[i].getTitle()<<'"'<< " ";
					writeOutput<<'"'<<musicvector[i].getArtists()<<'"'<<" ";
					writeOutput<<'"'<<musicvector[i].getYear()<<'"'<<" ";
					writeOutput<<'"'<<musicvector[i].getGenre()<<'"'<<" ";
					writeOutput<<endl;
				}
			}
		}
		//We are looking for the word to search in authors.
		else if(field=="authors")
		{
			for (int i = 0; i < bookvector.size(); ++i)
			{
				if(bookvector[i].getAuthors().find(word) !=std::string::npos) ////If there is, I print whichever line is in the output file by pulling it from the vector.
				{
					writeOutput<<'"'<<bookvector[i].getTitle()<<'"'<< " ";
					writeOutput<<'"'<<bookvector[i].getAuthors()<<'"'<<" ";
					writeOutput<<'"'<<bookvector[i].getYear()<<'"'<<" ";
					writeOutput<<'"'<<bookvector[i].getTags()<<'"'<<" ";
					writeOutput<<endl;
				}
			}
		}
		//We are looking for the word to search
		else if(field=="tags")
		{
			for (int i = 0; i < bookvector.size(); ++i)
			{
				if(bookvector[i].getTags().find(word) !=std::string::npos) ////If there is, I print whichever line is in the output file by pulling it from the vector.
				{
					writeOutput<<'"'<<bookvector[i].getTitle()<<'"'<< " ";
					writeOutput<<'"'<<bookvector[i].getAuthors()<<'"'<<" ";
					writeOutput<<'"'<<bookvector[i].getYear()<<'"'<<" ";
					writeOutput<<'"'<<bookvector[i].getTags()<<'"'<<" ";
					writeOutput<<endl;
				}
			}
		}
		//We are looking for the word to search
		else if(field=="starring")
		{
			for (int i = 0; i < movievector.size(); ++i)
			{
				if(movievector[i].getStarring().find(word) !=std::string::npos) ////If there is, I print whichever line is in the output file by pulling it from the vector.
				{
					writeOutput<<'"'<<movievector[i].getTitle()<<'"'<< " ";
					writeOutput<<'"'<<movievector[i].getDirector()<<'"'<<" ";
					writeOutput<<'"'<<movievector[i].getYear()<<'"'<<" ";
					writeOutput<<'"'<<movievector[i].getGenre()<<'"'<<" ";
					writeOutput<<'"'<<movievector[i].getStarring()<<'"'<<" ";
					writeOutput<<endl;
				}
			}
		}
		//We are looking for the word to search
		else if(field=="genre")
		{
			for (int i = 0; i < movievector.size(); ++i)
			{
				if(movievector[i].getGenre().find(word) !=std::string::npos)////If there is, I print whichever line is in the output file by pulling it from the vector.
				{
					writeOutput<<'"'<<movievector[i].getTitle()<<'"'<< " ";
					writeOutput<<'"'<<movievector[i].getDirector()<<'"'<<" ";
					writeOutput<<'"'<<movievector[i].getYear()<<'"'<<" ";
					writeOutput<<'"'<<movievector[i].getGenre()<<'"'<<" ";
					writeOutput<<'"'<<movievector[i].getStarring()<<'"'<<" ";
					writeOutput<<endl;
				}
			}
			for (int i = 0; i < musicvector.size(); ++i)
			{
				
				if(musicvector[i].getGenre().find(word) !=std::string::npos)////If there is, I print whichever line is in the output file by pulling it from the vector.
				{
					writeOutput<<'"'<<musicvector[i].getTitle()<<'"'<< " ";
					writeOutput<<'"'<<musicvector[i].getArtists()<<'"'<<" ";
					writeOutput<<'"'<<musicvector[i].getYear()<<'"'<<" ";
					writeOutput<<'"'<<musicvector[i].getGenre()<<'"'<<" ";
					writeOutput<<endl;
				}
			}
		}
		//We are looking for the word to search
		else if(field=="title")
		{
			for (int i = 0; i < bookvector.size(); ++i)
			{
				if(bookvector[i].getTitle().find(word) !=std::string::npos)//If there is, I print whichever line is in the output file by pulling it from the vector.
				{
					writeOutput<<'"'<<bookvector[i].getTitle()<<'"'<< " ";
					writeOutput<<'"'<<bookvector[i].getAuthors()<<'"'<<" ";
					writeOutput<<'"'<<bookvector[i].getYear()<<'"'<<" ";
					writeOutput<<'"'<<bookvector[i].getTags()<<'"'<<" ";
					writeOutput<<endl;
				}
			}
			for (int i = 0; i < movievector.size(); ++i)
			{
				if(movievector[i].getTitle().find(word) !=std::string::npos)//If there is, I print whichever line is in the output file by pulling it from the vector.
				{
					writeOutput<<'"'<<movievector[i].getTitle()<<'"'<< " ";
					writeOutput<<'"'<<movievector[i].getDirector()<<'"'<<" ";
					writeOutput<<'"'<<movievector[i].getYear()<<'"'<<" ";
					writeOutput<<'"'<<movievector[i].getGenre()<<'"'<<" ";
					writeOutput<<'"'<<movievector[i].getStarring()<<'"'<<" ";
					writeOutput<<endl;
				}
			}
			for (int i = 0; i < musicvector.size(); ++i)
			{
				
				if(musicvector[i].getTitle().find(word) !=std::string::npos)//If there is, I print whichever line is in the output file by pulling it from the vector.
				{
					writeOutput<<'"'<<musicvector[i].getTitle()<<'"'<< " ";
					writeOutput<<'"'<<musicvector[i].getArtists()<<'"'<<" ";
					writeOutput<<'"'<<musicvector[i].getYear()<<'"'<<" ";
					writeOutput<<'"'<<musicvector[i].getGenre()<<'"'<<" ";
					writeOutput<<endl;
				}
			}
	}
	else
	{
		throw(1);
	}
	}
	//We handle all error messages with exception handling.
	catch(int n) //If the command is not correct, we print the wrong command to the output file.
	{
		writeOutput<<"Exception: command is wrong"<<endl;
	}

	
	





}