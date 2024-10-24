#ifndef SCHEDULABLE
#define SCHEDULABLE

#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

namespace planning
{
  class Schedulable
  {
    protected:
      int id;

    public:
      Schedulable();
      Schedulable(int i);
      Schedulable(const Schedulable& s);
      virtual ~Schedulable();

      void setId(int i);

      int getId() const;

      Schedulable& operator=(const Schedulable& s);

      virtual string toString() const = 0;
      virtual string tuple() const = 0;
  };
}

#endif
