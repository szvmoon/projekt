//
// Created by student on 11.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Vehicle.h>
#include "typedefs.h"

struct TestSuiteVehicleFixture {
    const std::string testplateNumber = "ELC 4823";
    const int testbasePrice = 30;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(VehicleConstructorTest) {
        VehiclePtr Car = new Vehicle(testplateNumber, testbasePrice);
        BOOST_TEST(Car->get_plateNumber() == testplateNumber);
        BOOST_TEST(Car->get_basePrice() == testbasePrice);
        BOOST_TEST(Car->isRented() == false);
        delete Car;
    }

    BOOST_AUTO_TEST_CASE(VehicleSettersTest) {
        VehiclePtr Car = new Vehicle(testplateNumber, testbasePrice);
        Car->set_plateNumber("");
        BOOST_TEST(Car->get_plateNumber() == testplateNumber);
        Car->set_plateNumber("ESSUNIA");
        BOOST_TEST(Car->get_plateNumber() == "ESSUNIA");
        Car->set_basePrice(12);
        BOOST_TEST(Car->get_basePrice() == 12);
        Car->set_RentStatus(true);
        BOOST_TEST(Car->isRented() == true);
        delete Car;
    }

    BOOST_AUTO_TEST_CASE(VehicleMethodsTest) {
        VehiclePtr Car = new Vehicle(testplateNumber, testbasePrice);
        BOOST_TEST(Car->getVehicleInfo() == "Vehicle " + testplateNumber + " " + std::to_string(testbasePrice) + "\n");
        delete Car;
    }

BOOST_AUTO_TEST_SUITE_END()