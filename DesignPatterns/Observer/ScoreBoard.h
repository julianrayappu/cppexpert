
// concrete observer
#ifndef __SCOREBOARD__
#define __SCOREBOARD__

#include "Score.h"

class ScoreBoard : public AbstractObserver
{
public:
	explicit ScoreBoard(Score&);
	virtual ~ScoreBoard();

	void DisplayScore();

	void Update();

private:
	Score& _score;
};

#endif // __SCOREBOARD__
