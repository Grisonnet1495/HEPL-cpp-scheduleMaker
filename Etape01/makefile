# Dossier des librairies
LIBH = Classes/
LIBC = Classes/

# Flags
FLAGS = -Wall -g

# Nom de l'exécutable
EXECUTABLE = myprogram

# Nom des fichiers objets
OBJECTS = Test1.o Event.o

# Génère le programme en entier
all: $(EXECUTABLE)

# Génére l'exécutable avec les fichiers objets (-g inclut les informations de débogage)
$(EXECUTABLE): $(OBJECTS)
	g++ -g -o $(EXECUTABLE) $(OBJECTS)

# Génère chaques fichiers objets avec le main, les classese les librairies (-Wall active les warnings)
Test1.o: Test1.cpp
	g++ $(FLAGS) -c Test1.cpp -o Test1.o

Event.o: $(LIBC)Event.cpp
	g++ $(FLAGS) -c $(LIBC)Event.cpp -o Event.o -I $(LIBH)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

