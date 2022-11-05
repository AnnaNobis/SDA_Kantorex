#include "pch.h"
#include "KantorDisplay_switchForReports.h"
#include "../Report_Static_Library/ReportPrinter.hpp"

void KantorDisplay_switchForReports::displaySwitchForReports(int reportNumber)
{

		switch (reportNumber)
		{
		case 1: //users logger report
		{
			Table reportTransaction3;
			LoggedPrinter printer;

			auto data = printer.ReadLoggReportAll();
			reportTransaction3.add_row({ "DATE & TIME", "SURNAME", "NAME" ,"OPERATION" });
			
			std::for_each(data.begin(), data.end(), [&](LoginData l)
				{

					std::string tmp_dateTime = l._dateAndTime;
					std::string tmp_surname = l._surname;
					std::string tmp_name = l._name;
					std::string loggStatus;
					if (l._isLogged == 0)
					{
						loggStatus = "log out";
					}
					else
					{
						loggStatus = "log in";
					}
					reportTransaction3.add_row({ tmp_dateTime, tmp_surname, tmp_name, loggStatus }); });

			std::cout << reportTransaction3 << std::endl;
			std::cout << std::endl << std::endl << std::endl;


			break;
		}

		case 2: //daily transaction report
		{
			Table reportTransaction;
			ReportPrinter newReport;
			std::cout << "Enter report date, format: dd.mm.yyyy " << std::endl;
			std::string _reportDate;
			std::cin >> _reportDate;
			auto data = newReport.ReadDailyReport(_reportDate);
			reportTransaction.add_row({ "TRANSACTION NO", "DATE","TIME","CURRENCY FROM" ,"CASH AMOUNT FROM ","CURRENCY TO","CASH AMOUNT TO" });
			std::for_each(data.begin(), data.end(), [&](ReportData l)
				{std::string tmp_data = l._ID;
			std::string tmp_date = l._date;
			std::string tmp_time = l._time;
			std::string tmp_currency_from = l._currencyFrom;
			std::string tmp_cash_from = std::to_string(l._cashAmountFrom);
			std::string tmp_currency_to = l._currencyTo;
			std::string tmp_cash_to = std::to_string(l._cashAmountTo);
			reportTransaction.add_row({ tmp_data, tmp_date, tmp_time, tmp_currency_from, tmp_cash_from, tmp_currency_to , tmp_cash_to }); });

			std::cout << reportTransaction << std::endl;
			std::cout << std::endl << std::endl << std::endl;

			break;
		}

		case 3://currency transaction report

			Table reportTransaction2;
			ReportPrinter newReport;
			std::cout << "Enter currency code: e.g. USD, to enter currency report. " << std::endl;
			std::string _reportCurrency;
			std::cin >> _reportCurrency;
			auto data = newReport.ReadCurrencyReport(_reportCurrency);
			reportTransaction2.add_row({ "TRANSACTION NO", "DATE","TIME","CURRENCY FROM" ,"CASH AMOUNT FROM ","CURRENCY TO","CASH AMOUNT TO" });
			std::for_each(data.begin(), data.end(), [&](ReportData l)
				{std::string tmp_data = l._ID;
			std::string tmp_date = l._date;
			std::string tmp_time = l._time;
			std::string tmp_currency_from = l._currencyFrom;
			std::string tmp_cash_from = std::to_string(l._cashAmountFrom);
			std::string tmp_currency_to = l._currencyTo;
			std::string tmp_cash_to = std::to_string(l._cashAmountTo);
			reportTransaction2.add_row({ tmp_data, tmp_date, tmp_time, tmp_currency_from, tmp_cash_from, tmp_currency_to , tmp_cash_to }); });

			std::cout << reportTransaction2 << std::endl;
			std::cout << std::endl << std::endl << std::endl;

			break;

		}

}
