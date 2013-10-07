#include "TddStart.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

TddStart::TddStart(std::string classname)
: classname(classname)
{
        includeGuardName = makeIncludeGuardName(classname);
}

TddStart::~TddStart()
{
}

#define NOT_FOUND -1

void TddStart::createClassHeaderFile(std::istream& in, std::ostream& out)
{
        string contents = getFileContents(in);
        replaceAll(contents, "INCLUDE_GUARD", includeGuardName);
        replaceAll(contents, "ClassName", classname);
        out << contents;
}

void TddStart::createClassSourceFile(std::istream& in, std::ostream& out)
{
        string contents = getFileContents(in);
        replaceAll(contents, "ClassName", classname);
        out << contents;
}

void TddStart::createClassTestFile(std::istream& in, std::ostream& out)
{
        string contents = getFileContents(in);
        replaceAll(contents, "aClassName", "subject_" + classname);
        replaceAll(contents, "ClassName", classname);
        out << contents;
}

std::string TddStart::makeIncludeGuardName(const std::string& s) const
{
        string result = s;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        result += "_INCLUDED";
        return result;
}

void TddStart::replaceAll(std::string& subject, const std::string& find, const std::string& replacement) const
{
        int start = subject.find(find);
        while (start != NOT_FOUND)
        {
                subject.replace(start, find.size(), replacement);
                start = subject.find(find);
        }
}

string TddStart::getFileContents(std::istream& in)
{
        string contents = "";
        while (!in.eof())
        {
                string line;
                getline(in, line);
                contents += line;
                if (!in.eof())
                        contents += '\n';
        }
        return contents;
}

