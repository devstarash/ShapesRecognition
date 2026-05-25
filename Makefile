CXX = g++
CXXFLAGS = -std=c++17 -Wall

ROOT_SRC = src/Circle.cpp \
           src/Ellipse.cpp \
           src/Polygon.cpp \
           src/Rectangle.cpp \
           src/Triangle.cpp \
           src/VerticesFileReader.cpp

TASK_SRC = tasks/src/ComponentFinder.cpp \
           tasks/src/GridLoader.cpp \
           tasks/src/ResultWriter.cpp \
           tasks/src/ShapeClassifier.cpp \
           tasks/src/Main.cpp

INCLUDES = -I include \
           -I Exceptions \
           -I tasks/include

TARGET = tasks/bin/task1

.PHONY: all run clean

all: clean $(TARGET)

$(TARGET):
	mkdir -p tasks/bin
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(ROOT_SRC) $(TASK_SRC) -o $(TARGET)

run: all
	cd tasks && ./bin/task1

clean:
	rm -rf tasks/bin