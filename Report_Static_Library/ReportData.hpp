#pragma once
#include <string>
struct ReportData
{
	//std::string _date = "15.10.2022";
	//std::string _time = "15:01";
	//std::string _currency = "EUR";
	//double _cashAmount = 200;
	//std::string _userId = "admin";
	std::string _ID;

	std::string _date ;
	std::string _time ;
	std::string _currency ;
	double _cashAmount ;
	std::string _userId ;
	//int _ID ;
	static int count;
	ReportData(std::string date, std::string time, std::string currency, double cashAmount, std::string userId);
	ReportData();
	//void setNewId();
	void setID();
	//ReportData(std::string date, std::string time, std::string currency, std::string cashAmount, std::string userId);
	//ReportData();
	//void setNewId();
	std::string getDate();
};