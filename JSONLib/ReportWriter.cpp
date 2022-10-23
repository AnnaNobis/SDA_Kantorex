#include "ReportWriter.h"
#include <fstream>
#include "json/json.hpp"
#include <string>
using json = nlohmann::ordered_json;

std::string ReportWriter::filePath = "freshReport.json";

void to_json(json& j, const ReportData& data) {
	j = {
	{"transactionNumber", data._ID},
	{"date", data._date},
	{"time", data._time},
	{"currency_from", data._currencyFrom},
	{"amount_from", data._cashAmountFrom},
	{"currency_to", data._currencyTo},
	{"amount_to", data._cashAmountTo} };
}

bool ReportWriter::checkIfFileExist()
{
	std::ifstream checkedFile(filePath);
	return checkedFile.good();
}



void ReportWriter::changePath(std::string newPath)
{
	filePath = newPath;
}

void ReportWriter::writeReport(ReportData data)
{
	if (checkIfFileExist()) {
		writeToExistingReport(data);
	}
	else {
		writeNewReport(data);
	}
}

void ReportWriter::writeNewReport(ReportData data) {
	ReportData::count = 1;

	std::ofstream stream(ReportWriter::filePath);
	json j;
	std::vector<ReportData> vectorToWrite;
	vectorToWrite.push_back(data);
	j = json(vectorToWrite);
	stream << std::setw(4) << j << std::endl;
}

void ReportWriter::writeToExistingReport(ReportData data)
{
	std::vector<ReportData>fileData = ReportReader::readReport();
	int x = std::stoi(fileData[fileData.size() - 1]._ID)+1;
	//ReportData::count = std::stoi(fileData[fileData.size() - 1]._ID);
	
	data._ID = std::to_string(x);
	fileData.push_back(data);

	std::ofstream stream(filePath);
	json j;
	j = json(fileData);
	stream << std::setw(4) << j << std::endl;
}

void ReportWriter::getTransactionID()
{
}
