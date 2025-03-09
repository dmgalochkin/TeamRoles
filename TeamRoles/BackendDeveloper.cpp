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