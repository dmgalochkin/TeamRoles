#pragma once
#include <string>
#include "TDeveloper.h"

class TFrontendDeveloper : public TDeveloper {
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

  void Read(std::istream & i);

  TFrontendDeveloper();
  TFrontendDeveloper(int age_, int salary_,
                     const std::string & name_, int workExperience_,
                     int level_, int numberOfProgrammingLanguages_,
                     std::string* programmingLanguages_,
                     const std::string & preferredIDE_,
                     int numberOfUIFrameworks_, std::string* UIFrameworks_,
                     bool PWAKnowledge_);
  TFrontendDeveloper(const TFrontendDeveloper& p);
  ~TFrontendDeveloper();
};