#include "TDeveloper.h"
TDeveloper::TDeveloper() : TEmployee::TEmployee()
{
  this->level = 1;
  this->numberOfProgrammingLanguages = 0;
  this->programmingLanguages = nullptr;
  this->preferredIDE = "Notepad";
  this->role = "Developer";
}

TDeveloper::TDeveloper(int age_, int salary_,
                       const std::string & name_, int workExperience_,
                       int level_, int numberOfProgrammingLanguages_,
                       std::string* programmingLanguages_,
                       const std::string & preferredIDE_) : TEmployee::TEmployee(age_, salary_, name_, workExperience_)
{
  if (workExperience_ < 3)
    throw "TDeveloper can't have work experience less than 3 years ";
  if (salary_ < 30000)
    throw "TDeveloper can't have salary less than 30000 RUB";

  if (level_ < 1)
    throw "TDeveloper can't have level less than 1";
  if (level_ > 3)
    throw "TDeveloper can't have level more than 3";  this->level = level_;
  if (numberOfProgrammingLanguages_ < 0)
    throw "TDeveloper can't have number of programming languages less than 0";
  this->numberOfProgrammingLanguages = numberOfProgrammingLanguages_;
  if (this->numberOfProgrammingLanguages != 0)
  {
    this->programmingLanguages = new std::string[this->numberOfProgrammingLanguages];
    for (int i = 0; i < this->numberOfProgrammingLanguages; ++i)
      this->programmingLanguages[i] = programmingLanguages_[i];
  }
  if (preferredIDE_.empty())
    throw "Preferred IDE can't be empty";
  this->preferredIDE = preferredIDE_;
  this->role = "Developer";
}

TDeveloper::TDeveloper(const TDeveloper& p) : TEmployee::TEmployee(p)
{
  this->level = p.level;
  this->numberOfProgrammingLanguages = p.numberOfProgrammingLanguages;
  if (this->numberOfProgrammingLanguages != 0)
  {
    this->programmingLanguages = new std::string[this->numberOfProgrammingLanguages];
    for (int i = 0; i < this->numberOfProgrammingLanguages; ++i)
      this->programmingLanguages[i] = p.programmingLanguages[i];
  }
}

TDeveloper::~TDeveloper()
{
  if (this->numberOfProgrammingLanguages && this->programmingLanguages != nullptr)
    delete[] this->programmingLanguages;
}


int TDeveloper::GetLevel()
{
  return this->level;
}

int TDeveloper::GetNumberOfProgrammingLanguages()
{
  return this->numberOfProgrammingLanguages;
}

std::string* TDeveloper::GetProgrammingLanguages()
{
  std::string* programmingLanguages_ = new std::string[this->numberOfProgrammingLanguages];
  for (int i = 0; i < this->numberOfProgrammingLanguages; ++i)
    programmingLanguages_[i] = this->programmingLanguages[i];
  return programmingLanguages_;
}

std::string TDeveloper::GetPreferredIDE()
{
  return this->preferredIDE;
}

void TDeveloper::SetLevel(int level_)
{
  if (level_ < 1)
    throw "TDeveloper can't have level less than 1";
  if (level_ > 3)
    throw "TDeveloper can't have level more than 3";
  this->level = level_;
}

void TDeveloper::SetProgrammingLanguages(int numberOfProgrammingLanguages_,
                                         std::string* programmingLanguages_)
{
  if (numberOfProgrammingLanguages_ < 0)
    throw "TDeveloper can't have number of programming languages less than 0";
  if (this->programmingLanguages != nullptr)
    delete[] this->programmingLanguages;
  this->numberOfProgrammingLanguages = numberOfProgrammingLanguages_;
  if (this->numberOfProgrammingLanguages != 0)
  {
    this->programmingLanguages = new std::string[this->numberOfProgrammingLanguages];
    for (int i = 0; i < this->numberOfProgrammingLanguages; ++i)
      this->programmingLanguages[i] = programmingLanguages_[i];
  } else {
    this->programmingLanguages = nullptr;
  }

}

void TDeveloper::SetPreferredIDE(const std::string & preferredIDE_)
{
  if (preferredIDE_.empty())
    throw "Preferred IDE can't be empty";
  this->preferredIDE = preferredIDE_;
}

void TDeveloper::SetSalary(int salary_)
{
  if (salary_ < this->salary)
    throw "Cannot decrease salary";
  if (salary_ < 30000)
    throw "TDeveloper can't have salary less than 30000 RUB";
  this->salary = salary_;
}

void TDeveloper::SetWorkExperience(int workExperience_)
{
  if (workExperience_ < this->workExperience)
    throw "Cannot decrease work experience";
  if (workExperience_ < 3)
    throw "TDeveloper can't have work experience less than 3 years ";
  this->workExperience = workExperience_;
}