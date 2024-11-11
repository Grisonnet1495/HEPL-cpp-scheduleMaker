#ifndef XML_FILE_SERIALIZER_EXCEPTION_H
#define XML_FILE_SERIALIZER_EXCEPTION_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Exception.h"
using namespace std;

namespace planning
{
  class XmlFileSerializerException : public Exception
  {
    private:
      int code;

    public:
      static const int NOT_ALLOWED = 1;
      static const int FILE_NOT_FOUND = 2;
      static const int END_OF_FILE = 3;

      XmlFileSerializerException();
      XmlFileSerializerException(const string& m, int c);
      XmlFileSerializerException(const XmlFileSerializerException& x);
      ~XmlFileSerializerException();

      void setCode(int c);

      int getCode() const;
  };
}

#endif
