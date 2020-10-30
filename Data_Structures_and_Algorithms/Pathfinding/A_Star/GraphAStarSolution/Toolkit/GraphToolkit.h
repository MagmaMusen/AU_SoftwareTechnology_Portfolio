#pragma once

#include"Node.h"

using namespace std;


namespace Graphs
{
	typedef vector<Node*> Graph;	// Vector is used to hold the complete Graph - makes life easier
	typedef Graph::iterator GraphIter;	// Iterator for a Graph
	typedef vector<Edge*> EdgeList;
	typedef vector<Edge*>::iterator EdgeListIter;

	const string DELIMITERS = ":, ";
	const string LABEL_WEIGHT_SEPARATOR = "'";
	const string COMMENT_PREFIX = "//";

	//===============================================================
	// PRE:		
	// POST:	If a Node with label = lbl is in graph, it is returned. 
	//			Otherwise, nullptr is returned
	//===============================================================
	Node* findNode(Graph& g, string lbl);

	//===============================================================
	// PRE:		
	// POST:	All nodes in 'g' have been printed
	//===============================================================
	void print(Graph& g);

	//===============================================================
	// PRE:		File 'filename' contains a definition of a graph of this format:
	//			
	//			// C-style single-line comments allowed
	//			// Definition of A with neighbors B and C
	//			// and B with neighbors D and A
	//			A: B, C
	//			B: D, A
	// POST:	'graph' is read from the file 'filename'. Format of the file:
	// NOTE:	If directed = false, "A: B" will add an edge A-> and an edge B->A
	//
	//===============================================================
	void readNodeList(Graph& graph, string filename, bool directed = true);


	//===============================================================
	// PRE:		File 'filename' contains a definition of a graph of this format:
	//			
	//			// Definition of edges (a,b) of weight 3 and
	//			// (b,c) of weight 6
	//			a b 3
	//			b c 6
	//
	// POST:	'graph' is read from the file 'filename'. Format of the file:
	//
	// NOTE:	If directed = false, the def. "a b 3" will result in an 
	//			edge a->b AND an edge b-a, both of weight 3
	//===============================================================
	void readEdgeList(Graph& graph, string filename, bool directed = true);


	//===============================================================
	// PRE:		
	// POST:	All nodes in 'g' have been reset so that they are 
	//			unmarked and have the defined (default infinite) cost
	//===============================================================
	void reset(Graph g, int cost = INT_MAX);


	//===============================================================
	// PRE:		
	// POST:	If Node n is in graph, true is returned
	//			Otherwise, false is returned
	//===============================================================
	bool isInGraph(Graph g, Node* n);


	//===============================================================
	// PRE:		
	// POST:	Path from "from" to "to" has been printed
	//===============================================================
	int printPath(Graph& g, Node* from, Node* to);

	//===============================================================
	// PRE:		
	// POST:	A size x size grid of four-way connected nodes 
	//			has been created
	//===============================================================
	void createFourWayGrid(Graph& graph, int size);

	//===============================================================
	// PRE:		
	// POST:	The node at [row, col] has been made a wall, i.e., 
	//			all neighbouring nodes are disconnected
	//===============================================================
	void createWall(Graph& graph, int row, int col);


}


