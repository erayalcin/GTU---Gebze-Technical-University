#ifndef HEX_H
#define HEX_H
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
//I keep my class in .h file
using namespace std;
class Hex {

public:
	class Cell {
		private:
			int row, column, icon;
		public:
			int getRow()const;
			int getColumn()const;
			int getIcon()const;
			int setRow(int r);
			int setColumn(int c);
			int setIcon(int b);
		};

	explicit Hex(){}
	~Hex( )
	{
		delete[] hexCells;
	}
	int **solve;
	void printTable() const ;
	int getSelect() const;
	int setSelect(int a);
	int getSize() const;
	int getUser() const;
	int setUser(int a);
	int setSize(int a);
	int getComputerX() const;
	int getComputerY() const;
	int setComputerX(int x);
	int setComputerY(int y);
	int playGame();
	void loadFile(string input);
	int **step=new int*[1000];
	void firstFillTable();
	friend bool operator==(const Hex &h1,const Hex &h2);
	friend bool operator >(const Hex &h1,const Hex &h2);
	Hex& operator--();
	void findNonempty();
	void fillSolveArray();
	void play(int x, int y);
	void saveFile(string path);
	friend ostream& operator<< (std::ostream &out, const Hex &hex);
	friend ofstream& operator << (ofstream& in, Hex &hex);
	friend ifstream& operator >>(ifstream& in,Hex &hex);
	int determineWin(int x, int y);
	int play();
	int quit();
	int BeforeStartPlaying();
	int quit_check=0,k=0,nonempty,score=0;


private:
	int z;
	int selection, size, user,computer_x, computer_y;
	Cell ** hexCells;
};
vector<Hex> activegames;


#endif
