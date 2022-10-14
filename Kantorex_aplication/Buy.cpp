#include "Buy.h"

void Buy::setSpread(float spread)
{
	_spread = spread;
}

float Buy::getRate()
{
	auto getRate = createMapCodeRate();
	
	float rate = getRate[_currency];
	return rate;
}
