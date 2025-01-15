#ifndef COURSE_H
#define COURSE_H

#include "Event.h"
#include <set>
#include <string>
#include <iostream>
using namespace std;

namespace planning 
{
	class Course : public Event
	{
		// Opérateurs pour les flux
		friend ostream& operator<<(ostream& s, const Course& c);
		friend istream& operator>>(istream& s, Course& c);

	private:
		int professorId;
		int classroomId;
		set<int> groupsIds;	// Ensemble trié d'IDs uniques des groupes

	public:
      	// Constructeurs et destructeur	
		Course();
		Course(int code, const string& title, Timing *timing, int profId, int classId);
		Course(const Course& c);
		~Course();

		void setProfessorId(int p);
		void setClassroomId(int c);
		void setGroupsIds(set<int> g);

		int getProfessorId() const;
		int getClassroomId() const;
		set<int> getGroupsIds() const;

		void addGroupId(int g);
		bool isGroupIdPresent(int g) const;

		bool operator<(const Course& c) const;
		bool operator>(const Course& c) const;
		bool operator==(const Course& c) const;
	};
}

#endif // COURSE_H
