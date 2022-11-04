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
		std::map < std::string, float> rates = r.getSellRates();
		float rate = rates[_currencyTo];
		return rate;

}
void Sell::checkCurrencyFrom()
{
	std::string answer;
	if (_currencyFrom != "PLN")
	{
		std::string answer = "Powinieneœ wybraæ opcje Buy";
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
	float resultTemp = _spread / getRate() * _amount;
	float result = round(resultTemp); //*10000 / 10000; // wychodza bez miejsc po przecinku


	return result;
}
void Sell::printCalculatedValue()
{
	std::cout << "Exchanged gross amount: " << calculateExchangeValue() << "  in currency:  " << _currencyTo << std::endl;
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