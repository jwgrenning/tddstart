#include "TddStartMain.h"
#include <string>
#include <iostream>

using namespace std;

TddStartMain::TddStartMain(int argc, const char** argv, std::ostream& console)
: argc(argc), argv(argv), console(console)
{
}

TddStartMain::~TddStartMain()
{
}

int TddStartMain::run()
{
    if (argc == 1)
        console << "usage: " << argv[0] << " [--class|c|cmi|interface] name" << endl;
    return 1;
}

