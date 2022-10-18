#include "pch.h"
#include "ReportData.h"
#include "ReportData.h"
int ReportData::count = 0;

ReportData::ReportData(std::string date, std::string time, std::string currency, double cashAmount, std::string userId) :
	_date(date),
	_time(time),
	_currency(currency),
	_cashAmount(cashAmount),
	_userId(userId)
{
	/*setNewId();*/
	count++;
	_ID = std::to_string(count);
}


ReportData::ReportData()
{
	count++;
	_ID = std::to_string(count);
}