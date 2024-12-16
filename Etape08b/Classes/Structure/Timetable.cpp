#include "Timetable.h"
#include "../Exception/TimetableException.h"

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

// Méthodes pour les objets Classroom

int Timetable::addClassroom(const string& name, int seatingCapacity)
{
	Classroom c(Schedulable::currentId, name, seatingCapacity);
    Schedulable::currentId++;

	classrooms.insert(c);

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
	auto it = classrooms.begin();
	advance(it, index);
	if (it == classrooms.end()) throw TimetableException("Cannot find classroom.", TimetableException::INVALID_INDEX);
	return *it;
}

Classroom Timetable::findClassroomById(int id) const
{
	for (auto it = classrooms.cbegin(); it != classrooms.cend(); it++)
    {
        if (it->getId() == id) return *it;
    }

    throw TimetableException("Cannot find classroom.", TimetableException::INVALID_ID);
}

void Timetable::deleteClassroomByIndex(int index)
{
    auto it = classrooms.begin();
    advance(it, index);
    if (it != classrooms.end()) classrooms.erase(it);
    else cout << "Index hors limites." << endl;
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
	
	cout << "Id non trouve." << endl;
}

// Méthodes pour les objets Professor

int Timetable::addProfessor(const string& lastName,const string& firstName)
{
	Professor p(Schedulable::currentId, lastName, firstName);
	Schedulable::currentId++;

	professors.insert(p);

	return p.getId();
}

void Timetable::displayProfessors() const
{
	int i = 0;
	cout << "--- Liste des locaux ---" << endl;
	for (set<Professor>::const_iterator it = professors.cbegin(); it != professors.cend(); it++, i++)
	{
		cout << i << " : " << it->toString() << endl;
	}
}

Professor Timetable::findProfessorByIndex(int index) const
{
	auto it = professors.begin();
	advance(it, index);
	if (it == professors.end()) throw TimetableException("Cannot find professor.", TimetableException::INVALID_INDEX);
	return *it;
}

Professor Timetable::findProfessorById(int id) const
{
	for (auto it = professors.cbegin(); it != professors.cend(); it++)
    {
        if (it->getId() == id) return *it;
    }

	throw TimetableException("Cannot find professor", TimetableException::INVALID_ID);
}

void Timetable::deleteProfessorByIndex(int index)
{
	auto it = professors.begin();
    advance(it, index);
    if (it != professors.end()) professors.erase(it);
    else cout << "Index hors limites." << endl;
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
	
	cout << "Id non trouve." << endl;
}

// Méthodes pour les objets Group

int Timetable::addGroup(const string& name)
{
	Group g(Schedulable::currentId, name);
    Schedulable::currentId++;

	groups.insert(g);

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
	auto it = groups.begin();
	advance(it, index);
	if (it == groups.end()) TimetableException("Cannot find group.", TimetableException::INVALID_INDEX);
	return *it;
}

Group Timetable::findGroupById(int id) const
{
	for (auto it = groups.cbegin(); it != groups.cend(); it++)
    {
        if (it->getId() == id) return *it;
    }
    
    throw TimetableException("Cannot find group.", TimetableException::INVALID_ID);
}

void Timetable::deleteGroupByIndex(int index)
{
	auto it = groups.begin();
    advance(it, index);
    if (it != groups.end()) groups.erase(it);
    else cout << "Index hors limites." << endl;
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
	
	cout << "Id non trouve." << endl;
}
