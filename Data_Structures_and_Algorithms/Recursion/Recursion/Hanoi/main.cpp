#include<iostream>
#include<fstream>
using namespace std;


enum Pin
{
	PIN_1 = 1,
	PIN_2,
	PIN_3
};


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
void hanoi(unsigned int nDisks, Pin fromPin, Pin toPin, Pin viaPin)
{
	if (nDisks > 0)
	{
		hanoi(nDisks - 1, fromPin, viaPin, toPin);
		cout << "Move disk " << nDisks << " from pin " << fromPin << " to pin " << toPin << endl;
		hanoi(nDisks - 1, viaPin, toPin, fromPin);
	}
}


int main()
{
	//==================================
	// Test hanoi()
	int nDisks = 0;
	do
	{
		cout << "HANOI'S TOWERS: Enter number of disks to move (0 to exit): ";
		cin >> nDisks;
		hanoi(nDisks, Pin::PIN_1, Pin::PIN_3, Pin::PIN_2);
		cout << "Done..." << endl << endl;
	} while (nDisks > 0);

	//==================================

	
	return 0;

}