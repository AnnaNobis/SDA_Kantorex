#include "pch.h"
#include "Exchanger.h"

Exchanger::Exchanger(OperationSellBuy& chooseOperation, std::string& inputCurrencyFrom, float& inputAmount, std::string& inputCurrencyTo)
	: 
	_chooseOperation(chooseOperation),
	_inputCurrencyFrom(inputCurrencyFrom),
	_inputAmount(inputAmount),
	_inputCurrencyTo(inputCurrencyTo)
{
	if (chooseOperation == OperationSellBuy::BUY)
	{
		transaction= std::make_shared<Buy>();
	}
	else if (chooseOperation == OperationSellBuy::SELL)
	{
		transaction = std::make_shared<Sell>();
	}



	//transaction->setCurrencyFrom(_inputCurrencyFrom);
	//transaction->setCurrencyTo(_inputCurrencyTo);
	//transaction->setAmount(_inputAmount);
	//transaction->getRate();
	//transaction->getSpread();
	//transaction->setSpread(_spread);

};

void Exchanger::startTransaction()
{
	if (transaction->checkAmount() == true)
	{
		transaction->calculateExchangeValue();
		transaction->printCalculatedValue();
	}
}
//void Exchanger::print(int i)
//{
//	switch (i) 
//	{
//	case 1:
//		std::cout << "Podaj Walute do wymiany "<<std::endl;
//		break;
//	case 2:
//		std::cout << "Podaj kwote" << std::endl;
//		break;
//
//	case 3:
//		std::cout << "Podaj Walute docelow¹" << std::endl;
//		break;
//	
//	case 4:
//		std::cout << "Czy chcesz ustawic marze? : " << std::endl;
//		break;		
//	case 5:
//		std::cout << "Podaj wysokoœæ mar¿y : " << std::endl;
//		break;	
//	case 6:
//		std::cout << "Mar¿a wynosi : " << std::endl;
//		break;
//
//	}
//}
//
//void Exchanger::setSpread(float inputSpread)
//{
//	this->_spread = inputSpread;
//	transaction->setSpread(_spread);
//}
//
//float Exchanger::getSpread()
//{
//	transaction->getSpread();
//
//	return _spread;
//}

//void Exchanger::startExchangerDisplay()
//{
//	print(1);
//	std::cin >> _inputCurrencyFrom;
//	transaction->setCurrencyFrom(_inputCurrencyFrom);
//
//
//	print(2);
//	std::cin >> _inputAmount;
//	
//	print(3);
//	std::cin >> _inputCurrencyTo;
//
//	print(4);
//	std::cin >> _yesOrNO;
//
//	
//}