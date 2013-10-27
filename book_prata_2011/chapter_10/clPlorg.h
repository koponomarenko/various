#pragma once

#include <iostream>

class clPlorg
{
	static const int kNameLen = 20;
	char szName_[kNameLen];
	int nContentmentIndex_;

public:
	clPlorg(const char * szName = "Plorga");

	inline void SetCI(int nNewCI);
	inline void DisplayInfo() const;
};



inline void clPlorg::SetCI(int nNewCI)
{
	nContentmentIndex_ = nNewCI;
}


inline void clPlorg::DisplayInfo() const
{
	std::cout << "Name: " << szName_ << std::endl;
	std::cout << "Contentment Index: " << nContentmentIndex_ << std::endl;
}