#pragma once


template<typename T>
class Queue
{
public:
	virtual void push(const T& elm) = 0;
	virtual void pop() = 0;
	virtual T front() = 0;
	virtual bool isEmpty() = 0;
	virtual ~Queue() {}
};