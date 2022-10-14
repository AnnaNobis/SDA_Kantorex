#pragma once
#include "Cash.h"
#include <map>
#include <algorithm>

class CashBalance: public Cash
{ 
protected:
	std::map <std::string, float> _curriencyAndAmount;

public: 
	CashBalance();
	virtual void updateBalance();
};

