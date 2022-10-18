#pragma once
#include<string>
struct ReportData
{
	std::string _ID;
	std::string _date;
	std::string _time;
	std::string _currency;
	double _cashAmount;
	std::string _userId;
	static int count;
	ReportData(std::string date, std::string time, std::string currency, double cashAmount, std::string userId);
	ReportData();


};

