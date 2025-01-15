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
    // Constantes représentant différents types d'erreurs
    static const int INVALID_INDEX;
    static const int INVALID_ID;
    static const int INVALID_CODE;
    static const int FILE_ERROR;

    // Constructeurs et destructeur
    TimetableException();                 
    TimetableException(const string& m, int c);  
    TimetableException(const TimetableException& t);
    ~TimetableException();

    void setCode(int c);   
    int getCode() const; 
};

#endif
