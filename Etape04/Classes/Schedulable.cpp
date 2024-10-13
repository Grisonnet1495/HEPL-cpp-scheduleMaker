#include "Schedulable.h"

// Constructeurs

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

// Destructeur

Schedulable::~Schedulable()
{
	#ifdef DEBUG
      cout << ">>> Appelle du destructeur par defaut de Schedulable" << endl;
    #endif
}

// Getters

int Schedulable::getId()
{
	return id;
}

// Setters

void Schedulable::setId(int i)
{
	id = i;
}

// Méthodes de surcharge d'opérateurs

Schedulable& Schedulable::operator=(const Schedulable& s)
{
	id = p.id;

	return (*this);
}

ostream& operator<<(ostream& s, const Schedulable& s)
{
	s << toString();

	return s;
}
