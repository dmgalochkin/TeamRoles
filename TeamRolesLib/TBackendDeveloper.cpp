#include "TBackendDeveloper.h"
TBackendDeveloper::TBackendDeveloper() : TDeveloper::TDeveloper()
{
  this->numberOfDatabases = 0;
  this->databases = nullptr;
  this->numberOfContainers = 0;
  this->containers = nullptr;
  this->role = "BackendDeveloper";
}

TBackendDeveloper::TBackendDeveloper(int age_, int salary_,
                                     const std::string & name_, int workExperience_,
                                     int level_, int numberOfProgrammingLanguages_,
                                     std::string* programmingLanguages_,
                                     const std::string & preferredIDE_,
                                     int numberOfDatabases_, std::string* databases_,
                                     int numberOfContainers_, std::string* containers_
                              ) : TDeveloper(age_, salary_, name_, workExperience_,
                                             level_, numberOfProgrammingLanguages_,
                                             programmingLanguages_, preferredIDE_)
{

  if (numberOfDatabases_ < 0)
    throw "TBackendDeveloper can't have number of databases less than 0";
  this->numberOfDatabases = numberOfDatabases_;
  if (this->numberOfDatabases != 0)
  {
    this->databases = new std::string[this->numberOfDatabases];
    for (int i = 0; i < this->numberOfDatabases; ++i)
      this->databases[i] = databases_[i];
  }

  if (numberOfContainers_ < 0)
    throw "TBackendDeveloper can't have number of containers less than 0";
  this->numberOfContainers = numberOfContainers_;
  if (this->numberOfContainers != 0)
  {
    this->containers = new std::string[this->numberOfContainers];
    for (int i = 0; i < this->numberOfContainers; ++i)
      this->containers[i] = containers_[i];
  }

  this->role = "BackendDeveloper";
}

TBackendDeveloper::TBackendDeveloper(const TBackendDeveloper& p) : TDeveloper::TDeveloper(p)
{

  this->numberOfDatabases = p.numberOfDatabases;
  if (this->numberOfDatabases != 0)
  {
    this->databases = new std::string[this->numberOfDatabases];
    for (int i = 0; i < this->numberOfDatabases; ++i)
      this->databases[i] = p.databases[i];
  }


  this->numberOfContainers = p.numberOfContainers;
  if (this->numberOfContainers != 0)
  {
    this->containers = new std::string[this->numberOfContainers];
    for (int i = 0; i < this->numberOfContainers; ++i)
      this->containers[i] = p.containers[i];
  }
}

TBackendDeveloper::~TBackendDeveloper()
{
  if (this->numberOfDatabases && this->databases != nullptr)
    delete[] this->databases;
  if (this->numberOfContainers && this->containers != nullptr)
    delete[] this->containers;
}

int TBackendDeveloper::GetNumberOfDatabases()
{
  return this->numberOfDatabases;
}

std::string* TBackendDeveloper::GetDatabases()
{
  std::string* databases_ = new std::string[this->numberOfDatabases];
  for (int i = 0; i < this->numberOfDatabases; ++i)
    databases_[i] = this->databases[i];
  return databases_;
}

void TBackendDeveloper::SetDatabases(int numberOfDatabases_,
                                     std::string* databases_)
{
  if (numberOfDatabases_ < 0)
    throw "TBackendDeveloper can't have number of databases less than 0";
  if (this->databases != nullptr)
    delete[] this->databases;
  this->numberOfDatabases = numberOfDatabases_;
  if (this->numberOfDatabases != 0)
  {
    this->databases = new std::string[this->numberOfDatabases];
    for (int i = 0; i < this->numberOfDatabases; ++i)
      this->databases[i] = databases_[i];
  } else {
    this->databases = nullptr;
  }
}

int TBackendDeveloper::GetNumberOfContainers()
{
  return this->numberOfContainers;
}

std::string* TBackendDeveloper::GetContainers()
{
  std::string* containers_ = new std::string[this->numberOfContainers];
  for (int i = 0; i < this->numberOfContainers; ++i)
    containers_[i] = this->containers[i];
  return containers_;
}

void TBackendDeveloper::SetContainers(int numberOfContainers_,
                                      std::string* containers_)
{
  if (numberOfContainers_ < 0)
    throw "TBackendDeveloper can't have number of containers less than 0";
  if (this->containers != nullptr)
    delete[] this->containers;
  this->numberOfContainers = numberOfContainers_;
  if (this->numberOfDatabases != 0)
  {
    this->containers = new std::string[this->numberOfContainers];
    for (int i = 0; i < this->numberOfContainers; ++i)
      this->containers[i] = containers_[i];
  } else {
    this->containers = nullptr;
  }
}

void TBackendDeveloper::Read(std::istream& i)
{
  int age_;
  int salary_;
  std::string name_;
  int workExperience_;
  int level_;
  int numberOfProgrammingLanguages_;
  std::string* programmingLanguages_ = nullptr;
  std::string preferredIDE_;
  int numberOfDatabases_;
  std::string* databases_ = nullptr;
  int numberOfContainers_;
  std::string* containers_ = nullptr;

  i >> name_ >> age_ >> salary_ >> workExperience_ >> level_;

  i >> numberOfProgrammingLanguages_;
  if (numberOfProgrammingLanguages_ > 0)
  {
    programmingLanguages_ = new std::string[numberOfProgrammingLanguages_];
    for (int j = 0; j < numberOfProgrammingLanguages_; ++j)
      i >> programmingLanguages_[j];
  }

  i >> preferredIDE_;

  i >> numberOfDatabases_;
  if (numberOfDatabases_ > 0)
  {
    databases_ = new std::string[numberOfDatabases_];
    for (int j = 0; j < numberOfDatabases_; ++j)
      i >> databases_[j];
  }


  i >> numberOfContainers_;
  if (numberOfContainers_ > 0)
  {
    containers_ = new std::string[numberOfContainers_];
    for (int j = 0; j < numberOfContainers_; ++j)
      i >> containers_[j];
  }

  TBackendDeveloper::SetAge(age_);
  TBackendDeveloper::SetSalary(salary_);
  TBackendDeveloper::SetWorkExperience(workExperience_);
  TBackendDeveloper::SetLevel(level_);
  TBackendDeveloper::SetProgrammingLanguages(numberOfProgrammingLanguages_, programmingLanguages_);
  TBackendDeveloper::SetPreferredIDE(preferredIDE_);
  TBackendDeveloper::SetDatabases(numberOfDatabases_, databases_);
  TBackendDeveloper::SetContainers(numberOfContainers_, containers_);

  delete[] programmingLanguages_;
  delete[] databases_;
  delete[] containers_;
}