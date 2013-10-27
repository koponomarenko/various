#include "clCd_1.h"

#include <iostream>
#include <cstring>

clCd_1::clCd_1(char * szPerformers, char * szLabel, int nSelections, double nPlayTime)
{
	using std::strncpy;
	using std::strlen;

	if (szPerformers)
	{
		strncpy(szPerformers_, szPerformers, (strlen(szPerformers) < sizeof(szPerformers_)) ? strlen(szPerformers) : sizeof(szPerformers_) - 1);
		szPerformers_[(strlen(szPerformers) < sizeof(szPerformers_)) ? strlen(szPerformers) : sizeof(szPerformers_) - 1] = '\0';
	}
	else
		szPerformers_[0] = '\0';

	if (szLabel)
	{
		strncpy(szLabel_, szLabel, (strlen(szLabel) < sizeof(szLabel_)) ? strlen(szLabel) : sizeof(szLabel_) - 1);
		szLabel_[(strlen(szLabel) < sizeof(szLabel_)) ? strlen(szLabel) : sizeof(szLabel_) - 1] = '\0';
	}
	else
		szLabel_[0] = '\0';

	nSelections_ = nSelections;
	nPlayTime_ = nPlayTime;
}


clCd_1::clCd_1()
{
	szPerformers_[0] = '\0';
	szLabel_[0] = '\0';
	nSelections_ = 0;
	nPlayTime_ = 0;
}


clCd_1::~clCd_1()
{
}


void clCd_1::Report() const
{
	std::cout << "Performers: " << (szPerformers_[0] ? szPerformers_ : "none") << std::endl;
	std::cout << "Label: " << (szLabel_[0] ? szLabel_ : "none") << std::endl;
	std::cout << "Selections: " << nSelections_ << std::endl;
	std::cout << "PlayTime: " << nPlayTime_ << std::endl;
}

