#pragma once

int sum(int* ar, int n);
double fac(size_t n);
double tailfac(size_t n, double acc=1.0);
void num(unsigned int n);
int sum2(int n);
double power(int x, int exp);
unsigned int fib(unsigned int n);
unsigned int tailfib(
	unsigned int targetN,		// The target number
	unsigned int curN,			// The current level 
	unsigned int curFibNumber = 0,	// The Fibonacci number for the current level of recursion	[fib(n)]
	unsigned int nextFibNumber = 1);// The Fibonacci number for the next level of recursion		[fib(n+1)]
void hanoi(unsigned int nDisks, int fromPin, int toPin, int viaPin);


