#include "Group.h"

// Constructeurs

Group::Group():Schedulable()
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Group" << endl;
    #endif

    setName("---");
}

Group::Group(int i, const string n):Schedulable(i)
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Group" << endl;
    #endif

    setName(n);
}

Group::Group(const Group& g):Schedulable(g)
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Group" << endl;
    #endif

    setName(g.name);
}

// Destructeur

Group::~Group()
{
    #ifdef DEBUG
      cout << ">>> Appelle du destructeur de Group" << endl;
    #endif
}

// Setters

void Group::setName(const string n)
{
    name = n;
}

// Getters

const string& Group::getName() const
{
  return name;
}

// Méthodes d'instances

string Group::toString() const
{
    return name;
}

string Group::tuple() const
{
    return to_string(id) + ";" + name;
}

// Méthodes de surcharge d'opérateurs

Group& Group::operator=(const Group& g)
{
    Schedulable::operator=(g);
    name = g.name;

    return (*this);
}

ostream& operator<<(ostream& s, const Group& g)
{
    s << g.toString();

    return s;
}
