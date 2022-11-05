#pragma once
#include "../JSONLib/ReadSellRates.h"
#include "ITransaction.h"
#include <iostream>
#include"../ExhangerStaticLib/SellRate.h"

class Sell : public ITransaction
{
	SellRate r;
public:
	void setSpread() override;
	float getSpread() override;
	float getRate(); //zwracam value czyli mnoznik
	void checkCurrencyFrom()override;
	bool checkAmount()override;
	void setCurrencyFrom(std::string currencyFrom)override;
	void setAmount(float amount)override;
	float getAmount()override;
	std::string getCurrency() override;
	void setCurrencyTo(std::string currencyTo)override;

	float calculateExchangeValue() override;
	void printCalculatedValue() override;
	float calculateExchangeValueWantedAmount(float wantedAmount) override;
};