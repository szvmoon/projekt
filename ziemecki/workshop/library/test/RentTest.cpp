//
// Created by student on 11.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Rent.h>
#include <model/Bicycle.h>
#include "typedefs.h"

using namespace std;
struct TestSuiteRentFixture {
    const int testID= 12;
    pt::ptime testbeginTime=pt::ptime(gr::date(2021,5,16));
    ClientPtr testclient1;
    AddressPtr testaddress1;
    BicyclePtr testvehicle1;

    TestSuiteRentFixture() {
        testaddress1 = make_shared<Address>("London", "Accacia Avenue", "22");
        testvehicle1 = make_shared<Bicycle>("ECL123", 12);
        testclient1 = make_shared<Client>("Szymon", "Ziemecki", "123", testaddress1);
    }

    ~TestSuiteRentFixture() {
    }


};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

BOOST_AUTO_TEST_CASE(RentConstructorTest) {
        RentPtr R1 = make_shared<Rent>(testID, testclient1, testvehicle1,testbeginTime);
        BOOST_TEST(R1->get_ID() == testID);
        BOOST_TEST(R1->get_client() == testclient1);
        BOOST_TEST(R1->get_vehicle() == testvehicle1);
        BOOST_TEST(R1->get_beginDate() == testbeginTime);
        //BOOST_TEST(R1->get_vehicle()->isRented() == true);

}

    BOOST_AUTO_TEST_CASE(RentMethodsTest) {
        RentPtr R1 = make_shared<Rent>(testID, testclient1, testvehicle1,testbeginTime);
        R1->endRent(pt::ptime(gr::date(2021,5,17)));
        BOOST_TEST(R1->getRentInfo() == std::to_string(testID) + " " + R1->get_client()->get_firstName() + " " + R1->get_client()->get_lastName() + " " + R1->get_vehicle()->getVehicleInfo() + " 2021-May-16 00:00:00 2021-May-17 00:00:00" + "\n");
        BOOST_TEST(R1->getRentDays() == 2);
        BOOST_TEST(R1->getRentCost() == 2 * R1->get_vehicle()->get_basePrice());
        BOOST_TEST(R1->get_endDate() == pt::ptime(gr::date(2021,5,17)));
    }


BOOST_AUTO_TEST_SUITE_END()