#pragma once
#include <string>

class ITransaction
{
protected:
	
	float _spread = 0.00;
	std::string _currencyFrom;
	float _amount = 0.00;
	std::string _currencyTo;
	float _amountToGetFromClient = 0.00;

public:
	//ITransaction();
	virtual void setSpread() = 0;
	virtual float getSpread() = 0;
	virtual float getRate() = 0; //zwracam value czyli mnoznik
	virtual void checkCurrencyFrom() = 0;
	virtual void setCurrencyFrom(std::string  currencyFrom) = 0;
	virtual void setAmount(float amount) = 0;
	virtual float getAmount() = 0;
	virtual std::string getCurrency() = 0;
	virtual void setCurrencyTo(std::string  currencyTo) = 0;
	virtual void printCalculatedValue() = 0;
	virtual bool checkAmount() = 0;
	virtual float calculateExchangeValue() = 0;
	virtual float calculateExchangeValueWantedAmount(float wantedAmount) = 0;
};