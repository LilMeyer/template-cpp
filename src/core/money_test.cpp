#include <iostream>
#include "money.cpp"
#include "money.hpp"

#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestSuite.h>

using namespace std;

class MoneyTest : public CppUnit::TestFixture {
private:
    Money* money;
    double amount = 100;
    string currency = "EURO";
public:
  MoneyTest() {
    money = new Money(amount, "EURO");
  }

  virtual ~MoneyTest() {
    delete money;
  }

  static CppUnit::Test *suite() {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("MoneyTest");

    suiteOfTests->addTest(new CppUnit::TestCaller<MoneyTest>("Test1 - Unique Solution.",
            &MoneyTest::test1 ));
    return suiteOfTests;
  }

  /* Setup method */
  void setUp() {}

  /* Teardown method */
  void tearDown() {}

protected:
  void test1() {
    CPPUNIT_ASSERT_EQUAL(money->getAmount(), amount);
    CPPUNIT_ASSERT_EQUAL(money->getCurrency(), currency);
  }

};


int main(int argc, char* argv[]) {

  CppUnit::TextUi::TestRunner runner;
  std::cout << "Creating Test Suites:" << std::endl;
  runner.addTest(MoneyTest::suite());
  std::cout<< "Running the unit tests."<< std::endl;
  runner.run();

  return 0;
}
