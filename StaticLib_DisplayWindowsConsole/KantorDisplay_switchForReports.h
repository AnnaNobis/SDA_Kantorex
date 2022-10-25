#pragma once
#include "IKantorDisplay.h"
#include "../Report_Static_Library/LoggedPrinter.hpp"

class KantorDisplay_switchForReports : public IKantorDisplay
{
public:
	void displaySwitchForReports(int reportNumber);
};

