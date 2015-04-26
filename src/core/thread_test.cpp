#include <iostream>
#include <string>
#include <unordered_map>

#include <boost/thread.hpp>
#include <boost/date_time.hpp>

#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestSuite.h>

using namespace std;


void workerFunc() {
  boost::posix_time::seconds workTime(3);

  std::cout << "Worker: running" << std::endl;

  // Pretend to do something useful...
  boost::this_thread::sleep(workTime);

  std::cout << "Worker: finished" << std::endl;
}


class MapTest : public CppUnit::TestFixture {
private:
public:
  MapTest() {
  }
  virtual ~MapTest() {
  }

  static CppUnit::Test *suite() {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("MapTest");

    suiteOfTests->addTest(new CppUnit::TestCaller<MapTest>("Test1 - Unique Solution.",
            &MapTest::test1 ));
    return suiteOfTests;
  }

  /* Setup method */
  void setUp() {}

  /* Teardown method */
  void tearDown() {}

protected:
  void test1() {
    std::cout << "main: startup" << std::endl;
    boost::thread workerThread(workerFunc);
    std::cout << "main: waiting for thread" << std::endl;
    workerThread.join();
    std::cout << "main: done" << std::endl;
  }
};


int main(int argc, char* argv[]) {

  CppUnit::TextUi::TestRunner runner;
  cout << "Creating Test Suites:" << endl;
  runner.addTest(MapTest::suite());
  cout<< "Running the unit tests."<< endl;
  runner.run();

  return 0;
}
