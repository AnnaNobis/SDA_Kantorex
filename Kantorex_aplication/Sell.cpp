#include "Sell.h" 

void Sell::setSpread(float spread)
{
	_spread = spread;
}

float Sell::getRate()
{
	mapOfRateAndCurrency objTemp;
	auto RateAndCurrency = objTemp.createMapCodeRate();
	float rate = RateAndCurrency[_currency];
	return rate;
}

float Sell::calculateExchangeValue()
{
	return _spread * getRate() * _amount;
}