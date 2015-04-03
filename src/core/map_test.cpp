#include <iostream>
#include <string>
#include <map>

#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestSuite.h>

using namespace std;

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
    std::map<int, string> m;
    m[1] = "hello";
    string s;
    map<int, string>::iterator it = m.find(1);
    if(it != m.end()) {
      //element found;
      s = it->second;
      cout << "Element found:" << s << endl;
    }
  }

};


int main(int argc, char* argv[]) {

  CppUnit::TextUi::TestRunner runner;
  std::cout << "Creating Test Suites:" << std::endl;
  runner.addTest(MapTest::suite());
  std::cout<< "Running the unit tests."<< std::endl;
  runner.run();

  return 0;
}
