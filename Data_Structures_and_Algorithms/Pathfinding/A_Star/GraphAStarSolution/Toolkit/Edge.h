#pragma once
#include <ostream>
using std::ostream;



namespace Graphs
{
	class Node;

	class Edge
	{
	public:
		Edge(Node* f = nullptr, Node* t = nullptr, int w = 1);

		Node* from;
		Node* to;
		int weight;

		friend ostream& operator<<(ostream& out, Edge& e);
	};
}

