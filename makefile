# Dossier des librairies
LIBH = include/
LIBC = classes/

# Nom de l'exécutable
EXECUTABLE = myprogram

# Fichiers objets
OBJECTS = Test1.o Event.o

# Génère le programme en entier
all: $(EXECUTABLE)

# Génére l'exécutable (-g inclut les informations de débogage)
$(EXECUTABLE): $(OBJECTS)
	g++ -g -o $(EXECUTABLE) $(OBJECTS)

# Génère chaques fichiers objets (-Wall active les warnings)
Test1.o: Test1.cpp
	g++ -Wall -g -c Test1.cpp -o Test1.o

Event.o: $(LIBC)Event.cpp
	g++ -Wall -g -c $(LIBC)Event.cpp -o Event.o -I $(LIBH)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

