//
// Created by student on 06.04.2021.
//
#include <boost/test/unit_test.hpp>
//#include <model/Client.h>
//#include <model/Address.h>
#include <model/Rent.h>
#include <iostream>

struct TestSuiteClientFixture
{
    const int testID=13;
    pt::ptime testbeginTime=pt::ptime(gr::date(2021,10,10));
    Client *testclient1;
    Address *testaddress1;
    Vehicle *testvehicle1;
    TestSuiteClientFixture()
    {
        testaddress1 = new Address("Londyn", "Warecka", "13");
        testvehicle1 = new Vehicle("EZG23334",23);
        testclient1= new Client("Bartek", "Sliwa", "69420", testaddress1);
    }
    ~TestSuiteClientFixture()
    {
        delete testaddress1;
        delete testvehicle1;
        delete testclient1;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(RentConstructorTest)
    {
    /*    Rent R (testID,testclient1,testvehicle1, testbeginTime);
        BOOST_TEST(R->getid() == testID);
        BOOST_TEST(R->getclient() == testclient1);
        BOOST_TEST(R->getvehicle() == testvehicle1);
        BOOST_TEST(R->getbeginTime() == testbeginTime);
        BOOST_TEST(R->getvehicle()->getrented() == true);*/

    }
    BOOST_AUTO_TEST_CASE(RentSettersTest)
    {
  /*      Rent R(testID, testclient1, testvehicle1, testbeginTime);
        R.endRent(pt::ptime(gr::date(2021, 10, 12)));
        BOOST_TEST(R.getRentInfo() ==
                   std::to_string(testID) + " " + R.getclient()->getfirstName() + " " + R.getclient()->getlastName() +
                   " " + R.getvehicle()->getVehicleInfo());
        BOOST_TEST(R.getRentDays() == 2);
        BOOST_TEST(R.getRentCost() == 2 * R.getvehicle()->getbasePrice());*/
    }
BOOST_AUTO_TEST_SUITE_END()
