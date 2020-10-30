#include "Edge.h"
#include "Node.h"
#include<string>
#include<ostream>


namespace Graphs
{ 
	ostream& operator<<(ostream& out, Edge& e)
	{
		out <<  e.from->label << " -> " << e.to->label << ", w = " << e.weight << endl;
		return out;
	}


	Edge::Edge(Node* f, Node* t, int w)
		: from(f), to(t), weight(w)
	{}

}