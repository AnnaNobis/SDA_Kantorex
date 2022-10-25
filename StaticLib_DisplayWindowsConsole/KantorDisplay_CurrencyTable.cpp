#include "pch.h"
#include "KantorDisplay_CurrencyTable.h"

void KantorDisplay_CurrencyTable::displayCurrencyTable()
{
		Table currenciesTable;

		currenciesTable.add_row({ "SYM", "COUNTRY", "CURRENCY", "UNIT", "CURRENCY BALANCE", "BUY", "SELL" });
		currenciesTable.add_row({ "USD", "USA", "dolar", "100", "10000", "5.20", "4.90" });
		currenciesTable.add_row({ "EUR", "Europa", "euro", "100", "5000", "5.00", "4.50" });
		currenciesTable.add_row({ "CHF", "Szwajcaria", "frank szwajcarski", "100", "20000", "5.50", "5.00" });

		// center align 'Director' column
		currenciesTable.column(2).format()
			.font_align(FontAlign::center);

		// right align 'Estimated Budget' column
		currenciesTable.column(3).format()
			.font_align(FontAlign::right);

		// right align 'Release Date' column
		currenciesTable.column(4).format()
			.font_align(FontAlign::right);

		// center-align and color header cells
		for (size_t i = 0; i < 7; ++i)
		{
			currenciesTable[0][i].format()
				.font_color(Color::yellow)
				.font_align(FontAlign::center)
				.font_style({ FontStyle::bold });
		}

		std::cout << currenciesTable << std::endl;
		std::cout << std::endl << std::endl << std::endl;

	
}
