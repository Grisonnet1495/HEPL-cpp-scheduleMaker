#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Event.h"
#include "Timetable.h"
#include "TimetableException.h"
#include "TimingException.h"
#include "XmlFileSerializer.hpp"

using namespace std;
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
    courses = list<Course>();
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

	auto result = classrooms.insert(c);
	
	if (!result.second) return -1;
    Schedulable::currentId++;
	return c.getId();
}

void Timetable::displayClassrooms() const
{
	int i = 0;
	cout << "--- Liste des locaux ---" << endl;
	for (auto it = classrooms.cbegin() ; it != classrooms.cend() ; it++, i++)
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

    throw TimetableException("Id non trouvé.", TimetableException::INVALID_ID);
}

void Timetable::deleteClassroomByIndex(int index)
{	
	if (index >= 0)
	{
		auto it = classrooms.begin();
	    advance(it, index);
	    if (it != classrooms.end())
	    {
        	// Chercher si un cours contient ce local
        	auto coursesToDelete = filterCourses("", -1, -1, it->getId());
	    	
	    	// Supprimer le local
	    	classrooms.erase(it);

        	// Supprimer les cours le contenant
	    	for (auto& course : coursesToDelete)
	    	{
	    		deleteCourseByCode(course.getCode());
	    	}

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
        	// Chercher si un cours contient ce local
        	auto coursesToDelete = filterCourses("", -1, -1, it->getId());
	    	
	    	// Supprimer le local
        	classrooms.erase(it);

        	// Supprimer les cours le contenant
	    	for (auto& course : coursesToDelete)
	    	{
	    		deleteCourseByCode(course.getCode());
	    	}

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

	auto result = professors.insert(p);

	if (!result.second) return -1;
	Schedulable::currentId++;
	return p.getId();
}

void Timetable::displayProfessors() const
{
	int i = 0;
	cout << "--- Liste des locaux ---" << endl;
	for (auto it = professors.cbegin() ; it != professors.cend() ; it++, i++)
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
        	// Chercher si un cours contient ce professeur
        	auto coursesToDelete = filterCourses("", it->getId(), -1, -1);
	    	
	    	// Supprimer le professeur
	    	professors.erase(it);

        	// Supprimer les cours le contenant
	    	for (auto& course : coursesToDelete)
	    	{
	    		deleteCourseByCode(course.getCode());
	    	}

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
        	// Chercher si un cours contient ce professeur
        	auto coursesToDelete = filterCourses("", it->getId(), -1, -1);
	    	
	    	// Supprimer le professeur
        	professors.erase(it);

        	// Supprimer les cours le contenant
	    	for (auto& course : coursesToDelete)
	    	{
	    		deleteCourseByCode(course.getCode());
	    	}

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

	auto result = groups.insert(g);

	if (!result.second) return -1;
    Schedulable::currentId++;
	return g.getId();
}

void Timetable::displayGroups() const
{
	int i = 0;
	cout << "--- Liste des locaux ---" << endl;
	for (auto it = groups.cbegin() ; it != groups.cend() ; it++, i++)
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
	    	// Chercher si un cours contient ce groupe
	    	auto coursesToDelete = filterCourses("", -1, it->getId(), -1);
	    	
	    	// Supprimer le groupe
        	groups.erase(it);

        	// Supprimer les cours le contenant
	    	for (auto& course : coursesToDelete)
	    	{
	    		deleteCourseByCode(course.getCode());
	    	}

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
        	// Chercher si un cours contient ce groupe
        	auto coursesToDelete = filterCourses("", -1, it->getId(), -1);
	    	
	    	// Supprimer le groupe
        	groups.erase(it);

        	// Supprimer les cours le contenant
	    	for (auto& course : coursesToDelete)
	    	{
	    		deleteCourseByCode(course.getCode());
	    	}

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

	auto it = courses.begin();
    while(it != courses.end() && *it < c)
    { 
        it++;
    }
    courses.insert(it, c);
    Event::currentCode++;
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
        
        // Vérifie si le prochain itérateur n'est pas le dernier
        if (next(it) != groupIds.end()) {
            s += ", ";
        }
    }

    return s;
}

// Methodes pour sauvegarder et ouvrir des objets Timetable
// Sauvegarde l'emploi du temps dans plusieurs fichiers (config et XML)
void Timetable::save(const string& timetableName)
{
    // Sauvegarde currentId et currentCode
    string fileName = timetableName + "_config.dat";
    int fd;

    // Ouvrir le fichier avec les drapeaux pour écraser s'il existe
    if ((fd = open(fileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) { 
        throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR);
    }

    write(fd, &Schedulable::currentId, sizeof(int));
    write(fd, &Event::currentCode, sizeof(int));
    close(fd);

    // Sauvegarde des cours
    {
        fileName = timetableName + "_courses.xml";
        XmlFileSerializer<Course> fsw(fileName, XmlFileSerializer<Course>::WRITE, "courses");
        for (auto it = courses.cbegin(); it != courses.cend(); it++) {
            fsw.write(*it);
        }
    }

    // Sauvegarde des salles
    {
        fileName = timetableName + "_classrooms.xml";
        XmlFileSerializer<Classroom> fsw(fileName, XmlFileSerializer<Classroom>::WRITE, "classrooms");
        for (auto it = classrooms.cbegin(); it != classrooms.cend(); it++) {
            fsw.write(*it);
        }
    }

    // Sauvegarde des professeurs
    {
        fileName = timetableName + "_professors.xml";
        XmlFileSerializer<Professor> fsw(fileName, XmlFileSerializer<Professor>::WRITE, "professors");
        for (auto it = professors.cbegin(); it != professors.cend(); it++) {
            fsw.write(*it);
        }
    }

    // Sauvegarde des groupes
    {
        fileName = timetableName + "_groups.xml";
        XmlFileSerializer<Group> fsw(fileName, XmlFileSerializer<Group>::WRITE, "groups");
        for (auto it = groups.cbegin(); it != groups.cend(); it++) {
            fsw.write(*it);
        }
    }
}

// Charge l'emploi du temps à partir de plusieurs fichiers (config et XML)
void Timetable::load(const string& timetableName)
{
	// Chargement de currentId et de currentCode
	string fileName = timetableName + "_config.dat";
	int fd;

	if ((fd = open(fileName.c_str(), O_RDONLY)) == -1) throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR); // c_str() sert a transformer le string en const char*

	read(fd, &Schedulable::currentId, sizeof(int));
	read(fd, &Event::currentCode, sizeof(int));
	close(fd);

	// Chargement des courses
	fileName = timetableName + "_courses.xml";
	XmlFileSerializer<Course> *fsre = nullptr;

	// Tentative création objet serialisation
	try
	{
		fsre = new XmlFileSerializer<Course>(fileName, XmlFileSerializer<Course>::READ);
	}
	catch (const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	// Vérification objet créé
	if (fsre != nullptr)
	{
		bool end;
		while (!end)
		{
			try
			{
				// Lecture et ajout Course
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

	// Tentative création objet serialisation
  	try
  	{
    	fsrc = new XmlFileSerializer<Classroom>(fileName, XmlFileSerializer<Classroom>::READ);
	}
	catch(const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	// Vérification objet créé
	if (fsrc != nullptr)
	{
		bool end = false;
		while (!end)
		{
			try
			{
				// Lecture et ajout Classroom
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
	
	// Tentative création objet serialisation
  	try
  	{
    	fsrp = new XmlFileSerializer<Professor>(fileName, XmlFileSerializer<Professor>::READ);
	}
	catch(const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	// Vérification objet créé
	if (fsrp != nullptr)
	{
		bool end = false;
		while (!end)
		{
			try
			{
				// Lecture et ajout Professor
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
	
	// Tentative création objet serialisation
  	try
  	{
    	fsrg = new XmlFileSerializer<Group>(fileName, XmlFileSerializer<Group>::READ);
	}
	catch(const XmlFileSerializerException& e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	// Vérification objet créé
	if (fsrg != nullptr)
	{
		bool end = false;
		while (!end)
		{
			try
			{
				// Lecture et ajout Group				
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

void Timetable::importProfessorsFromCsv(const string& fileName)
{
    ifstream inFile(fileName, ios::in);
    if(!inFile.is_open())
    {
        throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR);
    }

    string line;
    while (getline(inFile, line))
    {
        if (!line.empty())
        {
            istringstream iss(line);
            string lastName, firstName;
            getline(iss, lastName, ';');
            getline(iss, firstName, ';');
            addProfessor(lastName, firstName);
        }
    }
    inFile.close();
}

void Timetable::importGroupsFromCsv(const string &fileName) {
    ifstream inFile(fileName, ios::in);
    if (!inFile.is_open()) {
        throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR);
    }

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            istringstream iss(line);
            string groupName;
            getline(iss, groupName, ';');
            addGroup(groupName);
        }
    }

    inFile.close();
}

void Timetable::importClassroomsFromCsv(const string &fileName) {
    ifstream inFile(fileName, ios::in);
    if (!inFile.is_open()) {
        throw TimetableException("Erreur d'ouverture du fichier", TimetableException::FILE_ERROR);
    }

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            istringstream iss(line);
            string classroomName;
            string seatingCapacityStr;

            getline(iss, classroomName, ';');
            getline(iss, seatingCapacityStr, ';');

            int seatingCapacity = stoi(seatingCapacityStr);
            addClassroom(classroomName, seatingCapacity);
        }
    }

    inFile.close();
}

// Exporte l'emploi du temps d'un professeur dans un fichier au format .hor
void Timetable::exportProfessorTimetable(int id) const {
    Professor professor;
    
    // Recherche professeur par id
    professor = findProfessorById(id);

    // Création fichier basé sur nom prof
    string fileName = professor.getLastName() + "_" + professor.getFirstName() + ".hor";
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        throw TimetableException("Impossible de créer le fichier " + fileName, TimetableException::FILE_ERROR);
    }

    // En-tête du fichier
    outFile << "Horaire de " << professor.getLastName() << " " << professor.getFirstName() << " :\n";

    // Parcourt tous les cours pour trouver ceux du professeur
    for (auto it = courses.cbegin(); it != courses.cend(); ++it) {
    	const auto& course = *it;
    	
    	if(course.getProfessorId() == id) {
    		const auto& timing = course.getTiming();
    		string startTime = timing.getStart().toString();
    		string durationText = timing.getDuration().toString();

    		string classroomName = findClassroomById(course.getClassroomId()).getName();

    		string groupNames;
    		for (const auto& groupId : course.getGroupsIds()) {
    			groupNames += findGroupById(groupId).getName() + ",";
    		}
    		if (!groupNames.empty()) groupNames.pop_back();	// Retire la dernière virgule

    		outFile << left 	// Positionne à gauche
    				<< setw(9) << timing.getDay()
    				<< setw(6) << startTime
    				<< setw(6) << durationText
    				<< setw(10) << classroomName
    				<< setw(20) << course.getTitle()
    				<< groupNames << "\n";
    	}
    }

    outFile.close();
}

// Exporte l'emploi du temps d'un groupe dans un fichier au format .hor
void Timetable::exportGroupTimetable(int id) const {
    Group group;

    // Recherche du groupe par ID
    group = findGroupById(id);

    // Génère le nom du fichier en fonction du nom du groupe
    string fileName = group.getName() + ".hor";
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        throw TimetableException("Impossible de créer le fichier " + fileName, TimetableException::FILE_ERROR);
    }

    // En-tête du fichier
    outFile << "Horaire de " << group.getName() << " :\n";

    // Parcourt tous les cours pour trouver ceux du groupe
    for (auto it = courses.cbegin(); it != courses.cend(); ++it) {
        const auto& course = *it;

        if (course.isGroupIdPresent(id)) {
            const auto& timing = course.getTiming();

            string startTime = timing.getStart().toString();
            string durationText = timing.getDuration().toString();

            string professorName = findProfessorById(course.getProfessorId()).getLastName() + " " +
                                   findProfessorById(course.getProfessorId()).getFirstName();

            string classroomName = findClassroomById(course.getClassroomId()).getName();

            outFile << left
                    << setw(9) << timing.getDay()
                    << setw(6) << startTime
                    << setw(6) << durationText
                    << setw(10) << classroomName
                    << setw(20) << course.getTitle()
                    << professorName << "\n";
        }
    }

    outFile.close();
}

// Exporte l'emploi du temps d'une salle dans un fichier au format .hor
void Timetable::exportClassroomTimetable(int id) const {
    Classroom classroom;

    // Recherche de la salle par ID
    classroom = findClassroomById(id);

    // Génère le nom du fichier en fonction du nom de la salle
    string fileName = classroom.getName() + ".hor";
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        throw TimetableException("Impossible de créer le fichier " + fileName, TimetableException::FILE_ERROR);
    }

    // En-tête du fichier
    outFile << "Horaire de " << classroom.getName() << " :\n";

    // Parcourt tous les cours pour trouver ceux de la salle
    for (auto it = courses.cbegin(); it != courses.cend(); ++it) {
        const auto& course = *it;

        if (course.getClassroomId() == id) {
            const auto& timing = course.getTiming();

            string startTime = timing.getStart().toString();
            string durationText = timing.getDuration().toString();

            string professorName = findProfessorById(course.getProfessorId()).getLastName() + " " +
                                   findProfessorById(course.getProfessorId()).getFirstName();

            string groupNames;
            for (const auto& groupId : course.getGroupsIds()) {
                groupNames += findGroupById(groupId).getName() + ",";
            }
            if (!groupNames.empty()) groupNames.pop_back(); // Retire la dernière virgule

            outFile << left
                    << setw(9) << timing.getDay()
                    << setw(6) << startTime
                    << setw(6) << durationText
                    << setw(15) << course.getTitle()
                    << setw(20) << professorName
                    << groupNames << "\n";
        }
    }

    outFile.close();
}

// Filtre les cours en fonction des critères spécifiés (jour, ID professeur, ID groupe, ID salle)
list<Course> Timetable::filterCourses(const string& day, int professorId, int groupId, int classroomId) const {
    list<Course> filteredCourses;

    // Parcourt tous les cours disponibles
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        bool matches = true;

        // Applique le filtre par jour si un jour est spécifié
        if (!day.empty() && it->getTiming().getDay() != day) {
            matches = false;
        }

        // Applique le filtre par ID de professeur si spécifié
        if (professorId != -1 && it->getProfessorId() != professorId) {
            matches = false;
        }

        // Applique le filtre par ID de groupe si spécifié
        if (groupId != -1 && !it->isGroupIdPresent(groupId)) {
            matches = false;
        }

        // Applique le filtre par ID de salle si spécifié
        if (classroomId != -1 && it->getClassroomId() != classroomId) {
            matches = false;
        }

        if (matches) {
            filteredCourses.push_back(*it);
        }
    }

    return filteredCourses;
}
