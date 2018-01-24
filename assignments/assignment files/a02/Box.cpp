// File: Box.cpp
#include <iostream>
#include "Box.h"

int main()
{
  Box box(1, 1, 2, 3);
  bool is_or_no = box.outside(2,2);

  std::cout << is_or_no << std::endl;

  return 0;
}
