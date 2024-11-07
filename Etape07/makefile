# Dossier des librairies

# Debug
DEBUG = #-D DEBUG

# Flags
FLAGS = -Wall -g

# Nom de l'exécutable
EXECUTABLE = myprogram

# Nom des fichiers objets
OBJECTS = Test6.o Event.o Time.o Timing.o Schedulable.o Professor.o Group.o Classroom.o Exception.o TimeException.o TimingException.o

# Génère le programme en entier
all: $(EXECUTABLE)

# Génére l'exécutable avec les fichiers objets (-g inclut les informations de débogage)
$(EXECUTABLE): $(OBJECTS)
	g++ -g -o $(EXECUTABLE) $(OBJECTS)

# Génère chaques fichiers objets avec le main, les classese les librairies (-Wall active les warnings)
Test6.o: Test6.cpp
	g++ $(FLAGS) $(DEBUG) -c Test6.cpp -o Test6.o

Event.o: Classes/Planning/Event.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Planning/Event.cpp -o Event.o

Time.o: Classes/Planning/Time.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Planning/Time.cpp -o Time.o

Timing.o: Classes/Planning/Timing.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Planning/Timing.cpp -o Timing.o

Schedulable.o: Classes/Structure/Schedulable.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Structure/Schedulable.cpp -o Schedulable.o

Professor.o: Classes/Structure/Professor.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Structure/Professor.cpp -o Professor.o

Group.o: Classes/Structure/Group.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Structure/Group.cpp -o Group.o

Classroom.o: Classes/Structure/Classroom.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Structure/Classroom.cpp -o Classroom.o

Exception.o: Classes/Exception/Exception.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Exception/Exception.cpp -o Exception.o

TimeException.o: Classes/Exception/TimeException.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Exception/TimeException.cpp -o TimeException.o

TimingException.o: Classes/Exception/TimingException.cpp
	g++ $(FLAGS) $(DEBUG) -c Classes/Exception/TimingException.cpp -o TimingException.o

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) *.xml
