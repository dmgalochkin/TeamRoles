#include "DataAnalyst.h"
DataAnalyst::DataAnalyst() : Analyst::Analyst()
{
  this->bigDataPlatform = "Google BigQuery";
  this->dataVisualizationTool = "Datawrapper";
}

DataAnalyst::DataAnalyst(int age_, int salary_,
            const std::string & name_, int workExperience_,
            const std::string & reportFormat_, int numberOfAnalysisTools_,
            std::string* analysisTools_,
            const std::string & bigDataPlatform_,
            const std::string & dataVisualizationTool_
            ) : Analyst(age_, salary_,
                      name_, workExperience_,
                      reportFormat_,numberOfAnalysisTools_,
                      analysisTools_)
{
  if (bigDataPlatform_.empty())
    throw "big data platform can't be empty";
  this->bigDataPlatform = bigDataPlatform_;
  if (dataVisualizationTool_.empty())
    throw "data visualization tool can't be empty";
  this->dataVisualizationTool = dataVisualizationTool_;
}

DataAnalyst::DataAnalyst(const DataAnalyst& p) : Analyst::Analyst(p)
{
  this->bigDataPlatform = p.bigDataPlatform;
  this->dataVisualizationTool = p.dataVisualizationTool;
}


std::string DataAnalyst::GetBigDataPlatform()
{
  return this->bigDataPlatform;
}

void DataAnalyst::SetBigDataPlatform(const std::string & bigDataPlatform_)
{
  if (bigDataPlatform_.empty())
    throw "big data platform can't be empty";
  this->bigDataPlatform = bigDataPlatform_;
}

std::string DataAnalyst::GetDataVisualizationTool()
{
  return this->dataVisualizationTool;
}

void DataAnalyst::SetDataVisualizationTool(const std::string & dataVisualizationTool_)
{
  if (dataVisualizationTool_.empty())
    throw "data visualization tool can't be empty";
  this->dataVisualizationTool = dataVisualizationTool_;
}

std::string DataAnalyst::GetRole()
{
  return "DataAnalyst";
}

void DataAnalyst::print(std::ostream& o)
{
  o << "Role: " << this->GetRole() << '\n';
  o << "Name: " << this->name << '\n';
  o << "Age: " << this->age << '\n';
  o << "Salary: " << this->salary << '\n';
  o << "Work Experience: " << this->workExperience << '\n';
  o << "Report format: " << this->reportFormat << '\n';
  o << "Analysis tools: ";
  for (int i = 0; i < this->numberOfAnalysisTools; ++i)
  {
    o << this->analysisTools[i] << ' ';
  }
  o << '\n';
  o << "BigData Platform: " << this->bigDataPlatform << '\n';
  o << "Data Visualization Tool: " << this->dataVisualizationTool << '\n';
  o << '\n';
}

void DataAnalyst::read(std::istream& i)
{
  i >> this->name >> this->age >> this->salary >> this->workExperience >> this->reportFormat;
  if (this->age <= 0)
    throw "Can't create employee with non positive age";
  if (this->salary <= 0)
    throw "Can't create employee with non positive salary";
  if (this->salary < 20000)
    throw "Analyst can't have salary less than 20000 RUB";
  if (this->workExperience < 1)
    throw "Analyst can't have work experience less than 1 years ";

  i >> this->numberOfAnalysisTools;
  if (this->numberOfAnalysisTools < 0)
    throw "Analyst can't have number of analysis tools less than 0";
  if (this->numberOfAnalysisTools != 0)
  {
    this->analysisTools = new std::string[this->numberOfAnalysisTools];
    for (int j = 0; j < this->numberOfAnalysisTools; ++j)
      i >> this->analysisTools[j];
  }
  i >> this->bigDataPlatform >> this->dataVisualizationTool;
}