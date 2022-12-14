#include "pch.h"
#include "Exchanger.h"

const std::string red("\033[0;37;41m");
const std::string reset("\033[0m");

Exchanger::Exchanger(CashBalance& b, OperationSellBuy chooseOperation, std::string inputCurrencyFrom, float inputAmount, std::string inputCurrencyTo)
	:
	_chooseOperation(chooseOperation),
	_inputCurrencyFrom(inputCurrencyFrom),
	_inputAmount(inputAmount),
	_inputCurrencyTo(inputCurrencyTo)
{
	//balance = std::make_shared<CashBalance>();
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
	transaction->setSpread();
	transaction->checkCurrencyFrom();
	startTransactionGivenAmount(b);
	//transaction->getRate();
	//transaction->getSpread();
	//transaction->setSpread();
}
//void Exchanger::calculationPrint()
//{
//	if (transaction->checkAmount() == true)
//	{
//		transaction->printCalculatedValue();
//	}
//}

std::string Exchanger::getCurrencyForBalance()
{
	return transaction->getCurrency();
}
float Exchanger::getAmountForBalance()
{
	return transaction->getAmount();
}
float Exchanger::getExchangedAmount()
{
	return transaction->calculateExchangeValue();
}
float Exchanger::getRate()
{
	return transaction->getRate();
}
void Exchanger::startTransactionGivenAmount(CashBalance& b)
{
	//CashBalance checkBalance; //cash balance shared pointer.

	if (_chooseOperation == OperationSellBuy::BUY)
	{
		bool check1 = b.checkCashRegister(transaction->calculateExchangeValue(), _inputCurrencyTo);
		if (transaction->checkAmount() == true && check1 == true)
		{

			transaction->calculateExchangeValue();
			transaction->printCalculatedValue();
			b.updateBalance(_inputCurrencyFrom, _inputAmount, transaction->calculateExchangeValue(), _inputCurrencyTo);
			ReportData data(_inputCurrencyFrom, static_cast<double>(_inputAmount), _inputCurrencyTo, transaction->calculateExchangeValue());
			ReportWriter::writeReport(data);
		}
		else if (check1!=true)
		{
			std::cout <<red<< "Not enough money in cash register, available money: " << b.getAmountOfCurrency(_inputCurrencyTo)<<reset<<std::endl;
		}
			else if (transaction->checkAmount() != true)
		{
			std::cout << red<<"Incorrect amount " <<reset<< std::endl;
		}

	}
	else if (_chooseOperation == OperationSellBuy::SELL)
	{
		bool check2 = b.checkCashRegister(transaction->calculateExchangeValue(), _inputCurrencyTo);
		if (transaction->checkAmount() == true && check2 == true)
		{
			transaction->calculateExchangeValue();
			transaction->printCalculatedValue();
			b.updateBalance(_inputCurrencyFrom, _inputAmount, transaction->calculateExchangeValue(), _inputCurrencyTo);
			ReportData data(_inputCurrencyFrom, static_cast<double>(_inputAmount), _inputCurrencyTo, transaction->calculateExchangeValue());
			ReportWriter::writeReport(data);
		}
		else if (check2 != true)
		{


			std::cout <<red<< "Not enough money in cash register, available money: " << b.getAmountOfCurrency(_inputCurrencyTo) << reset<<std::endl;
		}
		else if (transaction->checkAmount() != true)
		{
			std::cout << red<< "Incorrect amount "<<reset << std::endl;
		}
	}

}
//void Exchanger::startTransactionAmountDesired()
//{
//	//CashBalance checkBalance;
//	if (/*checkBalance.checkCashRegister() == true &&*/ transaction->checkAmount() == true)
//	{
//		transaction->calculateExchangeValueWantedAmount(_inputAmount);
//		transaction->printCalculatedValue();
//	};
//}
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