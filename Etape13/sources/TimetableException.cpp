#include "TimetableException.h"

// Variables constantes statiques

const int TimetableException::INVALID_INDEX = 1;
const int TimetableException::INVALID_ID = 2;
const int TimetableException::INVALID_CODE = 3;
const int TimetableException::FILE_ERROR = 4;

// Constructeurs

TimetableException::TimetableException():Exception()
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de TimetableException" << endl;
    #endif

    setCode(0);
}

TimetableException::TimetableException(const string& m, int c):Exception(m)
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de TimetableException" << endl;
    #endif

    setCode(c);
}

TimetableException::TimetableException(const TimetableException& t):Exception(t.getMessage())
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de TimetableException" << endl;
    #endif

    setCode(t.getCode());
}

// Destructeur

TimetableException::~TimetableException()
{
    #ifdef DEBUG
      cout << ">>> Appelle du destructeur de TimetableException" << endl;
    #endif
}

// Setters

void TimetableException::setCode(int c)
{
    code = c;
}

// Getters

int TimetableException::getCode() const
{
    return code;
}
