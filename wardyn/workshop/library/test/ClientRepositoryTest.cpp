//
// Created by student on 25.04.2021.
//
/*

#include <boost/test/unit_test.hpp>
#include "../repositories/StorageContainer.h"

struct TestSuiteRepositoryFixture{
    StorageContainer *test;
    TestSuiteRepositoryFixture(){
        test = new StorageContainer();
    }
    ~TestSuiteRepositoryFixture(){
        delete test;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepository, TestSuiteRepositoryFixture)
    BOOST_AUTO_TEST_CASE(ClientRepositoryTest) {
        BOOST_TEST(test->getClientRepository().get(0)->getClientInfo() == )
    }
}*/
