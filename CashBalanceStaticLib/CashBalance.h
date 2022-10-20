#pragma once
#include "../JSONLib/RawData.h"
#include "../JSONLib/Currency.h"
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include <algorithm>
#include "../ExhangerStaticLib/Exchanger.h"

class CashBalance
{
public:
	std::map<std::string, float>createMapp();
	void showOpeningBalance();
	//float setBalance(int howMuch, std::string input); 
	//auto buy = OperationSellBuy::BUY;
	//Exchanger exchanger();
	void updateBalance();

};