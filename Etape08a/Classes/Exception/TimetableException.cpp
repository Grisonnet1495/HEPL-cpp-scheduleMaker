#include "TimetableException.h"

////////////////////////////////////////////
/////// Constructeur ///////////////////////
////////////////////////////////////////////

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

////////////////////////////////////////////
/////// Destructeurs ///////////////////////
////////////////////////////////////////////

TimetableException::~TimetableException()
{
    #ifdef DEBUG
      cout << ">>> Appelle du destructeur de TimetableException" << endl;
    #endif
}

////////////////////////////////////////////
/////// Setter /////////////////////////////
////////////////////////////////////////////

void TimetableException::setCode(int c)
{
    code = c;
}

////////////////////////////////////////////
/////// Getter /////////////////////////////
////////////////////////////////////////////

int TimetableException::getCode() const
{
    return code;
}
