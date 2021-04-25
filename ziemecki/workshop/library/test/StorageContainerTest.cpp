//
// Created by student on 24.04.2021.
//

//
// Created by student on 11.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <repositories/StorageContainer.h>

struct TestSuiteStorageContainerFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    const std::string testPlateNumber = "ELC";
    const int testbasePrice = 20;
    AddressPtr testaddress1;


    TestSuiteStorageContainerFixture() {
        testaddress1 = new Address("London", "Accacia Avenue", "22");
    }

    ~TestSuiteStorageContainerFixture() {
        delete testaddress1;
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteStorgaeContainer, TestSuiteStorageContainerFixture)

    bool testId1(RentPtr ptr)
    {
        return ptr->get_ID()==1;
    }


    BOOST_AUTO_TEST_CASE(StorageContainerConstructorTest) {
        StorageContainerPtr S1 = new StorageContainer();
        BOOST_TEST(S1->getClientRepository()->get(0)->getClientInfo() == "Client Szymon Ziemecki 123 Address wwa jasna 1\n");
        BOOST_TEST(S1->getRentRepository()->get(0)->getRentInfo() == "1 Szymon Ziemecki Vehicle ELC 20 2021-May-16 00:00:00 not-a-date-time\n");
        BOOST_TEST(S1->getVehicleRepository()->get(0)->getVehicleInfo() == "Vehicle ELC 20");
        delete S1;
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryMethodsTest) {
        StorageContainerPtr S2 = new StorageContainer();
        ClientPtr K1 = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        S2->getClientRepository()->add(nullptr);
        BOOST_TEST(S2->getClientRepository()->size() == 1);
        S2->getClientRepository()->add(K1);
        BOOST_TEST(S2->getClientRepository()->get(1) == K1);
        BOOST_TEST(S2->getClientRepository()->size() == 2);
        S2->getClientRepository()->remove(nullptr);
        BOOST_TEST(S2->getClientRepository()->size() == 2);
        S2->getClientRepository()->remove(K1);
        BOOST_TEST(S2->getClientRepository()->size() == 1);
        BOOST_TEST(S2->getClientRepository()->report() == "Client Szymon Ziemecki 123 Address wwa jasna 1\n");


        delete S2;
        delete K1;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryMethodsTest) {
        StorageContainerPtr S2 = new StorageContainer();
        VehiclePtr V1 = new Vehicle(testPlateNumber, testbasePrice);
        S2->getVehicleRepository()->add(nullptr);
        BOOST_TEST(S2->getVehicleRepository()->size() == 1);
        S2->getVehicleRepository()->add(V1);
        BOOST_TEST(S2->getVehicleRepository()->get(1) == V1);
        BOOST_TEST(S2->getVehicleRepository()->size() == 2);
        S2->getVehicleRepository()->remove(nullptr);
        BOOST_TEST(S2->getVehicleRepository()->size() == 2);
        S2->getVehicleRepository()->remove(V1);
        BOOST_TEST(S2->getVehicleRepository()->size() == 1);
        BOOST_TEST(S2->getVehicleRepository()->report() == "Vehicle ELC 20");
        delete S2;
        delete V1;
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryMethodsTest) {
        StorageContainerPtr S2 = new StorageContainer();
        ClientPtr K1 = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        VehiclePtr V1 = new Vehicle(testPlateNumber, testbasePrice);
        RentPtr R1 = new Rent(2, K1, V1, pt::not_a_date_time);
        S2->getRentRepository()->add(nullptr);
        BOOST_TEST(S2->getRentRepository()->size() == 1);
        S2->getRentRepository()->add(R1);
        BOOST_TEST(S2->getRentRepository()->get(1) == R1);
        BOOST_TEST(S2->getRentRepository()->size() == 2);
        S2->getRentRepository()->remove(nullptr);
        BOOST_TEST(S2->getRentRepository()->size() == 2);

        std::vector<RentPtr> test = S2->getRentRepository()->findBy(testId1);
        BOOST_TEST(test[0]->get_ID() == 1);
        BOOST_TEST(test.size() == 1);


        S2->getRentRepository()->remove(R1);
        BOOST_TEST(S2->getRentRepository()->size() == 1);
        BOOST_TEST(S2->getRentRepository()->report() == "1 Szymon Ziemecki Vehicle ELC 20 2021-May-16 00:00:00 not-a-date-time\n");

        delete S2;
        delete V1;
        delete R1;
        delete K1;
    }


BOOST_AUTO_TEST_SUITE_END()