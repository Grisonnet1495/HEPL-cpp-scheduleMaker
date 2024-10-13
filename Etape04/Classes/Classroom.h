#ifndef CLASSROOM
#define CLASSROOM

#include <stdlib.h>
#include <iostream>
#include "Schedulable.h"
using namespace std;

class Classroom : public Schedulable
{
  private:
    string name;
    int seatingCapacity;

  public:
    Classroom();
    Classroom(const string& n, int s);
    Classroom(const Classroom& c);
    ~Classroom();

    void setName(const string& n);
    void setSeatingCapacity(int n);

    const string getName() const;
    int getSeatingCapacity() const;

    virtual const string& toString();
    virtual const string& tuple();
};

#endif
