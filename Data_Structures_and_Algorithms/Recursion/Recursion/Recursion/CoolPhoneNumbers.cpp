#include"Exercises.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

// Characters for individual digits
string digitChars[] = {
	// Chars		  // Digit
	"0",			// 0
	"1",			// 1
	"2abc",			// 2
	"3def",			// 3
	"4ghi",			// 4
	"5jkl",			// 5
	"6mno",			// 6
	"7pqrs",		// 7
	"8tuv",			// 8
	"9wxyz"			// 9
};


//----------------------------------------------------------------
// NAME:	findTextFromNumber
// 
// (1) State the problem:	Finds and outputs all strings corresponding to 
//							the number "number".
// (2) Find & handle BC:	|number| = 0: Output soFar
// (3) Find & handle RC:	|number| > 0: 
//							- For each character 'c' corresponding to number[0]:
//							-   number2Strings(number[1..|number|), c+soFar)
// (4) Ensure RC hits BC:	In RC, |number|>0 and  |number'| = |number|-1, 
//							which will eventually be=0, the BC
//----------------------------------------------------------------
void findTextFromNumber(string number, string soFar, ofstream& out)
{
	unsigned int curDigit;
	string newSoFar;
	string newNumber;

	if (number.size() == 0)
		out << soFar << endl;
	else
	{
		curDigit = number[0] - '0';							// Head of number 
		newNumber = number.substr(1, number.size());		// Tail part of number

		for (unsigned int i = 0; i<digitChars[curDigit].size(); i++)
		{
			newSoFar = soFar + digitChars[curDigit][i];			// i'th character for head of number added to new soFar
			findTextFromNumber(newNumber, newSoFar, out);
		}
	}
}