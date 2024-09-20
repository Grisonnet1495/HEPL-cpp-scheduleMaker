# Nom de l'exécutable
EXECUTABLE = myprogram


# Fichiers objets
OBJECTS = Test1.o Event.o


# Génère le programme en entier
all: $(EXECUTABLE)

# Génére l'exécutable (-Wall active les warnings et -g inclut les informations de débogage)
$(EXECUTABLE): $(OBJECTS)
	g++ -g -o $(EXECUTABLE) $(OBJECTS)

# Génère chaques fichiers objets
Test1.o: Test1.cpp
	g++ -Wall -g -c Test1.cpp -o Test1.o

Event.o: Event.cpp
	g++ -Wall -g -c Event.cpp -o Event.o

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

