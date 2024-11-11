static const char XmlFileSerializer::READ = 'R';
static const char XmlFileSerializer::WRITE = 'W';

template <typename T>  
XmlFileSerializer<T>::XmlFileSerializer(const string& f, char m, const string& c = "entities")
{
  #ifdef DEBUG
    cout << ">>> Appelle du constructeur d'initialisation de XmlFileSerializer" << endl;
  #endif

  filename = f;
  mode = m;
  collectionName = c;

  if (mode == WRITE)
  {
    file.open(filename, ios::in);

    if (!file)
    {
      cout << "Erreur d'ouverture du fichier." << endl;
    }
    else
    {
      file << '<?xml version="1.0" encoding="UTF-8"?>' << endl;
      file << "<" << colectionName << ">" << endl;
    }
  }
  else if (mode == READ)
  {
    file.open(filename, ios::out);

    if (!file)
    {
      cout << "Erreur d'ouverture du fichier." << endl;
    }
    else
    {
      string tmpString;
      getLine(file, tmpString);
      getLine(file, tmpString);
      collectionName = tmpString.substr(1, str.length() - 2);
    }
  }
}
 
template <typename T>  
XmlFileSerializer<T>::~XmlFileSerializer()
{
  #ifdef DEBUG
    cout << ">>> Appelle du destructeur par defaut de XmlFileSerializer" << endl;
  #endif

  if (mode == WRITE)
  {
    file << '</' << collectionName << '>' << endl;
  }

  file.close();
}
 
template <typename T>  
string XmlFileSerializer<T>::getFilename() const
{
  return filename; 
}

template <typename T>  
string XmlFileSerializer<T>::getCollectionName() const
{
  return collectionName; 
}

template <typename T>  
bool XmlFileSerializer<T>::isReadable() const
{
  return (mode == READ);
}

template <typename T>  
bool XmlFileSerializer<T>::isWritable() const
{
  return (mode == WRITE); 
}

template <typename T>  
void XmlFileSerializer<T>::write(const T& val)
{
  file << T; 
}

template <typename T>  
T XmlFileSerializer<T>::read()
{
  string line;
  file >> line;

  if (line == ('</' + collectionName + '>')) throw
}