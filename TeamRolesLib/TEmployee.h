#pragma once
#include <string>
#include <iostream>
class TEmployee {
protected:
  std::string name;
  std::string role;
  int age;
  int salary;
  int workExperience;

public:
  std::string GetName();
  int GetAge();
  int GetSalary();
  int GetWorkExperience();
  std::string GetRole();

  void SetName(const std::string & name_);
  void SetAge(int age_);
  virtual void SetSalary(int salary_) = 0;
  virtual void SetWorkExperience(int workExperience_) = 0;

  virtual void Read(std::istream & i) = 0;

  friend std::ostream& operator <<(std::ostream& o, TEmployee& e);
  friend std::istream& operator >>(std::istream& i, TEmployee& e);

  TEmployee();
  TEmployee(int age_, int salary_, const std::string & name_, int workExperience_);
  TEmployee(const TEmployee& p);
};

std::ostream& operator <<(std::ostream& o, TEmployee& e);
std::istream& operator >>(std::istream& i, TEmployee& e);

