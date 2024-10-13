#include "Classroom.h"

// Constructeurs

Classroom::Classroom()
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Classroom" << endl;
    #endif

    setName("---");
    setSeatingCapacity(0);
}

Classroom::Classroom(const string& n, int s)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Classroom" << endl;
    #endif

    setName(n);
    setSeatingCapacity(s);
}

Classroom::Classroom(const Classroom& c)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Classroom" << endl;
    #endif

    setName(c.name);
    setSeatingCapacity(c.seatingCapacity);
}

// Destructeurs

Classroom::~Classroom()
{
	#ifdef DEBUG
      cout << ">>> Appelle du destructeur de Classroom" << endl;
    #endif
}

// Setters

void Classroom::setName(const string& n)
{
	name = n;
}

void Classroom::setSeatingCapacity(int s)
{
	seatingCapacity = s;
}

// Getters

const string Classroom::getName() const
{
	return name;
}

int Classroom::getSeatingCapacity() const
{
	return seatingCapacity;
}
