
// concrete subject

#ifndef __SCORE__
#define __SCORE__

#include "AbstractSubject.h"

class Score : public AbstractSubject
{
public:
	Score();
	virtual ~Score();

	int GetRuns() const;
	void AddRuns(int runs);

	int GetWickets() const;
	void AddWicket();

private:
	int _runs;
	int _wickets;	
};

#endif // __SCORE__
