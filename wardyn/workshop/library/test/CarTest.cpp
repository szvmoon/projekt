//
// Created by student on 28.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Car.h>

struct TestSuiteCarFixture {
    const std::string testplateNumber = "EZG42069";
    const int testbasePrice = 50;
    const int testEngineDisplacement = 3000;
    const SegmentType testSegment = E;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteCar, TestSuiteCarFixture)

    BOOST_AUTO_TEST_CASE(CarConstructorTest) {
        CarPtr C = new Car(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        BOOST_TEST(C->getplateNumber() == testplateNumber);
        BOOST_TEST(C->getbasePrice() == testbasePrice);
        BOOST_TEST(C->getengineDisplacement() == 1200);
        BOOST_TEST(C->getrented() == false);
        BOOST_TEST(C->getSegment() == testSegment);
        delete C;
    }

    BOOST_AUTO_TEST_CASE(CarGetVehicleInfoTest) {
        CarPtr C = new Car(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        BOOST_TEST(C->getVehicleInfo() == "Car " + testplateNumber + " " + std::to_string(testbasePrice) + " " + std::to_string(testEngineDisplacement) + " " + std::to_string(testSegment) + "\n");
        delete C;
    }

    BOOST_AUTO_TEST_CASE(MopedSetRentStatusTest) {
        CarPtr C = new Car(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        C->setengineDisplacement(2800);
        BOOST_TEST(C->getengineDisplacement() == 2800);
        delete C;
    }

    BOOST_AUTO_TEST_CASE(MopedSetEngineDisplacementTest) {
        CarPtr C = new Car(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        C->setrented(true);
        BOOST_TEST(C->getrented() == true);
        delete C;
    }

    BOOST_AUTO_TEST_CASE(MopedGetActualRentPriceTest) {
        CarPtr C = new Car(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        BOOST_TEST(C->getActualRentalPrice() == testbasePrice * 1.5 * testSegment / 10);
        C->setengineDisplacement(1800);
        BOOST_TEST(C->getActualRentalPrice() == testbasePrice * 1.4 * testSegment / 10);
        delete C;
    }

BOOST_AUTO_TEST_SUITE_END()