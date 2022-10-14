#pragma once
#include "mapOfRateAndCurrency.h"
#include "Transaction.h"

class Buy : public ITransaction
{

public: 
	Buy();
	void setSpread(float spread=1.05) override;
	float getRate(); //zwracam value czyli mnoznik 
	float calculateExchangeValue() override;
};