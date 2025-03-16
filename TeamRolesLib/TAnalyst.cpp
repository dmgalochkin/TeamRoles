#include "TAnalyst.h"
TAnalyst::TAnalyst() : TEmployee::TEmployee()
{
  this->reportFormat = "PDF";
  this->numberOfAnalysisTools = 0;
  this->analysisTools = nullptr;
  this->role = "Analyst";
}

TAnalyst::TAnalyst(int age_, int salary_,
                   const std::string & name_, int workExperience_,
                   const std::string & reportFormat_, int numberOfAnalysisTools_,
                   std::string* analysisTools_) : TEmployee::TEmployee(age_, salary_, name_, workExperience_)
{
  if (workExperience_ < 1)
    throw "TAnalyst can't have work experience less than 1 years ";
  if (salary_ < 20000)
    throw "TAnalyst can't have salary less than 20000 RUB";

  if (reportFormat_.empty())
    throw "report format can't be empty";
  this->reportFormat = reportFormat_;

  if (numberOfAnalysisTools_ < 0)
    throw "TAnalyst can't have number of analysis tools less than 0";
  this->numberOfAnalysisTools = numberOfAnalysisTools_;
  if (this->numberOfAnalysisTools != 0)
  {
    this->analysisTools = new std::string[this->numberOfAnalysisTools];
    for (int i = 0; i < this->numberOfAnalysisTools; ++i)
      this->analysisTools[i] = analysisTools_[i];
  }
  this->role = "Analyst";
}

TAnalyst::TAnalyst(const TAnalyst& p) : TEmployee::TEmployee(p)
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

TAnalyst::~TAnalyst()
{
  if (this->numberOfAnalysisTools && this->analysisTools != nullptr)
    delete[] this->analysisTools;
}


std::string TAnalyst::GetReportFormat()
{
  return this->reportFormat;
}

int TAnalyst::GetNumberOfAnalysisTools()
{
  return this->numberOfAnalysisTools;
}

std::string* TAnalyst::GetAnalysisTools()
{
  std::string* analysisTools_ = new std::string[this->numberOfAnalysisTools];
  for (int i = 0; i < this->numberOfAnalysisTools; ++i)
    analysisTools_[i] = this->analysisTools[i];
  return analysisTools_;
}

void TAnalyst::SetReportFormat(const std::string &reportFormat_)
{
  if (reportFormat_.empty() == 0)
    throw "report format can't be empty";
  this->reportFormat = reportFormat_;
}

void TAnalyst::SetAnalysisTools(int numberOfAnalysisTools_,
                                std::string* analysisTools_)
{
  if (numberOfAnalysisTools_ < 0)
    throw "TAnalyst can't have number of analysis tools less than 0";
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

void TAnalyst::SetSalary(int salary_)
{
  if (salary_ < this->salary)
    throw "Cannot decrease salary";
  if (salary_ < 20000)
    throw "TAnalyst can't have salary less than 20000 RUB";
  this->salary = salary_;
}

void TAnalyst::SetWorkExperience(int workExperience_)
{
  if (workExperience_ < this->workExperience)
    throw "Cannot decrease work experience";
  if (workExperience_ < 1)
    throw "TAnalyst can't have work experience less than 1 years ";
  this->workExperience = workExperience_;
}