//
// Created by student on 03.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Address.h>

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(AddressConstructorTest)
    {
        Address a ("Los Angeles","Warecka","13");
        BOOST_TEST_CHECK(a.getAddressInfo()=="Adres: Los Angeles, Warecka, 13");
    }
    BOOST_AUTO_TEST_CASE(AddresssetcityTest)
    {
        Address a ("Moskwa","Julianowska","15");
        BOOST_TEST_CHECK(a.getcity()=="Moskwa");
        BOOST_TEST_CHECK(a.getstreet()=="Julianowska");
        BOOST_TEST_CHECK(a.getnumber()=="15");
    }
BOOST_AUTO_TEST_SUITE_END()