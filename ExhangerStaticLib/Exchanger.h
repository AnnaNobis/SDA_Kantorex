#pragma once
#include<memory>
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
	Exchanger(OperationSellBuy& chooseOperation);

	void startExchangerDisplay();

	//void getCurrency(std::string inputCurrency);
	void print(int i);


private:
	std::shared_ptr<ITransaction> transaction;
	std::string _inputCurrencyFrom;
	std::string _inputCurrencyTo;
	std::string _yesOrNO;
	float _inputAmount;
	float _spread;
	float _result;



  };


//transaction->setSpread(_spread);
//transaction->getSpread();
//transaction->getRate(); //zwracam value czyli mnoznik 
//
//transaction->setCurrencyFrom(_currencyFrom);
//transaction->setAmount(_amount);
//transaction->setCurrencyTo(_currencyTo);
//
//transaction->calculateExchangeValue();