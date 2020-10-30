#include"GraphToolkit.h"
using namespace Graphs;


int main()
{
	Graph graph;
	
	readGraph(graph, "example-graph2.txt");
	//readGraph(graph, "Book1.txt");

	print(graph);

	return 0;
}