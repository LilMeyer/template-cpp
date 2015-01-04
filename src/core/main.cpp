#include <iostream>
#include <iterator>
#include "unittest.h"

int main() {
  std::cout << "Hello world" << std::endl;
  int a = 12;
  int b = 12;
  ASSERT_EQ(a, b);
}
