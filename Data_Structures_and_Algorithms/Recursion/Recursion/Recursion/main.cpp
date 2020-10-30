#include"Exercises.h"
#include"Maze.h"
#include<iostream>
#include<fstream>
#include "CoolPhoneNumbers.h"

#include <list>
using namespace std;




int main()
{
	//==================================
	// //Test triangle()
	// int m, n;
	// cout << "Enter m:"; cin >> m;
	// cout << "Enter n:"; cin >> n;

	//triangle(m, n);
	//==================================

	////==================================
	//// Test find()
	//unsigned int* ar = makeArray(10);
	//cout << boolalpha << find(ar, 10, 2) << endl;
	//cout << boolalpha << find(ar, 10, 12) << endl;
	////==================================

	//==================================
	// Test bookletPrinting()
	// bookletPrinting(1, 32);
	//==================================


	//==================================
	// Test binary search
	//unsigned int* ar = makeArray(2000);
	//cout << binSearch(ar, 0, 2000, 512);
	//==================================

	//==================================
	// Test pattern()
	// pattern(m, n);
	//==================================



	//==================================
	//// Cool phone numbers
	//// The file stream where strings for the phone numbers go
	ofstream out;

	string number;
	string filename = "";

	cout << "Enter number: ";
	cin >> number;
	filename += number;
	filename += ".txt";

	out.open(filename.c_str(), ios::out);	// Open output file , e.g. "c:\22457896.txt"
	if (!out.good()) cout << "Failed to open file" << endl;

	findTextFromNumber(number, "", out);

	out.close();
	//==================================

	//==================================
	// Test hanoi()
	//int nDisks = 0;
	//do
	//{
	//	cout << "HANOI'S TOWERS: Enter number of disks to move: ";
	//	cin >> nDisks;
	//	hanoi(nDisks, Pin::PIN_1, Pin::PIN_3, Pin::PIN_2);
	//	cout << "Done..." << endl << endl;
	//} while (nDisks > 0);

	//==================================
	
	return 0;

}