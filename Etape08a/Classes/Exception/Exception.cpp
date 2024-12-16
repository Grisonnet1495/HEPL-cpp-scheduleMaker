#include "Exception.h"

////////////////////////////////////////////
/////// Constructeurs///////////////////////
////////////////////////////////////////////

Exception::Exception()
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Exception" << endl;
    #endif

    setMessage("---");
}

Exception::Exception(const string& m)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Exception" << endl;
    #endif

    setMessage(m);
}

Exception::Exception(const Exception& e)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Exception" << endl;
    #endif

    setMessage(e.getMessage());
}

////////////////////////////////////////////
/////// Destructeurs ///////////////////////
////////////////////////////////////////////

Exception::~Exception()
{
	#ifdef DEBUG
      cout << ">>> Appelle du destructeur par defaut de Exception" << endl;
    #endif
}

////////////////////////////////////////////
/////// Setter /////////////////////////////
////////////////////////////////////////////

void Exception::setMessage(const string& m)
{
	message = m;
}

////////////////////////////////////////////
/////// Getter /////////////////////////////
////////////////////////////////////////////

const string& Exception::getMessage() const
{
	return message;
}
