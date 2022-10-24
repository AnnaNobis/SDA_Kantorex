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
	//CashBalance(OperationSellBuy chooseOperation, std::string inputCurrencyFrom, float inputAmount, std::string inputCurrencyTo);
	std::map<std::string, float>createMapp();
	bool checkCashRegister();
	void showOpeningBalance();
	//float setBalance(int howMuch, std::string input);
	//auto buy = OperationSellBuy::BUY;
	//Exchanger exchanger();
	void updateBalance();
private:
	std::shared_ptr<Exchanger> balance = nullptr;
	OperationSellBuy _sellBuy;
	std::string _inputCurrencyFrom;
	float _inputAmount;
	std::string _inputCurrencyTo;

};