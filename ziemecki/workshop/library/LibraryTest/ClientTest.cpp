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
        bool NameGood = Klient->get_firstName() == name;
        BOOST_TEST(NameGood);
    }

    BOOST_AUTO_TEST_CASE(SurnameTest) {
        bool SurnameGood = Klient->get_lastName() == surname;
        BOOST_TEST(SurnameGood);
    }

    BOOST_AUTO_TEST_CASE(PIDTest) {
        bool PIDGood = Klient->get_personalID() == PID;
        BOOST_TEST(PIDGood);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Setters)

    BOOST_AUTO_TEST_CASE(firstnameSetter) {
        std::string testName = "Essunia";
        std::string emptyName = "";

        Klient->set_firstName(emptyName);

        bool NameChangeGood = Klient->get_firstName() == name;

        BOOST_TEST(NameChangeGood);

        Klient->set_firstName(testName);

        NameChangeGood = Klient->get_firstName() == testName;

        BOOST_TEST(NameChangeGood);
    }

    BOOST_AUTO_TEST_CASE(lastnameSetter) {
        std::string testSurname = "Essunia";
        std::string emptySurname = "";

        Klient->set_lastName(emptySurname);

        bool lastNameChangeGood = Klient->get_lastName() == surname;

        BOOST_TEST(lastNameChangeGood);

        Klient->set_lastName(testSurname);

        lastNameChangeGood = Klient->get_lastName() == testSurname;

        BOOST_TEST(lastNameChangeGood);
    }


BOOST_AUTO_TEST_SUITE_END()

