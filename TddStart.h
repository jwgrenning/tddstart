#ifndef D_TddStart_H
#define D_TddStart_H

///////////////////////////////////////////////////////////////////////////////
//
//  TddStart is responsible for ...
//
///////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iosfwd>

class TddStart
  {
  public:
    explicit TddStart(std::string classname);
    virtual ~TddStart();

    void createClassHeaderFile(std::istream&, std::ostream&);
    void createClassSourceFile(std::istream&, std::ostream&);
    void createClassTestFile(std::istream&, std::ostream&);

  private:

    std::string classname;
    std::string includeGuardName;

    std::string getFileContents(std::istream&);
    void replaceAll(std::string& subject, const std::string& find, const std::string& replacement) const;
    std::string makeIncludeGuardName(const std::string&) const;

    TddStart(const TddStart&);
    TddStart& operator=(const TddStart&);

  };

#endif  // D_TddStart_H
