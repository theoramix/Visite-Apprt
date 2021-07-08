BIN = main
FLAGS = -Wall -g
INC = 
LIBS = -lglut -lGLU -lGL -lm
GCC = g++
OBJECTS = rectangle.o main.o camera.o

default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

rectangle.o: rectangle.c rectangle.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

camera.o: camera.c camera.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

main.o: main.c
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;