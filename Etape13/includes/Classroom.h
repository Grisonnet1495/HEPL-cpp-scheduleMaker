#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Schedulable.h"
using namespace planning;

class Classroom : public Schedulable
{
  // Opérateurs pour les flux
  friend ostream& operator<<(ostream& s, const Classroom& c);
  friend istream& operator>>(istream& s, Classroom& c);

  private:
    string name;
    int seatingCapacity;

  public:
    // Constructeurs et destructeur    
    Classroom();
    Classroom(int id, const string& n, int s);
    Classroom(const Classroom& c);
    ~Classroom();

    void setName(const string& n);
    void setSeatingCapacity(int n);

    const string& getName() const;
    int getSeatingCapacity() const;

    Classroom& operator=(const Classroom& c);
    bool operator<(const Classroom& c) const;

    string toString() const override;
    string tuple() const override;
};

#endif
