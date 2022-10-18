#pragma once
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include <algorithm>

class CashBalance
{
private:

	std::map<std::string, double> _cashRegister
	{
		{"PLN", 10.000}, {"EUR", 5.000 }, {"USD", 3.000}, {"GBP", 5.000}
	};

public:
	CashBalance(std::map<std::string, double> cashRegister);
	void printBalance();
	float setBalance(int howMuch, std::string input); 
	void updateBalance();

};