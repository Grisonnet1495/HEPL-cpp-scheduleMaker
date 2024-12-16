#include "Schedulable.h"

namespace planning
{
	int Schedulable::currentCode = 1;

	///////////////////////////////////////////
  	/////// Constructeur //////////////////////
  	///////////////////////////////////////////

	Schedulable::Schedulable()
	{
		#ifdef DEBUG
	      cout << ">>> Appelle du constructeur par defaut de Schedulable" << endl;
	    #endif

	    setId(0);
	}

	Schedulable::Schedulable(int i)
	{
		#ifdef DEBUG
	      cout << ">>> Appelle du constructeur d'initialisation de Schedulable" << endl;
	    #endif

	    setId(i);
	}

	Schedulable::Schedulable(const Schedulable& s)
	{
		#ifdef DEBUG
	      cout << ">>> Appelle du constructeur de copie de Schedulable" << endl;
	    #endif

	    setId(s.getId());
	}

	///////////////////////////////////////////
  	/////// Destructeur ///////////////////////
  	///////////////////////////////////////////

	Schedulable::~Schedulable()
	{
		#ifdef DEBUG
	      cout << ">>> Appelle du destructeur par defaut de Schedulable" << endl;
	    #endif
	}

	///////////////////////////////////////////
  	/////// Getter ////////////////////////////
  	///////////////////////////////////////////

	int Schedulable::getId() const
	{
		return id;
	}

	///////////////////////////////////////////
  	/////// Setter ////////////////////////////
  	///////////////////////////////////////////

	void Schedulable::setId(int i)
	{
		id = i;
	}

	///////////////////////////////////////////
  	/////// Surcharge des opérateurs //////////
  	///////////////////////////////////////////

	Schedulable& Schedulable::operator=(const Schedulable& s)
	{
		id = s.id;

		return (*this);
	}
}
