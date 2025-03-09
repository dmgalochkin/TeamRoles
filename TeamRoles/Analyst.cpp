#include "Analyst.h"
Analyst::Analyst() : Employee::Employee()
{
  this->reportFormat = "PDF";
  this->numberOfAnalysisTools = 0;
  this->analysisTools = nullptr;
}

Analyst::Analyst(int age_, int salary_,
                     const std::string & name_, int workExperience_,
                     const std::string & reportFormat_, int numberOfAnalysisTools_,
                     std::string* analysisTools_) : Employee::Employee(age_, salary_, name_, workExperience_)
{
  if (workExperience_ < 1)
    throw "Analyst can't have work experience less than 1 years ";
  if (salary_ < 20000)
    throw "Analyst can't have salary less than 20000 RUB";

  if (reportFormat_.empty())
    throw "report format can't be empty";
  this->reportFormat = reportFormat_;

  if (numberOfAnalysisTools_ < 0)
    throw "Analyst can't have number of analysis tools less than 0";
  this->numberOfAnalysisTools = numberOfAnalysisTools_;
  if (this->numberOfAnalysisTools != 0)
  {
    this->analysisTools = new std::string[this->numberOfAnalysisTools];
    for (int i = 0; i < this->numberOfAnalysisTools; ++i)
      this->analysisTools[i] = analysisTools_[i];
  }
}

Analyst::Analyst(const Analyst& p) : Employee::Employee(p)
{
  this->reportFormat = p.reportFormat;
  this->numberOfAnalysisTools = p.numberOfAnalysisTools;
  if (this->numberOfAnalysisTools != 0)
    if (this->numberOfAnalysisTools != 0)
    {
      this->analysisTools = new std::string[this->numberOfAnalysisTools];
      for (int i = 0; i < this->numberOfAnalysisTools; ++i)
        this->analysisTools[i] = p.analysisTools[i];
    }
}

Analyst::~Analyst()
{
  if (this->numberOfAnalysisTools && this->analysisTools != nullptr)
    delete[] this->analysisTools;
}


std::string Analyst::GetReportFormat()
{
  return this->reportFormat;
}

int Analyst::GetNumberOfAnalysisTools()
{
  return this->numberOfAnalysisTools;
}

std::string* Analyst::GetAnalysisTools()
{
  std::string* analysisTools_ = new std::string[this->numberOfAnalysisTools];
  for (int i = 0; i < this->numberOfAnalysisTools; ++i)
    analysisTools_[i] = this->analysisTools[i];
  return analysisTools_;
}

void Analyst::SetReportFormat(const std::string &reportFormat_)
{
  if (reportFormat_.empty() == 0)
    throw "report format can't be empty";
  this->reportFormat = reportFormat_;
}

void Analyst::SetAnalysisTools(int numberOfAnalysisTools_,
                      std::string* analysisTools_)
{
  if (numberOfAnalysisTools_ < 0)
    throw "Analyst can't have number of analysis tools less than 0";
  if (this->analysisTools != nullptr)
    delete[] analysisTools;
  this->numberOfAnalysisTools = numberOfAnalysisTools_;
  if (this->numberOfAnalysisTools != 0)
  {
    this->analysisTools = new std::string[this->numberOfAnalysisTools];
    for (int i = 0; i < this->numberOfAnalysisTools; ++i)
      this->analysisTools[i] = analysisTools_[i];
  } else {
    this->analysisTools = nullptr;
  }
}

void Analyst::SetSalary(int salary_)
{
  if (salary_ < this->salary)
    throw "Cannot decrease salary";
  if (salary_ < 20000)
    throw "Analyst can't have salary less than 20000 RUB";
  this->salary = salary_;
}

void Analyst::SetWorkExperience(int workExperience_)
{
  if (workExperience_ < this->workExperience)
    throw "Cannot decrease work experience";
  if (workExperience_ < 1)
    throw "Analyst can't have work experience less than 1 years ";
  this->workExperience = workExperience_;
}

std::string Analyst::GetRole()
{
  return "Analyst";
}