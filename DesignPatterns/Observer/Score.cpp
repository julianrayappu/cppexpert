
#include <iostream>
#include "Score.h"

Score::Score() :
	_runs(0), 
	_wickets(0)
{}

Score::~Score()
{}

int Score::GetRuns() const
{
	return _runs;
}

void Score::AddRuns(int runs)
{
	_runs += runs;
	std::cout << "That's " << runs << " more runs." << std::endl;
	//NotifyObservers(); // choose not to notify observers for runs, only for wickets
}

int Score::GetWickets() const
{
	return _wickets;
}

void Score::AddWicket()
{
	_wickets++;
	NotifyObservers();
}
