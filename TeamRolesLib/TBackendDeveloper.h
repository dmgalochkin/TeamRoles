#pragma once
#include <string>
#include "TDeveloper.h"

class TBackendDeveloper : public TDeveloper {
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
  void Read(std::istream & i);

  TBackendDeveloper();
  TBackendDeveloper(int age_, int salary_,
                    const std::string & name_, int workExperience_,
                    int level_, int numberOfProgrammingLanguages_,
                    std::string* programmingLanguages_,
                    const std::string & preferredIDE_,
                    int numberOfDatabases_, std::string* databases_,
                    int numberOfContainers_, std::string* containers_);
  TBackendDeveloper(const TBackendDeveloper& p);
  ~TBackendDeveloper();
};