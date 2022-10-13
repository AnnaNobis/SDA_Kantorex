#pragma once
#include "ICurrentUser.hpp"
//#include "Display.hpp"

class Administrator : public ICurrentUser
{
private:
	//Display screen;
public:
	void displayStartScreen() override;
	virtual ~Administrator() {}
};

