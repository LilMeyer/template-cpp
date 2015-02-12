#include <iostream>
#include <iterator>
#include "unittest.h"

#include <boost/array.hpp>

#include <boost/thread.hpp>
// #include <boost/date_time.hpp>

// void workerFunc() {
//   boost::posix_time::seconds workTime(3);
//   std::cout << "Worker: running" << std::endl;
//   // Pretend to do something useful...
//   boost::this_thread::sleep(workTime);
//   std::cout << "Worker: finished" << std::endl;
// }

int main() {
  std::cout << "Hello world" << std::endl;
  int a = 12;
  int b = 12;
  ASSERT_EQUALS(a, b);
  boost::array<int, 4> arr = {{1,2,3,4}};
  ASSERT_EQ(1, arr[0]);

  // std::cout << "main: startup" << std::endl;
  // boost::thread workerThread(workerFunc);
  // std::cout << "main: waiting for thread" << std::endl;
  // workerThread.join();
  // std::cout << "main: done" << std::endl;

  return 0;
}
