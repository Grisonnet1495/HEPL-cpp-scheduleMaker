#ifndef TIMEEXCEPTION
#define TIMEEXCEPTION

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Exception.h"
using namespace std;

namespace planning
{
  class TimeException : public Exception
  {
    private:
      int code;

    public:
      static const int INVALID_HOUR = 1;
      static const int INVALID_MINUTE = 2;
      static const int OVERFLOW = 3;

      TimeException();
      TimeException(const string& m, int c);
      TimeException(const TimeException& t);
      ~TimeException();

      void setCode(int c);

      int getCode() const;
  };
}


#endif
