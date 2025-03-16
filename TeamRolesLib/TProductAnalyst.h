#pragma once
#include <string>
#include "TAnalyst.h"

class TProductAnalyst : public TAnalyst {
protected:
  int numberOfProductMetrics;
  std::string* productMetrics;
  std::string abTestingTool;
public:
  int GetNumberOfProductMetrics();
  std::string* GetProductMetrics();
  std::string GetAbTestingTool();

  void SetProductMetrics(int numberOfProductMetrics_,
                    std::string* productMetrics_);
  void SetAbTestingTool(const std::string & abTestingTool_);

  void Read(std::istream & i);

  TProductAnalyst();
  TProductAnalyst(int age_, int salary_,
                  const std::string & name_, int workExperience_,
                  const std::string & reportFormat_, int numberOfAnalysisTools_,
                  std::string* analysisTools_,
                  int numberOfProductMetrics_, std::string* productMetrics_,
                  const std::string & abTestingTool_);
  TProductAnalyst(const TProductAnalyst & p);
  ~TProductAnalyst();
};