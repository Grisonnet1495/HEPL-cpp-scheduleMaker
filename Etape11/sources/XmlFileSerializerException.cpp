#include "XmlFileSerializerException.h"

// Constructeurs

XmlFileSerializerException::XmlFileSerializerException():Exception()
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de TimeException" << endl;
    #endif

    setCode(0);
}

XmlFileSerializerException::XmlFileSerializerException(const string& m, int c):Exception(m)
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de TimeException" << endl;
    #endif

    setCode(c);
}

XmlFileSerializerException::XmlFileSerializerException(const XmlFileSerializerException& x):Exception(x.getMessage())
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de TimeException" << endl;
    #endif

    setCode(x.getCode());
}

// Destructeur

XmlFileSerializerException::~XmlFileSerializerException()
{
    #ifdef DEBUG
      cout << ">>> Appelle du destructeur de TimeException" << endl;
    #endif
}

// Setters

void XmlFileSerializerException::setCode(int c)
{
    code = c;
}

// Getters

int XmlFileSerializerException::getCode() const
{
    return code;
}
