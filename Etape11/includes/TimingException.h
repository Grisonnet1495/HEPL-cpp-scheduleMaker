#ifndef TIMING_EXCEPTION_H
#define TIMING_EXCEPTION_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Exception.h"
using namespace std;

namespace planning
{
  class TimingException : public Exception
  {
    private:
      int code;

    public:
      static const int INVALID_DAY = 1;
      static const int NO_TIMING = 2;
      static const int INVALID_TIMING = 3;

      TimingException();
      TimingException(const string& m, int c);
      TimingException(const TimingException& t);
      ~TimingException();

      void setCode(int c);

      int getCode() const;
  };
}

#endif
