//
// Created by student on 26.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Bicycle.h>

struct TestSuiteBicycleFixture {
    const std::string testplateNumber = "ELC 4823";
    const int testbasePrice = 30;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteBicycle, TestSuiteBicycleFixture)

    BOOST_AUTO_TEST_CASE(BicycleConstructorTest) {
        BicyclePtr B1 = new Bicycle(testplateNumber, testbasePrice);
        BOOST_TEST(B1->get_plateNumber() == testplateNumber);
        BOOST_TEST(B1->get_basePrice() == testbasePrice);
        BOOST_TEST(B1->isRented() == false);
        delete B1;
    }

    BOOST_AUTO_TEST_CASE(BicycleGetVehicleInfoTest) {
        BicyclePtr B1 = new Bicycle(testplateNumber, testbasePrice);
        BOOST_TEST(B1->getVehicleInfo() == "Bicycle " + testplateNumber + " " + std::to_string(testbasePrice) + "\n");
        delete B1;
    }

    BOOST_AUTO_TEST_CASE(BicycleSetRentStatusTest) {
        BicyclePtr B1 = new Bicycle(testplateNumber, testbasePrice);
        B1->set_RentStatus(true);
        BOOST_TEST(B1->isRented() == true);
        delete B1;
    }

    BOOST_AUTO_TEST_CASE(BicycleGetActualRentPriceTest) {
        BicyclePtr B1 = new Bicycle(testplateNumber, testbasePrice);
        BOOST_TEST(B1->getActualRentalPrice() == testbasePrice);
        delete B1;
    }

BOOST_AUTO_TEST_SUITE_END()