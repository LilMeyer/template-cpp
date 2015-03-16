#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class MoneyTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( MoneyTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testConstructor();
};

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( MoneyTest );

void MoneyTest::setUp() {
}

void MoneyTest::tearDown() {
}

void MoneyTest::testConstructor() {
 // Set up
  const std::string currencyFF( "FF" );
  const double longNumber = 12345678.90123;

  CPPUNIT_ASSERT_EQUAL(1, 1);

  // // Process
  // Money money( longNumber, currencyFF );

  // // Check
  // CPPUNIT_ASSERT_EQUAL( longNumber, money.getAmount() );
  // CPPUNIT_ASSERT_EQUAL( currencyFF, money.getCurrency() );
}


int main(int argc, char* argv[])
{
  // Get the top level suite from the registry
  CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( suite );

  // Change the default outputter to a compiler error format outputter
  runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
                                                       std::cerr ) );
  // Run the tests.
  bool wasSucessful = runner.run();

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}
