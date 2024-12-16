#ifndef GROUP_H
#define GROUP_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Schedulable.h"
using namespace planning;

class Group : public Schedulable
{
  friend ostream& operator<<(ostream& s, const Group& g);
  friend istream& operator>>(istream& s, Group& c);

  private:
    string name;

  public:
    Group();
    Group(int id, const string n);
    Group(const Group& g);
    ~Group();

    void setName(const string n);

    const string& getName() const;

    Group& operator=(const Group& g);
    bool operator<(const Group& g) const;

    string toString() const override;
    string tuple() const override;
};

#endif
