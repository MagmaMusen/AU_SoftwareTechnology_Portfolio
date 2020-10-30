#pragma comment(lib,"../x64/Debug/Toolkit.lib")

#include "../Toolkit/GraphToolkit.h"
#include"PriorityQueue.h"
#include <queue>
#include <iostream>


using namespace std;
using namespace Graphs;


//===================================================================
// Implementation of Dijkstra's using a priority queue as frontier
// This allows early-exit
//===================================================================
int DijkstraPQ(const Graph& g, Node* startNode, Node* endNode)
{
	reset(g);
	PQueue frontier;
	
	Node *v, *next = nullptr;
	int nNodesVisited = 0;

	startNode->cost = 0;
	frontier.push(new PQNode(startNode, startNode->cost));

	while (frontier.size() > 0)
	{
		v = frontier.top()->node;
		frontier.pop();
		++nNodesVisited;
		if (v == endNode) return nNodesVisited;

		for (EdgeListIter edge = v->neighbors.begin(); edge != v->neighbors.end(); ++edge)
		{
			if (*edge == nullptr) continue;
			next = (*edge)->to;
			if (next != nullptr && next->cost > v->cost + (*edge)->weight)
			{
				next->cost = v->cost + (*edge)->weight;
				next->prev = v;
				frontier.push(new PQNode(next, next->cost));
			}
		}
	}
	return -1;
}

//===================================================================
// Implementation of Dijkstra's using a FIFO queue as frontier
// This prohibits early-exit
//===================================================================
int dijkstraFIFO(Graph g, Node* startNode, Node* endNode)
{
	reset(g);
	queue<Node*> frontier;

	Node *v, *next = nullptr;
	int nNodesVisited = 0;

	startNode->cost = 0;
	frontier.push(startNode);

	while (frontier.size() > 0)
	{
		v = frontier.front();
		frontier.pop();
		++nNodesVisited;

		for (EdgeListIter edge = v->neighbors.begin(); edge != v->neighbors.end(); ++edge)
		{
			if (*edge == nullptr) continue;
			next = (*edge)->to;
			if (next != nullptr && next->cost > v->cost + (*edge)->weight)
			{
				next->cost = v->cost + (*edge)->weight;
				next->prev = v;
				frontier.push(next);
			}
		}
	}
	return nNodesVisited;
}


//=======================================
// Test program
//=======================================
int main()
{
	Graph graph;

	// Test Dijkstra's with PQ and FIFO on same graph (US road map)
	readEdgeList(graph, "USRoads.txt",  false);
	
	Node* sanDiego = findNode(graph, "San_Diego");
	Node* washington = findNode(graph, "Washington");

	int nodesVisitedPQ = DijkstraPQ(graph, sanDiego, washington);
	int nodesVisitedFIFO = dijkstraFIFO(graph, sanDiego, washington);

	int pathCost = printPath(graph, sanDiego->label, washington->label);

	cout << endl << "Total cost of path: " << pathCost << endl;
	
	cout << "Nodes visited using FIFO : " << nodesVisitedFIFO << endl;
	cout << "Nodes visited using PQ   : " << nodesVisitedPQ << endl;

	return 0;
}


