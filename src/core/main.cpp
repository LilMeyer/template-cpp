#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
// #include "unittest.h"

#include <boost/array.hpp>

typedef boost::array<std::string, 3> array;

int main() {
  std::cout << "Hello world" << std::endl;

  array a;

  a[0] = "Boris";
  a.at(1) = "Anton";
  *a.rbegin() = "Caesar";

  std::sort(a.begin(), a.end());

  for (array::const_iterator it = a.begin(); it != a.end(); ++it)

  return 0;
}
