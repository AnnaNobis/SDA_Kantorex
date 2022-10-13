#pragma once
#include "ICurrentUser.hpp"
//#include "Display.hpp"

class Cashier : public ICurrentUser
{
private:
	//Display display;
public:
	void displayStartScreen() override;
	virtual ~Cashier() {}
};

