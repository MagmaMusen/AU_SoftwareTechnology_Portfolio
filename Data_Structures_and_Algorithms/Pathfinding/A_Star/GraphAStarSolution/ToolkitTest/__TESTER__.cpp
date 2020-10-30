#pragma comment(lib,"../x64/Debug/Toolkit.lib")
#include "../Toolkit/GraphToolkit.h"


using namespace std;
using namespace Graphs;


void main()
{
	Graph graph;
	Graph weightedGraph;

	readNodeList(graph, "example-graph-nodelist.txt");
	print(graph);
}