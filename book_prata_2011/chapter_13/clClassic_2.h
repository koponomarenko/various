#pragma once

#include "clCd_2.h"

class clClassic_2 : public clCd_2
{
	char * pszPrimaryWork_;

public:
	clClassic_2(char * szPrimaryWork, char * szPerformers, char * szLabel, int nSelections, double nPlayTime);
	clClassic_2(char * szPrimaryWork, const clCd_2 & d);
	clClassic_2();
	clClassic_2(const clClassic_2 & c);
	virtual ~clClassic_2(void);

	clClassic_2 & operator=(const clClassic_2 & c);
};
