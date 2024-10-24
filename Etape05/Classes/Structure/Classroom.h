#ifndef CLASSROOM
#define CLASSROOM

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Schedulable.h"
using namespace std;

class Classroom : public Schedulable
{
  friend ostream& operator<<(ostream& s, const Classroom& c);

  private:
    string name;
    int seatingCapacity;

  public:
    Classroom();
    Classroom(int i, const string& n, int s);
    Classroom(const Classroom& c);
    ~Classroom();

    void setName(const string& n);
    void setSeatingCapacity(int n);

    const string& getName() const;
    int getSeatingCapacity() const;

    Classroom& operator=(const Classroom& c);

    string toString() const override;
    string tuple() const override;
};

#endif
