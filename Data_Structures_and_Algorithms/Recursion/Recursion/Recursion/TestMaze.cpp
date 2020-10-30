#include"Maze.h"
#include<iostream>
#include<sstream>
using namespace std;


Room** labyrinth;
list<string> path;

const size_t ROWS(4);
const size_t COLS(4);

//---------------------------------------------------------------
// connectRooms
// Connects room (row, col) with it's neighbour in a given direction 
// AND connects that neighbour back to room (row, col).
// Only directions SOUTH and EAST are necessary, as all connections 
// are two-way
//---------------------------------------------------------------
void connectRooms(int row, int col, Room::Dir dir)
{
	switch (dir)
	{
	case Room::SOUTH:	
		labyrinth[row * 4 + col]->neighbours[Room::SOUTH] = labyrinth[(row + 1) * 4 + col]; 
		labyrinth[(row + 1) * 4 + col]->neighbours[Room::NORTH] = labyrinth[row * 4 + col];
		break;
	case Room::EAST:	
		labyrinth[row * 4 + col]->neighbours[Room::EAST] = labyrinth[row * 4 + col + 1]; 
		labyrinth[row * 4 + col + 1]->neighbours[Room::WEST] = labyrinth[row * 4 + col];
		break;
	
	default:
		break;
	}
}


void testMaze()
{
	// Create labyrinth
	labyrinth = new Room*[ROWS * COLS];
	Room* exit = new Room("EXIT");
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			stringstream name;
			name << "[" << j << ", " << i << "]";
			labyrinth[i * 4 + j] = new Room(name.str());
		}
	}


	// Connect labyrinth 
	// Only east and south - the reverse directions will be "auto-connected"
	connectRooms(0, 0, Room::EAST);
	connectRooms(0, 0, Room::SOUTH);
	connectRooms(0, 1, Room::EAST);
	connectRooms(0, 3, Room::SOUTH);

	connectRooms(1, 0, Room::SOUTH);
	connectRooms(1, 1, Room::SOUTH);
	connectRooms(1, 2, Room::SOUTH);
	connectRooms(1, 2, Room::EAST);
	connectRooms(1, 3, Room::SOUTH);

	connectRooms(2, 0, Room::SOUTH);
	connectRooms(2, 0, Room::EAST);
	connectRooms(2, 2, Room::SOUTH);
	connectRooms(2, 3, Room::SOUTH);

	connectRooms(3, 0, Room::EAST);
	connectRooms(3, 1, Room::EAST);

	labyrinth[3 * 4 + 3]->neighbours[Room::EAST] = exit;


	// Run simulation
	if (!solveMaze(labyrinth[0]))
		cout << "No exit found - you're stuck for eternity!" << endl;
	else
	{
		cout << "Yay! Found an exit" << endl;
		cout << "Path to exit:" << endl;
		for (list<string>::iterator ix = path.begin(); ix != path.end(); ++ix)
			cout << *ix << " > ";
		cout << endl;
	}
}