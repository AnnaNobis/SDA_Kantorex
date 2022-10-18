#pragma once
#include "User.hpp"

class ILoggedUser
{
public:
	struct AllowedOperations
	{
		bool _canSell;
		bool _canBuy;
		bool _canBalance;
		bool _canReport;
		bool _canExit;
	};
protected:
	ILoggedUser::AllowedOperations _operations;
public:
	ILoggedUser();
	virtual ILoggedUser::AllowedOperations getAllowedOperations() =0;
	virtual bool getCanSell();
	virtual bool getCanBuy();
	virtual bool getCanBalance();
	virtual bool getCanReport();
	virtual bool getCanExit();
	
};

