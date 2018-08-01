
#ifndef __STACK_H__
#define __STACK_H__

#include <ostream>

using namespace std;

template <class T>
class Stack
{
public:
	Stack() {};
	virtual ~Stack() {}

	// push new value val to the top of the stack
	virtual void push(const T& val) = 0 ;
	
	// get top most item from the stack and remove it
	virtual T pop() = 0 ;
};

#endif // __STACK_H__
