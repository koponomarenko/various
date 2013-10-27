#pragma once

#include "clGunslinger.h"
#include "clPokerPlayer.h"

class clBadDude : public clGunslinger, public clPokerPlayer
{
public:
	clBadDude(void) {}
	clBadDude(std::string sFName, std::string sLName, double nTimeToReady = 0, int notches = 0)
		: clPerson(sFName, sLName), clGunslinger(sFName, sLName, nTimeToReady, notches)
	{}
	virtual ~clBadDude(void) {}

	double Gdraw() { return clGunslinger::Draw(); }
	int Cdraw() { return clPokerPlayer::Draw(); }
};

