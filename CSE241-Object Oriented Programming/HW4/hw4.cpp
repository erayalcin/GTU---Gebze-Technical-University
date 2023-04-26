#include <iostream>
//I kept my class as hex.h in a separate file.
#include "hex.h"
using namespace std;
//I performed the menu operations in my main function.
int main() {

	cout<<endl;
	cout<<endl;
	int select;
	int *game1=nullptr;
	int *game2=nullptr;
	//In the first option, it creates a new game, in the second option, it lists the active games,
	//and in the third option, it shows the non-empty cells in the active games.
	cout << "1.Create a New Game\n";
	cout << "2.List of Active Games and Play a Active Game\n";
	cout << "3.Compare two games\n";
	cout << "Select : ";
	cin >> select;
	cout<<endl;
	cout<<endl;
	if (select == 1) {
		// I created a class object for which you want to create a new game.
		Hex hex;
		hex.playGame();
		activegames.push_back(hex);
		main();

	}
	if(select==2)
	{
		//When you want to see active games and want to continue, you need to enter option number 2,
		//and here is a global vector where I keep my active games, and if there is a game saved in this vector,
		//I print the properties on the screen and I want the user to enter data for whatever game he wants to go to.
		if(activegames.size()>0)
		{
		int cont;
		for(int i=0;i<activegames.size();i++)
		{
			cout<<"--->"<<i+1<<".Game Properties --> Size :"<<activegames[i].getSize()<<"  Selection :"<<activegames[i].getSelect() <<"  User :"<<activegames[i].getUser();
			cout<<endl;
		}
		cout<<"Select game : ";
		cin>>cont;
		//I start that selected game
		cout<<activegames[cont-1].getSize();
		activegames[cont-1].printTable();
		activegames[cont-1].BeforeStartPlaying();
		activegames.push_back(activegames[cont-1]);
		main();
		}
	}
	if(select==3)
	{
		//In option 3, I list the active games and compares the number of non-empty cells of the 2 games entered,
		//and if they are equal, it says equal, if not, which one has more elements.
		int game1,game2;
		if(activegames.size()>=2)
		{
			for(int i=0;i<activegames.size();i++)
					{
						cout<<"--->"<<i+1<<".Game Properties --> Size :"<<activegames[i].getSize()<<"  Selection :"<<activegames[i].getSelect() <<"  User :"<<activegames[i].getUser();
						cout<<endl;
					}
			cout<<"Please select two games that you want  :";
			cin>>game1>>game2;
			Hex h1;
			h1=activegames[game1-1];
			Hex h2;
			h2=activegames[game2-1];
			h1.findNonempty();
			h2.findNonempty();


			if(h1==h2)
			{
				cout<<"Non-empty cell numbers are equal.\n";
			}
			else
			{
				cout<<"Non-empty cell numbers are not equal.\n";
				if(h1>h2)
				{
					cout<<"There are more cells full in game 1 than in game 2.";
					cout<<endl;
				}
				else
				{
					cout<<"There are more cells full in game 2 than in game 1.";
					cout<<endl;
				}
			}


		}
		else
		{
			cerr <<"A minimum of 2 games to be compared are required.\n";
		}

	}
}
//I'm building my getters and setters.
int Hex::getComputerX() const
{
	return computer_x;
}
int Hex::getComputerY() const
{
	return computer_y;
}
int Hex::setComputerX(int x)
{
	computer_x=x;
	return computer_x;
}
int Hex::setComputerY(int y)
{
	computer_y=y;
	return computer_y;
}
int Hex::getSize() const
{
	return size;
}
int Hex::getUser() const
{
	return user;
}
int Hex::getSelect() const
{
	return selection;
}
int Hex::setSize(int a)
{
	size=a;
	return size;
}
int Hex::setUser(int a)
{
	user=a;
	return user;
}
int Hex::setSelect(int a)
{
	selection=a;
	return selection;
}
//I'm counting non-blank cell numbers.
void Hex::findNonempty()
{
	int count=0;
	for(int i=0;i<size;i++)
				{
					for(int j=0;j<size;j++)
					{
						if(hexCells[i][j].getIcon()==120 || hexCells[i][j].getIcon()==111)
						{
							count++;
						}
					}
				}

	nonempty=count;
}
//I am comparing cell numbers.
bool operator >(const Hex &h1,const Hex &h2)
{


	return (h1.nonempty>h2.nonempty);

}
//I am comparing cell numbers .
bool operator==(const Hex &h1,const Hex &h2)
{


	return (h1.nonempty==h2.nonempty);

}
//For back steps I create operator - and go back 2 steps from the array where I kept the steps and remove the user's previous step.
Hex& Hex::operator -- ()
{
	if(k>0)
	{
	--k;
	--k;
	int *a=nullptr;
	int *b=nullptr;
	a=new int;
	b=new int;
	*a=step[k][0];
	*b=step[k][1];
	hexCells[*a][*b].setIcon(46);
	}
	else
	{
		cerr<<"Move not found.\n";
	}
	return *this;
}
//I press my table to the screen by operator overloading.
ostream& operator << (std::ostream &out, const Hex &hex)
{
	int a =hex.size;

			for (int i = 97; i < 123 && a != 0; i++) {
				out << "  " << char(i);
				a--;
			}
			out << "\n";

			for (int i = 0; i < hex.size; i++) {
				out << i + 1;
				for (int k = 0; k < i + 1; k++) {
					out << "  ";
				}
				for (int j = 0; j < hex.size; j++) {
					out << char(hex.hexCells[i][j].getIcon()) << "  ";
				}
				out << "\n";
			}
			out << "\n";

	return out;
}
//I also do operator overloading while saving to file.
ofstream& operator << (ofstream& out, Hex &hex)
{

	out << hex.getSelect() << "\n" << hex.getUser() << "\n"
			<< hex.getSize() << "\n";
	for (int i = 0; i < hex.getSize(); i++) {
				for (int j = 0; j < hex.getSize(); j++) {
					out << char(hex.hexCells[i][j].getIcon());
				}
			}
	return out;
}
//I do the reading from the file with operator overloading.
ifstream& operator >>(ifstream& in, Hex &hex)
{

	int bordersize, select, usernumber;

		int count = 0;
		Hex h1;
		string s;
		//First of all, I open my file and if the file is opened, I do the operations, if not, I give an error.
		if (in.is_open()) {

			//Then I take the first 3 lines one by one, here after taking them one by one,
			//I read them once in order not to get the \ n at the end of each line, then I switch to the 2nd line and reread.
			getline(in,s);
			select=int(s[0]-48);
			h1.setSelect(select);

			getline(in,s);
			usernumber=int(s[0]-48);
			h1.setUser(usernumber);
			getline(in,s);
			bordersize=int(s[0]-48);
			h1.setSize(bordersize);

			int a;
			getline(in,s);

			h1.firstFillTable();
			for(int i=0;i<bordersize;i++)
			{
				for(int j=0;j<bordersize;j++)
				{

					h1.hexCells[i][j].setIcon(int(s[count]));

					count++;
				}
			}
			h1.printTable();
			h1.BeforeStartPlaying();






		} else {
			cerr << "The file could not be opened. " << endl;
		}

}
void Hex::loadFile(string input) {
	//This function loads the saved game. While I was saving in the file,
	ifstream readFile(input);
	readFile >> *this; //I call operator overloading



}
void Hex::saveFile(string path)
{

		//In the file saving process,
		//I send the user who the user is, the table size and the game type to the function you want to save and save.

		ofstream saveFile(path); //To record ofstream, ifstream to read

		saveFile <<*this;


		cout << "Dosya Kaydedildi.\n";
		saveFile.close();
		BeforeStartPlaying();
}
//I create setters and getters.
int Hex::Cell::setRow(int r) {
	row = r;
	return row;
}
int Hex::quit(){
	return quit_check;
}
int Hex::Cell::getRow() const{
	return row;
}
int Hex::Cell::getColumn() const{
	return column;
}
int Hex::Cell::setColumn(int c) {
	column = c;
	return column;
}
int Hex::Cell::getIcon() const{
	return icon;
}
int Hex::Cell::setIcon(int b) {
	icon = b;
	return icon;
}
//I fill table when the game hasn't start
void Hex::firstFillTable() {

	int size=getSize();
	hexCells = new Cell*[size];
	for (int i = 0; i < size; i++) {
		hexCells[i] = new Cell[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			hexCells[i][j].setIcon(46);

		}
	}

}


void Hex::printTable() const {
	cout<<*this;
}
//I create Computer's moves here, I keep the previous steps so that the computer can make a logical step.
int Hex::play() {
	int x, y;
	x = getComputerX();
	y = getComputerY();
	step[k]=new int[2];
	step[k][0]=x;
	step[k][1]=y;
	k=k+1;


	if (x < getSize() && hexCells[x][y].getIcon() == 46) {
		hexCells[x][y].setIcon(111);
		setComputerX(x);
		setComputerY(y);
	} else if (x < getSize() - 1 && hexCells[x + 1][y].getIcon() == 46) {
		hexCells[x + 1][y].setIcon(111);
		setComputerX(x + 1);
		setComputerY(y);

	} else if (x < getSize() - 1 && hexCells[x - 1][y + 1].getIcon() == 46) {
		hexCells[x - 1][y + 1].setIcon(111);
		setComputerX(x - 1);
		setComputerY(y + 1);

	} else if (x < getSize() - 1 && hexCells[x + 1][y - 1].getIcon() == 46) {
		hexCells[x + 1][y - 1].setIcon(111);
		setComputerX(x + 1);
		setComputerY(y - 1);

	} else if (x < getSize() - 1 && hexCells[x][y - 1].getIcon() == 46) {
		hexCells[x][y - 1].setIcon(111);
		setComputerX(x);
		setComputerY(y - 1);

	} else if (x < getSize() - 1 && hexCells[x][y + 1].getIcon() == 46) {
		hexCells[x][y + 1].setIcon(111);
		setComputerX(x);
		setComputerY(y + 1);

	} else if (x < getSize() - 1 && hexCells[x - 1][y].getIcon() == 46) {
		hexCells[x - 1][y].setIcon(111);
		setComputerX(x - 1);
		setComputerY(y);

	} else {
		//If these six cases don't work, I put an O in the first empty place with a for loop.
		for (int i = 0; i < getSize(); i++) {
			for (int j = 0; j < getSize(); j++) {
				if (hexCells[i][j].getIcon() == 46) {
					x = i;
					hexCells[x][j].setIcon(111);

					i = getSize();
					j = getSize();

				}
			}

		}


	}
}
//I do this while filling the array with 0 at first, in which I keep the paths I went while winning.
void Hex::fillSolveArray() {

	int size=getSize();
		solve = new int*[size];
		for (int i = 0; i < size; i++) {
			solve[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				solve[i][j]=0;

			}
		}

}
//I check the winning situation in this function.
int Hex::determineWin(int x, int y) {
	if(user==1)
	{


	if (y == getSize() - 1 && hexCells[x][y].getIcon() == 120) {
		solve[x][y] = 1;
		score=score+10;
		return 1;

	}

	else {
		score=score+10;
		/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place
		 I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
		solve[x][y] = 1;

		/*Since we have 6 cases, I check these cases with if conditions. In this if condition,
		 I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
		if (hexCells[x][y + 1].getIcon() == 120 && solve[x][y + 1] == 0) {
			return determineWin(x, y + 1);
		} else if (x != 0 && hexCells[x - 1][y + 1].getIcon() == 120
				&& solve[x - 1][y + 1] == 0) {

			return determineWin(x - 1, y + 1);
		} else if (x != size - 1 && hexCells[x + 1][y].getIcon() == 120
				&& solve[x + 1][y] == 0) {

			return determineWin(x + 1, y);
		} else if (x != size - 1 && hexCells[x + 1][y - 1].getIcon() == 120
				&& solve[x + 1][y - 1] == 0) {

			return determineWin(x + 1, y - 1);
		} else if (x != 0 && hexCells[x - 1][y].getIcon() == 120
				&& solve[x - 1][y] == 0) {

			return determineWin(x - 1, y);
		} else if (hexCells[x][y - 1].getIcon() == 120
				&& solve[x][y - 1] == 0) {

			return determineWin(x, y - 1);
		} else {
			solve[x][y] = 0;

		}
	}
	return 0;
	}
	if(user==2)
	{
		if (x == getSize() - 1
						&& hexCells[x][y].getIcon()==111) {
					solve[x][y] = 1;
					score=score+10;
					return 1;


				}

				else {
					score=score+10;

					/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place
					 I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
					solve[x][y] = 1;

					/*Since we have 6 cases, I check these cases with if conditions. In this if condition,
					 I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
					if (hexCells[x + 1][y].getIcon()==111
							&& solve[x + 1][y] == 0) {
						return determineWin(x + 1, y);
					} else if (x!=0 && y != size-1  && hexCells[x-1][y + 1].getIcon()==111
							&& solve[x-1][y + 1] == 0) {

						return determineWin(x - 1, y + 1);
					} else if (x!=size - 1 && y != 0
							&& hexCells[x + 1][y - 1].getIcon()==111
							&& solve[x + 1][y - 1] == 0) {

						return determineWin(x + 1, y - 1);
					} else if (y != size -1
							&& hexCells[x + 1][y].getIcon()==111
							&& solve[x + 1][y] == 0) {

						return determineWin(x, y + 1);
					} else if (y != size -1 && hexCells[x][y + 1].getIcon()==111
							&& solve[x][y + 1] == 0) {

						return determineWin(x - 1, y);
					} else if (y!=0 && hexCells[x][y - 1].getIcon()==111
							&&solve[x][y - 1] == 0) {

						return determineWin(x, y - 1);
					} else {
						solve[x][y] = 0;



					}


				}
		return 0;
	}
}
//I fill the table according to the entered coordinate.
void Hex::play(int x, int y) {

	if (user == 1) {

		hexCells[x][y].setIcon(120);
		printTable();
	}
	if (user == 2) {
		hexCells[x][y].setIcon(111);
		printTable();
	}

}
//I get the table coordinates from the user in this function and send it to the play () and play (int x, int y) functions to fill the table.
int Hex::BeforeStartPlaying() {
	string input, input1;
	step[k]=new int[2];
	int winSituation;
	if (getSelect() == 1) {
		if (getUser() == 1) {
			cout << "Please User1 enters coordinate :";
			cin >> input;
			if (input == "save") {
				cin >> input1;
				saveFile(input1);
				BeforeStartPlaying();

			} else if (input == "load") {
				cin >> input1;
				loadFile(input1);



			} else if (input == "quit") {
				quit_check=1;

				return 0;
				//exit
			}else if (input == "undo") {
				--*this;
				printTable();
				BeforeStartPlaying();
			}
			else {

				for (int i = 0; i < getSize(); i++) {
					int a = 97;
					if (char(a + i) == input[0] && int(input[1] - 48) > 0
							&& int(input[1] - 48) <= getSize()) {

						int row = int(input[1] - 48);
						char col = input[0];
						//I check winning situations
						for (int j = 97; j < 123; j++) {

							if ((int) col == j) {
								if (hexCells[row - 1][col - 97].getIcon()
										== 46) {

									step[k][0]=row-1;
									step[k][1]=col-97;

									k=k+1;

									play(row - 1, col - 97);

									for (int k = 0; k < getSize(); k++) {
										if (hexCells[k][0].getIcon() == 120) {

											fillSolveArray();
											score=0;
											winSituation = determineWin(k, 0);

										}
									}
									cout << "1.User Score :"<<score<<endl;
									if (winSituation == 1) {
										for (int i = 0; i < getSize(); i++) {
											for (int j = 0; j < getSize(); j++) {
												if (solve[i][j] == 1) {
													hexCells[i][j].setIcon(88);

												}
											}
										}
										cout << endl;
										printTable();
										cout << endl;
										cout << "<-----> User 1 Win.<----->\n";
										main();
									}

									setUser(2);

								} else {
									cerr
											<< "----> This cell is full.Please select another cell \n";
									BeforeStartPlaying();
								}

							}

						}

					}
					//else BeforeStartPlaying();

				}

			}
		}
		if (getUser() == 2) {
			cout << "Please User2 enters coordinate :";
			cin >> input;
			if (input == "save") {
				cin >> input1;
				saveFile(input1);
				BeforeStartPlaying();

			} else if (input == "load") {
				cin >> input1;

				loadFile(input1);



			} else if (input == "quit") {
				quit_check=1;

				return 0;
				//exit
			}else if (input == "undo") {
				--*this;
				printTable();
				BeforeStartPlaying();
			}
			else {

				for (int i = 0; i < getSize(); i++) {
					int a = 97;
					if (char(a + i) == input[0] && int(input[1] - 48) > 0
							&& int(input[1] - 48) <= getSize()) {

						int row = int(input[1] - 48);
						char col = input[0];
						//I check winning situations
						for (int j = 97; j < 123; j++) {

							if ((int) col == j) {
								if (hexCells[row - 1][col - 97].getIcon()
										== 46) {
									step[k]=new int[2];
									step[k][0]=row-1;
									step[k][1]=col-97;
									k=k+1;
									play(row - 1, col - 97);
									for (int k = 0; k < getSize(); k++) {

										if (hexCells[0][k].getIcon() == 111) {
											score=0;

											fillSolveArray();
											winSituation = determineWin(0, k);


										}
									}
									cout << "2.User Score :"<<score<<endl;
									if (winSituation == 1) {
										for (int i = 0; i < getSize(); i++) {
											for (int j = 0; j < getSize(); j++) {
												if (solve[i][j] == 1) {
													hexCells[i][j].setIcon(79);

												}
											}
										}
										cout << endl;
										printTable();
										cout << endl;
										cout << "<-----> User 1 Win.<----->\n";
										main();
									}
									setUser(1);

									BeforeStartPlaying();

								} else {
									cerr<< "----> This cell is full.Please select another cell \n";
									BeforeStartPlaying();
								}

							}

						}

					}
					//else BeforeStartPlaying();

				}

			}
		}
	}

	if (getSelect() == 2) {
		if (getUser() == 1) {
			cout << "Please User1 enters coordinate :";
			cin >> input;

			if (input == "save") {
				cin >> input1;
				saveFile(input1);
				BeforeStartPlaying();

			} else if (input == "load") {
				cin >> input1;

				loadFile(input1);


			} else if (input == "quit") {
				quit_check=1;

				return 0;
				//exit
			}else if (input == "undo") {
				--*this;
				printTable();
				BeforeStartPlaying();
			}
			else {

				for (int i = 0; i < getSize(); i++) {
					int a = 97;
					if (char(a + i) == input[0] && int(input[1] - 48) > 0
							&& int(input[1] - 48) <= getSize()) {

						int row = int(input[1] - 48);
						char col = input[0];

						//I check winning situations
						for (int j = 97; j < 123; j++) {

							if ((int) col == j) {
								if (hexCells[row - 1][col - 97].getIcon()
										== 46) {

									step[k][0]=row-1;
									step[k][1]=col-97;
									k=k+1;
									play(row - 1, col - 97);

									for (int k = 0; k < getSize(); k++) {
										if (hexCells[k][0].getIcon() == 120) {

											fillSolveArray();
											score=0;
											winSituation = Hex::determineWin(k, 0);

										}
									}


									cout << "1.User Score :"<<score<<endl;

									if (winSituation == 1) {
										for (int i = 0; i < getSize(); i++) {
											for (int j = 0; j < getSize(); j++) {
												if (solve[i][j] == 1) {
													hexCells[i][j].setIcon(88);

												}
											}
										}
										cout << endl;
										printTable();
										cout << endl;
										cout << "<-----> User 1 Win.<----->\n";
										main();
									}

									setUser(2);



								} else {
									cerr
											<< "----> This cell is full.Please select another cell \n";
									BeforeStartPlaying();
								}

							}

						}

					}
					//else BeforeStartPlaying();

				}

			}
		}
		if (getUser()== 2) {
			score=0;
			play();

			for (int k = 0; k < getSize(); k++) {
				if (hexCells[0][k].getIcon() == 111) {

					fillSolveArray();
					winSituation = determineWin(0, k);

				}
			}
			cout << "Computer Score :"<<score<<endl;
			if (winSituation == 1) {
				for (int i = 0; i < getSize(); i++) {
					for (int j = 0; j < getSize(); j++) {
						if (solve[i][j] == 1) {
							hexCells[i][j].setIcon(79);

						}
					}
				}
				cout << endl;
				printTable();
				cout << endl;
				cout << "<-----> Computer Win.<----->\n";
				main();
			}
			setUser(1);
			printTable();
			BeforeStartPlaying();
		}
	}
}
//I also get the table size and game type from this function.
int Hex::playGame() {

	int size,select;
	cout << "Welcome " << endl;
	cout << "Please enter the table size :";

	cin >> size;
	setSize(size);
	if (size < 5) {
		cerr << "\nWrong size. Please enter correct size \n\n ";
		main();

	} else {

		cout << "\n1 - > User vs User :\n";
		cout << "2 - > User vs Computer :\n";
		cout << "Select - >";
		cin >> select;
		cout<<select;
		firstFillTable();
		printTable();
		setUser(1);
		setSelect(select);

		if (getSelect() == 1) {
			BeforeStartPlaying();
			return 0;
		}
		if (getSelect() == 2) {
			computer_x = 0;
			computer_y = 0;
			BeforeStartPlaying();
			return 0;
		}

	}
}

