#pragma once
#include <vector>
#include <queue>
#include "../Toolkit/Node.h"

using Graphs::Node;


// Priority queue
// DataType: The type of data to store in the priority queue
// PRiorityType: The type of the priority parameter (defaults to double)
template<typename DataType, typename PriorityType = double>
class PriorityQueue
{
	// Priority queue node: Contains a graph node pointer and a priority
	class PQNode
	{
		public:
			PQNode(const DataType& d, const PriorityType& p) : data(d), priority(p) {}
			DataType data;
			PriorityType priority;
	};

	// PQNode comparator: The ()-operator returns true iff left node's priority is 
	// higher thatn the right node's
	struct CompareNodes
	{
		bool operator()(const PQNode& l, const PQNode& r) const
		{
			return l.priority > r.priority;
		}
	};

	priority_queue<PQNode, vector<PQNode>, CompareNodes> pq;

public:
	void push(const DataType& data, const PriorityType& pri) { pq.push(PQNode(data, pri)); }
	void pop() { pq.pop(); }
	DataType top() { return pq.top().data; }
	bool isEmpty()	{		return pq.empty();	}
};



