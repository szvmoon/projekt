//
// Created by student on 11.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Address.h>
#include "typedefs.h"

using namespace std;

struct TestSuiteAddressFixture {
    const std::string testCity = "Warsaw";
    const std::string testStreet = "Jasna";
    const std::string testNumber = "12";

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(AddressConstructorTest) {
        AddressPtr Adres = make_shared<Address>(testCity, testStreet, testNumber);
        BOOST_TEST(Adres->get_City() == testCity);
        BOOST_TEST(Adres->get_Street() == testStreet);
        BOOST_TEST(Adres->get_Number() == testNumber);
    }

    BOOST_AUTO_TEST_CASE(AddressGetAddressInfoTest) {
        AddressPtr Adres = make_shared<Address>(testCity, testStreet, testNumber);
        BOOST_TEST(Adres->getAddressInfo() == "Address " + testCity + " " + testStreet + " " + testNumber);
    }

BOOST_AUTO_TEST_SUITE_END()