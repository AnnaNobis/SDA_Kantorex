#pragma once
#include <vector>
#include <string>
#include "ReportData.h"
class ReportReader
{
public:
	static std::vector<ReportData>readReport(std::string filePath);
};

