#ifndef D_TddStart_H
#define D_TddStart_H

///////////////////////////////////////////////////////////////////////////////
//
//  TddStart is responsible for ...
//
///////////////////////////////////////////////////////////////////////////////
#include <string>

class TddStart
  {
  public:
    explicit TddStart(std::string classname);
    virtual ~TddStart();

    std::string getHeader(const std::string& headerTemplate) const;

  private:

    std::string classname;

    void replaceAll(std::string& subject, const std::string& find, const std::string& replacement) const;

    TddStart(const TddStart&);
    TddStart& operator=(const TddStart&);

  };

#endif  // D_TddStart_H
