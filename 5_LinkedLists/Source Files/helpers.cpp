#include "helpers.h"

bool HELP::validateplayerscount(unsigned int num)
{
	if(num>=1 && num<=6)
		return true;
	else 
		return false;
}