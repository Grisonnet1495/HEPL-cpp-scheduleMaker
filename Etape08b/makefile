# Dossiers des librairies
PLANNING = Classes/Planning
STRUCTURE = Classes/Structure
EXCEPTION = Classes/Exception

# Debug
DEBUG = #-D DEBUG

# Flags
FLAGS = -Wall -g

# Nom de l'exécutable
EXECUTABLE = myprogram

# Nom des fichiers objets
OBJECTS = Test8b.o \
          Event.o Time.o Timing.o \
          Schedulable.o Professor.o Group.o Classroom.o Timetable.o\
          Exception.o TimeException.o TimingException.o TimetableException.o XmlFileSerializerException.o

# Génère le programme en entier
all: $(EXECUTABLE)
	@echo "Initialisation de la compilation complète... Terminé !"

# Génère l'exécutable avec les fichiers objets
$(EXECUTABLE): $(OBJECTS)
	@echo "Génération de l'exécutable $(EXECUTABLE)..."
	@g++ -g -o $(EXECUTABLE) $(OBJECTS)
	@echo "Compilation réussie. L'exécutable $(EXECUTABLE) est prêt."

# Génère chaque fichier objet individuellement
Test8b.o: Test8b.cpp
	@echo "Compilation de Test8b.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c Test8b.cpp -o Test8b.o

Event.o: $(PLANNING)/Event.cpp
	@echo "Compilation de Event.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(PLANNING)/Event.cpp -o Event.o

Time.o: $(PLANNING)/Time.cpp
	@echo "Compilation de Time.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(PLANNING)/Time.cpp -o Time.o

Timing.o: $(PLANNING)/Timing.cpp
	@echo "Compilation de Timing.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(PLANNING)/Timing.cpp -o Timing.o

Schedulable.o: $(STRUCTURE)/Schedulable.cpp
	@echo "Compilation de Schedulable.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(STRUCTURE)/Schedulable.cpp -o Schedulable.o

Professor.o: $(STRUCTURE)/Professor.cpp
	@echo "Compilation de Professor.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(STRUCTURE)/Professor.cpp -o Professor.o

Group.o: $(STRUCTURE)/Group.cpp
	@echo "Compilation de Group.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(STRUCTURE)/Group.cpp -o Group.o

Classroom.o: $(STRUCTURE)/Classroom.cpp
	@echo "Compilation de Classroom.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(STRUCTURE)/Classroom.cpp -o Classroom.o

Timetable.o: $(STRUCTURE)/Timetable.cpp
	@echo "Compilation de Timetable.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(STRUCTURE)/Timetable.cpp -o Timetable.o

Exception.o: $(EXCEPTION)/Exception.cpp
	@echo "Compilation de Exception.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(EXCEPTION)/Exception.cpp -o Exception.o

TimeException.o: $(EXCEPTION)/TimeException.cpp
	@echo "Compilation de TimeException.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(EXCEPTION)/TimeException.cpp -o TimeException.o

TimingException.o: $(EXCEPTION)/TimingException.cpp
	@echo "Compilation de TimingException.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(EXCEPTION)/TimingException.cpp -o TimingException.o

TimetableException.o: $(EXCEPTION)/TimetableException.cpp
	@echo "Compilation de TimetableException.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(EXCEPTION)/TimetableException.cpp -o TimetableException.o

XmlFileSerializerException.o: $(EXCEPTION)/XmlFileSerializerException.cpp
	@echo "Compilation de XmlFileSerializerException.cpp..."
	@g++ $(FLAGS) $(DEBUG) -c $(EXCEPTION)/XmlFileSerializerException.cpp -o XmlFileSerializerException.o

# Nettoyage
clean:
	@echo "Nettoyage des fichiers objets et de l'exécutable..."
	@rm -f $(EXECUTABLE) $(OBJECTS) *.xml
	@echo "Nettoyage terminé !"
