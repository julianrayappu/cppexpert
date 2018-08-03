
#ifndef __CRICKET_GAME__
#define __CRICKET_GAME__

// Game
#include "Score.h"

class CricketGame
{
public:
	explicit CricketGame(Score& score);
	virtual ~CricketGame();

	bool IsGameInPlay() const;

	void BowledOut();
	void CaughtOut();
	void RunOut();

	void Single();
	void Four();
	void Six();
	
private:
	Score& _score;
};

#endif // __CRICKET_GAME__
