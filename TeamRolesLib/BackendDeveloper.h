#pragma once
#include <string>
#include "Developer.h"

class BackendDeveloper : public Developer {
protected:
  int numberOfDatabases;
  std::string* databases;
  int numberOfContainers;
  std::string* containers;

public:
  int GetNumberOfDatabases();
  std::string* GetDatabases();
  int GetNumberOfContainers();
  std::string* GetContainers();

  void SetDatabases(int numberOfDatabases_,
                               std::string* databases_);
  void SetContainers(int numberOfContainers_,
                               std::string* containers_);

  std::string GetRole() override;

  void print(std::ostream & o);
  void read(std::istream & i);

  BackendDeveloper();
  BackendDeveloper(int age_, int salary_,
            const std::string & name_, int workExperience_,
            int level_, int numberOfProgrammingLanguages_,
            std::string* programmingLanguages_,
            const std::string & preferredIDE_,
            int numberOfDatabases_, std::string* databases_,
            int numberOfContainers_, std::string* containers_);
  BackendDeveloper(const BackendDeveloper& p);
  ~BackendDeveloper();
};