#include "Timetable.h"
#include "TimetableException.h"

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

void save(const string& timetableName)
{
	string fileName = timetableName + "_config.dat";
	int fd;

	if ((fd = open(fileName, O_WRONLY | O_CREAT, 0666)) == -1) throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR);

	write(fd, Schedulable::currentId);
	close(fd);

	string fileName = timetableName + "_classrooms.xml";
	XmlFileSerializer<Professor> XfsClassroom(fileName, XmlFileSerializer<Professor>::WRITE, "classrooms");
	cout << "Filename = " << XfsClassroom.getFilename() << endl;
	cout << "Collection name  = " << XfsClassroom.getCollectionName() << endl;
	cout << "Readable = " << XfsClassroom.isReadable() << endl;
	cout << "Writable = " << XfsClassroom.isWritable() << endl << endl;

	for (auto it = classrooms.cbegin(); it != classrooms.cend(); it++) {
		XfsClassroom.write(it);
	}
	delete XfsClassroom;

	string fileName = timetableName + "_professors.xml";
	XmlFileSerializer<Professor> XfsProfessor(fileName, XmlFileSerializer<Professor>::WRITE, "professors");
	cout << "Filename = " << XfsProfessor.getFilename() << endl;
	cout << "Collection name  = " << XfsProfessor.getCollectionName() << endl;
	cout << "Readable = " << XfsProfessor.isReadable() << endl;
	cout << "Writable = " << XfsProfessor.isWritable() << endl << endl;

	for (auto it = professors.cbegin(); it != professors.cend(); it++) {
		XfsProfessor.write(it);
	}
	delete XfsProfessor;

	string fileName = timetableName + "_groups.xml";
	XmlFileSerializer<Professor> XfsGroup(fileName, XmlFileSerializer<Group>::WRITE, "groups");
	cout << "Filename = " << XfsGroup.getFilename() << endl;
	cout << "Collection name  = " << XfsGroup.getCollectionName() << endl;
	cout << "Readable = " << XfsGroup.isReadable() << endl;
	cout << "Writable = " << XfsGroup.isWritable() << endl << endl;

	for (auto it = groups.cbegin(); it != groups.cend(); it++) {
		XfsGroup.write(it);
	}
	delete XfsGroup;
}
