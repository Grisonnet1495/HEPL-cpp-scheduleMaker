#ifndef TIME_EXCEPTION_H
#define TIME_EXCEPTION_H

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
      // Constantes pour les types d'erreurs      
      static const int INVALID_HOUR;
      static const int INVALID_MINUTE;
      static const int OVERFLOW;

      // Constructeurs et destructeur
      TimeException();
      TimeException(const string& m, int c);
      TimeException(const TimeException& t);
      ~TimeException();

      void setCode(int c);

      int getCode() const;
  };
}

#endif
