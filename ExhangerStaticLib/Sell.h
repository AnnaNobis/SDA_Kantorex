#pragma once
#include "RateCurrrencyMap.h"
#include "ITransaction.h"

class Sell : public ITransaction
{
public:
	void setSpread(float spread = 0.95) override;
	float getSpread() override;
	float getRate(); //zwracam value czyli mnoznik 

	void setCurrencyFrom(std::string  currencyFrom)override;
	void setAmount(float amount)override;
	void setCurrencyTo(std::string  currencyTo)override;

	float calculateExchangeValue() override;
};