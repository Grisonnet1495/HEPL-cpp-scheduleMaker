#ifndef SCHEDULABLE
#define SCHEDULABLE

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Timing.h"
using namespace std;

namespace planning
{
  class Schedulable
  {
    private:
      int id;

    public:
      static int currentCode;

      Schedulable();
      Schedulable(int i);
      Schedulabe(const Schedulable& s);
      ~Schedulable();

      void setId(int i);

      int getId() const;

      virtual const string& toString();
      virtual const string& tuple();
  };
}

#endif
