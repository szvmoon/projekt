//
// Created by student on 03.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Address.h>

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(AssertionsTests)
    {
        BOOST_TEST(true, boost::test_tools::tolerance(0.5));
        BOOST_TEST(true);
    }
    BOOST_AUTO_TEST_CASE(AddressConstructorTest)
    {
        Address a ("Los Angeles","Warecka","13");
        BOOST_TEST_CHECK(a.getAddressInfo()=="Adres: Los Angeles, Warecka, 13");
    }
    BOOST_AUTO_TEST_CASE(AddresssetcityTest)
    {
        Address a ("Moskwa","Julianowska","15");
        //a.setcity("Petersburg");
        BOOST_TEST_CHECK(a.getcity()=="Moskwa");
      /*  a.setcity("");
        BOOST_TEST_CHECK(a.getcity()=="Petersburg");*/

      //  a.setstreet("Sowinskiego");
        BOOST_TEST_CHECK(a.getstreet()=="Julianowska");
     //   a.setstreet("");
      //  BOOST_TEST_CHECK(a.getstreet()=="Sowinskiego");


       // a.setnumber("69");
        BOOST_TEST_CHECK(a.getnumber()=="15");
       // a.setnumber("");
        //BOOST_TEST_CHECK(a.getnumber()=="69");
    }
BOOST_AUTO_TEST_SUITE_END()