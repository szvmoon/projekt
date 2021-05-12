//
// Created by student on 12.05.2021.
//

#include <boost/date_time.hpp>
#include <boost/test/unit_test.hpp>
#include "managers/LogicContainer.h"
#include "typedefs.h"

struct TestSuiteVehicleManagerFixture {
    LogicContainerPtr logicContainerTest;

    TestSuiteVehicleManagerFixture() {
        logicContainerTest = std::make_shared<LogicContainer>();
    }

    ~TestSuiteVehicleManagerFixture() { }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleManager, TestSuiteVehicleManagerFixture)

    BOOST_AUTO_TEST_CASE(GetVehicleTest) {
        VehiclePtr bicycle = logicContainerTest->getVehicleManager().getVehicle("PN1");
        BOOST_CHECK(bicycle != nullptr);
        bicycle = logicContainerTest->getVehicleManager().getVehicle("0000000");
        BOOST_CHECK(bicycle == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RegisterVehicleTest) {
        VehiclePtr bicycle = logicContainerTest->getVehicleManager().registerBicycle("PN4", 150);
        VehiclePtr bicycle2 = logicContainerTest->getVehicleManager().registerBicycle("PN4", 200);
        BOOST_CHECK_EQUAL(logicContainerTest->getVehicleManager().findAllVehicles().size(), 4);
    }

    BOOST_AUTO_TEST_CASE(UnregisterVehicleTest) {
        VehiclePtr bicycle = logicContainerTest->getVehicleManager().registerBicycle("PN4", 150);
        VehiclePtr moped = logicContainerTest->getVehicleManager().registerMoped("PN5", 200, 300);
        VehiclePtr car = logicContainerTest->getVehicleManager().registerCar("PN6", 500, 1200, A);
        BOOST_CHECK_EQUAL(bicycle->isArchive(), false);
        logicContainerTest->getVehicleManager().unregisterVehicle(bicycle);
        BOOST_CHECK_EQUAL(bicycle->isArchive(), true);
    }

BOOST_AUTO_TEST_SUITE_END()