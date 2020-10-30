#pragma once
#include "../Toolkit/GraphToolkit.h"
#include <queue>

using Graphs::Node;

class PriorityQueue
{
	struct PQElement
	{
		PQElement(Node* n, int p) : node(n), pri(p) {}
		Node* node;
		int pri;
		bool operator<(const PQElement& rhs) const
		{
			return pri < rhs.pri;
		}
	};



public:
	void push(Node* node, int pri) { pq.push(PQElement(node, pri)); }

	Node* front() const
	{
		return pq.top().node;
	}

	void pop()
	{
		pq.pop();
	}

	bool isEmpty() const
	{
		return pq.empty();
	}

private:
	priority_queue<PQElement> pq;
};
