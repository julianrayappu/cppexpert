
// stack.cpp
#include <ostream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "ArrayStack.h"

using namespace std;

// size = 10
// 0 1 2 3 4 5 6 7 8 9
// 
//
template <typename T>
ArrayStack<T>::ArrayStack(int maxSize)
	: Stack<T>(), 
	  _maxSize(maxSize), 
	  _top(-1)
{
	_array = new T[_maxSize];
}


template <typename T>
void ArrayStack<T>::toStream(ostream& ostrm) const
{
	ostrm << "{" ;
	for (int i=0 ; i <= _top ; i++)
	{
		ostrm << _array[i] << ", " ;
	}
	ostrm << "}";
}


template <typename T>
void ArrayStack<T>::push(const T& val)
{
	if ((_top + 1) >= _maxSize)
	{
		stringstream s; 
		s << "Cannot push val " << val 
		  << ". Stack maxsize is " << _maxSize 
		  << " and top is " << _top ;
		throw overflow_error(s.str());
	}

	_top++;	
	_array[_top] = val;
	cout << "pushing " << val << " to stack at position " << _top << endl;
}


template <typename T>
T ArrayStack<T>::pop()
{
	if (_top < 0)
	{
		stringstream s;
		s << "Cannot pop stack anymore" 
		  << ". Stack maxsize is " << _maxSize 
		  << " and top is " << _top ;
		throw underflow_error(s.str());
	}
	
	T val = _array[_top];
	_top--;

	return val;
}


template <typename T>
ostream& operator<<(ostream& lhs, const ArrayStack<T>& stack)
{
	stack.toStream(lhs);
	return lhs;
}


int main()
{
	const int maxSize = 10;
	//Stack<int>& s = ArrayStack<int>(maxSize);  // compile error
	ArrayStack<int> s(maxSize);

	try
	{
		for (int i = 0; i < maxSize + 2 ; i++)
		{
			s.push(i);
			cout << "push (" << i << ") results in : " << s << endl;
		}
	}
	catch (const runtime_error& re)
	{
		cout << "stack push error occurred " << re.what() << endl;
	}

	try
	{
		int value;
		while (true)
		{
			value = s.pop();
			cout << "pop() results in " << value << endl;
		}
	}
	catch(const runtime_error& re)
	{
			cout << "stack pop error occurred " << re.what() << endl;
	}
}

