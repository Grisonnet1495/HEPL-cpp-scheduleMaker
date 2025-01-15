#ifndef XML_FILE_SERIALIZER_H
#define XML_FILE_SERIALIZER_H

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#include "XmlFileSerializerException.h"

// Classe générique pour la sérialisation des objets en XML
template<typename T>
class XmlFileSerializer
{
  private:
    fstream file;
    string filename;
    char mode;
    string collectionName;

  public:
    // Constantes pour les modes de lecture et d'écriture
    static const char READ;
    static const char WRITE;
    
    XmlFileSerializer() = delete;
    XmlFileSerializer(const string& f, char m, const string& c = "entities");
    XmlFileSerializer(const XmlFileSerializer& s) = delete;
    ~XmlFileSerializer();

    // Getters
    string getFilename() const;
    string getCollectionName() const;

    bool isReadable() const;   
    bool isWritable() const; 

    // Méthodes de lecture/écriture des objets
    void write(const T& t);          
    T read();                     

    XmlFileSerializer<T>& operator=(const XmlFileSerializer<T>&) = delete;
};

#include "XmlFileSerializer.ipp"

#endif
