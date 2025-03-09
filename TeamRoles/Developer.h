#pragma once
#include <string>
#include "Employee.h"

class Developer : Employee {
protected:
  int level;
  int numberOfProgrammingLanguages;
  std::string* programmingLanguages;
  std::string preferredIDE;

public:
  int GetLevel();
  int GetNumberOfProgrammingLanguages();
  std::string* GetProgrammingLanguages();
  std::string GetPreferredIDE();

  void SetLevel(int level_);
  void SetProgrammingLanguages(int numberOfProgrammingLanguages_,
                               std::string* programmingLanguages_);
  void SetPreferredIDE(const std::string & preferredIDE_);

  std::string GetRole();

  Developer();
  Developer(int age_, int salary_,
            const std::string & name_, int workExperience_,
            int level_, int numberOfProgrammingLanguages_,
            std::string* programmingLanguages_,
            const std::string & preferredIDE_);
  Developer(const Developer& p);
  ~Developer();
};
