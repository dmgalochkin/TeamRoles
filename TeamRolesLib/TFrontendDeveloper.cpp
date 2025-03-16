#include "TFrontendDeveloper.h"
TFrontendDeveloper::TFrontendDeveloper() : TDeveloper::TDeveloper()
{
  this->numberOfUIFrameworks = 0;
  this->UIFrameworks = nullptr;
  this->PWAKnowledge = false;
  this->role = "FrontendDeveloper";
}

TFrontendDeveloper::TFrontendDeveloper(int age_, int salary_,
                                       const std::string & name_, int workExperience_,
                                       int level_, int numberOfProgrammingLanguages_,
                                       std::string* programmingLanguages_,
                                       const std::string & preferredIDE_,
                                       int numberOfUIFrameworks_, std::string* UIFrameworks_,
                                       bool PWAKnowledge_
                                     ) : TDeveloper(age_, salary_, name_, workExperience_,
                                                    level_, numberOfProgrammingLanguages_,
                                                    programmingLanguages_, preferredIDE_)
{
  if (numberOfUIFrameworks_ < 0)
    throw "TFrontendDeveloper can't have number of UI frameworks less than 0";
  this->numberOfUIFrameworks = numberOfUIFrameworks_;
  if (this->numberOfUIFrameworks != 0)
  {
    this->UIFrameworks = new std::string[this->numberOfUIFrameworks];
    for (int i = 0; i < this->numberOfUIFrameworks; ++i)
      this->UIFrameworks[i] = UIFrameworks_[i];
  }

  this->PWAKnowledge = PWAKnowledge_;
  this->role = "FrontendDeveloper";
}

TFrontendDeveloper::TFrontendDeveloper(const TFrontendDeveloper& p) : TDeveloper::TDeveloper(p)
{
  this->numberOfUIFrameworks = p.numberOfUIFrameworks;
  if (this->numberOfUIFrameworks != 0)
  {
    this->UIFrameworks = new std::string[this->numberOfUIFrameworks];
    for (int i = 0; i < this->numberOfUIFrameworks; ++i)
      this->UIFrameworks[i] = p.UIFrameworks[i];
  }
  this->PWAKnowledge = p.PWAKnowledge;
}

TFrontendDeveloper::~TFrontendDeveloper()
{
  if (this->numberOfUIFrameworks && this->UIFrameworks != nullptr)
    delete[] this->UIFrameworks;;
}

int TFrontendDeveloper::GetNumberOfUIFrameworks()
{
  return this->numberOfUIFrameworks;
}

std::string* TFrontendDeveloper::GetUIFrameworks()
{
  std::string* UIFrameworks_ = new std::string[this->numberOfUIFrameworks];
  for (int i = 0; i < this->numberOfUIFrameworks; ++i)
    UIFrameworks_[i] = this->UIFrameworks[i];
  return UIFrameworks_;
}

void TFrontendDeveloper::SetUIFrameworks(int numberOfUIFrameworks_,
                                         std::string* UIFrameworks_)
{
  if (numberOfUIFrameworks_ < 0)
    throw "TFrontendDeveloper can't have number of UI frameworks less than 0";
  if (this->UIFrameworks != nullptr)
    delete[] this->UIFrameworks;
  this->numberOfUIFrameworks = numberOfUIFrameworks_;
  if (this->numberOfUIFrameworks != 0)
  {
    this->UIFrameworks = new std::string[this->numberOfUIFrameworks];
    for (int i = 0; i < this->numberOfUIFrameworks; ++i)
      this->UIFrameworks[i] = UIFrameworks_[i];
  } else {
    this->UIFrameworks = nullptr;
  }
}

bool TFrontendDeveloper::GetPWAKnowledge()
{
  return this->PWAKnowledge;
}

void TFrontendDeveloper::SetPWAKnowledge(bool PWAKnowledge_)
{
  this->PWAKnowledge = PWAKnowledge_;
}


void TFrontendDeveloper::Read(std::istream& i)
{

  int age_;
  int salary_;
  std::string name_;
  int workExperience_;
  int level_;
  int numberOfProgrammingLanguages_;
  std::string* programmingLanguages_ = nullptr;
  std::string preferredIDE_;
  int numberOfUIFrameworks_;
  std::string* UIFrameworks_;
  bool PWAKnowledge_;

  i >> name_ >> age_ >> salary_ >> workExperience_ >> level_;

  i >> numberOfProgrammingLanguages_;
  if (numberOfProgrammingLanguages_ > 0)
  {
    programmingLanguages_ = new std::string[numberOfProgrammingLanguages_];
    for (int j = 0; j < numberOfProgrammingLanguages_; ++j)
      i >> programmingLanguages_[j];
  }

  i >> preferredIDE_;

  i >> numberOfUIFrameworks_;
  if (numberOfUIFrameworks_ > 0)
  {
    UIFrameworks_ = new std::string[numberOfUIFrameworks_];
    for (int j = 0; j < numberOfUIFrameworks_; ++j)
      i >> UIFrameworks_[j];
  }

  i >> PWAKnowledge_;

  TFrontendDeveloper::SetAge(age_);
  TFrontendDeveloper::SetSalary(salary_);
  TFrontendDeveloper::SetWorkExperience(workExperience_);
  TFrontendDeveloper::SetLevel(level_);
  TFrontendDeveloper::SetProgrammingLanguages(numberOfProgrammingLanguages_, programmingLanguages_);
  TFrontendDeveloper::SetPreferredIDE(preferredIDE_);
  TFrontendDeveloper::SetUIFrameworks(numberOfUIFrameworks_, UIFrameworks_);

  delete[] programmingLanguages_;
  delete[] UIFrameworks_;
}