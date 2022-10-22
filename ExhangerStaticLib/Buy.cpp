#include "pch.h"
#include "Buy.h"


void Buy::setSpread()
{
	_spread = 1.05;
}

float Buy::getSpread()
{
	return _spread;
}

float Buy::getRate()
{
	ReadBuyRates objTemp;
	auto RateAndCurrency = objTemp.read();
	float rate = RateAndCurrency[_currencyFrom];
	return rate;
}

void Buy::checkCurrencyFrom()
{
	std::string answer;
	if (_currencyFrom == "PLN")
	{
		std::string answer = "Powiniene� wybra� opcje Sell";
		std::cout << answer << std::endl;

	}

}

bool Buy::checkAmount()
{
	if (_amount > 0)
	{
		return true;
	}
}

float Buy::calculateExchangeValue()
{
	float result = _spread * getRate() * _amount;
	return result;
}

void Buy::printCalculatedValue()
{
	std::cout << "Exchanged amount:  " << calculateExchangeValue() << "  in currency: " << _currencyFrom << std::endl;

}

void Buy::setCurrencyFrom(std::string  currencyFrom)
{
	_currencyFrom = currencyFrom;
}

void Buy::setAmount(float amount)
{
	_amount = amount;
}
float Buy::getAmount()
{
	return _amount;
}

std::string Buy::getCurrency()
{
	return _currencyFrom;
}

void Buy::setCurrencyTo(std::string  currencyTo)
{
	_currencyTo = currencyTo;
}
