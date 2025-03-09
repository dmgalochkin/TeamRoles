#pragma once
#include <string>
#include <iostream>
class Employee {
protected:
  std::string name;
  int age;
  int salary;
  int workExperience;

public:
  std::string GetName();
  int GetAge();
  int GetSalary();
  int GetWorkExperience();

  void SetName(const std::string & name_);
  void SetAge(int age_);
  virtual void SetSalary(int salary_) = 0;
  virtual void SetWorkExperience(int workExperience_) = 0;

  virtual std::string GetRole() = 0;

  virtual void print(std::ostream & o) = 0;
  virtual void read(std::istream & i) = 0;

  friend std::ostream& operator <<(std::ostream& o, Employee& e);
  friend std::istream& operator >>(std::istream& i, Employee& e);

  Employee();
  Employee(int age_, int salary_, const std::string & name_, int workExperience_);
  Employee(const Employee& p);
};

std::ostream& operator <<(std::ostream& o, Employee& e);
std::istream& operator >>(std::istream& i, Employee& e);

