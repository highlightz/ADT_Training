#include "checkbook.h"

bool Checkbook::writeCheck( float amount )
{
	if ( amount > balance )
		return false;

	balance -= amount;
	lastCheck = amount;
	return true;
}
