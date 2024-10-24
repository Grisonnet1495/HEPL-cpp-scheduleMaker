#ifndef EVENT
#define EVENT

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Timing.h"
using namespace std;

namespace planning
{
  class Event
  {
    private:
      int code;
      char *title;
      Timing *timing;

    public:
      static int currentCode;

      Event();
      Event(int c, const char *t);
      Event(const Event& e);
      ~Event();

      void setCode(int c);
      void setTitle(const char *t);
      void setTiming(const Timing& t);

      int getCode() const;
      const char* getTitle() const;
      const Timing& getTiming() const;

      void display() const;
      void incCurrentCode() const;
  };
}

#endif
