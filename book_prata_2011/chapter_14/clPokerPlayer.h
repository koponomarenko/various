#pragma once

#include "clPerson.h"
#include <cstdlib>
#include <time.h>

class clPokerPlayer : virtual public clPerson
{
	static bool bFirstCall;

public:
	clPokerPlayer(void) {}
	clPokerPlayer(std::string sFName, std::string sLName) : clPerson(sFName, sLName) {}
	virtual ~clPokerPlayer(void) {}

	int Draw()
	{
		if (bFirstCall)
		{
			srand(time(NULL));
			bFirstCall = false;
		}

		return rand() % 52 + 1;
	}
};

bool clPokerPlayer::bFirstCall = true;