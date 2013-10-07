#include "CppUTest/TestHarness.h"
#include "TddStartMain.h"
#include <string>
#include <sstream>


using namespace std;

TEST_GROUP(TddStartMain)
{
    TddStartMain * main;
    stringstream consoleOutput;

    void
    setup()
    {
        main = 0;
    }
    void
    teardown()
    {
        delete main;
    }
};

const char * argvNoParameters[] = { "tddstart" };

TEST(TddStartMain, reports_usage_message_for_no_parameters)
{
    main = new TddStartMain(1, argvNoParameters, consoleOutput);

    LONGS_EQUAL(1, main->run());
    CHECK_EQUAL("usage: tddstart [--class|c|cmi|interface] name\n", consoleOutput.str());
}

