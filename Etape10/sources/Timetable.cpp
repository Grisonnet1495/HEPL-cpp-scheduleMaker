#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include "Timetable.h"
#include "TimetableException.h"
#include "XmlFileSerializer.hpp"

using namespace planning;

int Schedulable::currentId = 1;
Timetable Timetable::instance;

Timetable::Timetable()
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Timetable" << endl;
    #endif

    classrooms = set<Classroom>();
    professors = set<Professor>();
    groups = set<Group>();
}

Timetable& Timetable::getInstance()
{
	return Timetable::instance;
}

Timetable::~Timetable()
{
	#ifdef DEBUG
      cout << ">>> Appelle du destructeur par defaut de Timetable" << endl;
    #endif
}

// Getters

set<Classroom> Timetable::getClassrooms() const
{
	return classrooms;
}

set<Professor> Timetable::getProfessors() const
{
	return professors;
}

set<Group> Timetable::getGroups() const
{
	return groups;
}

// Méthodes pour les objets Classroom

int Timetable::addClassroom(const string& name, int seatingCapacity)
{
	Classroom c(Schedulable::currentId, name, seatingCapacity);
    Schedulable::currentId++;

	auto result = classrooms.insert(c);
	
	if (!result.second) return -1;
	return c.getId();
}

void Timetable::displayClassrooms() const
{
	int i = 0;
	cout << "--- Liste des locaux ---" << endl;
	for (set<Classroom>::const_iterator it = classrooms.cbegin() ; it != classrooms.cend() ; it++, i++)
	{
		cout << i << " : " << it->toString() << endl;
	}
}

Classroom Timetable::findClassroomByIndex(int index) const
{
	if (index >= 0)
	{
		auto it = classrooms.begin();
		advance(it, index);
		if (it != classrooms.end()) return *it;
	}
	
	throw TimetableException("Index incorrect.", TimetableException::INVALID_INDEX);
}

Classroom Timetable::findClassroomById(int id) const
{
	for (auto it = classrooms.cbegin(); it != classrooms.cend(); it++)
    {
        if (it->getId() == id) return *it;
    }

    throw TimetableException("Id incorrect.", TimetableException::INVALID_ID);
}

void Timetable::deleteClassroomByIndex(int index)
{	
	if (index >= 0)
	{
		auto it = classrooms.begin();
	    advance(it, index);
	    if (it != classrooms.end())
	    {
	    	classrooms.erase(it);
	    	return;
	    }
	}
    
    throw TimetableException("Index incorrect.", TimetableException::INVALID_INDEX);
}

void Timetable::deleteClassroomById(int id)
{
	for (auto it = classrooms.cbegin(); it != classrooms.cend(); it++)
    {
        if (it->getId() == id)
        {
        	classrooms.erase(it);
        	return;
        }
    }
	
	throw TimetableException("Id non trouve.", TimetableException::INVALID_ID);
}

// Méthodes pour les objets Professor

int Timetable::addProfessor(const string& lastName,const string& firstName)
{
	Professor p(Schedulable::currentId, lastName, firstName);
	Schedulable::currentId++;

	auto result = professors.insert(p);

	if (!result.second) return -1;
	return p.getId();
}

void Timetable::displayProfessors() const
{
	int i = 0;
	cout << "--- Liste des locaux ---" << endl;
	for (set<Professor>::const_iterator it = professors.cbegin() ; it != professors.cend() ; it++, i++)
	{
		cout << i << " : " << it->toString() << endl;
	}
}

Professor Timetable::findProfessorByIndex(int index) const
{
	if (index >= 0)
	{
		auto it = professors.begin();
		advance(it, index);
		if (it != professors.end()) return *it;
	}
	
	throw TimetableException("Index incorrect.", TimetableException::INVALID_INDEX);
}

Professor Timetable::findProfessorById(int id) const
{
	for (auto it = professors.cbegin(); it != professors.cend(); it++)
    {
        if (it->getId() == id) return *it;
    }
    
	throw TimetableException("Id non trouve.", TimetableException::INVALID_ID);
}

void Timetable::deleteProfessorByIndex(int index)
{
	if (index >= 0)
	{
		auto it = professors.begin();
	    advance(it, index);
	    if (it != professors.end())
	    {
	    	professors.erase(it);
	    	return;
	    }
	}
	
    throw TimetableException("Index incorrect", TimetableException::INVALID_INDEX);
}

void Timetable::deleteProfessorById(int id)
{
	for (auto it = professors.cbegin(); it != professors.cend(); it++)
    {
        if (it->getId() == id)
        {
        	professors.erase(it);
        	return;
        }
    }
	
	throw TimetableException("Id non trouve.", TimetableException::INVALID_ID);
}

// Méthodes pour les objets Group

int Timetable::addGroup(const string& name)
{
	Group g(Schedulable::currentId, name);
    Schedulable::currentId++;

	auto result = groups.insert(g);

	if (!result.second) return -1;
	return g.getId();
}

void Timetable::displayGroups() const
{
	int i = 0;
	cout << "--- Liste des locaux ---" << endl;
	for (set<Group>::const_iterator it = groups.cbegin() ; it != groups.cend() ; it++, i++)
	{
		cout << i << " : " << it->toString() << endl;
	}
}

Group Timetable::findGroupByIndex(int index) const
{
	if (index >= 0)
	{
		auto it = groups.begin();
		advance(it, index);
		if (it != groups.end()) return *it;
	}
	
	throw TimetableException("Index incorrect.", TimetableException::INVALID_INDEX);
}

Group Timetable::findGroupById(int id) const
{
	for (auto it = groups.cbegin(); it != groups.cend(); it++)
    {
        if (it->getId() == id) return *it;
    }
    
    throw TimetableException("Id non trouve", TimetableException::INVALID_ID);
}

void Timetable::deleteGroupByIndex(int index)
{
	if (index >= 0)
	{
		auto it = groups.begin();
	    advance(it, index);
	    if (it != groups.end())
	    {
	    	groups.erase(it);
	    	return;
	    }
	}
	
    TimetableException("Index incorrect.", TimetableException::INVALID_INDEX);
}

void Timetable::deleteGroupById(int id)
{
	for (auto it = groups.cbegin(); it != groups.cend(); it++)
    {
        if (it->getId() == id)
        {
        	groups.erase(it);
        	return;
        }
    }
	
	throw TimetableException("Id non trouve.", TimetableException::INVALID_ID);
}

void Timetable::save(const string& timetableName)
{
	// Sauvegarde currenId
	string fileName = timetableName + "_config.dat";
	int fd;

	// Verifie si le fichier existe deja
	if (access(fileName.c_str(), F_OK) == 0) throw TimetableException("Un fichier du meme nom est deja present", TimetableException::FILE_EXISTS); // c_str() sert a transformer le string en const char*

	if ((fd = open(fileName.c_str(), O_WRONLY | O_CREAT, 0644)) == -1) throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR);

	write(fd, &Schedulable::currentId, sizeof(int));
	close(fd);

	{
		// Sauvegarde classrooms
		fileName = timetableName + "_classrooms.xml";
		XmlFileSerializer<Classroom> fsw(fileName, XmlFileSerializer<Classroom>::WRITE, "classrooms");
		cout << "Filename = " << fsw.getFilename() << endl;
		cout << "Collection name  = " << fsw.getCollectionName() << endl;
		cout << "Readable = " << fsw.isReadable() << endl;
		cout << "Writable = " << fsw.isWritable() << endl << endl;

		for (auto it = classrooms.cbegin(); it != classrooms.cend(); it++) {
			fsw.write(*it);
		}
	}

	{
		// Sauvegarde professors
		fileName = timetableName + "_professors.xml";
		XmlFileSerializer<Professor> fsw(fileName, XmlFileSerializer<Professor>::WRITE, "professors");
		cout << "Filename = " << fsw.getFilename() << endl;
		cout << "Collection name  = " << fsw.getCollectionName() << endl;
		cout << "Readable = " << fsw.isReadable() << endl;
		cout << "Writable = " << fsw.isWritable() << endl << endl;

		for (auto it = professors.cbegin(); it != professors.cend(); it++) {
			fsw.write(*it);
		}
	}

	{
		// Sauvegarde groups
		fileName = timetableName + "_groups.xml";
		XmlFileSerializer<Group> fsw(fileName, XmlFileSerializer<Group>::WRITE, "groups");
		cout << "Filename = " << fsw.getFilename() << endl;
		cout << "Collection name  = " << fsw.getCollectionName() << endl;
		cout << "Readable = " << fsw.isReadable() << endl;
		cout << "Writable = " << fsw.isWritable() << endl << endl;

		for (auto it = groups.cbegin(); it != groups.cend(); it++) {
			fsw.write(*it);
		}
	}
}

void Timetable::load(const string& timetableName)
{
	// Sauvegarde currentId
	string fileName = timetableName + "_config.dat";
	int fd;

	if ((fd = open(fileName.c_str(), O_RDONLY)) == -1) throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR); // c_str() sert a transformer le string en const char*

	read(fd, &Schedulable::currentId, sizeof(int));
	close(fd);

	// Sauvegarde de classrooms
	fileName = timetableName + "_classrooms.xml";
	XmlFileSerializer<Classroom> *fsrc = nullptr;

  	try
  	{
    	fsrc = new XmlFileSerializer<Classroom>(fileName, XmlFileSerializer<Classroom>::READ);
	    cout << "Filename = " << fsrc->getFilename() << endl;
	    cout << "Collection name = " << fsrc->getCollectionName() << endl;
	    cout << "Readable = " << fsrc->isReadable() << endl;
	    cout << "Writable = " << fsrc->isWritable() << endl << endl;
	} catch(const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (fsrc != nullptr)
	{
		cout << "Debut de lecture..." << endl;
		bool end = false;

		while (!end)
		{
			try
			{
				Classroom c = fsrc->read();
				cout << "Lu : " << c.toString() << endl;
				classrooms.insert(c);
			} catch(const XmlFileSerializerException& e) {
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
				{ 
				  end = true;
				  cout << "Fin de fichier atteinte." << endl;
				}
				else
				{
				  cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
				}
			}
		}
    	delete fsrc;

		cout << "Fin de lecture." << endl;
	}

	// Sauvegarde de professors
	fileName = timetableName + "_professors.xml";
	XmlFileSerializer<Professor> *fsrp = nullptr;
	
  	try
  	{
    	fsrp = new XmlFileSerializer<Professor>(fileName, XmlFileSerializer<Professor>::READ);
	    cout << "Filename = " << fsrp->getFilename() << endl;
	    cout << "Collection name = " << fsrp->getCollectionName() << endl;
	    cout << "Readable = " << fsrp->isReadable() << endl;
	    cout << "Writable = " << fsrp->isWritable() << endl << endl;
	} catch(const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (fsrp != nullptr)
	{
		cout << "Debut de lecture..." << endl;
		bool end = false;

		while (!end)
		{
			try
			{
				Professor p = fsrp->read();
				cout << "Lu : " << p.toString() << endl;
				professors.insert(p);
			} catch(const XmlFileSerializerException& e) {
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
				{ 
				  end = true;
				  cout << "Fin de fichier atteinte." << endl;
				}
				else
				{
				  cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
				}
			}
		}
    	delete fsrp;

		cout << "Fin de lecture." << endl;
	}

	// Sauvegarde de groups
	fileName = timetableName + "_groups.xml";
	XmlFileSerializer<Group> *fsrg = nullptr;
	
  	try
  	{
    	fsrg = new XmlFileSerializer<Group>(fileName, XmlFileSerializer<Group>::READ);
	    cout << "Filename = " << fsrg->getFilename() << endl;
	    cout << "Collection name = " << fsrg->getCollectionName() << endl;
	    cout << "Readable = " << fsrg->isReadable() << endl;
	    cout << "Writable = " << fsrg->isWritable() << endl << endl;
	} catch(const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (fsrg != nullptr)
	{
		cout << "Debut de lecture..." << endl;
		bool end = false;

		while (!end)
		{
			try
			{
				Group g = fsrg->read();
				cout << "Lu : " << g.toString() << endl;
				groups.insert(g);
			} catch(const XmlFileSerializerException& e) {
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
				{ 
				  end = true;
				  cout << "Fin de fichier atteinte." << endl;
				}
				else
				{
				  cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
				}
			}
		}
    	delete fsrg;

		cout << "Fin de lecture." << endl;
	}
}

void Timetable::clearTimetable()
{
	Schedulable::currentId = 1;
	classrooms.clear();
	professors.clear();
	groups.clear();
}
