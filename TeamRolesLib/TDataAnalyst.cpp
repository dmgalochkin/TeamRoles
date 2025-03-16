#include "TDataAnalyst.h"
TDataAnalyst::TDataAnalyst() : TAnalyst::TAnalyst()
{
  this->bigDataPlatform = "Google BigQuery";
  this->dataVisualizationTool = "Datawrapper";
  this->role = "DataAnalyst";
}

TDataAnalyst::TDataAnalyst(int age_, int salary_,
                           const std::string & name_, int workExperience_,
                           const std::string & reportFormat_, int numberOfAnalysisTools_,
                           std::string* analysisTools_,
                           const std::string & bigDataPlatform_,
                           const std::string & dataVisualizationTool_
            ) : TAnalyst(age_, salary_,
                         name_, workExperience_,
                         reportFormat_, numberOfAnalysisTools_,
                         analysisTools_)
{
  if (bigDataPlatform_.empty())
    throw "big data platform can't be empty";
  this->bigDataPlatform = bigDataPlatform_;
  if (dataVisualizationTool_.empty())
    throw "data visualization tool can't be empty";
  this->dataVisualizationTool = dataVisualizationTool_;
  this->role = "DataAnalyst";
}

TDataAnalyst::TDataAnalyst(const TDataAnalyst& p) : TAnalyst::TAnalyst(p)
{
  this->bigDataPlatform = p.bigDataPlatform;
  this->dataVisualizationTool = p.dataVisualizationTool;
}


std::string TDataAnalyst::GetBigDataPlatform()
{
  return this->bigDataPlatform;
}

void TDataAnalyst::SetBigDataPlatform(const std::string & bigDataPlatform_)
{
  if (bigDataPlatform_.empty())
    throw "big data platform can't be empty";
  this->bigDataPlatform = bigDataPlatform_;
}

std::string TDataAnalyst::GetDataVisualizationTool()
{
  return this->dataVisualizationTool;
}

void TDataAnalyst::SetDataVisualizationTool(const std::string & dataVisualizationTool_)
{
  if (dataVisualizationTool_.empty())
    throw "data visualization tool can't be empty";
  this->dataVisualizationTool = dataVisualizationTool_;
}

void TDataAnalyst::Read(std::istream& i)
{
  int age_;
  int salary_;
  std::string name_;
  int workExperience_;
  std::string reportFormat_;
  int numberOfAnalysisTools_;
  std::string* analysisTools_ = nullptr;
  std::string bigDataPlatform_;
  std::string dataVisualizationTool_;

  i >> name_ >> age_ >> salary_ >> workExperience_ >> reportFormat_;


  i >> numberOfAnalysisTools_;
  if (numberOfAnalysisTools_ > 0)
  {
    analysisTools_ = new std::string[numberOfAnalysisTools_];
    for (int j = 0; j < numberOfAnalysisTools_; ++j)
      i >> analysisTools_[j];
  }

  i >> bigDataPlatform_ >> dataVisualizationTool_;


  TDataAnalyst::SetAge(age_);
  TDataAnalyst::SetSalary(salary_);
  TDataAnalyst::SetWorkExperience(workExperience_);
  TDataAnalyst::SetReportFormat(reportFormat_);
  TDataAnalyst::SetAnalysisTools(numberOfAnalysisTools_, analysisTools_);
  TDataAnalyst::SetBigDataPlatform(bigDataPlatform_);
  TDataAnalyst::SetDataVisualizationTool(dataVisualizationTool_);

  delete[] analysisTools_;
}