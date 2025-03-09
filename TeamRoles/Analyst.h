#pragma once
#include "string"
#include "Employee.h"

class Analyst : Employee {
protected:
  std::string reportFormat;
  int numberOfAnalysisTools;
  std::string* analysisTools;

public:
  std::string GetReportFormat();
  int GetNumberOfAnalysisTools();
  std::string* GetAnalysisTools();

  void SetReportFormat(const std::string & reportFormat_);
  void SetAnalysisTools(int numberOfAnalysisTools_,
                        std::string* analysisTools_);

  std::string GetRole();

  Analyst();
  Analyst(int age_, int salary_,
            const std::string & name_, int workExperience_,
            const std::string & reportFormat_, int numberOfAnalysisTools_,
            std::string* analysisTools_);
  Analyst(const Analyst & p);
  ~Analyst();
};
