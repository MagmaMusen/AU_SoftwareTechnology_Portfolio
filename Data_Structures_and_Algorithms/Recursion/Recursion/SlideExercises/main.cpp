#include "SlideExercises.h"
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	//==================================
	// Test sum()
	//int ar[] = { 2, 4, 6, 8, 10 };
	//cout << "sum() test" << endl;
	//cout << "sum(ar, 5) is " << sum(ar, 5) << endl;
	//cout << endl;
	//==================================


	//==================================
	// Test sum2()
	//cout << "sum2() test" << endl;
	//cout << "sum2(5) is " << sum2(5) << endl;
	//cout << endl;
	//==================================


	//==================================
	// Test fac()
	//size_t n = 100;
	//cout << "fac() test" << endl;
	//cout << "fac(" << n << ") is " << fac(n) << endl;
	//cout << endl;
	//==================================

	//==================================
	// Test fac()
	// For tail recursion optimization to work, run code in release 
	// mode - no optimization will take place in debug!
	//cout << "tailfac() test" << endl;
	//cout << "tailfac(" << n << ") is " << tailfac(n) << endl;
	//cout << endl;
	//==================================

	//==================================
	// Test num
	//int n = 0;
	//cout << "num() test" << endl; 
	//cout << "num(7) is: " << endl;
	//num(7);
	//cout << endl;
	//==================================

	//==================================
	// Test power()
	//cout << "power() test" << endl;
	//cout << "power(2,4) is "  << power( 2, 4) << endl;
	//cout << "power(-4,9) is " << power(-4, 9) << endl;
	//cout << "power(2,-3) is " << power( 2,-3) << endl;
	//cout << endl;
	//==================================

	////==================================
	//// Test fib()
	//cout << "fib() test" << endl;
	//cout << "fib(12) is " << fib(12) << endl;
	//cout << endl;
	////==================================

	//for (int i = 1; i < 10; i++)
	//	cout << tailfib(i,0) << endl;



	//==================================
	// Test hanoi()
	int nDisks = 0;
	do
	{
		cout << "HANOI'S TOWERS: Enter number of disks to move: ";
		cin >> nDisks;
		hanoi(nDisks, 1, 3, 2);
	} while (nDisks > 0);

	//==================================

	
	return 0;

}