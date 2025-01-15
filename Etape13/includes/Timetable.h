#include <string.h>
#include <set>
#include <list>
#include "Schedulable.h"
#include "Professor.h"
#include "Classroom.h"
#include "Group.h"
#include "Course.h"

class Timetable 
{ 
  private:
    static Timetable instance; // Instance unique (singleton)

    set<Classroom> classrooms; // Ensemble des salles
    set<Professor> professors; // Ensemble des professeurs
    set<Group> groups;         // Ensemble des groupes
    list<Course> courses;      // Liste des cours planifiés

    Timetable();
    Timetable(const Timetable& t) = delete;
    Timetable& operator=(const Timetable& t) = delete;
 
  public:
    // Accès à l'instance unique (singleton)
    static Timetable& getInstance();

    ~Timetable();

    // Getters pour les collections
    set<Classroom> getClassrooms() const;
    set<Professor> getProfessors() const;
    set<Group> getGroups() const;
    list<Course> getCourses() const;

    // Gestion des salles
    int addClassroom(const string& name, int seatingCapacity);
    void displayClassrooms() const;
    Classroom findClassroomByIndex(int index) const;
    Classroom findClassroomById(int id) const;
    void deleteClassroomByIndex(int index);
    void deleteClassroomById(int id);
    bool isClassroomAvailable(int id, const Timing& timing);
 
    // Gestion des professeurs
    int addProfessor(const string& lastName, const string& firstName);
    void displayProfessors() const;                               
    Professor findProfessorByIndex(int index) const;              
    Professor findProfessorById(int id) const;                      
    void deleteProfessorByIndex(int index);                         
    void deleteProfessorById(int id);                                
    bool isProfessorAvailable(int id, const Timing& timing);       
 
    // Gestion des groupes
    int addGroup(const string& name);                
    void displayGroups() const;                    
    Group findGroupByIndex(int index) const;       
    Group findGroupById(int id) const;             
    void deleteGroupByIndex(int index);             
    void deleteGroupById(int id);                    
    bool isGroupAvailable(int id, const Timing& timing);

    // Gestion des cours
    void schedule(Course& c, const Timing& t);       
    void deleteCourseByCode(int code);             
    string tuple(const Course& c);                

    // Sauvegarde et chargement
    void save(const string& timetableName); 
    void load(const string& timetableName);         
    void clearTimetable();                          

    // Importation de données
    void importProfessorsFromCsv(const string& fileName);
    void importGroupsFromCsv(const string& fileName);
    void importClassroomsFromCsv(const string& fileName);

    // Exportation des emplois du temps
    void exportProfessorTimetable(int id) const;      
    void exportGroupTimetable(int id) const;          
    void exportClassroomTimetable(int id) const;     

    // Filtrage des cours selon des critères
    list<Course> filterCourses(const string& day, int professorId, int groupId, int classroomId) const;
};
