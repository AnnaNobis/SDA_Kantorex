#include "pch.h"
#include "Buy.h"
#include "BuyRate.h"
//#include "..\Kantorex_login\User.hpp"
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
	std::map < std::string, float> rates = r.getBuyRates();
	float rate = rates[_currencyFrom];
	std::cout << "RATE: " << rate << std::endl;
	return rate;
}
void Buy::checkCurrencyFrom()
{
	std::string answer;
	if (_currencyFrom == "PLN")
	{
		std::string answer = "Powinienes wybrac opcje Sell";
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

	//ReportWriter::writeReport(ReportData(_currencyFrom, _amount, _currencyTo, result));
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
float Buy::calculateExchangeValueWantedAmount(float wantedAmount)
{
	_amountToGetFromClient = wantedAmount / (_spread * getRate());
	double result = round(_amountToGetFromClient * 10000) / 100; // wychodza bez miejsc po przecinku
	return result;
}