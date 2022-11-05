#include "pch.h"
#include "KantorDisplay_CurrencyTable.h"
#include "../JSONLib/CodeBuySellRate.h"
#include "../JSONLib/ReadSellAndBuyTable.h"


void KantorDisplay_CurrencyTable::displayCurrencyTable()
{
	Table currenciesTable;
	ReadSellAndBuyTable dataTab;

	auto data = dataTab.read();
	currenciesTable.add_row({ "CODE", "BUY RATE", "SELL RATE" });

	std::for_each(data.begin(), data.end(), [&](CodeBuySellRate d)
		{

			std::string tmp_code = d._code;
			std::string tmp_buyR = d._rateBuy;
			std::string tmp_sellR = d._rateSell;

			currenciesTable.add_row({ tmp_code,tmp_buyR,tmp_sellR }); });

	std::cout << currenciesTable << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}
