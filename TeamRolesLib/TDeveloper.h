#pragma once
#include <string>
#include "TEmployee.h"

class TDeveloper : public TEmployee {
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

  void SetSalary(int salary_);
  void SetWorkExperience(int workExperience_);

  virtual void Read(std::istream & i) = 0;

  TDeveloper();
  TDeveloper(int age_, int salary_,
             const std::string & name_, int workExperience_,
             int level_, int numberOfProgrammingLanguages_,
             std::string* programmingLanguages_,
             const std::string & preferredIDE_);
  TDeveloper(const TDeveloper& p);
  ~TDeveloper();
};
