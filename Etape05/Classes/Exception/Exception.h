#ifndef EXCEPTION
#define EXCEPTION

#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

class Exception
{
  private:
    string message;

  public:
    Exception();
    Exception(const string& m);
    Exception(const Exception& e);
    ~Exception();

    void setMessage(const string& m);

    const string& getMessage() const;
};

#endif
