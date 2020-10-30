#include "Maze.h"
#include<iostream>

using namespace std;

extern list<string> path;

ostream& operator<<(ostream& out, Room& r)
{
	out << r.name << ":" << endl;
	if(r.neighbours[Room::NORTH] != nullptr) out << "  N: " << r.neighbours[Room::NORTH]->name << endl;
	if(r.neighbours[Room::EAST] != nullptr)  out << "  E: " << r.neighbours[Room::EAST]->name << endl;
	if(r.neighbours[Room::SOUTH] != nullptr) out << "  S: " << r.neighbours[Room::SOUTH]->name << endl;
	if(r.neighbours[Room::WEST] != nullptr)  out << "  W: " << r.neighbours[Room::WEST]->name << endl;

	out << endl;

	return out;
}

bool solveMaze(Room* room)
{
	// If this is not a room, or if we've already checked this room,
	// it doesn't lead to an exit
	if ((room == nullptr) || (room->visited == true)) 
		return false;

	room->visited = true;	// Remember that we've visited this room

	// Now we know that we're in a new valid room. Let's check it out

	if (room->name == "EXIT")	// We're at the exit! Yay!
	{
		path.push_front(room->name); // Print room name as part of the solution
		return true;
	}


	// We weren't at the exit, but maybe one of the neighbour shows a way out
	// Let's check it
	for (unsigned int i = 0; i <4; i++)
	{
		if (solveMaze(room->neighbours[i]))
		{
			// We found a way out! Add room name to path as part of the solution
			path.push_front(room->name);
			return true;
		}
	}

	// We found no way out through this room
	return false;
}

