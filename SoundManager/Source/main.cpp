#include <cppunit/ui/text/TestRunner.h>
#include "UserManagementTest.h"

int main()
{
    CppUnit::TextUi::TestRunner runner;

    // Add the test suite
    runner.addTest(UserManagementTest::suite());

    // Run the tests
    bool wasSuccessful = runner.run();

    return wasSuccessful ? 0 : 1;
}
