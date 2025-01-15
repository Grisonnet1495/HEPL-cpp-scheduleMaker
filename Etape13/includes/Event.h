#ifndef EVENT
#define EVENT

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Timing.h"
using namespace std;

namespace planning
{
  class Event
  {
    // Opérateurs pour les flux    
    friend ostream& operator<<(ostream& s, const Event& e);
    friend istream& operator>>(istream& s, Event& e);

    protected:
      int code;
      string title;
      Timing *timing; // Pointeur timing associé à la classe Timing

    public:
      static int currentCode;
      
      // Constructeurs et destructeur
      Event();
      Event(int code, const string& title, Timing *t);
      Event(const Event& e);
      ~Event();

      void setCode(int c);
      void setTitle(const string& t);
      void setTiming(const Timing& t);

      int getCode() const;
      const string& getTitle() const;
      const Timing& getTiming() const;

      void display() const;
      const string toString() const;
  };
}

#endif
