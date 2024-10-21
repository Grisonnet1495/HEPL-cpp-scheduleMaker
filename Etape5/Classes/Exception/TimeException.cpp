#include "TimeException.h"

namespace planning
{
    // Constructeurs

    TimeException::TimeException():Exception()
    {
        #ifdef DEBUG
          cout << ">>> Appelle du constructeur par defaut de TimeException" << endl;
        #endif

        setCode(0);
    }

    TimeException::TimeException(const string& m, int c):Exception(m)
    {
        #ifdef DEBUG
          cout << ">>> Appelle du constructeur d'initialisation de TimeException" << endl;
        #endif

        setCode(c);
    }

    TimeException::TimeException(const TimeException& t):Exception(t.getMessage())
    {
        #ifdef DEBUG
          cout << ">>> Appelle du constructeur de copie de TimeException" << endl;
        #endif

        setCode(t.getCode());
    }

    // Destructeur

    TimeException::~TimeException()
    {
        #ifdef DEBUG
          cout << ">>> Appelle du destructeur de TimeException" << endl;
        #endif
    }

    // Setters

    void TimeException::setCode(int c)
    {
        code = c;
    }

    // Getters

    int TimeException::getCode() const
    {
        return code;
    }
}
