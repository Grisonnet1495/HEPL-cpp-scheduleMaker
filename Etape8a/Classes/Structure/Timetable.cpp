Timetable::Timetable()
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Timetable" << endl;
    #endif

    classrooms = set<Classroom>();
    professors = set<Professor>();
    groups = set<Group>();
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
	// Créer un objet Classroom, puis incémenter currentId ?
	classrooms.insert(Classroom(name, seatingCapacity));
}

void Timetable::displayClassrooms() const
{
	cout << "Contenu du conteneur classrooms : " << endl;
	for (set<Classroom>::const_iterator i = classrooms.cbegin() ; i != classrooms.cend() ; i++)
	{
		cout << "- " << i->toString() << endl;
	}
}

Classroom Timetable::findClassroomByIndex(int index) const
{
	auto i = classrooms.begin();
	advance(i, index);

	if (i != classrooms.end()) return *i;
	else return nullptr;
}

Classroom Timetable::findClassroomById(int id) const
{
	Classroom c(id);
	auto i = classrooms.find(c);

	if (i != classrooms.end()) return *i;
	else return nullptr;
}

void Timetable::deleteClassroomByIndex(int index)
{
    auto i = classrooms.begin();
    advance(i, index);

    if (it != mySet.end()) classrooms.erase(i);
    else cout << "Index hors limites." << endl;
}

void Timetable::deleteClassroomById(int id)
{
	Classroom c(id);
	auto i = classrooms.find(c);

	if (i != classrooms.end()) classrooms.erase(i);
	else cout << "Id non trouve." << endl;
}

int addProfessor(const string& lastName,const string& firstName);
void displayProfessors() const;
Professor findProfessorByIndex(int index) const;
Professor findProfessorById(int id) const;
void deleteProfessorByIndex(int index);
void deleteProfessorById(int id);

int addGroup(const string& name);
void displayGroups() const;
Group findGroupByIndex(int index) const;
Group findGroupById(int id) const;
void deleteGroupByIndex(int index);
void deleteGroupById(int id);
