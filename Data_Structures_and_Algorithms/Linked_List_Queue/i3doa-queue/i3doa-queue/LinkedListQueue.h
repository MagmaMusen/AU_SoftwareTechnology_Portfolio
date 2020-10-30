#pragma once
#include "linkedlist.h"
#include"Queue.h"

template<typename T>
class LinkedListQueue : public Queue<T>
{
public:
	void push(const T& elm)
	{
		list.tailInsert(elm);
	}

	void pop()
	{ 
		if(isEmpty()) 
			throw std::out_of_range("pop from empty queue");
		list.headRemove();			
	}

	T front()
	{
		return list[0];
	}

	bool isEmpty()
	{
		return list.length() == 0;
	}

private:
	LinkedList<T> list;
};
