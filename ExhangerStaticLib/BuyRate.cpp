#include "pch.h"
#include "BuyRate.h"

BuyRate::BuyRate()
{
		ReadBuyRates r;
		buyRates = r.read();
}
