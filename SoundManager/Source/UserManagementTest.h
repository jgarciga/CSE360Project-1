#pragma once
#include <cppunit/extensions/HelperMacros.h>
#include "MainComponentLogin.h"

class UserManagementTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(UserManagementTest);
    CPPUNIT_TEST(testUserLogin);
    CPPUNIT_TEST(testAccountInfo);
    CPPUNIT_TEST_SUITE_END();

private:
    MainComponentLogin mainComp;

public:
    void testUserLogin()
    {
        mainComp.saveUserInfo("Johnny", "jgarciga", "IDK");

        // Correct login
        CPPUNIT_ASSERT(mainComp.checkLogin("Johnny", "jgarciga"));

        // Incorrect login
        CPPUNIT_ASSERT(!mainComp.checkLogin("johnny", "wrongpass"));
    }

    void testAccountInfo()
    {
        mainComp.saveUserInfo("Gina", "Ginapass", "IDK");

        // Account info retrieval
        CPPUNIT_ASSERT(mainComp.getAccountInfo("Gina") == "IDK");

        // Wrong username returns empty
        CPPUNIT_ASSERT(mainComp.getAccountInfo("Ezfan") == "");
    }
};
