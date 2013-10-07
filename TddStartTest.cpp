#include "CppUTest/TestHarness.h"
#include "TddStart.h"
#include <string>
#include <sstream>

using namespace std;

TEST_GROUP(TddStart)
{
    TddStart * tddStart;
    stringstream templateFile;
    stringstream outputFile;

    void
    setup()
    {
        tddStart = new TddStart("MyClass");
    }
    void
    teardown()
    {
        delete tddStart;
    }
};

TEST(TddStart, can_replace_include_guards_from_template)
{
    templateFile << "#ifndef INCLUDE_GUARD\n#define INCLUDE_GUARD\n";

    const string expected =
            "#ifndef MYCLASS_INCLUDED\n#define MYCLASS_INCLUDED\n";

    tddStart->createClassHeaderFile(templateFile, outputFile);
    CHECK_EQUAL(expected, outputFile.str());
}

TEST(TddStart, can_create_class_header_from_template)
{
    templateFile << "class ClassName\n virtual ~ClassName();\n";

    const string expected = "class MyClass\n virtual ~MyClass();\n";

    tddStart->createClassHeaderFile(templateFile, outputFile);
    CHECK_EQUAL(expected, outputFile.str());
}

TEST(TddStart, can_create_class_source_file_from_template)
{
    templateFile << "ClassName::ClassName(){}\nClassName::~ClassName(){}\n";

    const string expected = "MyClass::MyClass(){}\nMyClass::~MyClass(){}\n";

    tddStart->createClassSourceFile(templateFile, outputFile);
    CHECK_EQUAL(expected, outputFile.str());
}

TEST(TddStart, can_create_initial_class_test_file_from_template)
{
    templateFile
            << "TEST_GROUP(ClassName)\n ClassName * aClassName = new ClassName\n TEST(ClassName, name)\n";

    const string expected =
            "TEST_GROUP(MyClass)\n MyClass * subject_MyClass = new MyClass\n TEST(MyClass, name)\n";

    tddStart->createClassTestFile(templateFile, outputFile);
    CHECK_EQUAL(expected, outputFile.str());
}
