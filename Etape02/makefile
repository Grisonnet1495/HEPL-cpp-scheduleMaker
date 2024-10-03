# Dossier des librairies

# Flags
FLAGS = -Wall -g

# Nom de l'exécutable
EXECUTABLE = myprogram

# Nom des fichiers objets
OBJECTS = Test2.o Event.o Time.o Timing.o

# Génère le programme en entier
all: $(EXECUTABLE)

# Génére l'exécutable avec les fichiers objets (-g inclut les informations de débogage)
$(EXECUTABLE): $(OBJECTS)
	g++ -g -o $(EXECUTABLE) $(OBJECTS)

# Génère chaques fichiers objets avec le main, les classese les librairies (-Wall active les warnings)
Test2.o: Test2.cpp
	g++ $(FLAGS) -c Test2.cpp -o Test2.o

Event.o: Classes/Event.cpp
	g++ $(FLAGS) -c Classes/Event.cpp -o Event.o

Time.o: Classes/Time.cpp
	g++ $(FLAGS) -c Classes/Time.cpp -o Time.o

Timing.o: Classes/Timing.cpp
	g++ $(FLAGS) -c Classes/Timing.cpp -o Timing.o

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
