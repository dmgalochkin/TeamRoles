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
  if (abTestingTool_.empty())
    throw "A/B testing tool can't be empty";
  this->abTestingTool = abTestingTool_;
}


std::string ProductAnalyst::GetRole()
{
  return "ProductAnalyst";
}

void ProductAnalyst::print(std::ostream& o)
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
  o << "Product metrics: ";
  for (int i = 0; i < this->numberOfProductMetrics; ++i)
  {
    o << this->productMetrics[i] << ' ';
  }
  o << '\n';
  o << "A/B testing tool: " << this->abTestingTool << '\n';
  o << '\n';

}

void ProductAnalyst::read(std::istream& i)
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

  i >> this->numberOfProductMetrics;
  if (this->numberOfProductMetrics < 0)
    throw "ProductAnalyst can't have number of product metrics less than 0";
  if (this->numberOfProductMetrics != 0)
  {
    this->productMetrics = new std::string[this->numberOfProductMetrics];
    for (int j = 0; j < this->numberOfProductMetrics; ++j)
      i >> this->productMetrics[j];
  }

  i >> this->abTestingTool;
}