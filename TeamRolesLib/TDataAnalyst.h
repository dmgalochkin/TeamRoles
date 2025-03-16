#pragma once
#include <string>
#include "TAnalyst.h"


class TDataAnalyst : public TAnalyst {
protected:
  std::string bigDataPlatform;
  std::string dataVisualizationTool;

public:
  std::string GetBigDataPlatform();
  std::string GetDataVisualizationTool();

  void SetBigDataPlatform(const std::string & bigDataPlatform_);
  void SetDataVisualizationTool(const std::string & dataVisualizationTool_);

  void Read(std::istream & i);

  TDataAnalyst();
  TDataAnalyst(int age_, int salary_,
               const std::string & name_, int workExperience_,
               const std::string & reportFormat_, int numberOfAnalysisTools_,
               std::string* analysisTools_,
               const std::string & bigDataPlatform_,
               const std::string & dataVisualizationTool_);
  TDataAnalyst(const TDataAnalyst & p);
};