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

std::string Sell::checkCurrencyFrom(std::string currencyFrom)
{
		std::string answer;
		if (currencyFrom != "PLN")
		{
			std::string answer = "Powinieneœ wybraæ opcje Buy";
		}
		return answer;
}

bool Sell::checkAmount()
{
	if(_amount>0)
	return true;
}

float Sell::calculateExchangeValue()
{
	float result = _spread * getRate() * _amount;
	return result;
}

void Sell::printCalculatedValue()
{
	std::cout << calculateExchangeValue();
}
void Sell::setCurrencyFrom(std::string currencyFrom)
{
	currencyFrom = "PLN";
}

void Sell::setAmount(float amount)
{
	_amount = amount;
}

void Sell::setCurrencyTo(std::string  currencyTo)
{
	currencyTo = _currencyTo;
}
