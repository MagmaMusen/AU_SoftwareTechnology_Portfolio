#include<iostream>
#include<string>
#include<sstream>
using namespace std;


//******************************************************************************
//******************************************************************************
// HELPER FUNCTIONS - NOT PART OF EXERCISE SOLUTION
void printN(const string& s, unsigned int n, bool finishWithEndline = true);


//=============================================================================
// FUNC:  printN()
// DESCR: Prints a string n times
//
// Postcondition: The string s has been printed n times on a line. 
//=============================================================================
void printN(const string& s, unsigned int n, bool finishWithEndline)
{
	for (unsigned int i = 0; i < n; i++) cout << s;
	if (finishWithEndline) cout << endl;
}


//=============================================================================
// FUNC:  makeArray()
// DESCR: Creates and fills an array
//
//=============================================================================
unsigned int* makeArray(unsigned int size)
{
	unsigned int* retArray = new unsigned int[size];
	for (unsigned int i = 0; i<size; i++) retArray[i] = i;
	return retArray;
}

//******************************************************************************
//******************************************************************************





//******************************************************************************
//******************************************************************************
// EXERCISE FUNCTIONS


//=============================================================================
// FUNC:  triangle()
// DESCR: 
//
// (1) State the problem:	Print a pattern of '*'s as given in example below. m <= n
// (2) Find & handle BC:	m>n: nullptr
// (3) Find & handle RC:	m<=n:
//							- Write n '*'
//							- triangle(m+1, n)
//							- Write n '*'
// (4) Ensure RC hits BC:	Since in RC m <= n and m'=m+1, m will eventually be > n, the BC
//
/* Example output:
triangle(3, 5) will print this to cout:
***
****
*****
*****
****
***
*/
//=============================================================================
void triangle(unsigned int m, unsigned int n)
{
	if (m <= n)
	{
		printN("*", m);
		triangle(m + 1, n);
		printN("*", m);
	}
}



//=============================================================================
// FUNC:  find()
// DESCR:
//
// (1) State the problem:	Searches through the first n elements of ar for x. 
//							If x is in ar[0..n), the function returns true, 
//							else false is returned.
// (2) Find & handle BC:	n==0: Return false
// (3) Find & handle RC:	n>0:  ar[n-1] == x: Return true
//							else return find(ar, n-1, x)
// (4) Ensure RC hits BC:	In RC, n>0. If ar[n-1]==x, the function terminates immediately,
//							otherwise n' = n-1, which will eventually make n=0, the BC
//=============================================================================
bool find(unsigned int* ar, int n, int x)
{
	return n==0 ? false : (ar[n-1] == x || find(ar, n-1, x));
	//if (n == 0) return false;
	//return ar[n-1] == x || find(ar, n - 1, x);
}




//=============================================================================
// FUNC:  bookletPrinting()
// DESCR:					Outputs the 4 pages on each printed sheet of paper in 
//							booklet printing order. Note that the current sheet
//							number is given by (startPage+1)/2
//
//	Precondition:			Number of pages is divisible by 4
//	Postcondition:			Pages on each sheet of paper is output
//
// (1) State the problem:	Let sp = startPage, ep = endPage, rp = sp-ep+1
//							Output all pages [sp, ep] in booklet printing order
// (2) Find & handle BC:	sp <= ep : Printing complete
// (3) Find & handle RC:	sp > ep:	
//								(1) Print [sp, sp+1, ep-1, ep] on current sheet
//								(2) Call bookletPrinting(sp+2, ep-2)		
//							
// (4) Ensure RC hits BC:	In RC, rp > 0 and rp %4 == 0. Since recursive calls are
//							made with rp' = rp-4, rp' is decreasing by 4
//							(thus remains divisible by 4) and will thus eventually 
//							become 0 = BC
//=============================================================================
void bookletPrinting(unsigned int startPage, unsigned int endPage)
{
	if ((endPage - startPage + 1) % 4)
	{
		cout << "Error: Invalid page numbers: " << startPage << ", " << endPage << endl;
		return;
	}

	if (endPage <= startPage) return; // BC: No pages left to print

	int sheetNumber = (startPage + 1) / 2;
	// RC: Print the other pages, then the current ones
	cout << "Sheet " << sheetNumber << " contains pages " 
		<< startPage << ", " 
		<< startPage + 1 << ", " 
		<< endPage - 1 << ", " 
		<< endPage << endl;
	
	bookletPrinting(startPage + 2, endPage - 2);
}




//=============================================================================
// FUNC:  pattern()
// DESCR:
// (1) State the problem:	Prints a pattern as given below. n is a power of 2
// (2) Find & handle BC:	n==0: nullptr
// (3) Find & handle RC:	n > 0: 
//							- pattern(n/2, i)
//							- Print n '*' at pos i
//							- pattern(n/2, i+n)
// (4) Ensure RC hits BC:	In RC, n>0 and a power of 2. n' = n/2 which eventually
//							by integer division be 0, the BC.
//
// Example output: pattern (8,5) yields
// 0         1         2
// 012345678901234567890
//      * 
//      * * 
//        *
//      * * * *
//          * 
//          * * 
//            *
//      * * * * * * * * 
//              * 
//              * * 
//                *
//              * * * *
//                  * 
//                  * * 
//                    *
//=============================================================================
void pattern(unsigned int n, unsigned int i)
{
	if (n>0)	// RC
	{
		pattern(n / 2, i);						// Print first half of pattern
		printN(" ", i, false); printN("* ", n);	// Print "long center line"
		pattern(n / 2, n + i);					//	Print last half of pattern
	}
	// BC empty
}




//=============================================================================
// FUNC:  binSearch()
// DESCR:
// (1) State the problem:	Find tgt in ar[first, last]
// (2) Find & handle BC:	first > last: return false
// (3) Find & handle RC:	first <= last: 
//							if tgt ==ar[last+first/2] return true
//							if tgt < ar[last+first/2] search left half
//							if tgt > ar[last+first/2] search right half
// (4) Ensure RC hits BC:	In RC, last-first >= 0. When called recursively, only half of the array is searched
//							thus, by integer division, last'-first' will eventually become 0, the BC
//
bool binSearch(const unsigned int ar[], unsigned int first, unsigned int last, unsigned int tgt)
{
	if (first>last) return false;
	int half = (last + first) / 2;
	if (ar[half] == tgt) return true;
	else if (ar[half] > tgt) return binSearch(ar, first, half - 1, tgt);
	else return binSearch(ar, half + 1, last, tgt);
}



