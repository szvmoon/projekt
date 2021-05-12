//
// Created by student on 12.05.2021.
//



#include <boost/date_time.hpp>
#include <boost/test/unit_test.hpp>
#include "managers/LogicContainer.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "typedefs.h"

struct TestSuiteRentManagerFixture {
    LogicContainerPtr logicContainerTest;

    TestSuiteRentManagerFixture() {
        logicContainerTest = std::make_shared<LogicContainer>();
    }

    ~TestSuiteRentManagerFixture() { }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager, TestSuiteRentManagerFixture)

    BOOST_AUTO_TEST_CASE(RentVehicleTest) {
        ClientPtr client = logicContainerTest->getClientManager().getClient("007183000");
        VehiclePtr vehicle = logicContainerTest->getVehicleManager().getVehicle("PN1");
        ClientPtr client2 = logicContainerTest->getClientManager().getClient("123123123");
        VehiclePtr vehicle2 = logicContainerTest->getVehicleManager().getVehicle("PN2");
        RentPtr rent1 = logicContainerTest->getRentManager().rentVehicle(client, vehicle, boost::posix_time::not_a_date_time);
        RentPtr rent2 = logicContainerTest->getRentManager().rentVehicle(client2, vehicle2, boost::posix_time::not_a_date_time);
        BOOST_CHECK_EQUAL(logicContainerTest->getRentManager().findAllRents().size(), 2);
    }

    BOOST_AUTO_TEST_CASE(ReturnVehicleTest) {
        ClientPtr client = logicContainerTest->getClientManager().getClient("007183000");
        VehiclePtr vehicle = logicContainerTest->getVehicleManager().getVehicle("PN1");
        ClientPtr client2 = logicContainerTest->getClientManager().getClient("123123123");
        VehiclePtr vehicle2 = logicContainerTest->getVehicleManager().getVehicle("PN2");
        RentPtr rent1 = logicContainerTest->getRentManager().rentVehicle(client, vehicle, boost::posix_time::not_a_date_time);
        RentPtr rent2 = logicContainerTest->getRentManager().rentVehicle(client2, vehicle2, boost::posix_time::not_a_date_time);
        BOOST_CHECK_EQUAL(logicContainerTest->getRentManager().findAllRents().size(), 2);
        logicContainerTest->getRentManager().returnVehicle(vehicle2);
        BOOST_CHECK_EQUAL(logicContainerTest->getRentManager().findAllRents().size(), 1);
    }

BOOST_AUTO_TEST_SUITE_END()

