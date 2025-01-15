#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Schedulable.h"
using namespace planning;

class Professor : public Schedulable
{
  // Opérateurs pour les flux  
  friend ostream& operator<<(ostream& s, const Professor& p);
  friend istream& operator>>(istream& s, Professor& p);

  private:
    string lastName;
    string firstName;

  public:
    // Constructeurs et destructeur
    Professor();
    Professor(int id, const string& l, const string& f);
    Professor(const Professor& p);
    ~Professor();

    void setLastName(const string& l);
    void setFirstName(const string& f);

    const string& getLastName() const;
    const string& getFirstName() const;

    Professor& operator=(const Professor& p);
    bool operator<(const Professor& p) const;

    string toString() const override;
    string tuple() const override;
};

#endif
