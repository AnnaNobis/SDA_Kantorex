#include "pch.h"
#include "Sell.h"

void Sell::setSpread(float spread)
{
	_spread = spread;
}

float Sell::getSpread()
{
	return _spread;
}


float Sell::getRate()
{
	RateCurrencyMap objTemp;
	auto RateAndCurrency = objTemp.createMapCodeRate();
	float rate = RateAndCurrency[_currencyTo];
	return rate;
}

float Sell::calculateExchangeValue()
{
	return _spread * _amount / getRate();
}

void Sell::setCurrencyFrom(std::string currencyFrom)
{
	currencyFrom = _currencyFrom;
}

void Sell::setAmount(float amount)
{
	_amount = amount;
}

void Sell::setCurrencyTo(std::string  currencyTo)
{
	currencyTo = _currencyTo;
}
