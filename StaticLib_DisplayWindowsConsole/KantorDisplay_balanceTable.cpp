#include "pch.h"
#include "KantorDisplay_balanceTable.h"

void KantorDisplay_balanceTable::dislayBalanceTable(CashBalance& b)
{
	Table balanceTable;


	auto data = b.getBalanceMap();
	balanceTable.add_row({ "CURRENCY CODE", "AVAILABLE CASH" });
	for (auto& elem : data)
	{
		std::string temp = std::to_string(elem.second);
		balanceTable.add_row({ elem.first, temp });
	};


	std::cout << balanceTable << std::endl;
	std::cout << std::endl << std::endl << std::endl;
};
