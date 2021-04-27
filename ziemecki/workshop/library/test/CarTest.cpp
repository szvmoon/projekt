//
// Created by student on 26.04.2021.
//


#include <boost/test/unit_test.hpp>
#include <model/Car.h>

using namespace std;

struct TestSuiteCarFixture {
    const std::string testplateNumber = "ELC 4823";
    const int testbasePrice = 30;
    const int testEngineDisplacement = 1200;
    const SegmentType testSegment = B;

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteCar, TestSuiteCarFixture)

    BOOST_AUTO_TEST_CASE(CarConstructorTest) {
        CarPtr C1 = make_shared<Car>(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        BOOST_TEST(C1->get_plateNumber() == testplateNumber);
        BOOST_TEST(C1->get_basePrice() == testbasePrice);
        BOOST_TEST(C1->get_engineDisplacement() == 1200);
        //BOOST_TEST(C1->isRented() == false);
        BOOST_TEST(C1->get_segment() == testSegment);
    }

    BOOST_AUTO_TEST_CASE(CarGetVehicleInfoTest) {
        CarPtr C1 = make_shared<Car>(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        BOOST_TEST(C1->getVehicleInfo() == "Car " + testplateNumber + " " + std::to_string(testbasePrice) + " " + std::to_string(testEngineDisplacement) + " " + std::to_string(testSegment) + "\n");
    }

    BOOST_AUTO_TEST_CASE(MopedSetRentStatusTest) {
        CarPtr C1 = make_shared<Car>(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        C1->set_engineDisplacement(1400);
        BOOST_TEST(C1->get_engineDisplacement() == 1400);
    }
/*
    BOOST_AUTO_TEST_CASE(MopedSetEngineDisplacementTest) {
        CarPtr C1 = new Car(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        C1->set_RentStatus(true);
        BOOST_TEST(C1->isRented() == true);
        delete C1;
    }
*/
    BOOST_AUTO_TEST_CASE(MopedGetActualRentPriceTest) {
        CarPtr C1 = make_shared<Car>(testplateNumber, testbasePrice, testEngineDisplacement,testSegment);
        BOOST_TEST(C1->getActualRentalPrice() == testbasePrice * 1.1 * testSegment / 10);
        C1->set_engineDisplacement(1400);
        BOOST_TEST(C1->getActualRentalPrice() == testbasePrice * 1.2 * testSegment / 10);
    }


BOOST_AUTO_TEST_SUITE_END()