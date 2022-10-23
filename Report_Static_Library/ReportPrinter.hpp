#pragma once
#include <vector>
#include "ReportData.hpp"
#include "JSONReportReader.hpp"
#include <algorithm>
#include <iostream>
class ReportPrinter
{
	std::vector<ReportData> dailyData;
	//JSONReportReader dataFromFile;
public:
	
	ReportPrinter(std::string filePath);
	void ReadDailyReport(std::string date);
	void ReadCurrencyReport(std::string currency);
};
//class RawData
//{
//	JSONReader dataFromFile;
//	std::vector<Currency> rawDataVector;
//public:
//	RawData() {
//		rawDataVector = dataFromFile.readCurrencies();
//	}
//	std::vector<Currency> getRawData() {
//		return rawDataVector;
//	};
//};