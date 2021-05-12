//
// Created by student on 12.05.2021.
//

#include <boost/test/unit_test.hpp>
#include "managers/LogicContainer.h"
#include "model/Default.h"
#include "typedefs.h"
#include "model/Address.h"
#include "model/Client.h"

struct TestSuiteClientManagerFixture {
    LogicContainerPtr logicContainerTest;
    ClientTypePtr defaultMemberTest;
    AddressPtr addressTest;

    TestSuiteClientManagerFixture() {
        addressTest = std::make_shared<Address>("Nowy Sad", "Karczma", "1");
        defaultMemberTest = std::make_shared<Default>();
        logicContainerTest = std::make_shared<LogicContainer>();
    }

    ~TestSuiteClientManagerFixture() { }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(GetClientTest) {
        ClientPtr client = logicContainerTest->getClientManager().getClient("007183000");
        BOOST_CHECK(client != nullptr);
        client = logicContainerTest->getClientManager().getClient("0000000");
        BOOST_CHECK(client == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RegisterClientTest) {
        ClientPtr client = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "1337", addressTest, defaultMemberTest);
        ClientPtr client2 = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "1337", addressTest, defaultMemberTest);
        PrediaceByClientId functor("1337");
        BOOST_CHECK_EQUAL(logicContainerTest->getClientManager().findClients(functor).size(), 1);
        BOOST_CHECK_EQUAL(logicContainerTest->getClientManager().findAllClients().size(), 3);
    }

    BOOST_AUTO_TEST_CASE(UnregisterClientTest) {
        ClientPtr client = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "1337", addressTest, defaultMemberTest);
        ClientPtr client2 = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "1338", addressTest, defaultMemberTest);
        ClientPtr client3 = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "0987654321", addressTest, defaultMemberTest);
        BOOST_CHECK_EQUAL(client->isArchive(), false);
        logicContainerTest->getClientManager().unregisterClient(client);
        BOOST_CHECK_EQUAL(client->isArchive(), true);
    }

    BOOST_AUTO_TEST_CASE(FindClientTest) {
        ClientPtr client = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "1337", addressTest, defaultMemberTest);
        ClientPtr client2 = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "1338", addressTest, defaultMemberTest);
        ClientPtr client3 = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "0987654321", addressTest, defaultMemberTest);
        logicContainerTest->getClientManager().unregisterClient(client);
        PrediaceByClientId functor("1337");
        BOOST_CHECK_EQUAL(logicContainerTest->getClientManager().findClients(functor).size(), 0);
        PrediaceByClientId functor2("1338");
        BOOST_CHECK_EQUAL(logicContainerTest->getClientManager().findClients(functor2).size(), 1);
    }

    BOOST_AUTO_TEST_CASE(FindAllClientTest) {
        ClientPtr client = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "1337", addressTest, defaultMemberTest);
        ClientPtr client2 = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "1338", addressTest, defaultMemberTest);
        ClientPtr client3 = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "0987654321", addressTest, defaultMemberTest);
        BOOST_CHECK_EQUAL(logicContainerTest->getClientManager().findAllClients().size(), 5);
    }

    BOOST_AUTO_TEST_CASE(FunctorTest) {
        ClientPtr client = logicContainerTest->getClientManager().registerClient("Adam", "Nowak", "007183000", addressTest, defaultMemberTest);
        PrediaceByClientId functor("007183000");
        BOOST_CHECK_EQUAL(functor.operator()(client), true);
        BOOST_CHECK_EQUAL(functor(client), true);
        BOOST_CHECK_EQUAL(logicContainerTest->getClientManager().findClients(functor).size(),unsigned(1));
    }


BOOST_AUTO_TEST_SUITE_END()