#include "BackendDeveloper.h"
BackendDeveloper::BackendDeveloper() : Developer::Developer()
{
  this->numberOfDatabases = 0;
  this->databases = nullptr;
  this->numberOfContainers = 0;
  this->containers = nullptr;
}

BackendDeveloper::BackendDeveloper(int age_, int salary_,
                              const std::string & name_, int workExperience_,
                              int level_, int numberOfProgrammingLanguages_,
                              std::string* programmingLanguages_,
                              const std::string & preferredIDE_,
                              int numberOfDatabases_, std::string* databases_,
                              int numberOfContainers_, std::string* containers_
                              ) : Developer(age_, salary_, name_, workExperience_,
                                          level_, numberOfProgrammingLanguages_,
                                          programmingLanguages_, preferredIDE_)
{

  if (numberOfDatabases_ < 0)
    throw "BackendDeveloper can't have number of databases less than 0";
  this->numberOfDatabases = numberOfDatabases_;
  if (this->numberOfDatabases != 0)
  {
    this->databases = new std::string[this->numberOfDatabases];
    for (int i = 0; i < this->numberOfDatabases; ++i)
      this->databases[i] = databases_[i];
  }

  if (numberOfContainers_ < 0)
    throw "BackendDeveloper can't have number of containers less than 0";
  this->numberOfContainers = numberOfContainers_;
  if (this->numberOfContainers != 0)
  {
    this->containers = new std::string[this->numberOfContainers];
    for (int i = 0; i < this->numberOfContainers; ++i)
      this->containers[i] = containers_[i];
  }
}

BackendDeveloper::BackendDeveloper(const BackendDeveloper& p) : Developer::Developer(p)
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

BackendDeveloper::~BackendDeveloper()
{
  if (this->numberOfDatabases && this->databases != nullptr)
    delete[] this->databases;
  if (this->numberOfContainers && this->containers != nullptr)
    delete[] this->containers;
}

int BackendDeveloper::GetNumberOfDatabases()
{
  return this->numberOfDatabases;
}

std::string* BackendDeveloper::GetDatabases()
{
  std::string* databases_ = new std::string[this->numberOfDatabases];
  for (int i = 0; i < this->numberOfDatabases; ++i)
    databases_[i] = this->databases[i];
  return databases_;
}

void BackendDeveloper::SetDatabases(int numberOfDatabases_,
                             std::string* databases_)
{
  if (numberOfDatabases_ < 0)
    throw "BackendDeveloper can't have number of databases less than 0";
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

int BackendDeveloper::GetNumberOfContainers()
{
  return this->numberOfContainers;
}

std::string* BackendDeveloper::GetContainers()
{
  std::string* containers_ = new std::string[this->numberOfContainers];
  for (int i = 0; i < this->numberOfContainers; ++i)
    containers_[i] = this->containers[i];
  return containers_;
}

void BackendDeveloper::SetContainers(int numberOfContainers_,
                                    std::string* containers_)
{
  if (numberOfContainers_ < 0)
    throw "BackendDeveloper can't have number of containers less than 0";
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

std::string BackendDeveloper::GetRole()
{
  return "BackendDeveloper";
}

void BackendDeveloper::print(std::ostream& o)
{
  o << "Role: " << this->GetRole() << '\n';
  o << "Name: " << this->name << '\n';
  o << "Age: " << this->age << '\n';
  o << "Work Experience: " << this->workExperience << '\n';
  o << "Salary: " << this->salary << '\n';
  o << "Level: " << this->level << '\n';
  o << "Programming languages: ";
  for (int i = 0; i < this->numberOfProgrammingLanguages; ++i)
  {
    o << this->programmingLanguages[i] << ' ';
  }
  o << '\n';
  o << "Preferred IDE: " << this->preferredIDE << '\n';
  o << "Databases: ";
  for (int i = 0; i < this->numberOfDatabases; ++i)
  {
    o << this->databases[i] << ' ';
  }
  o << '\n';
  o << "Containers: ";
  for (int i = 0; i < this->numberOfContainers; ++i)
  {
    o << this->containers[i] << ' ';
  }
  o << '\n';
  o << '\n';

}

void BackendDeveloper::read(std::istream& i)
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

  i >> this->numberOfDatabases;
  if (this->numberOfDatabases < 0)
    throw "BackendDeveloper can't have number of databases less than 0";
  if (this->numberOfDatabases != 0)
  {
    this->databases = new std::string[this->numberOfProgrammingLanguages];
    for (int j = 0; j < this->numberOfDatabases; ++j)
      i >> this->databases[j];
  }

  i >> this->numberOfContainers;
  if (this->numberOfContainers < 0)
    throw "BackendDeveloper can't have number of containers less than 0";
  if (this->numberOfContainers != 0)
  {
    this->containers = new std::string[this->numberOfContainers];
    for (int j = 0; j < this->numberOfContainers; ++j)
      i >> this->containers[j];
  }
}