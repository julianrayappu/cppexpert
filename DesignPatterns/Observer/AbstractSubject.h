
#ifndef __ABSTRACT_SUBJECT__
#define __ABSTRACT_SUBJECT__

#include <list>
#include "AbstractObserver.h"

class AbstractSubject 
{
public:
	AbstractSubject();
	virtual ~AbstractSubject();

	void AddObserver(AbstractObserver*);
	void RemoveObserver(AbstractObserver*);

protected:
	// only subject concrete can call this
	void NotifyObservers();

private:
	std::list<AbstractObserver*> _observers;
};

#endif // __ABSTRACT_SUBJECT__
