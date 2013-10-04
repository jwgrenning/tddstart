#include "TddStart.h"
#include <string>

using namespace std;

TddStart::TddStart(std::string classname)
: classname(classname)
{
}

TddStart::~TddStart()
{
}

#define NOT_FOUND -1

std::string TddStart::getHeader(const std::string& headerTemplate) const
{
	string result = headerTemplate;
	string guardName = classname + "_INCLUDED";
	replaceAll(result, "INCLUDE_GUARD", guardName);
	replaceAll(result, "ClassName", classname);

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
