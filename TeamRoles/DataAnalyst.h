#pragma once
#include <string>
#include "Analyst.h"


class DataAnalyst : public Analyst {
protected:
  std::string bigDataPlatform;
  std::string dataVisualizationTool;

public:
  std::string GetBigDataPlatform();
  std::string GetDataVisualizationTool();

  void SetBigDataPlatform(const std::string & bigDataPlatform_);
  void SetDataVisualizationTool(const std::string & dataVisualizationTool_);

  std::string GetRole() override;

  void print(std::ostream & o);
  void read(std::istream & i);

  DataAnalyst();
  DataAnalyst(int age_, int salary_,
          const std::string & name_, int workExperience_,
          const std::string & reportFormat_, int numberOfAnalysisTools_,
          std::string* analysisTools_,
          const std::string & bigDataPlatform_,
          const std::string & dataVisualizationTool_);
  DataAnalyst(const DataAnalyst & p);
};