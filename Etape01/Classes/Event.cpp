#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Event.h"
using namespace std;

Event::Event()
{
  cout << ">>> Appelle du constructeur par defaut de Event" << endl;

  code = 1;
  title = nullptr;
  setTitle("---");
}

Event::Event(int c, const char *t)
{
  cout << ">>> Appelle du constructeur de Event avec 2 arguments" << endl;

  setCode(c);
  title = nullptr;
  setTitle(t);
}

Event::Event(const Event& E)
{
  cout << ">>> Appelle du constructeur de Event avec un argument Event" << endl;

  setCode(E.code);
  title = nullptr;
  setTitle(E.title);
}

Event::~Event()
{
  cout << ">>> Appelle du destructeur par defaut de Event" << endl;
  if (title) delete title;
}

void Event::setCode(int c)
{
if (c < 1) return;
  code = c;
}

void Event::setTitle(const char *t)
{
  if (t == nullptr) return;
  if (title) delete title;
  title = new char[strlen(t) + 1];
  strcpy(title, t);
}

int Event::getCode() const
{
  return code;
}

const char* Event::getTitle() const
{
  return title;
}

void Event::display() const
{
  cout << "Event(" << code << ") : " << title << endl;
}
