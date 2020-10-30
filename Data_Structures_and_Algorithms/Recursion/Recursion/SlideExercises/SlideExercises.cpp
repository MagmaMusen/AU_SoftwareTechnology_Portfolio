#include<iostream>
#include "SlideExercises.h"
using namespace std;



//====================================================================
// Algorithm				: sum()
// (1) State the problem	: Find the sum of the n first elements of 
//							  ar. n>= 0
// (2) Find and handle BC	: n==0: sum=0
// (3) Find and handle RC	: n>0 : sum = ar[0] + sum(ar+1, n-1)
// (4) Argue that RC -> BC	: In RC, n>0 and n decreases with 1 for 
//							  each recursive call. hence, eventually 
//							  n=0 which is the BC
//====================================================================
int sum(int* ar, int n)
{
	if (n == 0) return 0;
	else return ar[0] + sum(ar + 1, n - 1);
}



//====================================================================
// Algorithm				: fac()
// (1) State the problem	: Find the factorial of n, n> 0
// (2) Find and handle BC	: n==1: fac=1
// (3) Find and handle RC	: n>1 : fac = n*fac(n-1)
// (4) Argue that RC -> BC	: In RC, n>1 and n decreases with 1 for 
//							  each recursive call. hence, eventually 
//							  n=1 which is the BC
//====================================================================
double fac(size_t n)
{
	if (n == 1) return 1.0;
	else return n*fac(n - 1);
}



//====================================================================
// Algorithm				: num()
// (1) State the problem	: Print all numbers from n down to 1
// (2) Find and handle BC	: n==0: Empty
// (3) Find and handle RC	: n>0 : cout << "num is " << n, then num(n-1)
// (4) Argue that RC -> BC	: In RC, n>1 and n decreases with 1 for 
//							  each recursive call. hence, eventually 
//							  n=1 which is the BC
//====================================================================
void num(unsigned int n)
{
	if (n>0)
	{
		cout << "num is " << n << endl;
		num(n - 1);
	}
	// Implicit BC: n==0: Empty
}



//====================================================================
// Algorithm				: power()
// (1) State the problem	: Raise x to the power of exp.
// (2) Find and handle BC	: exp==0: power=1
// (3) Find and handle RC	: exp<0 : power = 1/power(x, -exp)
//							  exp>0 : power = x*power(x, exp-1)
// (4) Argue that RC -> BC	: In RC-1, exp<0 and the recursive call is
//							  with -exp, a less complex problem (see
//							  RC-2)
//							: In RC-2, exp>0 and exp decreases with 1 for
//							  each recursive call. hence, eventually 
//							  exp=0 which is the BC
//====================================================================
double power(int x, int exp)
{
	if (exp == 0)	return 1;	 // x^0 = 1
	if (exp < 0)	return 1 / power(x, -exp);   // x-exp = 1/xexp
	return x*power(x, exp - 1); // xexp = x * xexp-1
}



//====================================================================
// Algorithm				: fib()
// (1) State the problem	: Find the n'th fibonacci number
// (2) Find and handle BC	: n<=1: fib=n
// (3) Find and handle RC	: n>1: fib = fib(n-1)+fib(n-2)
// (4) Argue that RC -> BC	: In RC, n>1 and the recursive calls decrease 
//							  at most 2. Hence, the smallest value of n 
//							  in any recursive call is 0, the BC
//====================================================================
unsigned int fib(unsigned int n)
{
	if (n == 1 || n == 0) return n;
	return fib(n - 1) + fib(n - 2);
}

//====================================================================
// Algorithm				: hanoi()
// (1) State the problem	: Move n disks from pin fromPin to pin toPin
// (2) Find and handle BC	: n=0: Do nothing
// (3) Find and handle RC	: n>0: 
//							  (1) move n-1 disks from fromPin to viaPin via toPin 
//							  (2) move the n'th disk from fromPin to toPin 
//							  (3) move n-1 disks from viaPin to toPin via fromPin
// (4) Argue that RC -> BC	: In RC, n>0 and the recursive calls decrease 
//							  with 1 by each recursive call. Hence, eventually n=0, 
//							  the BC
//							  in any recursive call is 0, the BC
//====================================================================
void hanoi(unsigned int nDisks, int fromPin, int toPin, int viaPin)
{
	if (nDisks > 0)
	{
		hanoi(nDisks - 1, fromPin, viaPin, toPin);
		cout << "Move disk " << nDisks << " from pin " << fromPin << " to pin " << toPin << endl;
		hanoi(nDisks - 1, viaPin, toPin, fromPin);
	}
}