#pragma once
#include <string>

class ITransaction
{
protected:

	float _spread=0.00;
	std::string _currencyFrom;
	float _amount=0.00;
	std::string _currencyTo;

public:
	//ITransaction();
	virtual void setSpread(float spread) = 0;
	virtual float getSpread() = 0;
	virtual float getRate() = 0; //zwracam value czyli mnoznik
	virtual std::string checkCurrencyFrom(std::string currencyFrom)=0;
	virtual void setCurrencyFrom(std::string  currencyFrom)=0;
	virtual void setAmount(float amount) = 0;
	virtual void setCurrencyTo(std::string  currencyTo) = 0;
	virtual void printCalculatedValue()=0;
	virtual bool checkAmount()=0;

	virtual float calculateExchangeValue() = 0;


};
