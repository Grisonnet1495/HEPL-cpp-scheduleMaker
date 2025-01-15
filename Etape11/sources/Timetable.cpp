#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include "Event.h"
#include "Timetable.h"
#include "TimetableException.h"
#include "TimingException.h"
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

list<Course> Timetable::getCourses() const
{
	return courses;
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

bool Timetable::isClassroomAvailable(int id, const Timing& timing)
{
	for (auto it = courses.cbegin(); it != courses.cend(); it++)
	{
		if (it->getClassroomId() == id)
		{
			if (it->getTiming().intersect(timing) == true) return false;
		}
	}

	return true;
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

bool Timetable::isProfessorAvailable(int id, const Timing& timing)
{
	for (auto it = courses.cbegin(); it != courses.cend(); it++)
	{
		if (it->getProfessorId() == id)
		{
			if (it->getTiming().intersect(timing) == true) return false;
		}
	}

	return true;
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

bool Timetable::isGroupAvailable(int id, const Timing& timing)
{
	for (auto it = courses.cbegin(); it != courses.cend(); it++)
	{
		if (it->isGroupIdPresent(id))
		{
			if (it->getTiming().intersect(timing)) return false;
		}
	}

	return true;
}

// Methode pour planifier un cours

void Timetable::schedule(Course& c, const Timing& t) 
{
	if (!isClassroomAvailable(c.getClassroomId(), t)) throw TimingException("Local non disponible", TimingException::INVALID_TIMING);

	if (!isProfessorAvailable(c.getProfessorId(), t)) throw TimingException("Professeur non disponible", TimingException::INVALID_TIMING);

	for (const auto& groupId : c.getGroupsIds())
	{
		if (!isGroupAvailable(groupId, t)) throw TimingException("Groupe non disponible", TimingException::INVALID_TIMING);
	}

	c.setTiming(t);

	courses.push_back(c);
}

void Timetable::deleteCourseByCode(int code)
{
	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		if (it->getCode() == code)
		{
			courses.erase(it);
			return;
		}
	}

	throw TimetableException("Code non trouve.", TimetableException::INVALID_CODE);
}

// Méthode pour renvoyer un tuple representant un objet Course

string Timetable::tuple(const Course& c)
{
    string s = to_string(c.getCode()) + ";";
    s += c.getTiming().tuple() + ";";
    s += findClassroomById(c.getClassroomId()).getName() + ";";
    s += c.getTitle() + ";";
    s += findProfessorById(c.getProfessorId()).getLastName() + " " + findProfessorById(c.getProfessorId()).getFirstName() + ";";

    const auto groupIds = c.getGroupsIds();
    for (auto it = groupIds.begin(); it != groupIds.end(); it++) {
        s += findGroupById(*it).getName();
        if (next(it) != groupIds.end())    // Vérifie si le prochain itérateur n'est pas le dernier
            s += ", ";
    }

    return s;
}

// Methodes pour sauvegarder et ouvrir des objets Timetable

void Timetable::save(const string& timetableName)
{
	// Sauvegarde currenId
	string fileName = timetableName + "_config.dat";
	int fd;

	// Verifie si le fichier existe deja
	if (access(fileName.c_str(), F_OK) == 0) throw TimetableException("Un fichier du meme nom est deja present", TimetableException::FILE_EXISTS); // c_str() sert a transformer le string en const char*

	if ((fd = open(fileName.c_str(), O_WRONLY | O_CREAT, 0644)) == -1) throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR);

	write(fd, &Schedulable::currentId, sizeof(int));
	write(fd, &Event::currentCode, sizeof(int));
	close(fd);

	{
		// Sauvegarde des cours
		fileName = timetableName + "_courses.xml";
		XmlFileSerializer<Course> fsw(fileName, XmlFileSerializer<Course>::WRITE, "courses");
		for (auto it = courses.cbegin(); it != courses.cend(); it++) {
			fsw.write(*it);
		}
	}

	{
		// Sauvegarde classrooms
		fileName = timetableName + "_classrooms.xml";
		XmlFileSerializer<Classroom> fsw(fileName, XmlFileSerializer<Classroom>::WRITE, "classrooms");
		for (auto it = classrooms.cbegin(); it != classrooms.cend(); it++) {
			fsw.write(*it);
		}
	}

	{
		// Sauvegarde professors
		fileName = timetableName + "_professors.xml";
		XmlFileSerializer<Professor> fsw(fileName, XmlFileSerializer<Professor>::WRITE, "professors");
		for (auto it = professors.cbegin(); it != professors.cend(); it++) {
			fsw.write(*it);
		}
	}

	{
		// Sauvegarde groups
		fileName = timetableName + "_groups.xml";
		XmlFileSerializer<Group> fsw(fileName, XmlFileSerializer<Group>::WRITE, "groups");
		for (auto it = groups.cbegin(); it != groups.cend(); it++) {
			fsw.write(*it);
		}
	}
}

void Timetable::load(const string& timetableName)
{
	// Chargement currentId
	string fileName = timetableName + "_config.dat";
	int fd;

	if ((fd = open(fileName.c_str(), O_RDONLY)) == -1) throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR); // c_str() sert a transformer le string en const char*

	read(fd, &Schedulable::currentId, sizeof(int));
	read(fd, &Event::currentCode, sizeof(int));
	close(fd);

	// Chargement des courses
	fileName = timetableName + "_courses.xml";
	XmlFileSerializer<Course> *fsre = nullptr;

	try
	{
		fsre = new XmlFileSerializer<Course>(fileName, XmlFileSerializer<Course>::READ);
	}
	catch (const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (fsre != nullptr)
	{
		bool end;
		while (!end)
		{
			try
			{
				Course c = fsre->read();
				courses.push_back(c);
			}
			catch (XmlFileSerializerException& e)
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
				{
					end = true;
				}
				else
				{
                    cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
				}
			}
		}
		delete fsre;
	}

	// Chargement de classrooms
	fileName = timetableName + "_classrooms.xml";
	XmlFileSerializer<Classroom> *fsrc = nullptr;

  	try
  	{
    	fsrc = new XmlFileSerializer<Classroom>(fileName, XmlFileSerializer<Classroom>::READ);
	}
	catch(const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (fsrc != nullptr)
	{
		bool end = false;

		while (!end)
		{
			try
			{
				Classroom c = fsrc->read();
				classrooms.insert(c);
			} 
			catch(const XmlFileSerializerException& e) 
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
				{ 
				  end = true;
				}
				else
				{
				  cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
				}
			}
		}
    	delete fsrc;
	}

	// Chargement de professors
	fileName = timetableName + "_professors.xml";
	XmlFileSerializer<Professor> *fsrp = nullptr;
	
  	try
  	{
    	fsrp = new XmlFileSerializer<Professor>(fileName, XmlFileSerializer<Professor>::READ);
	}
	catch(const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (fsrp != nullptr)
	{
		bool end = false;

		while (!end)
		{
			try
			{
				Professor p = fsrp->read();
				professors.insert(p);
			}
			catch(const XmlFileSerializerException& e) 
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
				{ 
				  end = true;
				}
				else
				{
				  cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
				}
			}
		}
    	delete fsrp;
	}

	// Chargement de groups
	fileName = timetableName + "_groups.xml";
	XmlFileSerializer<Group> *fsrg = nullptr;
	
  	try
  	{
    	fsrg = new XmlFileSerializer<Group>(fileName, XmlFileSerializer<Group>::READ);
	}
	catch(const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (fsrg != nullptr)
	{
		bool end = false;

		while (!end)
		{
			try
			{
				Group g = fsrg->read();
				groups.insert(g);
			} 
			catch(const XmlFileSerializerException& e)
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
				{ 
				  end = true;
				}
				else
				{
				  cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
				}
			}
		}
    	delete fsrg;
	}
}

void Timetable::clearTimetable()
{
	Schedulable::currentId = 1;
	Event::currentCode = 1;
	classrooms.clear();
	professors.clear();
	groups.clear();
	courses.clear();
}
