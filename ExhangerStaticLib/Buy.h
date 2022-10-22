﻿#pragma once
//#include "RateCurrrencyMap.h"
#include "../JSONLib/ReadBuyRates.h"
#include "ITransaction.h"
#include <iostream>


class Buy : public ITransaction
{
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
};