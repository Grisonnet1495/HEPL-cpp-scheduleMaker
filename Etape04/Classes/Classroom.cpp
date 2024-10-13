#include "Classroom.h"

using namespace std;

// Constructeurs

Classroom::Classroom()
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Classroom" << endl;
    #endif

    setName("---");
    setSeatingCapacity(0);
}

Classroom::Classroom(int i, const string& n, int s)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Classroom" << endl;
    #endif

    setId(i);
    setName(n);
    setSeatingCapacity(s);
}

Classroom::Classroom(const Classroom& c)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Classroom" << endl;
    #endif

    setId(c.id);
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

// Méthodes d'instances

string Classroom::toString() const
{
    return name + " (" + to_string(seatingCapacity) + ")";
}

string Classroom::tuple() const
{
    return to_string(id) + ";" + name + " (" + to_string(seatingCapacity) + ")";
}

// Méthodes de surcharge d'opérateurs

ostream& operator<<(ostream& s, const Classroom& c)
{
    s << c.toString();

    return s;
}
