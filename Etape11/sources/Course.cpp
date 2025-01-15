#include "Course.h"

namespace planning 
{
    Course::Course() : Event()
    {
        #ifdef DEBUG
            cout << ">>> Appelle du constructeur par defaut de Course" << endl;
        #endif

        setProfessorId(0);
        setClassroomId(0);
    }

    Course::Course(int code, const string& title, Timing *timing, int profId, int classId) : Event(code, title, timing)
    {
    	#ifdef DEBUG
            cout << ">>> Appelle du constructeur par defaut de Course" << endl;
        #endif

        setProfessorId(profId);
        setClassroomId(classId);
    }

    Course::Course(const Course& c) : Event(c)
    {
        #ifdef DEBUG
            cout << ">>> Appelle du constructeur de copie de Course" << endl;
        #endif

        setProfessorId(c.professorId);
        setClassroomId(c.classroomId);
        groupsIds = c.groupsIds;
    }

    Course::~Course()
    {
        #ifdef DEBUG
            cout << ">>> Appelle du destructeur de Course" << endl;
        #endif
    }

    void Course::setProfessorId(int p)
    {
        professorId = p;
    }

    void Course::setClassroomId(int c)
    {
        classroomId = c;
    }

    int Course::getProfessorId() const
    {
        return professorId;
    }

    int Course::getClassroomId() const
    {
        return classroomId;
    }

    set<int> Course::getGroupsIds() const
    {
        return groupsIds;
    }

    void Course::addGroupId(int g)
    {
        groupsIds.insert(g);
    }

    bool Course::isGroupIdPresent(int g) const
    {
        return groupsIds.find(g) != groupsIds.end();
    }

    bool Course::operator<(const Course& c) const
    {
        return timing < c.timing;
    }

    bool Course::operator>(const Course& c) const
    {
        return timing > c.timing;
    }

    bool Course::operator==(const Course& c) const
    {
        return timing == c.timing &&
               code == c.code &&
               professorId == c.professorId &&
               classroomId == c.classroomId &&
               groupsIds == c.groupsIds;
    }

    ostream& operator<<(ostream& s, const Course& c)
    {
        s << "<Course>" << endl;
        s << "<code>" << endl;
        s << c.code << endl;
        s << "</code>" << endl;
        s << "<title>" << endl;
        s << c.title << endl;
        s << "</title>" << endl;
        s << "<timing>" << endl;
        s << *c.timing << endl;
        s << "</timing>" << endl;
        s << "<professorId>" << endl;
        s << c.professorId << endl;
        s << "</professorId>" << endl;
        s << "<classroomId>" << endl;
        s << c.classroomId << endl;
        s << "</classroomId>" << endl;
        s << "<groupsIds>" << endl;

        for (int id : c.groupsIds)
        {
            s << id << endl;
        }
        
        s << "</groupsIds>" << endl;
        s << "</Course>";

        return s;
    }

    istream& operator>>(istream& s, Course& c)
    {
        string sCode, sTitle, sProfessorId, sClassroomId, sGroupId, tag;
        Timing timing;

        getline(s, tag);                    // <Course>
        getline(s, tag);                    // <code>
        getline(s, sCode);                  // code value
        getline(s, tag);                    // </code>
        getline(s, tag);                    // <title>
        getline(s, sTitle);                 // title value
        getline(s, tag);                    // </title>
        getline(s, tag);                    // <timing>
        s >> timing;                        // Lire Timing en une étape
        getline(s, tag);                    // </timing>
        getline(s, tag);                    // <professorId>
        getline(s, sProfessorId);           // professorId value
        getline(s, tag);                    // </professorId>
        getline(s, tag);                    // <classroomId>
        getline(s, sClassroomId);           // classroomId value
        getline(s, tag);                    // </classroomId>
        getline(s, tag);                    // <groupsIds>
        getline(s, sGroupId);               // Premier id

        while (sGroupId != "</groupsIds>")
        {
            c.addGroupId(stoi(sGroupId));   // Lire chaque id et les encoder
            getline(s, sGroupId);
        }

        getline(s, tag);                    // </Course>

        // Initialiser les valeurs
        c.setCode(stoi(sCode));
        c.setTitle(sTitle);
        c.setProfessorId(stoi(sProfessorId));
        c.setClassroomId(stoi(sClassroomId));
        c.setTiming(timing);

        return s;
    }
}
