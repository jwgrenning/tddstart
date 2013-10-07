#ifndef TDDSTARTMAIN_INCLUDED
#define TDDSTARTMAIN_INCLUDED

#include <iosfwd>

class TddStart;

class TddStartMain
{
public:
    TddStartMain(int argc, const char** argv, std::ostream&);
    virtual ~TddStartMain();
    int run();

private:

    TddStart * tddStart;
    int argc;
    const char ** argv;
    std::ostream& console;

    TddStartMain(const TddStartMain&);
    TddStartMain& operator=(const TddStartMain&);

};

#endif
