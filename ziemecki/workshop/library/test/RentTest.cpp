//
// Created by student on 11.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Rent.h>
#include "typedefs.h"

struct TestSuiteRentFixture {
    const int testID= 12;
    pt::ptime testbeginTime=pt::ptime(gr::date(2021,5,16));
    ClientPtr testclient1;
    AddressPtr testaddress1;
    VehiclePtr testvehicle1;

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
        RentPtr R1 = new Rent(testID, testclient1, testvehicle1,testbeginTime);
        BOOST_TEST(R1->get_ID() == testID);
        BOOST_TEST(R1->get_client() == testclient1);
        BOOST_TEST(R1->get_vehicle() == testvehicle1);
        BOOST_TEST(R1->get_beginDate() == testbeginTime);
        BOOST_TEST(R1->get_vehicle()->isRented() == true);
        delete R1;

}

    BOOST_AUTO_TEST_CASE(RentMethodsTest) {
        RentPtr R1 = new Rent(testID, testclient1, testvehicle1,testbeginTime);
        R1->endRent(pt::ptime(gr::date(2021,5,17)));
        BOOST_TEST(R1->getRentInfo() == std::to_string(testID) + " " + R1->get_client()->get_firstName() + " " + R1->get_client()->get_lastName() + " " + R1->get_vehicle()->getVehicleInfo() + "\n");
        BOOST_TEST(R1->getRentDays() == 1);
        BOOST_TEST(R1->getRentCost() == 1 * R1->get_vehicle()->get_basePrice());
        BOOST_TEST(R1->get_endDate() == pt::ptime(gr::date(2021,5,17)));
        delete R1;

    }


BOOST_AUTO_TEST_SUITE_END()