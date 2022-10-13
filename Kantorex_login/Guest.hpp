#pragma once
#include "ICurrentUser.hpp"
//#include "Display.hpp"

class Guest : public ICurrentUser
{
private:
	//Display display;
public:
	void displayStartScreen() override;
	virtual ~Guest() {}
};

