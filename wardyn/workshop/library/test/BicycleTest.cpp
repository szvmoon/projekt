//
// Created by student on 28.04.2021.
//
#include <boost/test/unit_test.hpp>
#include <model/Bicycle.h>

struct TestSuiteBicycleFixture {
    const string testplateNumber = "EZG42069";
    const int testbasePrice = 10;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteBicycle, TestSuiteBicycleFixture)

BOOST_AUTO_TEST_CASE(BicycleConstructorTest) {
        BicyclePtr B = new Bicycle(testplateNumber, testbasePrice);
        BOOST_TEST(B->getplateNumber() == testplateNumber);
        BOOST_TEST(B->getbasePrice() == testbasePrice);
        BOOST_TEST(B->getrented() == false);
        delete B;
}

BOOST_AUTO_TEST_CASE(BicycleGetVehicleInfoTest) {
        BicyclePtr B = new Bicycle(testplateNumber, testbasePrice);
        BOOST_TEST(B->getVehicleInfo() == "Bicycle: " + testplateNumber + " " + std::to_string(testbasePrice) + "\n");
        delete B;
}

BOOST_AUTO_TEST_CASE(BicycleSetRentStatusTest) {
        BicyclePtr B = new Bicycle(testplateNumber, testbasePrice);
        B->setrented(true);
        BOOST_TEST(B->getrented() == true);
        delete B;
}

BOOST_AUTO_TEST_CASE(BicycleGetActualRentPriceTest) {
        BicyclePtr B = new Bicycle(testplateNumber, testbasePrice);
        BOOST_TEST(B->getActualRentalPrice() == testbasePrice);
        delete B;
}

BOOST_AUTO_TEST_SUITE_END()
