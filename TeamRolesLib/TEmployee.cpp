#include <string>
#include <iostream>
#include "TEmployee.h"

TEmployee::TEmployee() {
  this->age = 25;
  this->salary = 50000;
  this->name = "John";
  this->workExperience = 0;
  this->role = "Employee";
}

TEmployee::TEmployee(int age_, int salary_, const std::string & name_, int workExperience_) : TEmployee::TEmployee()
{
  if (age_ <= 0)
    throw "Can't create employee with non positive age";
  this->age = age_;
  if (salary_ <= 0)
    throw "Can't create employee with non positive salary";
  this->salary = salary_;
  if (name_.empty())
    throw "Can't create employee with empty name";
  this->name = name_;
  if (workExperience_ < 0)
    throw "Can't create employee with negative work experience";
  this->workExperience = workExperience_;
  this->role = "Employee";
}

TEmployee::TEmployee(const TEmployee& p)
{
  this->age = p.age;
  this->salary = p.salary;
  this->name = p.name;
  this->workExperience = p.workExperience;
}

int TEmployee::GetAge()
{
  return this->age;
}

int TEmployee::GetSalary(){
  return this->salary;
}

std::string TEmployee::GetName()
{
  return this->name;
}

std::string TEmployee::GetRole()
{
  return this->role;
}

int TEmployee::GetWorkExperience()
{
  return this->workExperience;
}


void TEmployee::SetAge(int age_)
{
  if (age_ < this->age)
    throw "Can't decrease employee's age";
  this->age = age_;
}

void TEmployee::SetSalary(int salary_)
{
  if (salary_ < this->salary)
    throw "Can't decrease employee's salary";
  this->salary = salary_;
}


void TEmployee::SetName(const std::string & name_)
{
  if (name_.empty())
    throw "Can't set empty name";
  this->name = name_;
}

std::ostream& operator <<(std::ostream& o, TEmployee& e) {
  o << e.name << ' ' << e.role;
  return o;
}

std::istream& operator >>(std::istream& i, TEmployee& e) {
  e.Read(i);
  return i;
}