//
// Created by student on 24.03.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include <model/Address.h>
#include <iostream>

struct TestSuiteClientFixture
{
    std::string testFirstName = "Bartek";
    const string testLastName = "Sliwa";
    const string testPersonalID = "0000";
    Address *testaddress1;
    Address *testaddress2;
    TestSuiteClientFixture()
    {
        testaddress1 = new Address("Londyn", "Warecka", "13");
        testaddress2 = new Address("Warszawa", "Warszawska", "23");
    }
    ~TestSuiteClientFixture()
    {
        delete testaddress1;
        delete testaddress2;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(AssertionsTests)
    {
        BOOST_TEST(true, boost::test_tools::tolerance(0.5));
        BOOST_TEST(true);
    }
    BOOST_AUTO_TEST_CASE(ClientConstructorTest)
    {
        Client t (testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST_CHECK(t.getClientInfo()=="Client, Bartek, Sliwa, 0000, Adres: Londyn, Warecka, 13\n");
    }
    BOOST_AUTO_TEST_CASE(ClientSettersTest)
    {
        Client t (testFirstName, testLastName, testPersonalID, testaddress1);
        t.setfirstName("Janok");
        BOOST_TEST_CHECK(t.getfirstName()=="Janok");
        t.setfirstName("");
        BOOST_TEST_CHECK(t.getfirstName()=="Janok");

        t.setlastName("Mandarynka");
        BOOST_TEST_CHECK(t.getlastName()=="Mandarynka");
        t.setfirstName("");
        BOOST_TEST_CHECK(t.getlastName()=="Mandarynka");

        Address a2 ("Warszawa", "Warszawska", "23");
        t.setaddresspointer(&a2);
        BOOST_TEST_CHECK(t.getaddresspointer()==&a2);
        t.setaddresspointer(nullptr);
        BOOST_TEST_CHECK(t.getaddresspointer()==&a2);
    }
BOOST_AUTO_TEST_SUITE_END()