#ifndef SCHEDULABLE
#define SCHEDULABLE

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Timing.h"
using namespace std;

class Schedulable
{
  friend ostream& operator<<(ostream& s, const Schedulable& s);

  protected:
    int id;

  public:
    static int currentCode;

    Schedulable();
    Schedulable(int i);
    Schedulabe(const Schedulable& s);
    ~Schedulable();

    void setId(int i);

    int getId() const;

    Schedulable& operator=(const Schedulable& s);

    virtual string toString();
    virtual string tuple();
};

#endif
