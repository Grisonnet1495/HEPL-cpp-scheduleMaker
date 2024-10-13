#ifndef GROUP
#define GROUP

#include <stdlib.h>
#include <iostream>
#include "Schedulable.h"
using namespace std;

class Group : public Schedulable
{
  private:
    int name;

  public:
    Group();
    Group(const int n);
    Group(const Group& g);
    ~Group();

    void setName(int n);

    int getName() const;

    virtual const string& toString();
    virtual const string& tuple();
};

#endif
