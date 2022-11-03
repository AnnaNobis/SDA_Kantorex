#pragma once
#include "../JSONLib/RawData.h"
#include "../JSONLib/Currency.h"
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include <algorithm>
class CashBalance
{
private:
	std::map<std::string, float>balanceMap;
public:
	CashBalance();
	void createMapp();
	bool checkCashRegister(float exchangedCash, std::string finalCurrency);
	void showBalance();
	void updateBalance(std::string currency, float inputCash, float exchangedCash, std::string finalCurrency);

};
