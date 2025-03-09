#include "Developer.h"
Developer::Developer() : Employee::Employee()
{
  this->level = 1;
  this->numberOfProgrammingLanguages = 0;
  this->programmingLanguages = nullptr;
  this->preferredIDE = "Notepad";
}

Developer::Developer(int age_, int salary_,
    const std::string & name_, int workExperience_,
    int level_, int numberOfProgrammingLanguages_,
    std::string* programmingLanguages_,
    const std::string & preferredIDE_) : Employee::Employee(age_, salary_, name_, workExperience_)
{
  if (workExperience_ < 3)
    throw "Developer can't have work experience less than 3 years ";
  if (salary_ < 30000)
    throw "Developer can't have salary less than 30000 RUB";

  this->level = level_;
  if (numberOfProgrammingLanguages_ < 0)
    throw "Developer can't have number of programming languages less than 0";
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
}

Developer::Developer(const Developer& p) : Employee::Employee(p)
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

Developer::~Developer()
{
  if (this->numberOfProgrammingLanguages && this->programmingLanguages != nullptr)
    delete[] this->programmingLanguages;
}


int Developer::GetLevel()
{
  return this->level;
}

int Developer::GetNumberOfProgrammingLanguages()
{
  return this->numberOfProgrammingLanguages;
}

std::string* Developer::GetProgrammingLanguages()
{
  std::string* programmingLanguages_ = new std::string[this->numberOfProgrammingLanguages];
  for (int i = 0; i < this->numberOfProgrammingLanguages; ++i)
    programmingLanguages_[i] = this->programmingLanguages[i];
  return programmingLanguages_;
}

std::string Developer::GetPreferredIDE()
{
  return this->preferredIDE;
}

void Developer::SetLevel(int level_)
{
  if (level_ < 1)
    throw "Developer can't have level less than 1";
  if (level_ > 3)
    throw "Developer can't have level more than 3";
  this->level = level_;
}

void Developer::SetProgrammingLanguages(int numberOfProgrammingLanguages_,
                             std::string* programmingLanguages_)
{
  if (numberOfProgrammingLanguages_ < 0)
    throw "Developer can't have number of programming languages less than 0";
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

void Developer::SetPreferredIDE(const std::string & preferredIDE_)
{
  if (preferredIDE_.empty())
    throw "Preferred IDE can't be empty";
  this->preferredIDE = preferredIDE_;
}

std::string Developer::GetRole()
{
  return "Developer";
}