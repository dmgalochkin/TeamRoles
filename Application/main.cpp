#include <iostream>
#include "Employee.h"
#include "BackendDeveloper.h"
#include "FrontendDeveloper.h"
#include "DataAnalyst.h"
#include "ProductAnalyst.h"
int main()
{
  Employee** array = new Employee*[4];
  array[0] = new BackendDeveloper();
  array[1] = new FrontendDeveloper();
  array[2] = new DataAnalyst();
  array[3] = new ProductAnalyst();

  for (int i = 0; i < 4; ++i) {
    std::cout << (*array[i]) << '\n';
  }

  std::cout << (*array[0]) << '\n';
  std::cin >> (*array[0]);
  std::cout << (*array[0]);

  /*
   *
Retardo
27
70000
5
2
2
Python Scala
Clion
1
Excel
1
Docker
   */

  delete[] array;
}