//
// Created by student on 27.03.2021.
//

#include <boost/test/unit_test.hpp>
#include <model/Client.h>

#define name "Szymon"
#define surname "Ziemecki"
#define PID "236709"

Client *Klient = new Client(name, surname, PID);

BOOST_AUTO_TEST_SUITE(Constructor)


    BOOST_AUTO_TEST_CASE(NameTest) {
        BOOST_TEST(Klient->get_firstName() == name);
    }

    BOOST_AUTO_TEST_CASE(SurnameTest) {
        BOOST_TEST(Klient->get_lastName() == surname);
    }

    BOOST_AUTO_TEST_CASE(PIDTest) {
        BOOST_TEST(Klient->get_personalID() == PID);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Setters)

    BOOST_AUTO_TEST_CASE(firstnameSetter) {
        std::string testName = "Essunia";
        std::string emptyName = "";

        Klient->set_firstName(emptyName);
        BOOST_TEST(Klient->get_firstName() == name);
        Klient->set_firstName(testName);
        BOOST_TEST(Klient->get_firstName() == testName);
    }

    BOOST_AUTO_TEST_CASE(lastnameSetter) {
        std::string testSurname = "Essunia";
        std::string emptySurname = "";

        Klient->set_lastName(emptySurname);
        BOOST_TEST(Klient->get_lastName() == surname);
        Klient->set_lastName(testSurname);
        BOOST_TEST(Klient->get_lastName() == testSurname);
    }


BOOST_AUTO_TEST_SUITE_END()


