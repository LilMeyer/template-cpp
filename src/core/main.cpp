#include <iostream>
#include <iterator>
#include "unittest.h"

#include <boost/smart_ptr/shared_ptr.hpp>
#include <memory>

class A{};

int main() {
  std::cout << "Hello world" << std::endl;
  int a = 12;
  int b = 12;
  ASSERT_EQ(a, b);

  boost::shared_ptr<A> pA(new A);
  std::cout << pA.get() << std::endl;
  boost::shared_ptr<A> pB(pA);
  std::cout << pA.get() << std::endl;
  std::cout << pB.get() << std::endl;

  return 0;
}
