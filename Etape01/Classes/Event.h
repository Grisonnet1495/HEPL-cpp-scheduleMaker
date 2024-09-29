#ifndef EVENT
#define EVENT

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "../../Etape02/Classes/Timing.h"
using namespace std;

class Event
{
  private:
    int code;
    char *title;
    Timing *timing;

  public:
    Event();
    Event(int c, const char *t);
    Event(const Event &E);
    ~Event();

    void setCode(int c);
    void setTitle(const char *t);
    void setTiming(const Timing& T);

    int getCode() const;
    const char* getTitle() const;
    const Timing& getTiming() const;

    void display() const;
};

#endif
