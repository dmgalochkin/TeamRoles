#include <string>
#include <iostream>
#include "Employee.h"

Employee::Employee() {
  this->age = 25;
  this->salary = 50000;
  this->name = "John";
  this->workExperience = 0;
}

Employee::Employee(int age_, int salary_, const std::string & name_, int workExperience_) : Employee::Employee()
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
}

Employee::Employee(const Employee& p)
{
  this->age = p.age;
  this->salary = p.salary;
  this->name = p.name;
  this->workExperience = p.workExperience;
}

int Employee::GetAge()
{
  return this->age;
}

int Employee::GetSalary(){
  return this->salary;
}

std::string Employee::GetName()
{
  return this->name;
}

int Employee::GetWorkExperience()
{
  return this->workExperience;
}


void Employee::SetAge(int age_)
{
  if (age_ < this->age)
    throw "Can't decrease employee's age";
  this->age = age_;
}

void Employee::SetSalary(int salary_)
{
  if (salary_ < this->salary)
    throw "Can't decrease employee's salary";
  this->salary = salary_;
}


void Employee::SetName(const std::string & name_)
{
  if (name_.empty())
    throw "Can't set empty name";
  this->name = name_;
}

std::ostream& operator <<(std::ostream& o, Employee& e) {
  e.print(o);
  return o;
}
std::istream& operator >>(std::istream& i, Employee& e) {
  e.read(i);
  return i;
}