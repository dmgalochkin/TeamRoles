#include "ProductAnalyst.h"
ProductAnalyst::ProductAnalyst() : Analyst::Analyst()
{
  this->numberOfProductMetrics = 0;
  this->productMetrics = nullptr;
  this->abTestingTool = "Adobe Target";
}

ProductAnalyst::ProductAnalyst(int age_, int salary_,
                               const std::string & name_, int workExperience_,
                               const std::string & reportFormat_, int numberOfAnalysisTools_,
                               std::string* analysisTools_,
                               int numberOfProductMetrics_, std::string* productMetrics_,
                               const std::string & abTestingTool_
                               ) : Analyst(age_, salary_,
                                  name_, workExperience_,
                                  reportFormat_,numberOfAnalysisTools_,
                                  analysisTools_)
{
  if (abTestingTool_.empty())
    throw "A/B testing tool can't be empty";
  this->abTestingTool = abTestingTool_;
  if (numberOfProductMetrics_ < 0)
    throw "ProductAnalyst can't have number of product metrics less than 0";
  this->numberOfProductMetrics = numberOfProductMetrics_;
  if (this->numberOfProductMetrics != 0)
  {
    this->productMetrics = new std::string[this->numberOfProductMetrics];
    for (int i = 0; i < this->numberOfProductMetrics; ++i)
      this->productMetrics[i] = productMetrics_[i];
  }
}

ProductAnalyst::ProductAnalyst(const ProductAnalyst& p) : Analyst::Analyst(p)
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

ProductAnalyst::~ProductAnalyst()
{
  if (this->numberOfProductMetrics && this->productMetrics != nullptr)
    delete[] this->productMetrics;
}


int ProductAnalyst::GetNumberOfProductMetrics()
{
  return this->numberOfProductMetrics;
}

std::string* ProductAnalyst::GetProductMetrics()
{
  std::string* productMetrics_ = new std::string[this->numberOfProductMetrics];
  for (int i = 0; i < this->numberOfProductMetrics; ++i)
    productMetrics_[i] = this->productMetrics[i];
  return productMetrics_;
}

void ProductAnalyst::SetProductMetrics(int numberOfProductMetrics_,
                                       std::string* productMetrics_)
{
  if (numberOfProductMetrics_ < 0)
    throw "ProductAnalyst can't have number of product metrics less than 0";
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


std::string ProductAnalyst::GetAbTestingTool()
{
  return this->abTestingTool;
}

void ProductAnalyst::SetAbTestingTool(const std::string & abTestingTool_)
{
  if (abTestingTool_.empty() == 0)
    throw "A/B testing tool can't be empty";
  this->abTestingTool = abTestingTool_;
}


std::string ProductAnalyst::GetRole()
{
  return "ProductAnalyst";
}