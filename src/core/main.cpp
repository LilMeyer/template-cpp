#include <iostream>
#include <iterator>
#include "unittest.h"

#include <boost/array.hpp>

int main() {
  std::cout << "Hello world" << std::endl;
  int a = 12;
  int b = 12;
  ASSERT_EQUALS(a, b);
  boost::array<int, 4> arr = {{1,2,3,4}};
  ASSERT_EQ(1, arr[0]);

  return 0;
}
