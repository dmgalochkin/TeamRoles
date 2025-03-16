#include <iostream>
#include "TEmployee.h"
#include "TBackendDeveloper.h"
#include "TFrontendDeveloper.h"
#include "TDataAnalyst.h"
#include "TProductAnalyst.h"
int main()
{
  TEmployee** array = new TEmployee*[4];
  array[0] = new TBackendDeveloper();
  array[1] = new TFrontendDeveloper();
  array[2] = new TDataAnalyst();
  array[3] = new TProductAnalyst();

  array[1]->SetName("Mike");
  array[2]->SetName("Robert");
  array[3]->SetName("David");

  for (int i = 0; i < 4; ++i) {
    std::cout << (*array[i]) << '\n';
  }

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