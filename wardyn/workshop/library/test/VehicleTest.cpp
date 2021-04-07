//
// Created by student on 06.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Vehicle.h>

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(VehicleConstructorTest)
    {
        Vehicle v ("237732", 12);
        BOOST_TEST_CHECK(v.getVehicleInfo()=="Pojazd: 237732, 12");
    }
    BOOST_AUTO_TEST_CASE(VehicleSettersTest)
    {
        Vehicle v ("237732", 12);
        v.setplateNumber("939939");
        BOOST_TEST_CHECK(v.getplateNumber()=="939939");
        v.setplateNumber("");
        BOOST_TEST_CHECK(v.getplateNumber()=="939939");
        v.setbasePrice(69);
        BOOST_TEST_CHECK(v.getbasePrice()==69);
    }
BOOST_AUTO_TEST_SUITE_END()