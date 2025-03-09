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
  this->PWAKnowledge = p.PWAKnowledge;
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

void FrontendDeveloper::print(std::ostream& o)
{
  o << "Role: " << this->GetRole() << '\n';
  o << "Name: " << this->name << '\n';
  o << "Age: " << this->age << '\n';
  o << "Salary: " << this->salary << '\n';
  o << "Work Experience: " << this->workExperience << '\n';
  o << "Level: " << this->level << '\n';
  o << "Programming languages: ";
  for (int i = 0; i < this->numberOfProgrammingLanguages; ++i)
  {
    o << this->programmingLanguages[i] << ' ';
  }
  o << '\n';
  o << "Preferred IDE: " << this->preferredIDE << '\n';
  o << "UI Frameworks: ";
  for (int i = 0; i < this->numberOfUIFrameworks; ++i)
  {
    o << this->UIFrameworks[i] << ' ';
  }
  o << '\n';
  o << "PWAKnowledge: " << this->PWAKnowledge;
  o << '\n';
}

void FrontendDeveloper::read(std::istream& i)
{
  i >> this->name >> this->age >> this->salary >> this->workExperience >> this->level;
  if (this->age <= 0)
    throw "Can't create employee with non positive age";
  if (this->salary <= 0)
    throw "Can't create employee with non positive salary";
  if (this->salary < 30000)
    throw "Developer can't have salary less than 30000 RUB";
  if (this->workExperience < 3)
    throw "Developer can't have work experience less than 3 years ";
  if (this->level < 1)
    throw "Developer can't have level less than 1";
  if (this->level > 3)
    throw "Developer can't have level more than 3";

  i >> this->numberOfProgrammingLanguages;
  if (this->numberOfProgrammingLanguages < 0)
    throw "Developer can't have number of programming languages less than 0";
  if (this->numberOfProgrammingLanguages != 0)
  {
    this->programmingLanguages = new std::string[this->numberOfProgrammingLanguages];
    for (int j = 0; j < this->numberOfProgrammingLanguages; ++j)
      i >> this->programmingLanguages[j];
  }

  i >> this->preferredIDE;

  i >> this->numberOfUIFrameworks;
  if (this->numberOfUIFrameworks < 0)
    throw "FrontendDeveloper can't have number of UI frameworks less than 0";
  if (this->numberOfUIFrameworks != 0)
  {
    this->UIFrameworks = new std::string[this->numberOfProgrammingLanguages];
    for (int j = 0; j < this->numberOfProgrammingLanguages; ++j)
      i >> this->UIFrameworks[j];
  }
  i >> this->PWAKnowledge;
}