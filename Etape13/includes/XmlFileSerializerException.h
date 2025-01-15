#ifndef XML_FILE_SERIALIZER_EXCEPTION_H
#define XML_FILE_SERIALIZER_EXCEPTION_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Exception.h"
using namespace std;

class XmlFileSerializerException : public Exception
{
  private:
    int code;

  public:
    // Constantes représentant les types d'erreurs possibles
    static const int NOT_ALLOWED;  
    static const int FILE_NOT_FOUND; 
    static const int FILE_ERROR;  
    static const int END_OF_FILE;

    // Constructeurs et destructeur
    XmlFileSerializerException();                      
    XmlFileSerializerException(const string& m, int c);
    XmlFileSerializerException(const XmlFileSerializerException& x); 
    ~XmlFileSerializerException();

    void setCode(int c);    

    int getCode() const;      
};

#endif
