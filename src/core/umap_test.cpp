#include <iostream>
#include <string>
#include <unordered_map>

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
    unordered_map<string, string> uMap;
    uMap = { { "Australia", "Canberra" }, { "U.S.", "Washington" }, { "France", "Paris" }};

    cout << "uMap contains:";
    for(auto it = uMap.begin(); it != uMap.end(); ++it) {
      cout << " " << it->first << ":" << it->second;
    }
    cout << endl;

    cout << "uMap's buckets contain:\n";
    for(unsigned i = 0; i < uMap.bucket_count(); ++i) {
      cout << "bucket #" << i << " contains:";
      for(auto local_it = uMap.begin(i); local_it!= uMap.end(i); ++local_it) {
        cout << " " << local_it->first << ":" << local_it->second;
      }
      cout << endl;
    }

    std::unordered_map<std::string, string>::const_iterator got = uMap.find("France");
    if(got == uMap.end()) {
      std::cout << "not found";
    } else {
      std::cout << "The capital of " << got->first << " is " << got->second;
    }
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
