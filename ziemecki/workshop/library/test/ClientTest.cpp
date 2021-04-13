//
// Created by student on 27.03.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include <model/Address.h>

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    Address *testaddress1;
    Address *testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = new Address("London", "Accacia Avenue", "22");
        testaddress2 = new Address("London", "Rue Morgue", "13");
    }

    ~TestSuiteClientFixture() {
        delete testaddress1;
        delete testaddress2;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        Client *Klient = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(Klient->get_firstName() == testFirstName);
        BOOST_TEST(Klient->get_lastName() == testLastName);
        BOOST_TEST(Klient->get_personalID() == testPersonalID);
        BOOST_TEST(Klient->get_Address() == testaddress1);
        delete Klient;
    }

    BOOST_AUTO_TEST_CASE(ClientSetterTest) {
        Client *Klient = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        Klient->set_firstName("");
        BOOST_TEST(Klient->get_firstName() == testFirstName);
        Klient->set_firstName("Essunia");
        BOOST_TEST(Klient->get_firstName() == "Essunia");

        Klient->set_lastName("");
        BOOST_TEST(Klient->get_lastName() == testLastName);
        Klient->set_lastName("Essunia");
        BOOST_TEST(Klient->get_lastName() == "Essunia");

        Klient->set_Address(nullptr);
        BOOST_TEST(Klient->get_Address() == testaddress1);
        Klient->set_Address(testaddress2);
        BOOST_TEST(Klient->get_Address() == testaddress2);

        delete Klient;
    }

    BOOST_AUTO_TEST_CASE(ClientMethodsTest) {
        Client *Klient = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(Klient->getClientInfo() ==
                   "Client " + testFirstName + " " + testLastName + " " + testPersonalID + " " + testaddress1->getAddressInfo() + "\n");
        delete Klient;
    }


BOOST_AUTO_TEST_SUITE_END()


