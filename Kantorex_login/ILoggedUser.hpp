#pragma once
#include "User.hpp"
#include <iostream>

class ILoggedUser
{
public:
	struct AllowedOperations
	{
		bool _canSell;
		bool _canBuy;
		bool _canBalance;
		bool _canReport;
		bool _canSetOperations;
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
	virtual bool getCanSetOperationns();
	virtual void setAllowedOperations(AllowedOperations operations);
	virtual void setCanSell(bool canSell);
	virtual void setCanBuy(bool canBuy);
	virtual void setCanBalance(bool canBalance);
	virtual void setCanReport(bool canReport);	
	virtual void displayAllowedOperations();
};

