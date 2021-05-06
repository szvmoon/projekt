//
// Created by student on 24.03.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include <model/Address.h>
#include <model/Bicycle.h>
#include <iostream>
#include "typedefs.h"

struct TestSuiteClientFixture {
    std::string testFirstName = "Bartek";
    const string testLastName = "Sliwa";
    const string testPersonalID = "0000";
    pt::ptime testbeginTime=pt::ptime(gr::date(2021,5,16));

    AddressPtr testaddress1;
    AddressPtr testaddress2;
    BicyclePtr testbicycle;

    TestSuiteClientFixture() {
        testaddress1 = new Address ("Londyn", "Warecka", "13");
        testaddress2 = new Address ("Warszawa", "Warszawska", "23");
        testbicycle = new Bicycle ("EZG42069", 10);
    }
    ~TestSuiteClientFixture() {
        delete testaddress1;
        delete testaddress2;
        delete testbicycle;
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
        BOOST_TEST_CHECK(t.getClientInfo()=="Client, Bartek, Sliwa, 0000, Adres: Londyn, Warecka, 13");
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
    BOOST_AUTO_TEST_CASE(ClientRemoveRentTest) {
        ClientPtr t = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        RentPtr r = new Rent(1, t, testbicycle, testbeginTime);
        BOOST_TEST(t->getRent() == "Current Rents:\n" + r->getRentInfo());
        t->removeRent(r);
        BOOST_TEST(t->getRent() == "Current Rents:\n");

        delete r;
        delete t;
    }

    BOOST_AUTO_TEST_CASE(ClientGetClientInfoTest) {
        ClientPtr t = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(t->getClientInfo() ==
                   "Client " + testFirstName + " " + testLastName + " " + testPersonalID + " " +
                   testaddress1->getAddressInfo() + "\n");
        delete t;
    }
    BOOST_AUTO_TEST_CASE(ClientGetFullClientInfoTest) {
        ClientPtr t = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(t->getFullClientInfo() == t->getClientInfo() + t->getRent());

        delete t;
    }

BOOST_AUTO_TEST_SUITE_END()