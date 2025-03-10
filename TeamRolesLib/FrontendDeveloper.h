#pragma once
#include <string>
#include "Developer.h"

class FrontendDeveloper : public Developer {
protected:
  int numberOfUIFrameworks;
  std::string* UIFrameworks;
  bool PWAKnowledge;

public:
  int GetNumberOfUIFrameworks();
  std::string* GetUIFrameworks();
  bool GetPWAKnowledge();

  void SetUIFrameworks(int numberOfUIFrameworks_, std::string* UIFrameworks_);
  void SetPWAKnowledge(bool PWAKnowledge_);

  std::string GetRole() override;

  void print(std::ostream & o);
  void read(std::istream & i);

  FrontendDeveloper();
  FrontendDeveloper(int age_, int salary_,
                   const std::string & name_, int workExperience_,
                   int level_, int numberOfProgrammingLanguages_,
                   std::string* programmingLanguages_,
                   const std::string & preferredIDE_,
                   int numberOfUIFrameworks_, std::string* UIFrameworks_,
                   bool PWAKnowledge_);
  FrontendDeveloper(const FrontendDeveloper& p);
  ~FrontendDeveloper();
};