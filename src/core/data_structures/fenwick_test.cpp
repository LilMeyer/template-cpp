#include <iostream>
#include <vector>
#include <string>

#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestSuite.h>

// http://www.boost.org/doc/libs/1_57_0/libs/bimap/doc/html/index.html

#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>

using namespace std;
using namespace boost;

template <class T>
ostream& operator<< (ostream& out, const vector<T>& v) {
  out << "[";
  size_t last = v.size() - 1;
  for(size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}


class FenwickTest : public CppUnit::TestFixture {
private:
  vector<int> v = { 1, 3, 2, 4, 10, 2};
  vector<int> c;
  int fen[100];
  int size;
public:
  FenwickTest() {
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(10);
    v.push_back(2);
    int size = v.size();
    int total = 0;
    for(int i = 0; i < size; i++) {
      total += v[i];
      c.push_back(total);
    }
  }

  static CppUnit::Test *suite() {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("FenwickTest");

    suiteOfTests->addTest(new CppUnit::TestCaller<FenwickTest>("Test1 - Unique Solution.",
            &FenwickTest::test1));
    return suiteOfTests;
  }

  /* Setup method */
  void setUp() {}

  /* Teardown method */
  void tearDown() {}

protected:

  void add(int idx, int val) {

  }

  void test1() {

  }
};


int main(int argc, char* argv[]) {

  CppUnit::TextUi::TestRunner runner;
  std::cout << "Creating Test Suites:" << std::endl;
  runner.addTest(FenwickTest::suite());
  std::cout<< "Running the unit tests."<< std::endl;
  runner.run();

  return 0;
}
