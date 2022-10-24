#pragma once
#include <memory>
#include "ITransaction.h"
#include "Buy.h"
#include "Sell.h"
#include <string>
#include <algorithm>
#include <iostream>

enum class OperationSellBuy { SELL, BUY };

class Exchanger
{
public:
	OperationSellBuy _chooseOperation;
	Exchanger(OperationSellBuy chooseOperation, std::string inputCurrencyFrom, float inputAmount, std::string inputCurrencyTo);
	//void rate();
	void calculationPrint();
	std::string getCurrencyForBalance(); //dla Marty CashBAlance
	float getAmountForBalance(); //dla Marty CashBAlance
	float getExchangedAmount();

private:
	std::shared_ptr<ITransaction> transaction = nullptr;
	std::string _inputCurrencyFrom;
	std::string _inputCurrencyTo;
	float _inputAmount;
};