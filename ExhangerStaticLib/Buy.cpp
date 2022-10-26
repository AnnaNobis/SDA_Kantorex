#include "pch.h"
#include "Buy.h"
#include "..\JSONLib\ReportWriter.h"
#include "..\Report_Static_Library\ReportData.hpp"
#include "..\Kantorex_login\User.hpp"

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
	float resultTemp = _spread * getRate() * _amount;
	float result = round(resultTemp);//* 10000 / 10000; // wychodza bez miejsc po przecinku

	return result;
}

void Buy::printCalculatedValue()
{
	std::cout << "Exchanged amount:  " << calculateExchangeValue() << "  in currency: " << _currencyTo << std::endl;

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
