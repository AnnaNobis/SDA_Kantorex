#pragma once
#include <memory>
#include "ITransaction.h"
#include "Buy.h"
#include "Sell.h"
#include <string>
#include <algorithm>
#include <iostream>
#include "../CashBalanceStaticLib/CashBalance.h"

enum class OperationSellBuy { SELL, BUY };
class Exchanger
{
public:
	OperationSellBuy _chooseOperation;
	Exchanger(CashBalance& b, OperationSellBuy chooseOperation, std::string inputCurrencyFrom, float inputAmount, std::string inputCurrencyTo);
	//void rate();
	float getExchangedAmount();
	float getRate();
	//void calculationPrint();
	//void startTransaction();
	std::string getCurrencyForBalance(); //dla Marty CashBAlance
	float getAmountForBalance(); //dla Marty CashBAlance
	void startTransactionGivenAmount(CashBalance& b);
	//void startTransactionAmountDesired();
	//std::shared_ptr<CashBalance> balance = nullptr;

private:
	std::shared_ptr<ITransaction> transaction = nullptr;
	//std::shared_ptr<CashBalance> balance = nullptr; --> tymaczasowo przeniesione do public
	std::string _inputCurrencyFrom;
	std::string _inputCurrencyTo;
	float _inputAmount;
};