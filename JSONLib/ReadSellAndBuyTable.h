#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "CodeBuySellRate.h"

class ReadSellAndBuyTable
{	static std::string filePath;
public:
	std::vector<CodeBuySellRate> read();

};

