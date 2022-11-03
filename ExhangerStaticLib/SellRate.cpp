#include "pch.h"
#include "SellRate.h"

SellRate::SellRate()
{
	ReadSellRates r;
	sellRates = r.read();
}


