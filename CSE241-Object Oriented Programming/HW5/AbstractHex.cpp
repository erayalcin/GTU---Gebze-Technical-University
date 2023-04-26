#include "AbstractHex.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

namespace Hex {

AbstractHex::AbstractHex(void) {

}
int AbstractHex::get_computerx() {
	return computerx;
}
void AbstractHex::set_computerx(int comx) {
	computery = comx;

}
void AbstractHex::set_computery(int comy) {
	computery = comy;
}
int AbstractHex::get_computery() {
	return computerx;
}

void AbstractHex::reset()
{
	for (int j = 0; j < ySize; ++j) {
			for (int i = 0; i < xSize; ++i) {

				this->operator()(i, j) = '\0';

			}
		}
}
void AbstractHex::readFile(const string& filename) {

	ifstream readFile(filename);
	int bordersize, select, usernumber;

	int count = 0;

	string s;
	//First of all, I open my file and if the file is opened, I do the operations, if not, I give an error.
	if (readFile.is_open()) {

		//Then I take the first 3 lines one by one, here after taking them one by one,
		//I read them once in order not to get the \ n at the end of each line, then I switch to the 2nd line and reread.
		getline(readFile, s);
		select = int(s[0] - 48);
		this->setSelection(select);
		getline(readFile, s);
		usernumber = int(s[0] - 48);
		this->setUser(usernumber);
		getline(readFile, s);
		bordersize = int(s[0] - 48);
		this->setSize(bordersize, bordersize);
		this->fillArray();

		getline(readFile, s);

		for (int i = 0; i < bordersize; i++) {
			for (int j = 0; j < bordersize; j++) {

				this->operator ()(i, j) = int(s[count]);

				count++;
			}
		}

	} else {
		cerr << "The file could not be opened. " << endl;
	}

}
//It write hex board to file
void AbstractHex::writeFile(const string& filename) {
	ofstream saveFile(filename);
	saveFile << this->get_selection() << "\n" << this->get_user() << "\n"
			<< this->get_xSize() << "\n";
	for (int i = 0; i < get_xSize(); i++) {
		for (int j = 0; j < get_ySize(); j++) {
			saveFile << char(this->operator ()(i, j));
		}
	}

}
//It fill hex table with .
void AbstractHex::fillArray() {
	for (int j = 0; j < ySize; ++j) {
		for (int i = 0; i < xSize; ++i) {

			this->operator()(i, j) = 46;

		}
	}

}
//Print function
void AbstractHex::print() const {

	int a = xSize;
	cout << "  ";
	for (int i = 97; i < 123 && a != 0; i++) {
		cout << char(i) << "    ";
		a--;
	}
	cout << "\n";

	for (int i = 0; i < xSize; i++) {
		cout << i + 1;
		for (int k = 0; k < i + 1; k++) {
			cout << "  ";
		}
		for (int j = 0; j < ySize; j++) {
			cout << char(this->operator()(i, j));
			cout << "    ";
		}
		cout << "\n";
	}
	cout << "\n";

}


int AbstractHex::play(int x, int y) {

	if (user == 1) {

		this->operator()(x, y) = 120;

	}
	if (user == 2) {
		this->operator()(x, y) = 111;

	}
	print();
	return 0;
}
void AbstractHex::setSize(const int& xSize, const int& ySize) {
	if (xSize <= 1 || ySize <= 1) {
		cerr << endl << "Invalid size for argument ! " << endl << endl;

	}

	this->xSize = xSize;
	this->ySize = ySize;

}
void AbstractHex::setSelection(const int& selection) {

	this->selection = selection;

}
int AbstractHex::determineWin(int x, int y) {
	if (get_user() == 1) {

		if (y == get_ySize() - 1 && this->check_valid(x, y, 2) == 1) {
			solve[x][y] = 1;
			//score=score+10;
			return 1;

		}

		else {

			//score=score+10;
			/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place
			 I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
			solve[x][y] = 1;

			/*Since we have 6 cases, I check these cases with if conditions. In this if condition,
			 I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
			if (y < get_ySize() && this->check_valid(x, y + 1, 2) == 1
					&& solve[x][y + 1] == 0) {
				return determineWin(x, y + 1);
			} else if (x > 0 && y < get_ySize()
					&& this->check_valid(x - 1, y + 1, 2) == 1
					&& solve[x - 1][y + 1] == 0) {

				return determineWin(x - 1, y + 1);
			} else if (x < get_xSize() - 1
					&& this->check_valid(x + 1, y, 2) == 1
					&& solve[x + 1][y] == 0) {

				return determineWin(x + 1, y);
			} else if (x < get_xSize() - 1 && y > 0
					&& this->check_valid(x + 1, y - 1, 2) == 1
					&& solve[x + 1][y - 1] == 0) {

				return determineWin(x + 1, y - 1);
			} else if (x > 0 && this->check_valid(x - 1, y, 2) == 1
					&& solve[x - 1][y] == 0) {

				return determineWin(x - 1, y);
			} else if (y > 0 && this->check_valid(x, y - 1, 2) == 1
					&& solve[x][y - 1] == 0) {

				return determineWin(x, y - 1);
			} else {
				solve[x][y] = 0;

			}
		}
		return 0;
	}
	if (get_user() == 2) {

		if (x == get_xSize() - 1 && this->check_valid(x, y, 2) == 1) {
			solve[x][y] = 1;
			//score=score+10;
			return 1;

		}

		else {
			//score=score+10;

			/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place
			 I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
			solve[x][y] = 1;

			/*Since we have 6 cases, I check these cases with if conditions. In this if condition,
			 I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
			if (this->check_valid(x + 1, y, 2) == 1 && solve[x + 1][y] == 0) {
				return determineWin(x + 1, y);
			} else if (x > 0 && y < get_ySize()
					&& this->check_valid(x - 1, y + 1, 2)
					&& solve[x - 1][y + 1] == 0) {

				return determineWin(x - 1, y + 1);
			} else if (y > 0 && x < get_xSize()
					&& this->check_valid(x + 1, y - 1, 2) == 1
					&& solve[x + 1][y - 1] == 0) {

				return determineWin(x + 1, y - 1);
			} else if (y > 0 && x < get_xSize()
					&& this->check_valid(x + 1, y - 1, 2) == 1
					&& solve[x + 1][y - 1] == 0) {

				return determineWin(x, y + 1);
			} else if (y < get_ySize() && this->check_valid(x, y + 1, 2) == 1
					&& solve[x][y + 1] == 0) {

				return determineWin(x - 1, y);
			} else if (y > 0 && this->check_valid(x, y - 1, 2) == 1
					&& solve[x][y - 1] == 0) {

				return determineWin(x, y - 1);
			} else {
				solve[x][y] = 0;

			}

		}
		return 0;
	}
}
void AbstractHex::fillSolveArray() {

	vector<int> v1;

	for (int i = 0; i < get_xSize(); i++) {
		for (int j = 0; j < get_ySize(); j++) {
			v1.push_back(0);

		}
		solve.push_back(v1);

	}
}
bool AbstractHex::checkFull() {
	int count = 0;

	for (int i = 0; i < get_xSize(); i++) {
		for (int j = 0; j < get_ySize(); j++) {
			if (this->check_valid(i, j, 0) == false) {
				count++;
			}
		}
	}
	if (count == (get_xSize() * get_ySize()) - 1) {
		return true;
	} else
		return false;
}
bool AbstractHex::isEnd(int x, int y) {

	if (determineWin(x, y) == 1) {
		return true;
	} else {
		if (checkFull() == true) {
			cerr << "This game is fulled." << endl;
		}

		return false;
	}
}
void AbstractHex::setUser(const int& user) {
	this->user = user;
}
int AbstractHex::play() {
	int x, y;
	x = get_computerx();
	y = get_computery();

	if (x < get_xSize() - 1 && this->operator()(x, y) == 46) {
		this->operator()(x, y) = 111;
		set_computerx(x);
		set_computerx(y);
	} else if (x < get_xSize() - 1 && this->operator()(x + 1, y) == 46) {
		this->operator()(x + 1, y) = 111;
		set_computerx(x);
		set_computerx(y);

	} else if (x < get_xSize() - 1 && this->operator()(x - 1, y + 1) == 46) {
		this->operator()(x - 1, y + 1) = 111;
		set_computerx(x);
		set_computerx(y);

	} else if (x < get_xSize() - 1 && this->operator()(x + 1, y - 1) == 46) {
		this->operator()(x + 1, y - 1) = 111;
		set_computerx(x);
		set_computerx(y);

	} else if (x < get_xSize() - 1 && this->operator()(x, y - 1) == 46) {
		this->operator()(x, y - 1) = 111;
		set_computerx(x);
		set_computerx(y);

	} else if (x < get_xSize() - 1 && this->operator()(x, y + 1) == 46) {
		this->operator()(x, y + 1) = 111;
		set_computerx(x);
		set_computerx(y);

	} else if (x < get_xSize() - 1 && this->operator()(x - 1, y) == 46) {
		this->operator()(x - 1, y) = 111;
		set_computerx(x);
		set_computerx(y);

	} else {
		//If these six cases don't work, I put an O in the first empty place with a for loop.
		for (int i = 0; i < get_xSize(); i++) {
			for (int j = 0; j < get_ySize(); j++) {
				if (this->operator()(i, j) == 46) {
					x = i;
					this->operator()(x, j) = 111;

					i = get_xSize();
					j = get_ySize();

				}
			}

		}

	}
}
int AbstractHex::BeforeStartPlaying() {
	string input, input1;

	int winSituation;
	if (get_selection() == 1) {
		if (get_user() == 1) {
			cout << "Please User1 enters coordinate :";
			cin >> input;
			if (input == "save") {
				cin >> input1;
				writeFile(input1);
				BeforeStartPlaying();

			} else if (input == "load") {
				cin >> input1;
				readFile(input1);
				print();
				BeforeStartPlaying();

			} else if (input == "quit") {
				//quit_check=1;
				return 0;
				//exit
			} else if (input == "lastmove") {

				//printTable();
				//BeforeStartPlaying();
			} else {

				for (int i = 0; i < get_xSize(); i++) {
					int a = 97;
					if (char(a + i) == input[0] && int(input[1] - 48) > 0
							&& int(input[1] - 48) <= get_ySize()) {

						int row = int(input[1] - 48);
						char col = input[0];
						//I check winning situations
						for (int j = 97; j < 123; j++) {

							if ((int) col == j) {

								if (this->check_valid(row - 1, col - 97, 1)
										== 1) {

									play(row - 1, col - 97);

									for (int k = 0; k < get_xSize(); k++) {

										if (this->check_valid(k, 0, 2) == 1) {

											solve.clear();
											fillSolveArray();
											//score=0;

											winSituation = isEnd(k, 0);

										}
									}
									//cout << "1.User Score :"<<score<<endl;
									if (winSituation == 1) {
										for (int i = 0; i < get_xSize(); i++) {
											for (int j = 0; j < get_ySize();
													j++) {
												if (solve[i][j] == 1) {

													this->operator()(i, j) = 88;

												}
											}
										}
										cout << endl;

										cout << endl;
										print();
										cout << "<-----> User 1 Win.<----->\n";
										exit(1);
										//main();
									}

									setUser(2);

								}

							}

						}

					}

				}

			}

		}
		if (get_user() == 2) {
			cout << "Please User2 enters coordinate :";
			cin >> input;
			if (input == "save") {
				cin >> input1;
				writeFile(input1);
				BeforeStartPlaying();

			} else if (input == "load") {
				cin >> input1;
				readFile(input1);
				print();
				BeforeStartPlaying();

			} else if (input == "quit") {
				exit(1);

			} else if (input == "lastmove") {

				//printTable();
				//BeforeStartPlaying();
			} else {

				for (int i = 0; i < get_xSize(); i++) {
					int a = 97;
					if (char(a + i) == input[0] && int(input[1] - 48) > 0
							&& int(input[1] - 48) <= get_ySize()) {

						int row = int(input[1] - 48);
						char col = input[0];
						//I check winning situations
						for (int j = 97; j < 123; j++) {

							if ((int) col == j) {

								if (this->check_valid(row - 1, col - 97, 1)
										== 1) {

									play(row - 1, col - 97);

									for (int k = 0; k < get_xSize(); k++) {
										if (this->check_valid(0, k, 2) == 1) {
											solve.clear();
											fillSolveArray();
											//score=0;
											winSituation = isEnd(0, k);

										}
									}
									//cout << "1.User Score :"<<score<<endl;
									if (winSituation == 1) {
										for (int i = 0; i < get_xSize(); i++) {
											for (int j = 0; j < get_ySize();
													j++) {
												if (solve[i][j] == 1) {
													this->operator()(i, j) = 79;

												}
											}
										}
										cout << endl;
										print();
										cout << endl;
										cout << "<-----> User 2 Win.<----->\n";
										exit(1);
									}

									setUser(1);
									BeforeStartPlaying();

								}

							}

						}

					}

				}

			}
		}
	}
	if (get_selection() == 2) {
		if (get_user() == 1) {
			cout << "Please User1 enters coordinate :";
			cin >> input;
			if (input == "save") {
				cin >> input1;
				writeFile(input1);
				BeforeStartPlaying();

			} else if (input == "load") {
				cin >> input1;
				readFile(input1);
				print();
				BeforeStartPlaying();

			} else if (input == "quit") {
				//quit_check=1;
				return 0;
				//exit
			} else if (input == "lastmove") {

				//printTable();
				//BeforeStartPlaying();
			} else {

				for (int i = 0; i < get_xSize(); i++) {
					int a = 97;
					if (char(a + i) == input[0] && int(input[1] - 48) > 0
							&& int(input[1] - 48) <= get_ySize()) {

						int row = int(input[1] - 48);
						char col = input[0];
						//I check winning situations
						for (int j = 97; j < 123; j++) {

							if ((int) col == j) {

								if (this->check_valid(row - 1, col - 97, 1)
										== 1) {

									play(row - 1, col - 97);

									for (int k = 0; k < get_xSize(); k++) {

										if (this->check_valid(k, 0, 2) == 1) {

											solve.clear();
											fillSolveArray();
											//score=0;

											winSituation = isEnd(k, 0);

										}
									}
									//cout << "1.User Score :"<<score<<endl;
									if (winSituation == 1) {
										for (int i = 0; i < get_xSize(); i++) {
											for (int j = 0; j < get_ySize();
													j++) {
												if (solve[i][j] == 1) {

													this->operator()(i, j) = 88;

												}
											}
										}
										cout << endl;

										cout << endl;
										print();
										cout << "<-----> User 1 Win.<----->\n";
										exit(1);
										//main();
									}

									setUser(2);

								}

							}

						}

					}

				}

			}
		}
		if (get_user() == 2) {

			play();

			for (int k = 0; k < get_xSize(); k++) {
				if (this->operator ()(0, k) == 111) {
					solve.clear();
					fillSolveArray();
					winSituation = isEnd(0, k);

				}
			}

			if (winSituation == 1) {
				for (int i = 0; i < get_xSize(); i++) {
					for (int j = 0; j < get_ySize(); j++) {
						if (solve[i][j] == 1) {
							this->operator()(i, j) = 79;

						}
					}
				}
				cout << endl;
				print();
				cout << endl;
				cout << "<-----> Computer Win.<----->\n";
				exit(1);
			}
			this->setUser(1);
			print();
			BeforeStartPlaying();
		}
	}

}

/*bool AbstractHex::move(const char& letter)
 {
 bool flag = true;

 set_player_pos();

 switch(letter)
 {
 case 'r':case 'R':
 flag = moveRight();
 break;

 case 'l':case 'L':
 flag = moveLeft();
 break;

 case 'u':case 'U':
 flag = moveUp();
 break;

 case 'd':case 'D':
 flag = moveDown();
 break;

 default:
 flag = false;
 break;
 }

 if( flag )
 {
 ++number_Of_Moves;
 last_Move = letter;
 }

 set_player_pos();

 return flag;
 }*/

/*bool AbstractHex::isSolved(void) const
 {
 int counter = 1;

 for( int j = 0 ; j < get_ySize() ; ++j )
 {
 for( int i = 0 ; i < get_xSize() ; ++i )
 {
 if( this -> operator()( i , j ) != 0 && this -> operator()( i , j ) == counter )
 ++counter;
 else if( !(counter == get_xSize() * get_ySize() && this -> operator()( i , j ) == blankRepresentation) )
 return false;
 }
 }

 return true;
 }*/

/*bool AbstractHex::operator==(const AbstractHex& other) const
 {
 if( get_xSize() != other.get_xSize() || get_ySize() != other.get_ySize() )
 return false;

 for( int j = 0 ; j < get_ySize() ; ++j )
 for( int i = 0 ; i < get_xSize() ; ++i )
 if( this -> operator()( i , j ) != other.operator()( i , j ) )
 return false;

 return true;
 }*/

/* There are two seperate function decleration for ()  overloading */
/* Because the issues of rvalue and lvalue */

AbstractHex::~AbstractHex() {
}

/* After this point , there are my own functions */
/* My inline function`s definition in the class  */

/*bool AbstractHex::set_player_pos(void)
 {


 return 0;

 }*/

/*bool AbstractHex::moveRight(void)
 {
 if( ( playerX + 1  )< xSize && this->operator()( playerX + 1, playerY ) != 0)
 {
 this->operator()( playerX, playerY ) = this->operator()( playerX + 1, playerY );
 this->operator()( playerX + 1, playerY ) = blankRepresentation;

 return true;
 }
 return false;
 }*/

/* bool AbstractHex::moveLeft(void)
 {
 if( ( playerX - 1  ) >= 0 && this->operator()( playerX - 1, playerY ) != 0)
 {
 this->operator()( playerX, playerY ) = this->operator()( playerX - 1, playerY );
 this->operator()( playerX - 1, playerY ) = blankRepresentation;

 return true;
 }
 return false;
 }*/

/*bool AbstractHex::moveUp(void)
 {
 if( ( playerY - 1  ) >= 0 && this->operator()( playerX , playerY - 1 ) != 0)
 {
 this->operator()( playerX, playerY ) = this->operator()( playerX , playerY - 1 );
 this->operator()( playerX , playerY - 1 ) = blankRepresentation;

 return true;
 }

 return false;
 }

 bool AbstractHex::moveDown(void)
 {
 if( ( playerY + 1  ) < ySize && this->operator()( playerX , playerY + 1 ) != 0)
 {
 this->operator()( playerX, playerY ) = this->operator()( playerX , playerY + 1 );
 this->operator()( playerX , playerY + 1 ) = blankRepresentation;

 return true;
 }
 return false;
 }*/

}

