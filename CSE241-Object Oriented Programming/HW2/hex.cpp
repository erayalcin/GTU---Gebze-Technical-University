//============================================================================
// Name        : hexgame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <fstream>
#include <iostream>
using namespace std;
int select_menu(int hex[12][12]);
void printTable(const int size, int hextable[12][12]);
void firstFillTable(const int size, int hextable[12][12]);
int determineWin(int x, int y, int hexTable[12][12], const int size,
		int solve[12][12], int user);
int computerSteps(const int size, int hextable[12][12], int count,
		int store[2]);
int UservsUser(const int size, int hextable[12][12], char x, int y,
		int userCheck);
int game(const int size, int hex[12][12], const int selection, int user);
int isFull(int hex[12][12], const int size, int* result);


enum icon {
	Lowerx = 120, Lowero = 111, Uppero = 79, UpperX = 88, dot = 46
};

//In this function, I print the table of the hex game on the screen.
void printTable(const int size, int hextable[12][12]) {
	cout << "\n";
	cout << "\n";
	//I do not include the coordinates in the hex array.
	char alpha[12] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l' };
	//In this for loop, I print the coordinates of the letters in the first line to the screen.

	for (int i = 0; i < size; i++) {
		cout << "  " << alpha[i];
	}

	cout << "\n";
	//Then It prints table of hex game on screen
	//I use nested for loops because my array is 2d array.
	for (int i = 0; i < size; i++) {
		cout << i + 1;
		for (int k = 0; k < i + 1; k++) {
			cout << "  ";
		}
		for (int j = 0; j < size; j++) {
			//The reason I use it as char in this line is because the array is integer,
			//save the data with asci codes and print it as char on the screen.
			cout << char(hextable[i][j]) << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}
//In this function, I first fill the array with dots. We have to do this because the empty state of the table is formed with dots.
void firstFillTable(int size, int hextable[12][12]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			hextable[i][j] = icon::dot;
		}

	}
}
//In this function, we control which user the user is, our vertical and horizontal operations. If the user is 1 I am sending 0, if the user is 2, I am sending 1.
int determineWin(int x, int y, int hexTable[12][12], const int size,
		int solve[12][12], int user = 0) {

	if (user == 0) {

		/*I have my winning situation checked here. In order to win, I start horizontally from the left and check
		 if there is an X in the first column and then evaluate the 6 movements,
		 if it cannot finds a place to go, it leaves the loop and then looks to see if there is a spike x in that column.
		 To win, she must go to the last position and horizontally to the position before the table size. */

		if (y == size - 1 && hexTable[x][y] == icon::Lowerx) {
			solve[x][y] = 1;
			return 1;
		}

		else {
			/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place
			 I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
			solve[x][y] = 1;
			/*Since we have 6 cases, I check these cases with if conditions. In this if condition,
			 I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
			if (hexTable[x][y + 1] == 120 && solve[x][y + 1] == 0) {
				return determineWin(x, y + 1, hexTable, size, solve);
			}
			if (hexTable[x - 1][y + 1] == icon::Lowerx
					&& solve[x - 1][y + 1] == 0) {

				return determineWin(x - 1, y + 1, hexTable, size, solve);
			}
			if (hexTable[x + 1][y] == icon::Lowerx && solve[x + 1][y] == 0) {

				return determineWin(x + 1, y, hexTable, size, solve);
			}
			if (hexTable[x + 1][y - 1] == icon::Lowerx
					&& solve[x + 1][y - 1] == 0) {

				return determineWin(x + 1, y - 1, hexTable, size, solve);
			}
			if (hexTable[x - 1][y] == icon::Lowerx && solve[x - 1][y] == 0) {

				return determineWin(x - 1, y, hexTable, size, solve);
			}
			if (hexTable[x][y - 1] == icon::Lowerx && solve[x][y - 1] == 0) {

				return determineWin(x, y - 1, hexTable, size, solve);
			} else {
				solve[x][y] = 1;
				return 0;
			}
		}

	}
	//We vertically control the same actions for the second user. We do the same operations that we do on User 1. This second user will also be a computer for us.
	if (user == 1) {
		if (x == size - 1 && hexTable[x][y] == icon::Lowero) {
			solve[x][y] = 1;
			return 1;
		}

		else {

			solve[x][y] = 1;

			if (hexTable[x + 1][y] == icon::Lowero && solve[x + 1][y] == 0) {
				return determineWin(x + 1, y, hexTable, size, solve, 1);
			}
			if (hexTable[x][y + 1] == icon::Lowero && solve[x][y + 1] == 0) {
				return determineWin(x, y + 1, hexTable, size, solve, 1);
			}
			if (hexTable[x - 1][y + 1] == icon::Lowero
					&& solve[x - 1][y + 1] == 0) {
				return determineWin(x - 1, y + 1, hexTable, size, solve, 1);
			}
			if (hexTable[x + 1][y - 1] == icon::Lowero
					&& solve[x + 1][y - 1] == 0) {
				return determineWin(x + 1, y - 1, hexTable, size, solve, 1);
			}
			if (hexTable[x - 1][y] == icon::Lowero && solve[x - 1][y] == 0) {
				return determineWin(x - 1, y, hexTable, size, solve, 1);
			}
			if (hexTable[x][y - 1] == icon::Lowero && solve[x][y - 1] == 0) {
				return determineWin(x, y - 1, hexTable, size, solve, 1);
			} else {
				solve[x][y] = 1;
				return 0;
			}
		}

	}
}
/*In this function, I create the computer steps.
 For this I need to save the coordinates and for this I keep the previous coordinates.
 First, I look for an empty place in the first line and create the points according to that location. While creating these points,
 I consider 6 situations as I did in the winning case I look at these 6 cases one by one and then the computer puts O in the first empty place.*/
int computerSteps(const int size, int hextable[12][12], int count,
		int store[2]) {
	int x, y, consty;
	auto result = 0;
	int solve[12][12];
	//Here I fill the sequence where I control my steps in case of winning with 0.
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			solve[i][j] = 0;
		}
	}
	/*While the computer is working, I throw the first position to the first empty line and since this first operation is different,
	 * I put it in a separate condition. Then I increment this condition by one, and then I look at the 6 states in order,
	 * enter whatever it provides, and assign O to that position, and then store this position in the store array and use this position in the next move.*/
	if (count == 1) {

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (hextable[i][j] == icon::dot) {
					x = i;
					hextable[x][j] = icon::Lowero;
					store[0] = x;
					store[1] = j;
					return 0;
				}
			}

		}

		printTable(size, hextable);
	}
	//It looks at 6 situations in turn and enters whichever is appropriate and does not look at the others.(diş
	else {
		x = store[0];
		y = store[1];
		if (hextable[x + 1][y] == icon::dot) {
			hextable[x + 1][y] = icon::Lowero;
			store[0] = x + 1;
			store[1] = y;
		} else if (hextable[x - 1][y + 1] == icon::dot) {
			hextable[x - 1][y + 1] = icon::Lowero;
			store[0] = x - 1;
			store[1] = y + 1;
		} else if (hextable[x + 1][y - 1] == icon::dot) {
			hextable[x + 1][y - 1] = icon::Lowero;
			store[0] = x + 1;
			store[1] = y - 1;
		} else if (hextable[x][y - 1] == icon::dot) {
			hextable[x][y - 1] = icon::Lowero;
			store[0] = x;
			store[1] = y - 1;
		} else if (hextable[x][y + 1] == icon::dot) {
			hextable[x][y + 1] = icon::Lowero;
			store[0] = x;
			store[1] = y + 1;
		} else if (hextable[x - 1][y] == icon::dot) {
			hextable[x - 1][y] = icon::Lowero;
			store[0] = x - 1;
			store[1] = y;
		} else {
			//If these six cases don't work, I put an O in the first empty place with a for loop.
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (hextable[i][j] == icon::dot) {
						x = i;
						hextable[x][j] = icon::Lowero;
						store[0] = x;
						store[1] = j;
						return 0;
					}
				}

			}
		}
		//Here I am doing the winning situation. Since there is a 2nd user on the computer, I send the same function as the 2nd user.
		for (int i = 0; i < size; i++) {
			if (hextable[0][i] == icon::Lowero) {
				consty = i;
				solve[0][consty] = 1;
				result = determineWin(0, consty, hextable, size, solve, 1);
			}
		}

		if (result == 1) {

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (solve[i][j] == 1) {
						hextable[i][j] = icon::Uppero;
					}
				}

			}
		}
		return result;
	}
}
/*In this function, the user plays against the user and each user marks the position they want to throw.
 * First, I convert the positions it throws to an integer value. I set the alphabet as a string and compare it with the data entered by the user.
 * I convert the letter the user has entered into a number and place it in my hex array accordingly.*/
int UservsUser(const int size, int hextable[12][12], char x, int y,
		int userCheck = 0) {

	char alpha[12] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l' };
	int x1, result = 0;
	int consty;
	int solve[12][12];

	//First, I reset the sequence in which I recorded the steps, the reason I do this is because it does not overlap every time the program runs.
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			solve[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++)//I'm converting the coordinates to integers.
			{
		if (alpha[i] == x) {

			x1 = i;
		}
	}

	//We check whether every user wins when they log in. We do the control process from left to right for horizontal. For vertical, we do it from top to bottom.
	if (userCheck == 0) {

		hextable[y - 1][x1] = icon::Lowerx;
		for (int i = 0; i < size; i++) {
			if (hextable[i][0] == icon::Lowerx && result == 0) {
				y = i;
				result = determineWin(y, 0, hextable, size, solve);
			}
		}
		if (result == 1) {

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (solve[i][j] == 1) {
						hextable[i][j] = icon::UpperX;
					}
				}

			}
		}
		return result;
	}
	//We check whether every user wins when they log in. We do the control process from left to right for horizontal. For vertical, we do it from top to bottom.
	if (userCheck == 1) {
		hextable[y - 1][x1] = icon::Lowero;
		for (int i = 0; i < size; i++) {
			if (hextable[0][i] == icon::Lowero && result == 0) {

				result = determineWin(0, i, hextable, size, solve, 1);
			}
		}

		if (result == 1) {
			for (int i = 0; i < size; i++) {

				for (int j = 0; j < size; j++) {
					if (solve[i][j] == 1) {
						hextable[i][j] = icon::Uppero;
					}
				}

			}
		}
		return result;
	}
}
/*In the function of checking whether the table is full or not, I keep a counter and I increase 1 at each point where you see it, if not,
 I check it lastly. If the counter is 0, it shows that all its coordinates are filled.*/
int isFull(int hex[12][12], const int size, int* result) {
	auto count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (hex[i][j] == icon::dot) {
				count++;
			}
		}
	}
	if (count == 0) {
		*result = 1;
	} else
		*result = 0;
}
void load_file(string y) {
	//This function loads the saved game. While I was saving in the file,
	//I printed the game type (uservsuser or uservscomputer) on the first line, and then on the 2nd line,
	//I printed the table size on the 3rd line, which user belongs to.
	//I printed the output of the table on the 4th line.
	char c;
	ifstream readFile(y);
	int bordersize, select, usernumber;
	auto row = 0;
	auto count = 0;
	//First of all, I open my file and if the file is opened, I do the operations, if not, I give an error.
	if (readFile.is_open()) {

		//Then I take the first 3 lines one by one, here after taking them one by one,
		//I read them once in order not to get the \ n at the end of each line, then I switch to the 2nd line and reread.
		readFile.get(c);
		select = c - 48;
		readFile.get(c);
		readFile.get(c);
		usernumber = c - 48;
		readFile.get(c);
		readFile.get(c);
		bordersize = c - 48;
		int loadhex[12][12];
		readFile.get(c);

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
		if (usernumber == 1)
			printTable(bordersize, loadhex);
		game(bordersize, loadhex, select, usernumber);
	} else {
		cerr << "The file could not be opened. " << endl;
	}

}
void save_file(int hex[12][12], int user, const int size, const int selection,
		string y) {
	//In the file saving process,
	//I send the user who the user is, the table size and the game type to the function you want to save and save.
	ofstream saveFile(y); //To record ofstream, ifstream to read
	saveFile << selection << "\n" << user << "\n" << size << "\n";
	cout << selection << "\n" << user << "\n" << size << "\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			saveFile << char(hex[i][j]);
		}
	}
	cout << "Dosya Kaydedildi.\n";
	saveFile.close();
	game(size,hex,selection,user);
}
int game(const int size, int hex[12][12], const int selection, int user) {
	//I do the selection functions in this menu.
	/*I do the data entry control in the same menu. If it is trying to enter data in the existing location,
	 * I log in again. If the table is full, I end the game. When the winner is,
	 * I press the screen here. In short, I do applications such as screen printing, data entry, data entry control in this menu.*/
	auto check = 0, control = 0;
	decltype(check) check1;
	decltype(control) count;

	int full = 0;
	int store[2];
	string x, y;
	int line;
	char alpha[12] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l' };

	if (selection == 1) {

		while (control == 0) {
			isFull(hex, size, &full);

			if (full == 1) {
				//I check if the table is full.
				//Here I draw my full variable with reference.
				cerr << "Table is full." << endl;
				control = 1;
				check = 1;
				return 0;
			}

			if (user == 1 && control == 0) {
				while (check != 1 || check1 != 1) {

					cout << "Please User1 enters coordinate :";
					cin >> x;
					if (x == "SAVE") {
						cin >> y;
						save_file(hex, user, size, selection, y);
						return 0;
					} else if (x == "LOAD") {
						cin >> y;
						load_file(y);
						return 0;

					} else {
						line = int(x[1] - 48);

						for (int i = 0; i < size; i++) {
							if (alpha[i] == x[0]) {
								if (hex[line - 1][i] == icon::dot)
									check = 1;
							}
						}
						if (line > 0 && line <= size) {
							check1 = 1;
						}
						if (check != 1 || check1 != 1) {
							cerr << "User1 tekrar giriniz...\n";
						}
					}
				}
				user = 2;
				if (UservsUser(size, hex, x[0], line) == 1) {
					printTable(size, hex);
					cout << "1.User  Win\n";
					control = 1;

				}
			}

			else if (user == 2 && control == 0) {

				printTable(size, hex);

				check = 0;
				check1 = 0;
				while (check != 1 || check1 != 1) {
					cout << "Please User2 enters coordinate :";
					cin >> x;
					if (x == "SAVE") {
						cin >> y;
						save_file(hex, user, size, selection, y);
						return 0;

					} else if (x == "LOAD") {
						cin >> y;
						load_file(y);
						return 0;
					} else {
						line = int(x[1] - 48);

						for (int i = 0; i < size; i++) {
							if (alpha[i] == x[0]) {
								if (hex[line - 1][i] == icon::dot)
									check = 1;
							}
						}
						if (line > 0 && line <= size) {
							check1 = 1;
						}
						if (check != 1 || check1 != 1) {
							cerr << "User2 tekrar giriniz...\n";
						}
					}
				}

				if (UservsUser(size, hex, x[0], line, 1) == 1) {
					printTable(size, hex);
					cout << "2.User Win\n";
					control = 1;

				} else {
					printTable(size, hex);
					user = 1;
				}
				check = 0;
				check1 = 0;

			}
		}

	}
	//I do all my operations on UservsUser in uservscomputer.
	if (selection == 2) {

		while (control == 0) {
			if (user == 1) {
				isFull(hex, size, &full);
				if (full == 1) {

					cerr << "Table is full." << endl;
					control = 1;
					check = 1;
					return 0;
				}
				while (check != 1 || check1 != 1) {
					cout << "Please User1 enters coordinate :";
					cin >> x;
					if (x == "save") {
						cin >> y;
						save_file(hex, user, size, selection, y);
					} else if (x == "load") {
						cin >> y;
						load_file(y);
						return 0;

					} else {

						line = int(x[1] - 48);
					}
					for (int i = 0; i < size; i++) {
						if (alpha[i] == x[0]) {
							if (hex[line - 1][i] == icon::dot)
								check = 1;
						}
					}
					if (line > 0 && line <= size) {
						check1 = 1;
					}
					if (check != 1 || check1 != 1) {
						cerr << "User1 tekrar giriniz...\n";
					}

				}
				user = 2;

				if (UservsUser(size, hex, x[0], line) == 1) {
					printTable(size, hex);
					cout << "1.User Win\n";
					control = 1;
					return 0;
				}
			}

			else if (user == 2) {

				isFull(hex, size, &full);
				if (full == 1) {

					cerr << "Table is full." << endl;
					control = 1;
					check = 1;
					return 0;
				} else {

					check = 0;
					check1 = 0;
					count++;

					if (computerSteps(size, hex, count, store) == 1) {
						printTable(size, hex);
						cout << "Computer Win\n";
						control = 1;

					} else {
						printTable(size, hex);
						user = 1;
					}
					check = 0;
					check1 = 0;
				}

			}
		}
	}
}
int select_menu(int hex[12][12]) {

	int size;
	int selection;
	cout << endl;
	cout << "Welcome " << endl;
	cout << "Press 6--->6x6" << endl;
	cout << "Press 7--->7x7" << endl;
	cout << "Press 8--->8x8" << endl;
	cout << "Press 9--->9x9" << endl;
	cout << "Press 10--->10x10" << endl;
	cout << "Press 11--->11x11" << endl;
	cout << "Press 12--->12x12" << endl;
	cout << "Please enter the table size :";

	cin >> size;
	if (size < 6 || size > 12) {
		cerr << "Wrong size. Please enter correct size \n ";
		return 0;
	} else {
		cout << "\n1 - > User vs User :\n";
		cout << "2 - > User vs Computer :\n";
		cout << "Select - >";
		cin >> selection;
		firstFillTable(size, hex);
		printTable(size, hex);
		game(size, hex, selection, 1);

	}
}
int main() {

	int hex[12][12];
	select_menu(hex);
}
