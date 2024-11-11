#ifndef EVENT_H
#define EVENT_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Timing.h"
using namespace std;

template <typename Xml>
namespace planning
{
  class XmlFileSerializer
  {
    friend ostream& operator<<(ostream& s, const XmlFileSerializer& x);
    friend istream& operator>>(istream& s, XmlFileSerializer& x);

    private:
      fstream file;
      string filename;
      char mode;
      string collectionName;

    public:
      static int currentCode;

      XmlFileSerializer();
      XmlFileSerializer(int c, const string& t);
      XmlFileSerializer(const Event& e);
      ~XmlFileSerializer();

      void setFile(const fstream& file);
      void setFilename(const string& filename);
      void setMode(char m);
      void setCollectionName(const string& c);

      int getFile() const;
      const string& getFilename() const;
      char getMode() const;
      const string& getCollectionName() const;
  };
}

#endif
