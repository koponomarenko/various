#include <iostream>
#include <cstring>

#include "clPlorg.h"

using namespace std;

clPlorg::clPlorg(const char * szName)
{
	nContentmentIndex_ = 50; // by default
	
	if (szName)
	{
		strncpy(szName_, szName, (strlen(szName) < kNameLen) ? strlen(szName) : kNameLen - 1);
		szName_[(strlen(szName) < kNameLen) ? strlen(szName) : kNameLen - 1] = '\0';
	}
}

