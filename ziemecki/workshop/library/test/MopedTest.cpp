//
// Created by student on 26.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Moped.h>

struct TestSuiteMopedFixture {
    const std::string testplateNumber = "ELC 4823";
    const int testbasePrice = 30;
    const int testEngineDisplacement = 1200;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteMoped, TestSuiteMopedFixture)

    BOOST_AUTO_TEST_CASE(MopedConstructorTest) {
        MopedPtr M1 = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        BOOST_TEST(M1->get_plateNumber() == testplateNumber);
        BOOST_TEST(M1->get_basePrice() == testbasePrice);
        BOOST_TEST(M1->get_engineDisplacement() == 1200);
        BOOST_TEST(M1->isRented() == false);
        delete M1;
    }

    BOOST_AUTO_TEST_CASE(MopedGetVehicleInfoTest) {
        MopedPtr M1 = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        BOOST_TEST(M1->getVehicleInfo() == "Moped " + testplateNumber + " " + std::to_string(testbasePrice) + " " + std::to_string(testEngineDisplacement) + "\n");
        delete M1;
    }

    BOOST_AUTO_TEST_CASE(MopedSetRentStatusTest) {
        MopedPtr M1 = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        M1->set_engineDisplacement(1400);
        BOOST_TEST(M1->get_engineDisplacement() == 1400);
        delete M1;
    }

    BOOST_AUTO_TEST_CASE(MopedSetEngineDisplacementTest) {
        MopedPtr M1 = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        M1->set_RentStatus(true);
        BOOST_TEST(M1->isRented() == true);
        delete M1;
    }

    BOOST_AUTO_TEST_CASE(MopedGetActualRentPriceTest) {
        MopedPtr M1 = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        BOOST_TEST(M1->getActualRentalPrice() == testbasePrice * 1.1);
        M1->set_engineDisplacement(1400);
        BOOST_TEST(M1->getActualRentalPrice() == testbasePrice *1.2);
        delete M1;
    }

BOOST_AUTO_TEST_SUITE_END()