#pragma once

#include <string>

class clGolf
{
	std::string sFullname_;
	int nHandicap_;

public:
	clGolf(const std::string & sName = "", int hc = 0);

	bool Set();
	void Handicap(int hc);
	void Show() const;
};
