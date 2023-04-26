//============================================================================
// Name        : hw3.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <fstream>

#include <iostream>
#include <vector>
using namespace std;

//I define Class I and then I create another class called Cell that creates cells in it and I create a 2d vector.
class Hex {

public:

	void user1();
	void playGame();
	 static int counthexcell(int a);
	void firstFillTable(int size);
	void printTable()const;
	int play();
	int play(int size, int selection, int user);
	void saveFile();
	void loadFile();
	int fillSolveArray();

	int determineWin(int x, int y);
	static int NumberofCell;
	class Cell {
	public:
		int winner = 0;

		int user;
		int size;

		vector<vector<int> > solve;
		int selection;
		char col;
		string path;
		int row;
		int load_check;
		void selectmenu();
		int input_size();
		int get_computer_x();
		int get_computer_y();
		int input_size(int boardsize);
		int input_selection(int i_selection);
		int input_user(int i_user);
		int input_computer_x(int i);
		int input_computer_y(int j);
		string input_path(string i_path);
		int input_loadcheck(int check);

		enum icon {
			Lowerx = 120, Lowero = 111, Uppero = 79, UpperX = 88, dot = 46
		};
	private:
		int computer_x;
		int computer_y;
	};

	Cell cell_class;

private:
	vector<vector<int> > hexCells;


} load;
//Global vector where I keep active games
vector<Hex> activegames;
//In this function, I print non-blank cell numbers in active games. This function works as much as there are active games.
int Hex::counthexcell(int a)
{
	int sum=0;

	for(int k=0;k<activegames[a].hexCells.size();k++)
						{
							for(int j=0;j<activegames[a].hexCells.size();j++)
							{

								if(activegames[a].hexCells[k][j]!=46)
								{
									sum++;
								}
							}
						}



	return sum;

}


string Hex::Cell::input_path(string i_path) {
	path = i_path;
	return path;
}
/*First, I press the menu in the main function to the screen,
 * then I create a Hex vector globally and save the object of the game I create into this global vector.
 * I am listing this from the global vector I use when showing active games.
 * The reason I keep a vector is that the user can open as many games as they want and there is no limit to it,
 so it made more sense to me than to create one object by hand.*/
int main() {

	int select, game,game1,sum=0;
	//In the first option, it creates a new game, in the second option, it lists the active games,
	//and in the third option, it shows the non-empty cells in the active games.
	cout << "1.Create a New Game\n";
	cout << "2.List of Active Games\n";
	cout << "3.Compare two games";
	cout << "Select : ";
	cin >> select;
	if (select == 1) {

		Hex hex_1;
		hex_1.playGame();
		hex_1.firstFillTable(hex_1.cell_class.input_size());
		hex_1.cell_class.input_computer_x(0);
		hex_1.cell_class.input_computer_y(0);
		hex_1.play(hex_1.cell_class.size, hex_1.cell_class.selection,
				hex_1.cell_class.user);

		if (hex_1.cell_class.winner != 1) {
			activegames.push_back(hex_1);
			if (load.cell_class.load_check == 1) {
				activegames.push_back(load);
			}

			main();
		}

	} else if (select == 2) {
		if(activegames.size()==0)
		{
			cerr<<"No active games. \n";
		}
		else
		{


		for (int i = 0; i < activegames.size(); i++) {
			cout << i + 1 << "---> Games\n";

		}
		cout << "Select to continue a game  : ";
		cin >> game;

		activegames[game - 1].play(activegames[game - 1].cell_class.size,
				activegames[game - 1].cell_class.selection,
				activegames[game - 1].cell_class.user);
		//Here I encountered a problem while loading, I saw that when I exit the loaded game and enter data,
		//it does not save the data I have made, so I check it with the check variable.
		if (load.cell_class.load_check == 1) {
			activegames.push_back(load);
		}
		}

	} else if (select == 3) {

		for(int i=0;i<activegames.size();i++)
						{
				cout<<"Sum of non-empties cell in "<<i+1<<".active game : "<<Hex::counthexcell(i)<<endl;
						}









	}

}
//Here I am creating the vector that I will use when checking whether I win or not.I fill this vector with 0
int Hex::fillSolveArray() {

	vector<int> v1;

	for (int i = 0; i < cell_class.size; i++) {
		for (int j = 0; j < cell_class.size; j++) {
			v1.push_back(0);

		}
		cell_class.solve.push_back(v1);

	}
}
int Hex::determineWin(int x, int y) {

	if (cell_class.user == 1) {

		if (y == cell_class.size - 1
				&& hexCells[x][y] == cell_class.icon::Lowerx) {
			Hex::cell_class.solve[x][y] = 1;
			cell_class.winner = 1;

		}

		else {

			/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place
			 I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
			cell_class.solve[x][y] = 1;

			/*Since we have 6 cases, I check these cases with if conditions. In this if condition,
			 I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
			if (hexCells[x][y + 1] == cell_class.icon::Lowerx
					&& Hex::cell_class.solve[x][y + 1] == 0) {
				determineWin(x, y + 1);
			} else if (x != 0
					&& hexCells[x - 1][y + 1] == cell_class.icon::Lowerx
					&& cell_class.solve[x - 1][y + 1] == 0) {

				determineWin(x - 1, y + 1);
			} else if (x != cell_class.size-1
					&& hexCells[x + 1][y] == cell_class.icon::Lowerx
					&& Hex::cell_class.solve[x + 1][y] == 0) {

				determineWin(x + 1, y);
			} else if (x != cell_class.size-1
					&& hexCells[x + 1][y - 1] == cell_class.icon::Lowerx
					&& cell_class.solve[x + 1][y - 1] == 0) {

				determineWin(x + 1, y - 1);
			} else if (x != 0 && hexCells[x - 1][y] == cell_class.icon::Lowerx
					&& Hex::cell_class.solve[x - 1][y] == 0) {

				determineWin(x - 1, y);
			} else if (hexCells[x][y - 1] == cell_class.icon::Lowerx
					&& Hex::cell_class.solve[x][y - 1] == 0) {

				determineWin(x, y - 1);
			} else {
				Hex::cell_class.solve[x][y] = 0;
				cell_class.winner = 0;

			}
		}
	} else if (cell_class.user == 2) {

		if (x == cell_class.size - 1
				&& hexCells[x][y] == cell_class.icon::Lowero) {
			Hex::cell_class.solve[x][y] = 1;
			cell_class.winner = 1;

		}

		else {

			cout<<x<<" :"<<y;
			/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place
			 I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
			cell_class.solve[x][y] = 1;

			/*Since we have 6 cases, I check these cases with if conditions. In this if condition,
			 I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
			if (hexCells[x + 1][y] == cell_class.icon::Lowero
					&& cell_class.solve[x + 1][y] == 0) {
				determineWin(x + 1, y);
			} else if (x!=0 && y != cell_class.size-1  && hexCells[x-1][y + 1] == cell_class.icon::Lowero
					&& cell_class.solve[x-1][y + 1] == 0) {

				determineWin(x - 1, y + 1);
			} else if (x!=cell_class.size - 1 && y != 0
					&& hexCells[x + 1][y - 1] == cell_class.icon::Lowero
					&& cell_class.solve[x + 1][y - 1] == 0) {

				determineWin(x + 1, y - 1);
			} else if (y != cell_class.size -1
					&& hexCells[x + 1][y] == cell_class.icon::Lowero
					&& cell_class.solve[x + 1][y] == 0) {

				determineWin(x, y + 1);
			} else if (y != cell_class.size -1 && hexCells[x][y + 1] == cell_class.icon::Lowero
					&& cell_class.solve[x][y + 1] == 0) {

				determineWin(x - 1, y);
			} else if (y!=0 && hexCells[x][y - 1] == cell_class.icon::Lowero
					&& cell_class.solve[x][y - 1] == 0) {

				determineWin(x, y - 1);
			} else {
				cell_class.solve[x][y] = 0;

				cell_class.winner = 0;

			}


		}
	}
}
//Here, since I cannot access variables that are private, I have them return with a function.
int Hex::Cell::input_computer_x(int i) {
	computer_x = i;
	return computer_x;
}
int Hex::Cell::input_computer_y(int j) {
	computer_x = j;
	return computer_x;
}
int Hex::Cell::get_computer_x() {

	return computer_x;
}
int Hex::Cell::get_computer_y() {

	return computer_x;
}
//Here, on the uservscomputer, where I created the computer steps,
//I also send the computer steps as user 2 to determineWin and check them.
int Hex::play() {
	int size = cell_class.size;
	int x = cell_class.get_computer_x();
	int y =  cell_class.get_computer_y();


	if (hexCells[x][y] == cell_class.icon::dot) {
		hexCells[x][y] = cell_class.icon::Lowero;
		cell_class.input_computer_x(x);
		cell_class.input_computer_y(y);
	} else if (x != cell_class.size-1
			&& hexCells[x + 1][y] == cell_class.icon::dot) {
		hexCells[x + 1][y] = cell_class.icon::Lowero;
		cell_class.input_computer_x(x+1);
		cell_class.input_computer_y(y);

	} else if (y != cell_class.size-1
			&& x != 0 && hexCells[x - 1][y + 1] == cell_class.icon::dot) {
		hexCells[x - 1][y + 1] = cell_class.icon::Lowero;
		cell_class.input_computer_x(x-1);
		cell_class.input_computer_y(y+1);

	} else if (x != cell_class.size-1
			&& y != 0 && hexCells[x + 1][y - 1] == cell_class.icon::dot) {
		hexCells[x + 1][y - 1] = cell_class.icon::Lowero;
		cell_class.input_computer_x(x+1);
		cell_class.input_computer_y(y-1);

	} else if (y != 0 && hexCells[x][y - 1] == cell_class.icon::dot) {
		hexCells[x][y - 1] = cell_class.icon::Lowero;
		cell_class.input_computer_x(x);
		cell_class.input_computer_y(y-1);

	} else if (y!=cell_class.size -1 && hexCells[x][y + 1] == cell_class.icon::dot) {
		hexCells[x][y + 1] = cell_class.icon::Lowero;
		cell_class.input_computer_x(x);
		cell_class.input_computer_y(y+1);

	} else if (x!=0 && hexCells[x - 1][y] == cell_class.icon::dot) {
		hexCells[x - 1][y] = cell_class.icon::Lowero;
		cell_class.input_computer_x(x-1);
		cell_class.input_computer_y(y);

	} else {
		//If these six cases don't work, I put an O in the first empty place with a for loop.
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (hexCells[i][j] == cell_class.icon::dot) {
					x = i;
					hexCells[x][j] = cell_class.icon::Lowero;
					cell_class.input_computer_x(x);
					cell_class.input_computer_y(j);
					j=size;
					i=size;


				}
			}

		}
		//I check winning situations
		for (int k = 0; k < cell_class.size; k++) {
			if (hexCells[0][k] == 111) {
			cell_class.solve.clear();
			fillSolveArray();
			cell_class.user = 2;
			determineWin(0, k);



			}
		}

		if (cell_class.winner == 1 && cell_class.user == 2) {
									for (int i = 0; i < cell_class.solve.size(); i++) {
										for (int j = 0; j < cell_class.solve.size(); j++) {
											if (cell_class.solve[i][j] == 1) {
												hexCells[i][j] = cell_class.icon::Uppero;
											}
										}
									}
									cout << endl;
									printTable();
									cout << endl;
									cout << "User 2 win.\n";
									main();

								} else {
									cell_class.user = 1;

									//play(cell_class.size, cell_class.selection, cell_class.user);
								}

	}



}
void Hex::loadFile() {
	//This function loads the saved game. While I was saving in the file,
	//I printed the game type (uservsuser or uservscomputer) on the first line, and then on the 2nd line,
	//I printed the table size on the 3rd line, which user belongs to.
	//I printed the output of the table on the 4th line.

	char c;

	ifstream readFile(cell_class.path);

	int bordersize, select, usernumber;
	auto row = 0;
	auto count = 0;

	//First of all, I open my file and if the file is opened, I do the operations, if not, I give an error.
	if (readFile.is_open()) {

		//Then I take the first 3 lines one by one, here after taking them one by one,
		//I read them once in order not to get the \ n at the end of each line, then I switch to the 2nd line and reread.
		readFile.get(c);
		select = c - 48;
		cout << "a  :" << c;
		readFile.get(c);
		readFile.get(c);
		usernumber = c - 48;
		cout << "a  :" << c;
		readFile.get(c);
		readFile.get(c);
		cout << "a  :" << c;
		bordersize = c - 48;
		readFile.get(c);
		//The value I get here can be ten digits, so I used such a function.
		if (c != '\n') {
			bordersize = (bordersize * 10) + ((int) c - 48);
			readFile.get(c);
		}

		int loadhex[bordersize][bordersize];

		while (readFile.get(c)) {
			if (c == '\n') {
				break;
			} else {
				if (row != bordersize) {

					loadhex[row][count] = int(c);
					if (count == bordersize - 1) {
						count = 0;
						row++;
					} else
						count++;

				}
			}
		}

		vector<int> v1;
		cout << endl;
		for (int i = 0; i < bordersize; i++) {
			v1.clear();
			for (int j = 0; j < bordersize; j++) {
				int b = loadhex[i][j];
				v1.push_back(b);
			}
			load.hexCells.push_back(v1);
		}

		load.cell_class.size = bordersize;
		load.cell_class.selection = select;
		load.cell_class.user = usernumber;

		load.play(load.cell_class.size, load.cell_class.selection,
				load.cell_class.user);
		//activegames.pop_back();

	} else {
		cerr << "The file could not be opened. " << endl;
	}
}
void Hex::saveFile() {
	//In the file saving process,
	//I send the user who the user is, the table size and the game type to the function you want to save and save.
	cout<<cell_class.selection<<endl;
	ofstream saveFile(cell_class.path); //To record ofstream, ifstream to read

	saveFile << cell_class.selection << "\n" << cell_class.user << "\n"
			<< cell_class.size << "\n";
	cout << cell_class.selection << "\n" << cell_class.user << "\n"
			<< cell_class.size << "\n";
	for (int i = 0; i < cell_class.size; i++) {
		for (int j = 0; j < cell_class.size; j++) {
			saveFile << char(hexCells[i][j]);
		}
	}
	cout << "Dosya Kaydedildi.\n";
	saveFile.close();
	play(cell_class.size, cell_class.selection, cell_class.user);
}
int Hex::Cell::input_size() {
	return size;
}
int Hex::Cell::input_size(int boardsize) {
	size = boardsize;
	return size;
}
int Hex::Cell::input_selection(int i_selection) {
	selection = i_selection;
	return selection;
}
int Hex::Cell::input_user(int i_user) {
	user = i_user;
	return user;
}
int Hex::Cell::input_loadcheck(int check) {
	load_check = check;
	return load_check;
}
//Here, it runs uservsuser or uservscomputer according to the Selection process.
int Hex::play(int size, int selection, int user) {

	Hex::printTable();
	string input, input1;
	if (selection == 1) {
		if (user == 1) {
			cout << "Please User1 enters coordinate :";
						cin >> input;
						if (input == "SAVE") {
							cin >> input1;
							cell_class.input_path(input1);
							cell_class.user=1;
							cell_class.selection=1;
							saveFile();

						} else if (input == "LOAD") {
							cin >> input1;
							cell_class.input_path(input1);
							load.cell_class.input_loadcheck(1);
							cell_class.user=1;
							loadFile();

						} else if (input == "quit") {

							cell_class.input_user(user);
							return 0;

						} else {

							for (int i = 0; i < size; i++) {
								int a = 97;

								if (char(a + i) == input[0] && int(input[1] - 48) > 0
										&& int(input[1] - 48) <= size) {

									cell_class.row = int(input[1] - 48);
									cell_class.col = input[0];
									//I check winning situations
									for (int j = 97; j < 123; j++) {
										{

											if ((int) cell_class.col == j
													&& hexCells[cell_class.row - 1][j - 97]
															== 46) {
												hexCells[cell_class.row - 1][j - 97] = 120;
												for (int k = 0; k < cell_class.size; k++) {
													if (hexCells[k][0] == 120) {
														cell_class.solve.clear();
														fillSolveArray();
														cell_class.user = 1;
														determineWin(k, 0);

													}
												}

												if (cell_class.winner == 1) {
													//scout<<cell_class.winner;

													for (int i = 0;
															i < cell_class.solve.size();
															i++) {
														for (int j = 0;
																j < cell_class.solve.size();
																j++) {
															if (cell_class.solve[i][j]
																	== 1) {
																hexCells[i][j] =
																		cell_class.icon::UpperX;
															}
														}
													}
													cout << endl;
													printTable();
													cout << endl;
													cout << "User 1 win.\n";
													main();

												} else {

													user = 2;

													return play(size, selection, user);
												}

											}

										}

									}
								}

							}

						}

						cerr << "Please input correct cell or row...\n\n";
						return play(size, selection, user);

		}
//User 1 I do the same operations that I do in user 2. User1 x User2 o
		else if (user == 2) {
			cout << "Please User2 enters coordinate :";
			cin >> input;
			if (input == "SAVE") {
				cin >> input1;
				cell_class.input_path(input1);
				cell_class.user=2;
				cell_class.selection=1;
				saveFile();


			} else if (input == "LOAD") {
				cin >> input1;
				cell_class.input_path(input1);
				load.cell_class.input_loadcheck(1);
				cell_class.user=2;
				loadFile();

			} else if (input == "quit") {

				cell_class.input_user(user);
				return 0;
			} else {
				for (int i = 0; i < size; i++) {
									int a = 97;

									if (char(a + i) == input[0] && int(input[1] - 48) > 0
											&& int(input[1] - 48) <= size) {

										cell_class.row = int(input[1] - 48);
										cell_class.col = input[0];
										//I check winning situations
										for (int j = 97; j < 123; j++) {
											{

												if ((int) cell_class.col == j
														&& hexCells[cell_class.row - 1][j - 97]
																== 46) {
													hexCells[cell_class.row - 1][j - 97] = 111;
													for (int k = 0; k < cell_class.size; k++) {
														if (hexCells[0][k] == 111) {
															cell_class.solve.clear();
															fillSolveArray();
															cell_class.user = 2;
															determineWin(0, k);

														}
													}
													if (cell_class.winner == 1) {


														for (int i = 0;
																i < cell_class.solve.size();
																i++) {
															for (int j = 0;
																	j < cell_class.solve.size();
																	j++) {
																if (cell_class.solve[i][j]
																		== 1) {
																	hexCells[i][j] =
																			cell_class.icon::Uppero;
																}
															}
														}
														cout << endl;
														printTable();
														cout << endl;
														cout << "User 2 win.\n";
														main();

													} else {

														user = 1;
														return play(size, selection, user);
													}

												}

											}

										}
									}

								}




			}
			cerr << "Please input correct cell or row...\n\n";
						return play(size, selection, user);
		}

//If the User Vs Computer status is here, I do the same for user 1 and then send it to the play () function for the computer.
	} else if (selection == 2) {

		if (user == 1) {
			cout << "Please User1 enters coordinate :";
						cin >> input;
						if (input == "SAVE") {
							cin >> input1;
							cell_class.input_path(input1);
							cell_class.user=1;
							cell_class.selection=2;
							saveFile();


						} else if (input == "LOAD") {
							cin >> input1;
							cell_class.input_path(input1);
							load.cell_class.input_loadcheck(1);
							cell_class.user=1;
							loadFile();

						} else if (input == "quit") {

							cell_class.input_user(user);
							return 0;

						} else {

							for (int i = 0; i < size; i++) {
								int a = 97;

								if (char(a + i) == input[0] && int(input[1] - 48) > 0
										&& int(input[1] - 48) <= size) {

									cell_class.row = int(input[1] - 48);
									cell_class.col = input[0];
									//I check winning situations
									for (int j = 97; j < 123; j++) {
										{

											if ((int) cell_class.col == j
													&& hexCells[cell_class.row - 1][j - 97]
															== 46) {
												hexCells[cell_class.row - 1][j - 97] = 120;
												for (int k = 0; k < cell_class.size; k++) {
													if (hexCells[k][0] == 120) {
														cell_class.solve.clear();
														fillSolveArray();
														cell_class.user = 1;
														determineWin(k, 0);

													}
												}
												if (cell_class.winner == 1) {
													//scout<<cell_class.winner;

													for (int i = 0;
															i < cell_class.solve.size();
															i++) {
														for (int j = 0;
																j < cell_class.solve.size();
																j++) {
															if (cell_class.solve[i][j]
																	== 1) {
																hexCells[i][j] =
																		cell_class.icon::UpperX;
															}
														}
													}
													cout << endl;
													printTable();
													cout << endl;
													cout << "User 1 win.\n";
													main();

												}
												else {

												cell_class.user = 2;
												play();
												if(cell_class.winner==0)
												{
													user=1;
													play(size, selection, user);
												}
																							}
											}


										}

									}
								}


							}

						}


							cerr << "Please input correct cell or row...\n\n";
							play(size, selection, user);




		}

	}

}
//I filled into 2d vector with .(dot)
void Hex::firstFillTable(int size) {

	vector<int> v1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			v1.push_back(46);

		}
		hexCells.push_back(v1);
	}

}
//Here I get the table size and playing type from the user.
void Hex::playGame() {
	int size, selection, user = 1;
	cout << "Welcome " << endl;
	cout << "Please enter the table size :";

	cin >> size;
	cell_class.input_size(size);
	if (size < 5) {
		cerr << "\nWrong size. Please enter correct size \n\n ";
		main();

	} else {
		cout << "\n1 - > User vs User :\n";
		cout << "2 - > User vs Computer :\n";
		cout << "Select - >";
		cin >> selection;
		cell_class.input_selection(selection);
		cell_class.input_user(user);
	}

}
//Here I am calling the function that I will use that I want to print the game.
void Hex::printTable() const {

	int a = hexCells.size();
	for (int i = 97; i < 123 && a != 0; i++) {
		cout << "  " << char(i);
		a--;
	}
	cout << "\n";

	for (int i = 0; i < hexCells.size(); i++) {
		cout << i + 1;
		for (int k = 0; k < i + 1; k++) {
			cout << "  ";
		}
		for (int j = 0; j < hexCells.size(); j++) {
			cout << (char) hexCells[i][j] << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}

