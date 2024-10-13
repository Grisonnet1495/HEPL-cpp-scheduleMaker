#ifndef SCHEDULABLE
#define SCHEDULABLE

#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

class Schedulable
{
  friend ostream& operator<<(ostream& s, const Schedulable& schedulable);

  protected:
    int id;

  public:
    static int currentCode;

    Schedulable();
    Schedulable(int i);
    Schedulable(const Schedulable& s);
    ~Schedulable();

    void setId(int i);

    int getId() const;

    Schedulable& operator=(const Schedulable& s);

    virtual string toString() const;
    virtual string tuple() const;
};

#endif
