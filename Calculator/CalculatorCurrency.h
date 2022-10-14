#pragma once
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include "../Kantorex_aplication/RawData.h"
//mapa z vectora raw data dodaj
class CalculatorCurrency 
{

public:
	CalculatorCurrency(std::string transaction);
	std::map<std::string, float> createMapCodeRate();
	float getRate();
	void insertAmount();
	//void chooseDesiredCurrency();
	float Exchange();

	float getSpread();
	void setSpread(float spread=1.05);

	float setCurrency(float currency);

	float& UpdateBalace();
	std::string txtBase();

private:
	
	float _amount;
	float _spread;
	std::string _currencyFrom;
	std::string _currencyTo;
};

