#pragma once
#include "RateCurrrencyMap.h"
#include "ITransaction.h"

class Buy : public ITransaction
{
public:
	
	void setSpread(float spread = 1.05) override;
	float getSpread() override;
	float getRate(); //zwracam value czyli mnoznik 
	std::string checkCurrencyFrom(std::string currencyFrom)override;
	bool checkAmount()override;
	void setCurrencyFrom(std::string currencyFrom)override;
	void setAmount(float amount)override;
	void setCurrencyTo(std::string  currencyTo)override;
	float calculateExchangeValue() override;
	void  printCalculatedValue() override;
};