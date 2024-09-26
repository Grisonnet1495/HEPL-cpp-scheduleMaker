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

Event.o: Etape01/Classes/Event.cpp
	g++ $(FLAGS) -c Etape01/Classes/Event.cpp -o Event.o -I Etape01/Classes/

Time.o: Etape02/Classes/Time.cpp
	g++ $(FLAGS) -c Etape02/Classes/Time.cpp -o Time.o -I Etape02/Classes/

Timing.o: Etape02/Classes/Timing.cpp
	g++ $(FLAGS) -c Etape02/Classes/Timing.cpp -o Timing.o -I Etape02/Classes/

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
