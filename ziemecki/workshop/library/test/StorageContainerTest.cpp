//
// Created by student on 24.04.2021.
//

//
// Created by student on 11.04.2021.
//

#include <boost/test/unit_test.hpp>
#include <repositories/StorageContainer.h>

using namespace std;

struct TestSuiteStorageContainerFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    const std::string testPlateNumber = "ELC";
    const int testbasePrice = 20;
    AddressPtr testaddress1;


    TestSuiteStorageContainerFixture() {
        testaddress1 = make_shared<Address>("London", "Accacia Avenue", "22");
    }

    ~TestSuiteStorageContainerFixture() {
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteStorgaeContainer, TestSuiteStorageContainerFixture)

    bool testId1(RentPtr ptr)
    {
            return ptr->get_ID() == 1;
    }

    bool testName1(ClientPtr ptr)
    {
        return ptr->get_firstName() == "Jon";
    }

    bool testPNumber1(VehiclePtr ptr)
    {
        return ptr->get_plateNumber() == "ELC1";
    }


    BOOST_AUTO_TEST_CASE(StorageContainerConstructorTest) {
        StorageContainerPtr S1 = make_shared<StorageContainer>();
        BOOST_TEST(S1->getClientRepository()->get(0)->getClientInfo() == "Client Szymon Ziemecki 123 Address wwa jasna 1\n");
        BOOST_TEST(S1->getRentRepository()->get(0)->getRentInfo() == "1 Szymon Ziemecki Bicycle ELC 20\n 2021-May-16 00:00:00 not-a-date-time\n");
        BOOST_TEST(S1->getVehicleRepository()->get(0)->getVehicleInfo() == "Bicycle ELC 20\n");
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryMethodsTest) {
        StorageContainerPtr S2 = make_shared<StorageContainer>();
        ClientPtr K1 = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);

        // add test
        S2->getClientRepository()->add(nullptr);
        BOOST_TEST(S2->getClientRepository()->size() == 1);
        S2->getClientRepository()->add(K1);
        BOOST_TEST(S2->getClientRepository()->get(1) == K1);
        BOOST_TEST(S2->getClientRepository()->size() == 2);

        // findBy test
        std::vector<ClientPtr> test = S2->getClientRepository()->findBy(testName1);
        BOOST_TEST(test[0]->get_firstName() == testFirstName);
        BOOST_TEST(test.size() == 1);

        // findAll test
        std::vector<ClientPtr> test2 = S2->getClientRepository()->findAll();
        BOOST_TEST(test2.size() == 2);

        //remove test
        S2->getClientRepository()->remove(nullptr);
        BOOST_TEST(S2->getClientRepository()->size() == 2);
        S2->getClientRepository()->remove(K1);
        BOOST_TEST(S2->getClientRepository()->size() == 1);

        //report test
        BOOST_TEST(S2->getClientRepository()->report() == "Client Szymon Ziemecki 123 Address wwa jasna 1\n");
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryMethodsTest) {
        StorageContainerPtr S2 = make_shared<StorageContainer>();
        BicyclePtr V1 = make_shared<Bicycle>("ELC1", testbasePrice);

        // add test
        S2->getVehicleRepository()->add(nullptr);
        BOOST_TEST(S2->getVehicleRepository()->size() == 1);
        S2->getVehicleRepository()->add(V1);
        BOOST_TEST(S2->getVehicleRepository()->get(1) == V1);
        BOOST_TEST(S2->getVehicleRepository()->size() == 2);

        // findBy test
        std::vector<VehiclePtr> test = S2->getVehicleRepository()->findBy(testPNumber1);
        BOOST_TEST(test[0]->get_plateNumber() == "ELC1");
        BOOST_TEST(test.size() == 1);

        // findAll test
        std::vector<VehiclePtr> test2 = S2->getVehicleRepository()->findAll();
        BOOST_TEST(test2.size() == 2);

        //remove test
        S2->getVehicleRepository()->remove(nullptr);
        BOOST_TEST(S2->getVehicleRepository()->size() == 2);
        S2->getVehicleRepository()->remove(V1);
        BOOST_TEST(S2->getVehicleRepository()->size() == 1);

        //report test
        BOOST_TEST(S2->getVehicleRepository()->report() == "Bicycle ELC 20\n");;
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryMethodsTest) {
        StorageContainerPtr S2 = make_shared<StorageContainer>();
        ClientPtr K1 = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        BicyclePtr V1 = make_shared<Bicycle>(testPlateNumber, testbasePrice);
        RentPtr R1 = make_shared<Rent>(2, K1, V1, pt::not_a_date_time);

        //add test
        S2->getRentRepository()->add(nullptr);
        BOOST_TEST(S2->getRentRepository()->size() == 1);
        S2->getRentRepository()->add(R1);
        BOOST_TEST(S2->getRentRepository()->get(1) == R1);
        BOOST_TEST(S2->getRentRepository()->size() == 2);

        // findBy test
        std::vector<RentPtr> test = S2->getRentRepository()->findBy(testId1);
        BOOST_TEST(test[0]->get_ID() == 1);
        BOOST_TEST(test.size() == 1);

        // findAll test
        std::vector<RentPtr> test2 = S2->getRentRepository()->findAll();
        BOOST_TEST(test2.size() == 2);


        //remove test
        S2->getRentRepository()->remove(nullptr);
        BOOST_TEST(S2->getRentRepository()->size() == 2);

        S2->getRentRepository()->remove(R1);
        BOOST_TEST(S2->getRentRepository()->size() == 1);

        //report test
        BOOST_TEST(S2->getRentRepository()->report() == "1 Szymon Ziemecki Bicycle ELC 20\n 2021-May-16 00:00:00 not-a-date-time\n");

    }


BOOST_AUTO_TEST_SUITE_END()