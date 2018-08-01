
// ArrayStack.h

#ifndef __ARRAY_STACK__
#define __ARRAY_STACK__

#include <ostream>
#include "Stack.h"

using namespace std;

template <class T>
class ArrayStack : public Stack<T> {

public:
	ArrayStack(int maxSize);

	virtual ~ArrayStack() {}

	virtual void push(const T& val);

	virtual T pop();

	virtual void toStream(ostream&) const;

	template <typename S>
	friend ostream& operator<<(ostream&, const ArrayStack<S>&);

private:
	const int _maxSize;
	int _top;
	T* _array;
};

template <typename S>
ostream& operator<<(ostream&, const ArrayStack<S>&);

#endif // __ARRAY_STACK__
