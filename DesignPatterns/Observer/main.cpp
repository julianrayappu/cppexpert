
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Score.h"
#include "ScoreBoard.h"
#include "CricketGame.h"

int GetEvent()
{
	return (rand() % 6) + 1;
}

int main()
{
	Score score;
	ScoreBoard scoreBoard(score);
	CricketGame cricketGame(score);

	srand(time(NULL)); // initialise random numbers;

	int event;
	while (cricketGame.IsGameInPlay())
	{
	 	event = GetEvent();
	 	switch(event) 
	 	{
	 		case 1:
	 			cricketGame.Single();
	 			break;
	 		case 2:
	 			cricketGame.RunOut();
	 			break;
	 		case 3:
	 			cricketGame.CaughtOut();
	 			break;
	 		case 4:
	 			cricketGame.Four();
	 			break;
	 		case 5:
	 			cricketGame.BowledOut();
	 			break;
	 		case 6:
	 			cricketGame.Six();
	 			break;
	 		default:
	 			std::cout << "unexpected event " << event << std::endl;
	 	}
	}

	return 0;
}
