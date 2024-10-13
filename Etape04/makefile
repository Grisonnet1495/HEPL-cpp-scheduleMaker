# Dossier des librairies

# Debug
DEBUG = -D DEBUG

# Flags
FLAGS = -Wall -g

# Nom de l'exécutable
EXECUTABLE = myprogram

# Nom des fichiers objets
OBJECTS = Test4.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o

# Génère le programme en entier
all: $(EXECUTABLE)

# Génére l'exécutable avec les fichiers objets (-g inclut les informations de débogage)
$(EXECUTABLE): $(OBJECTS)
	g++ -g -o $(EXECUTABLE) $(OBJECTS)

# Génère chaques fichiers objets avec le main, les classese les librairies (-Wall active les warnings)
Test4.o: Test4.cpp
	g++ $(FLAGS) $(DEBUG) -c Test4.cpp -o Test4.o

Event.o: Classes/Event.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Event.cpp -o Event.o

Time.o: Classes/Time.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Time.cpp -o Time.o

Timing.o: Classes/Timing.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Timing.cpp -o Timing.o

Schedulable.o: Classes/Schedulable.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Schedulable.cpp -o Schedulable.o

Professor.o: Classes/Professor.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Professor.cpp -o Professor.o

Group.o: Classes/Group.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Group.cpp -o Group.o

Classroom.o: Classes/Classroom.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Classroom.cpp -o Classroom.o

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
