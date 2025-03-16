#pragma once
#include "string"
#include "TEmployee.h"

class TAnalyst : public TEmployee {
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

  void SetSalary(int salary_);
  void SetWorkExperience(int workExperience_);

  virtual void Read(std::istream & i) = 0;

  TAnalyst();
  TAnalyst(int age_, int salary_,
           const std::string & name_, int workExperience_,
           const std::string & reportFormat_, int numberOfAnalysisTools_,
           std::string* analysisTools_);
  TAnalyst(const TAnalyst & p);
  ~TAnalyst();
};
