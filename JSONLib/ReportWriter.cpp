#include "ReportWriter.h"
#include <fstream>
#include "json/json.hpp"
using json = nlohmann::ordered_json;

std::string ReportWriter::filePath = "json.json";

void to_json(json& j, const ReportData& data) {
	j = {
	{"transactionNumber", data._ID},
	{"date", data._date},
	{"time", data._time},
	{"currency", data._currency},
	{"amount", data._cashAmount},
	{"user", data._userId} };
}

bool ReportWriter::checkIfFileExist(std::string filePath)
{
	std::ifstream checkedFile(filePath);
	return checkedFile.good();
}

ReportWriter::ReportWriter(std::string filePath)
{
}

void ReportWriter::setFilePath(std::string filePath)
{
	ReportWriter::filePath = filePath;
}

void ReportWriter::writeReport(ReportData data)
{
	if (checkIfFileExist(ReportWriter::filePath)) {
		writeToExistingReport(data);
	}
	else {
		writeNewReport(data);
	}
}

void ReportWriter::writeNewReport( ReportData data) {

	std::ofstream stream(ReportWriter::filePath);
	json j;
	std::vector<ReportData> vectorToWrite;
	vectorToWrite.push_back(data);
	j = json(vectorToWrite);
	stream << std::setw(4) << j << std::endl;
}

void ReportWriter::writeToExistingReport(ReportData data)
{
	std::vector<ReportData>fileData = ReportReader::readReport(ReportWriter::filePath);
	fileData.push_back(data);

	std::ofstream stream(filePath);
	json j;
	j = json(fileData);
	stream << std::setw(4) << j << std::endl;
}