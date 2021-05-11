//
// Created by student on 28.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Moped.h>

struct TestSuiteMopedFixture {
    const std::string testplateNumber = "ELC 4823";
    const int testbasePrice = 15;
    const int testEngineDisplacement = 900;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteMoped, TestSuiteMopedFixture)

    BOOST_AUTO_TEST_CASE(MopedConstructorTest) {
        MopedPtr m = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        BOOST_TEST(m->getplateNumber() == testplateNumber);
        BOOST_TEST(m->getbasePrice() == testbasePrice);
        BOOST_TEST(m->getengineDisplacement() == 900);
        BOOST_TEST(m->getrented() == false);
        delete m;
    }
    BOOST_AUTO_TEST_CASE(MopedGetVehicleInfoTest) {
        MopedPtr m = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        BOOST_TEST(m->getVehicleInfo() == "Moped: " + testplateNumber + ", " + std::to_string(testbasePrice) + " " + std::to_string(testEngineDisplacement) + "\n");
        delete m;
    }
    BOOST_AUTO_TEST_CASE(MopedSetRentStatusTest) {
        MopedPtr m = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        m->setengineDisplacement(1100);
        BOOST_TEST(m->getengineDisplacement() == 1100);
        delete m;
    }
    BOOST_AUTO_TEST_CASE(MopedSetEngineDisplacementTest) {
        MopedPtr m = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        m->setrented(true);
        BOOST_TEST(m->getrented() == true);
        delete m;
    }
    BOOST_AUTO_TEST_CASE(MopedGetActualRentPriceTest) {
        MopedPtr m = new Moped(testplateNumber, testbasePrice, testEngineDisplacement);
        BOOST_TEST(m->getActualRentalPrice() == testbasePrice);
        m->setengineDisplacement(1100);
        BOOST_TEST(m->getActualRentalPrice() == testbasePrice *1.1);
        delete m;
    }

BOOST_AUTO_TEST_SUITE_END()