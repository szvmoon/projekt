//
// Created by student on 24.03.2021.
//

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(true, boost::test_tools::tolerance(0.5));
        BOOST_TEST(true);
    }

BOOST_AUTO_TEST_SUITE_END()