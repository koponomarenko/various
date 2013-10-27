#pragma once

#include <string>
#include <valarray>
#include "clPair.h"


class clWine_1
{
	std::string sLabel_;
	int nYears_;
	clPair< std::valarray<int>, std::valarray<int> > Year_Bottles_;

public:
	clWine_1(void);
	clWine_1(const char * l, int y, const int yr[], const int bot[]);
	clWine_1(const char * l, int y);
	~clWine_1(void);

	void GetBottles();
	void Show() const;
	std::string & Label() { return sLabel_; }
	const std::string & Label() const { return sLabel_; }
	int sum() const { return Year_Bottles_.second().sum(); }
};
