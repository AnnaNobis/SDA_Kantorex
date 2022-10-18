#include "pch.h"
#include "Buy.h"


void Buy::setSpread(float spread)
{
	_spread = spread;
}

float Buy::getSpread()
{
	return _spread;
}

float Buy::getRate()
{
	RateCurrencyMap objTemp;
	auto RateAndCurrency = objTemp.createMapCodeRate();
	float rate = RateAndCurrency[_currencyFrom];
	return rate;
}

float Buy::calculateExchangeValue()
{
	return _spread * getRate() * _amount;
}

void Buy::setCurrencyFrom(std::string  currencyFrom)
{
	currencyFrom = _currencyFrom;
}

void Buy::setAmount(float amount)
{
	_amount = amount;
}

void Buy::setCurrencyTo(std::string  currencyTo)
{
	currencyTo = _currencyTo;
}
