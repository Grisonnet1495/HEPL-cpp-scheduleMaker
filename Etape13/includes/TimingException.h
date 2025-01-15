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
      // Différents types d'erreurs liées aux horaires
      static const int INVALID_DAY;
      static const int NO_TIMING;
      static const int INVALID_TIMING;

      // Constructeurs et destructeur
      TimingException();                        
      TimingException(const string& m, int c);   
      TimingException(const TimingException& t); 
      ~TimingException();                     

      void setCode(int c);

      int getCode() const;
  };
}

#endif
