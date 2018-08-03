
#include <iostream>

#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(Score& score) :
	_score(score)
{
	_score.AddObserver(this);	
}

ScoreBoard::~ScoreBoard()
{
	_score.RemoveObserver(this);
}

void ScoreBoard::DisplayScore()
{
	std::cout << "[ScoreBoard] The score is now " << _score.GetRuns() << " / " << _score.GetWickets() << std::endl;
}

void ScoreBoard::Update()
{
	DisplayScore();
}
