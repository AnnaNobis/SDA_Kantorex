#pragma once
#include <memory>
#include "ITransaction.h"
#include "Buy.h"
#include "Sell.h"
#include <string>
#include <algorithm>

enum class OperationSellBuy { SELL=1, BUY=2 };


class Exchanger
{
public:
	OperationSellBuy _chooseOperation;

	Exchanger(OperationSellBuy& chooseOperation, std::string& inputCurrencyFrom, float& inputAmount,
		std::string& inputCurrencyTo);
	//void getCurrency(std::string inputCurrency);
	//void print(int i);
	//void setSpread(float inputSpread);
	//float getSpread();

private:
	std::shared_ptr<ITransaction> transaction = nullptr;
	std::string _inputCurrencyFrom;
	std::string _inputCurrencyTo;
	float _inputAmount;


		//CashBalance cashBalance;
			//cashBalance.cashBalance() { 

			//xxx = cashBalance.getMap();
	//calculateExchangeValue - xxx[currencyFrom / To]- jak dostac sie do mapy;

	//}

//transaction->setSpread(_spread);
//transaction->getSpread();
//transaction->getRate(); //zwracam value czyli mnoznik 
//
//transaction->setCurrencyFrom(_currencyFrom);
//transaction->setAmount(_amount);
//transaction->setCurrencyTo(_currencyTo);
//
//transaction->calculateExchangeValue();
};


