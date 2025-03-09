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
  if (bigDataPlatform_.empty() == 0)
    throw "big data platform can't be empty";
  this->bigDataPlatform = bigDataPlatform_;
}

std::string DataAnalyst::GetDataVisualizationTool()
{
  return this->dataVisualizationTool;
}

void DataAnalyst::SetDataVisualizationTool(const std::string & dataVisualizationTool_)
{
  if (dataVisualizationTool_.empty() == 0)
    throw "data visualization tool can't be empty";
  this->dataVisualizationTool = dataVisualizationTool_;
}

std::string DataAnalyst::GetRole()
{
  return "DataAnalyst";
}