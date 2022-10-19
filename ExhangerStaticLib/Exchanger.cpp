#include "pch.h"
#include "Exchanger.h"

Exchanger::Exchanger(OperationSellBuy& chooseOperation) : _chooseOperation(chooseOperation)
{
	startExchangerDisplay();

	if (chooseOperation == OperationSellBuy::BUY)
	{
		transaction = std::make_shared<Buy>();

	}
	else if (chooseOperation == OperationSellBuy::SELL)
	{
		transaction = std::make_shared<Sell>();
	}


	transaction->setCurrencyFrom(_inputCurrencyFrom);
	transaction->setCurrencyTo(_inputCurrencyTo);
	transaction->setAmount(_inputAmount);
	transaction->getRate();
	transaction->getSpread();
	transaction->setSpread(_spread);
	transaction->calculateExchangeValue();

};

void Exchanger::print(int i)
{
	switch (i) 
	{
	case 1:
		std::cout << "Podaj Walute do wymiany "<<std::endl;
		break;
	case 2:
		std::cout << "Podaj kwote" << std::endl;
		break;

	case 3:
		std::cout << "Podaj Walute docelow¹" << std::endl;
		break;
	
	case 4:
		std::cout << "Czy chcesz ustawic marze? : " << std::endl;
		break;	
	case 5:
		std::cout << "Mar¿a wynosi : " << std::endl;
		break;

	}
}

void Exchanger::startExchangerDisplay()
{
	print(1);
	std::cin >> _inputCurrencyFrom;

	print(2);
	std::cin >> _inputAmount;
	
	print(3);
	std::cin >> _inputCurrencyTo;

	print(4);
	std::cin >> _yesOrNO;
	if (_yesOrNO == "yes")
	{

	}
	else if (_yesOrNO == "no")
	{
		print(5);

	}
}