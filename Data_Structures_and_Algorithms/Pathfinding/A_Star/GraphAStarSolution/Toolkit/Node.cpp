#include <string>
#include "Node.h"

namespace Graphs
{
	Node::Node(string d) : label(d), cost(0), prev(nullptr), x(0), y(0)
	{

	}

	ostream& operator<<(ostream& out, Node& g)
	{
		out << "Node " << g.label << " (cost: " << g.cost;
		if (g.prev)
		{
			out << ", prev: " << g.prev->label;
		}

		out << "): neighbors: ";
		for (vector<Edge*>::iterator ix = g.neighbors.begin(); ix != g.neighbors.end(); ++ix)
		{
			out << (*ix)->to->label << " (w" << (*ix)->weight << "), ";
		}
		return out;
	}
}