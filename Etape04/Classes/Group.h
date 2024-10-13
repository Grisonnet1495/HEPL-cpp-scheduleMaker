#ifndef GROUP
#define GROUP

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Schedulable.h"
using namespace std;

class Group : public Schedulable
{
  friend ostream& operator<<(ostream& s, const Group& g);

  private:
    string name;

  public:
    Group();
    Group(int i, const string n);
    Group(const Group& g);
    ~Group();

    void setName(const string n);

    int getName() const;

    string toString() override;
    string tuple() override;
};

#endif
