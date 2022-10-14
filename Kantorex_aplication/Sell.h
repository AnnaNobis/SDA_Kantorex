#pragma once
#include "mapOfRateAndCurrency.h"
#include "Transaction.h"

class Sell : public ITransaction
{
public:
	void setSpread(float spread = 0.95) override;
	float getRate(); //zwracam value czyli mnoznik 
	float calculateExchangeValue() override;

};

