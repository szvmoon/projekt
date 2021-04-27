//
// Created by student on 27.03.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include <model/Vehicle.h>
#include <model/Address.h>
#include <model/Bicycle.h>
#include "typedefs.h"

using namespace std;

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    pt::ptime testbeginTime=pt::ptime(gr::date(2021,5,16));
    AddressPtr testaddress1;
    AddressPtr testaddress2;
    BicyclePtr testvehicle1;

    TestSuiteClientFixture() {
        testaddress1 = make_shared<Address>("London", "Accacia Avenue", "22");
        testaddress2 = make_shared<Address>("London", "Rue Morgue", "13");
        testvehicle1 = make_shared<Bicycle>("ELC123", 20);
    }

    ~TestSuiteClientFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        ClientPtr Klient = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(Klient->get_firstName() == testFirstName);
        BOOST_TEST(Klient->get_lastName() == testLastName);
        BOOST_TEST(Klient->get_personalID() == testPersonalID);
        BOOST_TEST(Klient->get_Address() == testaddress1);
    }

    BOOST_AUTO_TEST_CASE(ClientSetFirstNameTest) {
        ClientPtr Klient = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        Klient->set_firstName("");
        BOOST_TEST(Klient->get_firstName() == testFirstName);
        Klient->set_firstName("Essunia");
        BOOST_TEST(Klient->get_firstName() == "Essunia");
    }

    BOOST_AUTO_TEST_CASE(ClientSetLastNameTest) {
        ClientPtr Klient = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        Klient->set_lastName("");
        BOOST_TEST(Klient->get_lastName() == testLastName);
        Klient->set_lastName("Essunia");
        BOOST_TEST(Klient->get_lastName() == "Essunia");
    }

    BOOST_AUTO_TEST_CASE(ClientSetAddressTest) {
        ClientPtr Klient = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        Klient->set_Address(nullptr);
        BOOST_TEST(Klient->get_Address() == testaddress1);
        Klient->set_Address(testaddress2);
        BOOST_TEST(Klient->get_Address() == testaddress2);
    }

    BOOST_AUTO_TEST_CASE(ClientRemoveRentTest) {
        ClientPtr Klient = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        RentPtr Rent1 = make_shared<Rent>(1, Klient, testvehicle1, testbeginTime);
        //BOOST_TEST(Klient->get_Rents() == "Actual Rents:\n" + Rent1->getRentInfo());

        //Klient->remove_Rent(Rent1);
        //BOOST_TEST(Klient->get_Rents() == "Actual Rents:\n");
    }

    BOOST_AUTO_TEST_CASE(ClientGetClientInfoTest) {
        ClientPtr Klient = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(Klient->getClientInfo() ==
                   "Client " + testFirstName + " " + testLastName + " " + testPersonalID + " " +
                   testaddress1->getAddressInfo() + "\n");
    }
    /*
    BOOST_AUTO_TEST_CASE(ClientGetFullClientInfoTest) {
        ClientPtr Klient = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(Klient->getFullClientInfo() == Klient->getClientInfo() + Klient->get_Rents());
        delete Klient;
    }
*/

BOOST_AUTO_TEST_SUITE_END()


