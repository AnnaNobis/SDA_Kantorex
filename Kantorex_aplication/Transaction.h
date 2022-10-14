#pragma once
#include <string>
class ITransaction
{
protected: 
	float _spread;
	std::string _currency;
	float _amount;

public: 
	ITransaction();
	virtual void setSpread(float spread) = 0;
	virtual float getRate(); //zwracam value czyli mnoznik 
	virtual float calculateExchangeValue();

};

