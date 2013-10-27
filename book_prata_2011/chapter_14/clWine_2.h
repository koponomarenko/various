#pragma once

#include <string>
#include <valarray>
#include "clPair.h"


class clWine_2 : private std::string, private clPair< std::valarray<int>, std::valarray<int> >
{
	int nYears_;

public:
	clWine_2(void);
	clWine_2(const char * l, int y, const int yr[], const int bot[]);
	clWine_2(const char * l, int y);
	~clWine_2(void);

	void GetBottles();
	void Show() const;
	std::string & Label() { return (std::string &)*this; }
	const std::string & Label() const { return (const std::string &)*this; }
	int sum() const { return clPair::second().sum(); }
};
