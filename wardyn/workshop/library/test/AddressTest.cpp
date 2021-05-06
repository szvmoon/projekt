//
// Created by student on 03.04.2021.
//

#include <boost/test/unit_test.hpp>
#include "model/Address.h"
#include "typedefs.h"

struct TestSuiteAddressFixture {
    const std::string testCity = "Londyn";
    const std::string testStreet = "Warecka";
    const std::string testNumber = "13";

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(AddressConstructorTest) {
        AddressPtr A = new Address(testCity, testStreet, testNumber);
        BOOST_TEST(A->getcity() == testCity);
        BOOST_TEST(A->getstreet() == testStreet);
        BOOST_TEST(A->getnumber() == testNumber);
        delete A;
    }

    BOOST_AUTO_TEST_CASE(AddressGetAddressInfoTest) {
        AddressPtr A = new Address(testCity, testStreet, testNumber);
        BOOST_TEST(A->getAddressInfo() == "Adres: " + testCity + ", " + testStreet + ", " + testNumber);
        delete A;
    }
BOOST_AUTO_TEST_SUITE_END()