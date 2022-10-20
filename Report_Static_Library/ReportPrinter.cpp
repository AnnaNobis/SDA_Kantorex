#include "pch.h"
#include "ReportPrinter.hpp"

ReportPrinter::ReportPrinter(std::string filePath)
{
	dailyData = dataFromFile.readReport(filePath);

}

void ReportPrinter::ReadDailyReport(std::string date)
{
	std::vector<ReportData> tmp_data(dailyData.size());

	auto it = std::copy_if(dailyData.begin(), dailyData.end(), tmp_data.begin(), [&](ReportData r) 
		{
			
		return r._date == date;
		});

	tmp_data.resize(std::distance(tmp_data.begin(), it));

	std::cout << std::endl << "################DAILY REPORT: " << date << " ################" << std::endl;

	std::for_each(tmp_data.begin(), tmp_data.end(), [](ReportData l) {
		std::cout << std::endl 
			<< "amount: " << l._cashAmount 
			<< "    currency: " << l._currency 
			<< "    date: " << l._date 
			<< "    time: " << l._time
			<< "    user: " << l._userId
			<< "    user: " << l._ID
			<< std::endl; });


}

void ReportPrinter::ReadCurrencyReport(std::string currency)
{

	std::vector<ReportData> tmp_data(dailyData.size());

	auto it = std::copy_if(dailyData.begin(), dailyData.end(), tmp_data.begin(), [&](ReportData r)
		{

			return r._currency == currency;
		});

	tmp_data.resize(std::distance(tmp_data.begin(), it));

	std::cout << std::endl << "################CURRENCY REPORT: " << currency << " ################" << std::endl;

	std::for_each(tmp_data.begin(), tmp_data.end(), [](ReportData l) {
		std::cout << std::endl
			<< "amount: " << l._cashAmount
			<< "    currency: " << l._currency
			<< "    date: " << l._date
			<< "    time: " << l._time
			<< "    user: " << l._userId
			<< "    user: " << l._ID
			<< std::endl; });


}
