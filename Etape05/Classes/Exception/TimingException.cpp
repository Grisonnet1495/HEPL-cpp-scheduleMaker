#include "TimingException.h"

namespace planning
{
    // Constructeurs

    TimingException::TimingException():Exception()
    {
        #ifdef DEBUG
          cout << ">>> Appelle du constructeur par defaut de TimingException" << endl;
        #endif

        setCode(0);
    }

    TimingException::TimingException(const string& m, int c):Exception(m)
    {
        #ifdef DEBUG
          cout << ">>> Appelle du constructeur d'initialisation de TimingException" << endl;
        #endif

        setCode(c);
    }

    TimingException::TimingException(const TimingException& t):Exception(t.getMessage())
    {
        #ifdef DEBUG
          cout << ">>> Appelle du constructeur de copie de TimingException" << endl;
        #endif

        setCode(t.getCode());
    }

    // Destructeur

    TimingException::~TimingException()
    {
        #ifdef DEBUG
          cout << ">>> Appelle du destructeur de TimingException" << endl;
        #endif
    }

    // Setters

    void TimingException::setCode(int c)
    {
        code = c;
    }

    // Getters

    int TimingException::getCode() const
    {
        return code;
    }
}
