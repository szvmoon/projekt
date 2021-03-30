//
// Created by student on 24.03.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Client.h>

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(AssertionsTests)
    {
        BOOST_TEST(true, boost::test_tools::tolerance(0.5));
        BOOST_TEST(true);
    }
    BOOST_AUTO_TEST_CASE(ClientConstructorTest)
    {
        Client t ("Krzysiek","Pilsner","6663");
        BOOST_TEST_CHECK(t.getClientInfo()=="Client, Krzysiek, Pilsner, 6663\n");
    }
    BOOST_AUTO_TEST_CASE(ClientSetFirstnameTest)
    {
        Client t ("Jan","Bach","345456");
        t.setfirstName("Janok");
        BOOST_TEST_CHECK(t.getfirstName()=="Janok");
        t.setfirstName("");
        BOOST_TEST_CHECK(t.getfirstName()=="Janok");
    }
    BOOST_AUTO_TEST_CASE(ClientSetLastnameTest)
    {
        Client t ("Bartek","Sliwa","00000000");
        t.setlastName("Mandarynka");
        BOOST_TEST_CHECK(t.getlastName()=="Mandarynka");
        t.setfirstName("");
        BOOST_TEST_CHECK(t.getlastName()=="Mandarynka");
    }
BOOST_AUTO_TEST_SUITE_END()