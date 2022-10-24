#include "pch.h"
#include "ReportPrinter.hpp"

ReportPrinter::ReportPrinter(/*std::string filePath*/)
{
	//std::shared_ptr<ReportReader> dataFromFile
	dailyData = dataFromFile.readReport();

}

std::vector<ReportData> ReportPrinter::ReadDailyReport(std::string date)
{
	std::vector<ReportData> tmp_data(dailyData.size());

	auto it = std::copy_if(dailyData.begin(), dailyData.end(), tmp_data.begin(), [&](ReportData r) 
		{
			
		return r._date == date;
		});

	tmp_data.resize(std::distance(tmp_data.begin(), it));

	//std::cout << std::endl << "################DAILY REPORT: " << date << " ################" << std::endl;

	/*std::for_each(tmp_data.begin(), tmp_data.end(), [](ReportData l) {
		std::cout << std::endl 
			<< "transactionNumber: " << l._ID 
			<< "    date: " << l._date 
			<< "    time: " << l._time 
			<< "    currency_from: " << l._currencyFrom
			<< "    amount_from: " << l._cashAmountFrom
			<< "    currency_to: " << l._currencyTo
			<< "    amount_to: " << l._cashAmountTo
			<< std::endl; });*/
	return tmp_data;


}

std::vector<ReportData> ReportPrinter::ReadCurrencyReport(std::string currency)
{

	std::vector<ReportData> tmp_data(dailyData.size());

	auto it = std::copy_if(dailyData.begin(), dailyData.end(), tmp_data.begin(), [&](ReportData r)
		{

			return r._currencyFrom == currency || r._currencyTo == currency;
		});

	tmp_data.resize(std::distance(tmp_data.begin(), it));

	/*std::cout << std::endl << "################CURRENCY REPORT: " << currency << " ################" << std::endl;

	std::for_each(tmp_data.begin(), tmp_data.end(), [](ReportData l) {
		std::cout << std::endl
			<< "transactionNumber: " << l._ID
			<< "    date: " << l._date
			<< "    time: " << l._time
			<< "    currency_from: " << l._currencyFrom
			<< "    amount_from: " << l._cashAmountFrom
			<< "    currency_to: " << l._currencyTo
			<< "    amount_to: " << l._cashAmountTo
			<< std::endl; });*/

	return tmp_data;
}
