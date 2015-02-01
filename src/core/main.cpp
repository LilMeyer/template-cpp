#include <iostream>
#include <iterator>
#include "unittest.h"

#include <boost/lambda/lambda.hpp>
#include <algorithm>


int main() {
  std::cout << "Hello world" << std::endl;
  int a = 12;
  int b = 12;
  ASSERT_EQ(a, b);
  using namespace boost::lambda;
  typedef std::istream_iterator<int> in;
  std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " " );
}
