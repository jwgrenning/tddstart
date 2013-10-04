#include "TddStart.h"
#include <string>

//CppUTest includes should be after your and system includes
#include "CppUTest/TestHarness.h"

using namespace std;

TEST_GROUP(TddStart)
{
  TddStart* tddStart;

  void setup()
  {
    tddStart = new TddStart("MyClass");
  }
  void teardown()
  {
    delete tddStart;
  }
};

TEST(TddStart, replace_include_guards_name)
{
	const string includeGuardTemplate =
			"#ifndef INCLUDE_GUARD\n#define INCLUDE_GUARD\n";

	const string includeGuardResult =
			"#ifndef MyClass_INCLUDED\n#define MyClass_INCLUDED\n";

	string result = tddStart->getHeader(includeGuardTemplate);
	CHECK_EQUAL(includeGuardResult, result);
}

TEST(TddStart, replace_classname)
{
	const string classNameTemplate =
			"class ClassName\n"
			"    virtual ~ClassName();\n";

	const string classNameResult =
			"class MyClass\n"
			"    virtual ~MyClass();\n";

	string result = tddStart->getHeader(classNameTemplate);
	CHECK_EQUAL(classNameResult, result);
}
