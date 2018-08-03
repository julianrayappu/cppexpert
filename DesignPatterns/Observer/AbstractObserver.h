
#ifndef __ABSTRACT_OBSERVER__
#define __ABSTRACT_OBSERVER__

class AbstractObserver
{
public:
	AbstractObserver() {}
	virtual ~AbstractObserver() {}

	virtual void Update() = 0;
};

#endif // __ABSTRACT_OBSERVER__
