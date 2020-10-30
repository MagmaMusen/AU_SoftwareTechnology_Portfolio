#pragma once
#include <stdexcept>


template<typename T>
class LinkedList
{
public:
	LinkedList() 
	: tail(nullptr), head(nullptr), size(0)
	{
	}

	LinkedList(const LinkedList& other)
	: head(nullptr), tail(nullptr), size(0)
	{
		if (&other == this) return;
		if (other.length() == 0) return;

		copyContents(other);

		size = other.size;

	}

	LinkedList<T>& operator=(const LinkedList<T>& rhs)
	{

		LinkedList<T> retVal;
		if (rhs.length() == 0) return retVal;
		
		clear();

		copyContents(rhs);

		size = rhs.size;

		return retVal;
	}


	~LinkedList()
	{
		clear();
	}

	void insert(const T& data, unsigned int index)
	{
		if (index == 0)
		{
			headInsert(data);
			return;
		}

		if(index == size)
		{
			tailInsert(data);
			return;
		}

		Node* temp = get(index-1);
		temp->next = new Node(data, temp->next);
		++size;
	}


	void tailInsert(const T& data)
	{
		if (size == 0)
		{
			headInsert(data);
			tail = head;
			return;
		}

		tail->next = new Node(data, tail->next);
		tail = tail->next;
		++size;
	}


	void remove(const unsigned int index)
	{
		if (index == 0)
		{
			headRemove();
			return;
		}


		Node* temp = get(index-1);
		if (!temp->next) throw std::out_of_range("index out of range");

		Node* condemned = temp->next;
		temp->next = condemned->next;
		delete condemned;
		--size;

		if (size == 0)	// removed last element
			tail = nullptr;
		else if (index == size)
			tail = get(size - 1);
	}


	unsigned int length() const
	{
		return size;
	}

	T& operator[](unsigned int index)
	{
		return get(index)->data;
	}

	void headInsert(const T& data)
	{
		head = new Node(data, head);
		++size;

		if (size == 1) 
			tail = head;
	}


	void headRemove()
	{
		if (head)
		{
			Node* temp = head->next;
			delete head;
			head = temp;
			--size;
		}

		if (size == 0)
			tail = nullptr;
	}

	void clear()
	{
		while (head) headRemove();
		head = nullptr;
		tail = nullptr;
	}




private:

	class Node
	{
		public:
		Node(const T& d = T(), Node* n = nullptr) : data(d), next(n) {}
		T data;
		Node* next;
	};


	Node* get(unsigned int index) const
	{
		if(index >= length())throw std::out_of_range("index out of range");
		Node* cursor = head;

		for (unsigned int i = 0; i < index; i++)
		{
			cursor = cursor->next;
		}
		return cursor;
	}

	void copyContents(const LinkedList& src)
	{
		// Do a deep copy
		headInsert(src.head->data);	// Copy first node
		Node* cursor = head;
		Node* otherCursor = src.head;

		while (otherCursor->next)
		{
			cursor->next = new Node(otherCursor->next->data);
			otherCursor = otherCursor->next;
			cursor = cursor->next;
		}

		tail = cursor;
	}

	Node* tail;
	Node* head;
	unsigned int size;
};
