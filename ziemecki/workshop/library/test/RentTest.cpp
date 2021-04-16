//
// Created by student on 11.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Rent.h>

struct TestSuiteRentFixture {
    const int testID= 12;
    pt::ptime testbeginTime=pt::second_clock::local_time();
    Client *testclient1;
    Address *testaddress1;
    Vehicle *testvehicle1;

    TestSuiteRentFixture() {
        testaddress1 = new Address("London", "Accacia Avenue", "22");
        testvehicle1 = new Vehicle("ECL123", 12);
        testclient1 = new Client("Szymon", "Ziemecki", "123", testaddress1);
    }

    ~TestSuiteRentFixture() {
        delete testclient1;
        delete testvehicle1;
        delete testaddress1;
    }


};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

BOOST_AUTO_TEST_CASE(RentConstructorTest) {
        Rent *R1 = new Rent(testID, testclient1, testvehicle1,testbeginTime);
        BOOST_TEST(R1->get_ID() == testID);
        BOOST_TEST(R1->get_client() == testclient1);
        BOOST_TEST(R1->get_vehicle() == testvehicle1);
        BOOST_TEST(R1->get_beginDate() == testbeginTime);
        BOOST_TEST(R1->get_vehicle()->isRented() == true);
        delete R1;

}


BOOST_AUTO_TEST_SUITE_END()