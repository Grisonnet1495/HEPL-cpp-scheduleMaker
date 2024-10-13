#ifndef PROFESSOR
#define PROFESSOR

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Schedulable.h"
using namespace std;

class Professor : public Schedulable
{
  friend ostream& operator<<(ostream& s, const Professor& p);

  private:
    string lastName;
    string firstName;

  public:
    Professor();
    Professor(int i, const string& l, const string& f);
    Professor(const Professor& p);
    ~Professor();

    void setLastName(const string& l);
    void setFirstName(const string& f);

    const string getLastName() const;
    const string getFirstName() const;

    string toString() const override;
    string tuple() const override;
};

#endif
