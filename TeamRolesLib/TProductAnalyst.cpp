#include "TProductAnalyst.h"
TProductAnalyst::TProductAnalyst() : TAnalyst::TAnalyst()
{
  this->numberOfProductMetrics = 0;
  this->productMetrics = nullptr;
  this->abTestingTool = "Adobe Target";
  this->role = "ProductAnalyst";
}

TProductAnalyst::TProductAnalyst(int age_, int salary_,
                                 const std::string & name_, int workExperience_,
                                 const std::string & reportFormat_, int numberOfAnalysisTools_,
                                 std::string* analysisTools_,
                                 int numberOfProductMetrics_, std::string* productMetrics_,
                                 const std::string & abTestingTool_
                               ) : TAnalyst(age_, salary_,
                                            name_, workExperience_,
                                            reportFormat_, numberOfAnalysisTools_,
                                            analysisTools_)
{
  if (abTestingTool_.empty())
    throw "A/B testing tool can't be empty";
  this->abTestingTool = abTestingTool_;
  if (numberOfProductMetrics_ < 0)
    throw "TProductAnalyst can't have number of product metrics less than 0";
  this->numberOfProductMetrics = numberOfProductMetrics_;
  if (this->numberOfProductMetrics != 0)
  {
    this->productMetrics = new std::string[this->numberOfProductMetrics];
    for (int i = 0; i < this->numberOfProductMetrics; ++i)
      this->productMetrics[i] = productMetrics_[i];
  }
  this->role = "ProductAnalyst";
}

TProductAnalyst::TProductAnalyst(const TProductAnalyst& p) : TAnalyst::TAnalyst(p)
{
  this->abTestingTool = p.abTestingTool;
  this->numberOfProductMetrics = p.numberOfProductMetrics;
  if (this->numberOfProductMetrics != 0)
  {
    this->productMetrics = new std::string[this->numberOfProductMetrics];
    for (int i = 0; i < this->numberOfProductMetrics; ++i)
      this->productMetrics[i] = p.productMetrics[i];
  }
}

TProductAnalyst::~TProductAnalyst()
{
  if (this->numberOfProductMetrics && this->productMetrics != nullptr)
    delete[] this->productMetrics;
}


int TProductAnalyst::GetNumberOfProductMetrics()
{
  return this->numberOfProductMetrics;
}

std::string* TProductAnalyst::GetProductMetrics()
{
  std::string* productMetrics_ = new std::string[this->numberOfProductMetrics];
  for (int i = 0; i < this->numberOfProductMetrics; ++i)
    productMetrics_[i] = this->productMetrics[i];
  return productMetrics_;
}

void TProductAnalyst::SetProductMetrics(int numberOfProductMetrics_,
                                        std::string* productMetrics_)
{
  if (numberOfProductMetrics_ < 0)
    throw "TProductAnalyst can't have number of product metrics less than 0";
  if (this->productMetrics != nullptr)
    delete[] this->productMetrics;
  this->numberOfProductMetrics = numberOfProductMetrics_;
  if (this->numberOfProductMetrics != 0)
  {
    this->productMetrics = new std::string[this->numberOfProductMetrics];
    for (int i = 0; i < this->numberOfProductMetrics; ++i)
      this->productMetrics[i] = productMetrics_[i];
  } else {
    this->productMetrics = nullptr;
  }
}


std::string TProductAnalyst::GetAbTestingTool()
{
  return this->abTestingTool;
}

void TProductAnalyst::SetAbTestingTool(const std::string & abTestingTool_)
{
  if (abTestingTool_.empty())
    throw "A/B testing tool can't be empty";
  this->abTestingTool = abTestingTool_;
}

void TProductAnalyst::Read(std::istream& i)
{
  int age_;
  int salary_;
  std::string name_;
  int workExperience_;
  std::string reportFormat_;
  int numberOfAnalysisTools_;
  std::string* analysisTools_ = nullptr;
  int numberOfProductMetrics_;
  std::string* productMetrics_ = nullptr;
  std::string abTestingTool_;

  i >> name_ >> age_ >> salary_ >> workExperience_ >> reportFormat_;


  i >> numberOfAnalysisTools_;
  if (numberOfAnalysisTools_ > 0)
  {
    analysisTools_ = new std::string[numberOfAnalysisTools_];
    for (int j = 0; j < numberOfAnalysisTools_; ++j)
      i >> analysisTools_[j];
  }

  i >> numberOfProductMetrics_;
  if (numberOfProductMetrics_ > 0)
  {
    productMetrics_ = new std::string[numberOfProductMetrics_];
    for (int j = 0; j < numberOfProductMetrics_; ++j)
      i >> productMetrics_[j];
  }

  i >> abTestingTool_;


  TProductAnalyst::SetAge(age_);
  TProductAnalyst::SetSalary(salary_);
  TProductAnalyst::SetWorkExperience(workExperience_);
  TProductAnalyst::SetReportFormat(reportFormat_);
  TProductAnalyst::SetAnalysisTools(numberOfAnalysisTools_, analysisTools_);
  TProductAnalyst::SetProductMetrics(numberOfProductMetrics_, productMetrics_);
  TProductAnalyst::SetAbTestingTool(abTestingTool_);

  delete[] analysisTools_;
  delete[] productMetrics_;
}