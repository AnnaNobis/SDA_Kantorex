#pragma once
#include "mapOfRateAndCurrency.h"
#include "Transaction.h"

class Buy :Transaction
{
private:
	float _spread;
	float _currency;
public: 
	void setSpread(float spread=1.05);

	float getRate() //zwracam value czyli mnoznik 
	
};

