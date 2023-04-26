#include "HexArray1D.h"
#include "AbstractHex.h"
#include "HexVector.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace Hex;
void printHexDetails(const AbstractHex*);
void checkHexArray1D();
void checkHexVector();
//It print details of hex table
void printHexDetails(const AbstractHex* hex) {
	cout << "Row : " << hex->get_xSize() << endl;
	cout << "Column : " << hex->get_ySize() << endl;

}
//Test functions
void checkHexArray1D() {

	cout<< "_______________  Two parameter constructor testing  _______________\n";
	HexArray1D test_arr(6, 6);
	printHexDetails(&test_arr);
	test_arr.print();
	cout << "_______________  FillArray function testing  _______________\n";
	test_arr.fillArray();
	cout << "_______________  Print function testing  _______________\n";
	test_arr.print();
	cout<< "_______________  SetUser and SetSelection function testing  _______________\n";
	test_arr.setUser(1);
	test_arr.setSelection(1);
	cout << "_______________  Play function testing  _______________\n";
	test_arr.play(2, 2);
	cout<< "_________________  writeFile function testing  _________________\n";
	cout << "Writing test/Hex1D.txt\n";
	test_arr.writeFile("test/Hex1D.txt");
	cout << "_________________  readFile function testing  _________________\n";
	cout << "Writing test/Hex1D.txt\n";
	test_arr.readFile("test/Hex1D.txt");
	test_arr.print();
	cout << "_______________  Reset function testing  _______________\n";
	test_arr.reset();
	test_arr.print();
	cout<< "___________________  setSize function testing  ___________________\n";
	cout << "Before setSize function : \n";
	printHexDetails(&test_arr);
	cout << "\nAfter setSize function : \n";
	test_arr.setSize(5, 5);
	printHexDetails(&test_arr);

}
void checkHexVector() {

	cout<< "_______________  Two parameter constructor testing  _______________\n";
	HexVector vec_test(6, 6);
	printHexDetails(&vec_test);

	cout << "_______________  FillArray function testing  _______________\n";
	vec_test.fillArray();

	cout << "_______________  Print function testing  _______________\n";
	vec_test.print();
	cout<< "_______________  SetUser and SetSelection function testing  _______________\n";
	vec_test.setUser(1);
	vec_test.setSelection(1);
	cout << "_______________  Play function testing  _______________\n";
	vec_test.play(2, 2);
	cout<< "_________________  writeFile function testing  _________________\n";
	cout << "Writing test/Hex1D.txt\n";
	vec_test.writeFile("test/HexVector.txt");
	cout << "_________________  readFile function testing  _________________\n";
	cout << "Writing test/Hex1D.txt\n";
	vec_test.readFile("test/HexVector.txt");
	vec_test.print();
	cout << "_______________  Reset function testing  _______________\n";
	vec_test.reset();
	vec_test.print();
	cout<< "___________________  setSize function testing  ___________________\n";
	cout << "Before setSize function : \n";
	printHexDetails(&vec_test);
	cout << "\nAfter setSize function : \n";
	vec_test.setSize(5, 5);
	printHexDetails(&vec_test);

}

int main() {
	checkHexArray1D();
	checkHexVector();
	int size, selection, user, choose;
	cout << "Welcome " << endl;
	cout << "\n1 - > Start with HexArray1D :\n";
	cout << "2 - > Start with HexVector :\n";
	cout << "Select - >";
	cin >> choose;

	cout << "Please enter the table size :";
	cin >> size;

	cout << "\n1 - > User vs User :\n";
	cout << "2 - > User vs Computer :\n";
	cout << "Select - >";
	cin >> selection;
	if (choose == 1) {
		HexArray1D hexx(size, size);
		hexx.fillArray();

		hexx.setSelection(selection);
		user = 1;
		hexx.setUser(user);
		if (selection == 1) {
			hexx.setSelection(selection);
			hexx.print();
			cout << "Selection   :" << hexx.get_selection() << endl;
			cout << "User   :" << hexx.get_user() << endl;
			hexx.BeforeStartPlaying();
			return 0;
		}
		if (selection == 2) {
			hexx.setSelection(selection);
			hexx.print();
			cout << "Selection   :" << hexx.get_selection() << endl;
			cout << "User   :" << hexx.get_user() << endl;
			hexx.set_computerx(0);
			hexx.set_computery(0);
			hexx.BeforeStartPlaying();
			return 0;
		}
	}

	if (choose == 2) {
		HexVector hexx(size, size);
		hexx.fillArray();

		hexx.setSelection(selection);
		user = 1;
		hexx.setUser(user);
		if (selection == 1) {
			hexx.setSelection(selection);
			hexx.print();
			cout << "Selection   :" << hexx.get_selection() << endl;
			cout << "User   :" << hexx.get_user() << endl;
			hexx.BeforeStartPlaying();
			return 0;
		}
		if (selection == 2) {
			hexx.setSelection(selection);
			hexx.print();
			cout << "Selection   :" << hexx.get_selection() << endl;
			cout << "User   :" << hexx.get_user() << endl;
			hexx.set_computerx(0);
			hexx.set_computery(0);
			hexx.BeforeStartPlaying();
			return 0;
		}
	}

}

