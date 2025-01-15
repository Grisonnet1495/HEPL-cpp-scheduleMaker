#ifndef XML_FILE_SERIALIZER_H
#define XML_FILE_SERIALIZER_H

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#include "XmlFileSerializerException.h"

template<typename T>
class XmlFileSerializer
{
  private:
    fstream file;
    string filename;
    char mode;
    string collectionName;

  public:
    static const char READ = 'R';
    static const char WRITE = 'W';
    
    XmlFileSerializer() = delete;
    XmlFileSerializer(const string& f, char m, const string& c = "entities");
    XmlFileSerializer(const XmlFileSerializer& s) = delete;
    ~XmlFileSerializer();

    string getFilename() const;
    string getCollectionName() const;
    bool isReadable() const;
    bool isWritable() const;

    void write(const T& t);
    T read();

    XmlFileSerializer<T>& operator=(const XmlFileSerializer<T>&) = delete;
};

#include "XmlFileSerializer.ipp"

#endif
