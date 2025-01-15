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
    static Timetable instance;

    set<Classroom> classrooms;
    set<Professor> professors;
    set<Group> groups;
    list<Course> courses;

    Timetable();
    Timetable(const Timetable& t) = delete;
    Timetable& operator=(const Timetable& t) = delete;
 
  public:
    static Timetable& getInstance();

    ~Timetable();

    set<Classroom> getClassrooms() const;
    set<Professor> getProfessors() const;
    set<Group> getGroups() const;
    list<Course> getCourses() const;

    int addClassroom(const string& name,int seatingCapacity);
    void displayClassrooms() const;
    Classroom findClassroomByIndex(int index) const;
    Classroom findClassroomById(int id) const;
    void deleteClassroomByIndex(int index);
    void deleteClassroomById(int id);
    bool isClassroomAvailable(int id, const Timing& timing);
 
    int addProfessor(const string& lastName,const string& firstName);
    void displayProfessors() const;
    Professor findProfessorByIndex(int index) const;
    Professor findProfessorById(int id) const;
    void deleteProfessorByIndex(int index);
    void deleteProfessorById(int id);
    bool isProfessorAvailable(int id, const Timing& timing);
 
    int addGroup(const string& name);
    void displayGroups() const;
    Group findGroupByIndex(int index) const;
    Group findGroupById(int id) const;
    void deleteGroupByIndex(int index);
    void deleteGroupById(int id);
    bool isGroupAvailable(int id, const Timing& timing);

    void schedule(Course& c, const Timing& t);
    void deleteCourseByCode(int code);
    string tuple(const Course& c);

    void save(const string& timetableName);
    void load(const string& timetableName);
    void clearTimetable();

    void importProfessorsFromCsv(const string& fileName);
    void importGroupsFromCsv(const string& fileName);
    void importClassroomsFromCsv(const string& fileName);

    void exportProfessorTimetable(int id) const;
    void exportGroupTimetable(int id) const;
    void exportClassroomTimetable(int id) const;
};
