///////////////////////////////////////////
/////////// Constructeur //////////////////
///////////////////////////////////////////
template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string& f, char m, const string& c)
{
  #ifdef DEBUG
    cout << ">>> Appelle du constructeur d'initialisation de XmlFileSerializer" << endl;
  #endif

  filename = f;
  mode = m;
  collectionName = c;

  if (mode == WRITE)
  {
    file.open(filename, ios::out);

    if (!file)
    {
      cout << "Erreur d'ouverture du fichier." << endl;
    }
    else
    {
      file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
      file << "<" << collectionName << ">" << endl;
    }
  }
  else if (mode == READ)
  {
    file.open(filename, ios::in);

    if (!file) throw XmlFileSerializerException("Le fichier n'existe pas.", XmlFileSerializerException::FILE_NOT_FOUND);

    string line;
    getline(file, line);
    getline(file, line);
    collectionName = line.substr(1, line.length() - 2);
  }
}

///////////////////////////////////////////
////////////// Destructeur ////////////////
///////////////////////////////////////////
template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{
  #ifdef DEBUG
    cout << ">>> Appelle du destructeur par defaut de XmlFileSerializer" << endl;
  #endif

  if (mode == WRITE) file << "</" << collectionName << ">" << endl;

  file.close();
}

///////////////////////////////////////////
////// Retourne le nom du fichier /////////
///////////////////////////////////////////
template <typename T>
string XmlFileSerializer<T>::getFilename() const
{
  return filename;
}

///////////////////////////////////////////
//// Retourne le nom de la collection /////
///////////////////////////////////////////
template <typename T>
string XmlFileSerializer<T>::getCollectionName() const
{
  return collectionName;
}

///////////////////////////////////////////
//// Vérifie si le fichier est lisible ////
///////////////////////////////////////////
template <typename T>
bool XmlFileSerializer<T>::isReadable() const
{
  return (mode == READ);
}

///////////////////////////////////////////
//// Vérifie si le fichier est écrivable //
///////////////////////////////////////////
template <typename T>
bool XmlFileSerializer<T>::isWritable() const
{
  return (mode == WRITE);
}

///////////////////////////////////////////
/////// Écrit un objet dans le fichier ////
///////////////////////////////////////////
template <typename T>
void XmlFileSerializer<T>::write(const T& t)
{
  if (mode == READ) throw XmlFileSerializerException("Le fichier n'est pas en mode ecriture.", XmlFileSerializerException::NOT_ALLOWED);

  file << t << endl;
}

///////////////////////////////////////////
////// Lit un objet depuis le fichier /////
///////////////////////////////////////////
template <typename T>  
T XmlFileSerializer<T>::read()
{
  if (mode == WRITE) throw XmlFileSerializerException("Le fichier n'est pas en mode lecture.", XmlFileSerializerException::NOT_ALLOWED);

  T object;
  string tmpString;
  int oldPosition;

  oldPosition = file.tellg();
  file >> tmpString;

  if (tmpString == ("</" + collectionName + ">")) 
    throw XmlFileSerializerException("Fin du fichier.", XmlFileSerializerException::END_OF_FILE);

  file.seekg(oldPosition);
  file >> object;

  return object;
}
