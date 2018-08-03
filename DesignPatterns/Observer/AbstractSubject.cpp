
#include <algorithm>
#include <iostream>

#include "AbstractSubject.h"


AbstractSubject::AbstractSubject(){
	_observers.clear();	
}

AbstractSubject::~AbstractSubject()
{
	std::cout << "AbstractSubject destroyed" << std::endl;
}

void AbstractSubject::AddObserver(AbstractObserver* observer)
{
	_observers.push_back(observer);
}

void AbstractSubject::RemoveObserver(AbstractObserver* observer)
{
	std::list<AbstractObserver*>::iterator iterToDelete;
	iterToDelete = std::find(_observers.begin(), _observers.end(), observer);
	if (iterToDelete != _observers.end())
	{
		_observers.erase(iterToDelete);
	}

	std::cout << "Observer removed" << std::endl;
}

void AbstractSubject::NotifyObservers()
{
	for (AbstractObserver* observer : _observers)
	{
		observer->Update();
	}
}
