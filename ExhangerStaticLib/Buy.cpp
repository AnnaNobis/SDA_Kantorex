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

std::string Buy::checkCurrencyFrom(std::string currencyFrom)
{
	std::string answer;
	if (currencyFrom == "PLN")
	{
		std::string answer = "Powinieneœ wybraæ opcje Sell";
	}
	return answer;
}

float Buy::calculateExchangeValue()
{
	float result = _spread * getRate() * _amount;
	return result;
}

void Buy::printCalculatedValue()
{
	std::cout << calculateExchangeValue();
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
