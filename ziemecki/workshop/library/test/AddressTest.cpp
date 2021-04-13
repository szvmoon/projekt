//
// Created by student on 11.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Address.h>

struct TestSuiteAddressFixture {
    const std::string testCity = "Warsaw";
    const std::string testStreet = "Jasna";
    const std::string testNumber = "12";

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(AddressConstructorTest) {
        Address *Adres = new Address(testCity, testStreet, testNumber);
        BOOST_TEST(Adres->get_City() == testCity);
        BOOST_TEST(Adres->get_Street() == testStreet);
        BOOST_TEST(Adres->get_Number() == testNumber);
        delete Adres;
    }

    BOOST_AUTO_TEST_CASE(AddressSettersTest) {
        Address *Adres = new Address(testCity, testStreet, testNumber);
        Adres->set_City("Jaworzno");
        BOOST_TEST(Adres->get_City() == "Jaworzno");
        Adres->set_Street("Essunia");
        BOOST_TEST(Adres->get_Street() == "Essunia");
        Adres->set_Number("14");
        BOOST_TEST(Adres->get_Number() == "14");
    }

BOOST_AUTO_TEST_SUITE_END()