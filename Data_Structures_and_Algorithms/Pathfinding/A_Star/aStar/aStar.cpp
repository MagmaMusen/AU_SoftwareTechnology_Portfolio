#pragma comment(lib,"../x64/Debug/Toolkit.lib")

#include <iostream>
#include "../Toolkit/GraphToolkit.h"
#include "../Toolkit/PriorityQueue.h"
#include "Heuristics.h"

using namespace Graphs;


int aStar(Graph g, Node* startNode, Node* endNode, double(*h)(Node*, Node*), double hWeight = 1)
{
	reset(g);
	PriorityQueue<Node*> frontier;
	int nNodesVisited = 0;
	startNode->cost = 0;
	
	frontier.push(startNode, startNode->cost + hWeight*h(startNode, endNode));

	while (!frontier.isEmpty())
	{
		Node* current = frontier.top();
		frontier.pop();
		++nNodesVisited;

		if (current == endNode) return nNodesVisited;

		for (EdgeListIter edge = current->neighbors.begin(); edge != current->neighbors.end(); ++edge)
		{
			if (*edge == nullptr || (*edge)->to == nullptr) continue;

			Node *neighbor = (*edge)->to;

			if (neighbor->cost > current->cost + (*edge)->weight)
			{
				neighbor->cost = current->cost + (*edge)->weight;
				neighbor->prev = current;

				frontier.push(neighbor, neighbor->cost + hWeight * h(neighbor, endNode));
			}
		}
	}
	
	return -1;
}


int main()
{
	Graph graph;
	
	createFourWayGrid(graph, 10);

	createWall(graph, 2, 2);
	createWall(graph, 3, 2);
	createWall(graph, 3, 3);
	createWall(graph, 3, 4);
	createWall(graph, 3, 5);
	createWall(graph, 4, 5);
	createWall(graph, 5, 3);
	createWall(graph, 6, 5);
	createWall(graph, 7, 5);
	
	Node* S = findNode(graph, "[5;1]");
	Node* T = findNode(graph, "[3;6]");

	int nNodesVisited = aStar(graph, S, T, manhattan, 5.0);

	cout << "Path:   ";
	printPath(graph, S, T);
	
	cout << endl << "Nodes visited: " << nNodesVisited << endl;

	return 0;
}






