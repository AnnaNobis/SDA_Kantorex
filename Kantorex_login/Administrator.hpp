#pragma once
#include "ILoggedUser.hpp"

class Administrator : public ILoggedUser
{
public:
	Administrator();
	ILoggedUser::AllowedOperations getAllowedOperations() override;
	virtual void setAllowedOperations(AllowedOperations operations) override;
	virtual void setCanSell(bool canSell) override;
	virtual void setCanBuy(bool canBuy) override;
	virtual void setCanBalance(bool canBalance) override;
	virtual void setCanReport(bool canReport) override;
	void displayAllowedOperations() override;
	virtual ~Administrator() {}
};

