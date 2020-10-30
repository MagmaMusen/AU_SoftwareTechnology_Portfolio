#pragma once
#include "../Toolkit/Node.h"
#include <algorithm>


// Manhattan distance - heuristic used for grid which allows movement in 4 directions
double manhattan(Node* from, Node* to)
{
	return abs(static_cast<double>(to->x) - from->x) + abs(static_cast<double>(to->y) - from->y);
}


// Diagonal distance - heuristics used for grid which allows movement in 8 directions
double diagonal(Node* from, Node* to)
{
	return 	max(
		abs(static_cast<double>(to->x) - from->x),
		abs(static_cast<double>(to->y) - from->y)
	);
}


// Euclidian distance - heuristics used for grid which allows movement in any direction
double euclidian(Node* from, Node* to)
{
	return 	sqrt(
		(to->x - from->x) * (to->x - from->x) +
		(to->y - from->y) * (to->y - from->y)
	);
}



double zero(Node* from, Node* to)
{
	return 0;
}