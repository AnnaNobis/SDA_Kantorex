#pragma once
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include "../Kantorex_aplication/Transaction.h"
#include "../Kantorex_aplication/RawData.h"
#include "../Kantorex_aplication/Buy.h"
#include "../Kantorex_aplication/Sell.h"
#include <memory>



//mapa z vectora raw data dodaj
class CalculatorCurrency 
{

public:
	CalculatorCurrency(std::string buyOrSell);
	
	void insertAmount();
	float Exchange();
	float& UpdateBalace();

private:
	
	float _amount;
	float _spread;
	std::string _currencyFrom;
	std::string _currencyTo;
};

