#include "Event.h"
#include "../Exception/TimingException.h"

namespace planning
{
  // Constructeurs

  int Event::currentCode = 1;

  Event::Event()
  {
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Event" << endl;
    #endif

    setCode(1);
    title = nullptr;
    setTitle("---");
    timing = nullptr;
    setTiming(Timing());
    incCurrentCode();
  }

  Event::Event(int c, const char *t)
  {
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Event" << endl;
    #endif

    setCode(c);
    title = nullptr;
    setTitle(t);
    timing = nullptr;
    setTiming(Timing());
    incCurrentCode();
  }

  Event::Event(const Event& e)
  {
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Event" << endl;
    #endif

    setCode(e.code);
    title = nullptr;
    setTitle(e.title);
    timing = nullptr;
    setTiming(e.getTiming());
    incCurrentCode();
  }

  // Destructeur

  Event::~Event()
  {
    #ifdef DEBUG
      cout << ">>> Appelle du destructeur par defaut de Event" << endl;
    #endif
    
    if (title) delete title;
    if (timing) delete timing;
  }

  // Setters

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

  void Event::setTiming(const Timing& t)
  {
    if (timing) delete timing;
    timing = new Timing(t);
  }

  // Getters

  int Event::getCode() const
  {
    return code;
  }

  const char* Event::getTitle() const
  {
    return title;
  }

  const Timing& Event::getTiming() const
  {
    if (timing) return *timing;
    throw TimingException("Pas de timing.", TimingException::NO_TIMING);
  }

  // Méthodes d'instances

  void Event::display() const
  {
    cout << "Event(" << code << ") : " << title << "; Date : ";
    timing->display();
  }

  void Event::incCurrentCode() const
  {
    currentCode++;
  }
}
