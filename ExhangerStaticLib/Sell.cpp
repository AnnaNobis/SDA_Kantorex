#include "pch.h"
#include "Sell.h"

void Sell::setSpread()
{
	_spread = 0.95;
}
float Sell::getSpread()
{
	return _spread;
}
float Sell::getRate()
{
	ReadSellRates objTemp;
	auto RateAndCurrency = objTemp.read();
	float rate = RateAndCurrency[_currencyTo];
	return rate;
}
void Sell::checkCurrencyFrom()
{
	std::string answer;
	if (_currencyFrom != "PLN")
	{
		std::string answer = "Powiniene� wybra� opcje Buy";
		std::cout << answer << std::endl;
	}
}
bool Sell::checkAmount()
{
	if (_amount > 0)
		return true;
}
float Sell::calculateExchangeValue()
{
	float result = _spread / getRate() * _amount;
	//ReportWriter::writeReport(ReportData(_currencyFrom, _amount, _currencyTo, result));
	return result;
}
void Sell::printCalculatedValue()
{
	std::cout << "Exchanged amount: " << calculateExchangeValue() << "  in currency:  " << _currencyTo << std::endl;
}
void Sell::setCurrencyFrom(std::string currencyFrom)
{
	_currencyFrom = "PLN";
}
void Sell::setAmount(float amount)
{
	_amount = amount;
}
void Sell::setCurrencyTo(std::string  currencyTo)
{
	_currencyTo = currencyTo;
}
float Sell::getAmount()
{
	return _amount;
}
std::string Sell::getCurrency()
{
	return _currencyTo;
}
float Sell::calculateExchangeValueWantedAmount(float wantedAmount)
{
	_amountToGetFromClient = wantedAmount / (_spread * getRate());
	double result = round(_amountToGetFromClient * 10000) / 100; // wychodza bez miejsc po przecinku
	return result;
}