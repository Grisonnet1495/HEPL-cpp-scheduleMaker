#ifndef PROFESSOR
#define PROFESSOR

#include <stdlib.h>
#include <iostream>
#include "Schedulable.h"
using namespace std;

class Professor : public Schedulable
{
  private:
    string lastName;
    string firstName;

  public:
    Professor();
    Professor(const string& l, const string& f);
    Professor(const Professor& p);
    ~Professor();

    void setLastName(const string& l);
    void setFirstName(const string& f);

    const string getLastName() const;
    const string getFirstName() const;

    virtual const string& toString();
    virtual const string& tuple();
};

#endif
