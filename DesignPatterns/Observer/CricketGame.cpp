
#include <iostream>
#include "CricketGame.h"

CricketGame::CricketGame(Score& score) :
	_score(score)
{
	std::cout << "Its going to be a great match today!" << std::endl;
}	

CricketGame::~CricketGame()
{
	std::cout << "I promised you it would be a great match. And what a match it was!" << std::endl;
}

bool CricketGame::IsGameInPlay() const
{
	if (_score.GetWickets() < 11)
	{
		return true;
	}

	return false;
}

void CricketGame::BowledOut()
{
	std::cout << "That ball was straight on. He's gone!" << std::endl;
	_score.AddWicket();
}

void CricketGame::CaughtOut()
{
	std::cout << "What a catch!" << std::endl;
	_score.AddWicket();
}

void CricketGame::RunOut()
{
	std::cout << "Run out! What a throw!" << std::endl;
	_score.AddWicket();
}

void CricketGame::Single()
{
	std::cout << "A nice nudge for a quick run" << std::endl;
	_score.AddRuns(1);
}
void CricketGame::Four()
{
	std::cout << "Well hit! And that will reach the boundary" << std::endl;
	_score.AddRuns(4);
}

void CricketGame::Six()
{
	std::cout << "And that's over the fence" << std::endl;
	_score.AddRuns(6);
}
