CC=g++
RMRF= /bin/rm -rf
CFLAGS=-lglut -lGLU -lGL -o

SRC=src/
HEADERS=headers/
BIN=bin
MKDIR_P = mkdir -p

all: 
	$(RMRF) $(BIN) && $(MKDIR_P) $(BIN) && $(CC) $(SRC)color.cpp $(SRC)geometry.cpp $(SRC)light.cpp $(SRC)ray.cpp $(SRC)scene.cpp $(SRC)sphere.cpp $(SRC)winged.cpp $(SRC)glRoutine.cpp $(SRC)glutRoutine.cpp $(SRC)input.cpp $(SRC)rtRoutine.cpp $(SRC)main.cpp -I$(HEADERS) $(CFLAGS) $(BIN)/main



clean:
	$(RMRF) $(BIN)
