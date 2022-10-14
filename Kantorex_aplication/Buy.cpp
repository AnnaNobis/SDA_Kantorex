#include "Buy.h" 

Buy::Buy() : ITransaction()
{

};


void Buy::setSpread(float spread)
{
	_spread = spread;
}

float Buy::getRate()
{
	mapOfRateAndCurrency objTemp;
	auto RateAndCurrency = objTemp.createMapCodeRate();
	float rate = RateAndCurrency[_currency];
	return rate;
}

float Buy::calculateExchangeValue()
{
	return _spread* getRate()* _amount;
}