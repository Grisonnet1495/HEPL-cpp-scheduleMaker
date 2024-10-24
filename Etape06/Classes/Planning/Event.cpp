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
    setTitle("---");
    timing = nullptr;
    incCurrentCode();
  }

  Event::Event(int c, const string& t)
  {
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Event" << endl;
    #endif

    setCode(c);
    setTitle(t);
    timing = nullptr;
    incCurrentCode();
  }

  Event::Event(const Event& e)
  {
    #ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Event" << endl;
    #endif

    setCode(e.code);
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
    
    if (timing) delete timing;
  }

  // Setters

  void Event::setCode(int c)
  {
  if (c < 1) return;
    code = c;
  }

  void Event::setTitle(const string& t)
  {
    title = t;
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

  const string& Event::getTitle() const
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

  // Méthodes de surcharge d'opérateurs

  ostream& operator<<(ostream& s, const Event& e)
  {
    s << "<Event>" << endl;
    s << "<code>" << endl;
    s << e.code << endl;
    s << "</code>" << endl;
    s << "<title>" << endl;
    s << e.title << endl;
    s << "</title>" << endl;

    try
    {
      s << "<timing>" << endl;
      s << e.timing << endl;
      s << "</timing>" << endl;
    }
    catch (TimingException& t)
    {
      cout << "Erreur : " << t.getMessage();
      cout << "Code d'erreur : " << t.getCode();
    }

    s << "</Event>" << endl;

    return s;
  }

  istream& operator>>(istream& s, Event& e)
  {
    string sCode, sTitle, tag;
    Timing timing;
    getline(s, tag);
    getline(s, tag);
    getline(s, sCode);
    getline(s, tag);
    getline(s, tag);
    getline(s, sTitle);
    getline(s, tag);
    getline(s, tag);

    if (tag == "<timing>")
    {
      s >> timing;
      getline(s, tag);
      getline(s, tag);
    }

    e.setCode(stoi(sCode));
    e.setTitle(sTitle);
    e.setTiming(timing);

    return s;
  }
}
