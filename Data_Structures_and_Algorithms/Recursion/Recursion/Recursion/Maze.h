#pragma once
#include<cstdlib>
#include<string>
#include<list>

using namespace std;

class Room
{
public:

	enum Dir
	{ 
		NORTH, EAST, SOUTH, WEST
	};

	const int maxDir = WEST + 1;

	// Constructor
	Room(string n) : name(n)
	{
		for (int i = 0; i < maxDir; i++)
		{
			neighbours[i] = nullptr;
		}
		visited = false;
	}
	bool visited;
	Room* neighbours[4];
	string name;
};

ostream& operator<<(ostream& out, Room& r);

bool solveMaze(Room* room);

void testMaze();