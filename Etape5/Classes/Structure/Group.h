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

    const string& getName() const;

    Group& operator=(const Group& g);

    string toString() const override;
    string tuple() const override;
};

#endif
