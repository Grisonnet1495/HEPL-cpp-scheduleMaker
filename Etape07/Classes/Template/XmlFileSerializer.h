#ifndef XML_FILE_SERIALIZER
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
    friend ostream& operator<<(ostream& s, const Event& e);
    friend istream& operator>>(istream& s, Event& e);

    private:
      int code;
      string title;
      Timing *timing;

    public:
      static int currentCode;

      Event();
      Event(int c, const string& t);
      Event(const Event& e);
      ~Event();

      void setCode(int c);
      void setTitle(const string& t);
      void setTiming(const Timing& t);

      int getCode() const;
      const string& getTitle() const;
      const Timing& getTiming() const;

      void display() const;
      void incCurrentCode() const;
  };
}

#endif
