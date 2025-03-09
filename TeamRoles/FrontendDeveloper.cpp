#include "FrontendDeveloper.h"
FrontendDeveloper::FrontendDeveloper() : Developer::Developer()
{
  this->numberOfUIFrameworks = 0;
  this->UIFrameworks = nullptr;
  this->PWAKnowledge = false;
}

FrontendDeveloper::FrontendDeveloper(int age_, int salary_,
                                     const std::string & name_, int workExperience_,
                                     int level_, int numberOfProgrammingLanguages_,
                                     std::string* programmingLanguages_,
                                     const std::string & preferredIDE_,
                                     int numberOfUIFrameworks_, std::string* UIFrameworks_,
                                     bool PWAKnowledge_
                                     ) : Developer(age_, salary_, name_, workExperience_,
                                                level_, numberOfProgrammingLanguages_,
                                                programmingLanguages_, preferredIDE_)
{
  if (numberOfUIFrameworks_ < 0)
    throw "FrontendDeveloper can't have number of UI frameworks less than 0";
  this->numberOfUIFrameworks = numberOfUIFrameworks_;
  if (this->numberOfUIFrameworks != 0)
  {
    this->UIFrameworks = new std::string[this->numberOfUIFrameworks];
    for (int i = 0; i < this->numberOfUIFrameworks; ++i)
      this->UIFrameworks[i] = UIFrameworks_[i];
  }

  this->PWAKnowledge = PWAKnowledge_;
}

FrontendDeveloper::FrontendDeveloper(const FrontendDeveloper& p) : Developer::Developer(p)
{
  this->numberOfUIFrameworks = p.numberOfUIFrameworks;
  if (this->numberOfUIFrameworks != 0)
  {
    this->UIFrameworks = new std::string[this->numberOfUIFrameworks];
    for (int i = 0; i < this->numberOfUIFrameworks; ++i)
      this->UIFrameworks[i] = p.UIFrameworks[i];
  }
}

FrontendDeveloper::~FrontendDeveloper()
{
  if (this->numberOfUIFrameworks && this->UIFrameworks != nullptr)
    delete[] this->UIFrameworks;;
}

int FrontendDeveloper::GetNumberOfUIFrameworks()
{
  return this->numberOfUIFrameworks;
}

std::string* FrontendDeveloper::GetUIFrameworks()
{
  std::string* UIFrameworks_ = new std::string[this->numberOfUIFrameworks];
  for (int i = 0; i < this->numberOfUIFrameworks; ++i)
    UIFrameworks_[i] = this->UIFrameworks[i];
  return UIFrameworks_;
}

void FrontendDeveloper::SetUIFrameworks(int numberOfUIFrameworks_,
                                    std::string* UIFrameworks_)
{
  if (numberOfUIFrameworks_ < 0)
    throw "FrontendDeveloper can't have number of UI frameworks less than 0";
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

bool FrontendDeveloper::GetPWAKnowledge()
{
  return this->PWAKnowledge;
}

void FrontendDeveloper::SetPWAKnowledge(bool PWAKnowledge_)
{
  this->PWAKnowledge = PWAKnowledge_;
}


std::string FrontendDeveloper::GetRole()
{
  return "FrontendDeveloper";
}