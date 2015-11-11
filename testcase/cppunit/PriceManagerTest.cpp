#include "../../PriceManager.hpp"
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class PriceManagerTest:  public CppUnit::TestFixture {
public:
   static CppUnit::Test *suite()
   {
     CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "PriceManagerTestSuite" );
     suiteOfTests->addTest( new CppUnit::TestCaller<PriceManagerTest>(
                                    "Add Price",
                                    &PriceManagerTest::addPrice ) );
     suiteOfTests->addTest( new CppUnit::TestCaller<PriceManagerTest>(
                                    "Remove Price",
                                    &PriceManagerTest::removePrice) );
     return suiteOfTests;
   }

   void setUp()
   {
	priceManagerToBeTested = new PriceManager();
   }
   void tearDown()
   {
	delete priceManagerToBeTested;
   }


private:
   PriceManager *priceManagerToBeTested;

protected:
 /* add TEST-CODE-XYZ which cost 1$ for 1 unit */
 /* add TEST-CODE-XYZ which cost 3$ for 4 unit */
 /* getPrice() should return 4 unit price as 3$ */
  void addPrice()
  {
	priceManagerToBeTested->addPrice("TEST-CODE-XYZ", 1, 1);
	priceManagerToBeTested->addPrice("TEST-CODE-XYZ", 4, 3);
	CPPUNIT_ASSERT(priceManagerToBeTested->getPrice("TEST-CODE-XYZ", 4) == 3);
  }
 /* add TEST-CODE-XYZ which cost 1$ for 1 unit */
 /* add TEST-CODE-XYZ which cost 3$ for 4 unit */
 /* remove TEST-CODE-XYZ which cost 3$ for 4 unit */
 /* getPrice() should return 4 unit price as 4$ */
  void removePrice()
  {
	priceManagerToBeTested->addPrice("TEST-CODE-XYZ", 1, 1);
	priceManagerToBeTested->addPrice("TEST-CODE-XYZ", 4, 3);
	priceManagerToBeTested->removePrice("TEST-CODE-XYZ", 4);
	CPPUNIT_ASSERT(priceManagerToBeTested->getPrice("TEST-CODE-XYZ", 4) == 4);
  }

 /* getPrice() NEED NOT be tested as thats how we have already verified other functions */

};

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
  	runner.addTest(PriceManagerTest::suite() );
  	runner.run();
  	return 0;
}

