#include "Group.h"

// Constructeurs

Group::Group()
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Group" << endl;
    #endif

    setName(0);
}

Group::Group(int n)
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Group" << endl;
    #endif

    setName(n);
}

Group::Group(const Group& g)
{
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Group" << endl;
    #endif

    setName(g.name);
}

// Destructeurs

Group::~Group()
{
    #ifdef DEBUG
      cout << ">>> Appelle du destructeur de Group" << endl;
    #endif
}

// Setters

void Group::setName(const int n)
{
    name = n;
}

// Getters

int Group::getName() const
{
  return name;
}
