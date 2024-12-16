#ifndef TIMETABLE_EXCEPTION_H
#define TIMETABLE_EXCEPTION_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Exception.h"
using namespace std;

class TimetableException : public Exception
{
  private:
    int code;

  public:
    static const int INVALID_INDEX = 1;
    static const int INVALID_ID = 2;
    static const int FILE_ERROR = 3;

    TimetableException();
    TimetableException(const string& m, int c);
    TimetableException(const TimetableException& t);
    ~TimetableException();

    void setCode(int c);

    int getCode() const;
};

#endif
