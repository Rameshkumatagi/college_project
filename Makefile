CFLAGS=-Wall
project: project.o
	$(CXX) -o project project.o

project.o: project.cpp
	$(CXX) -std=c++11 -c  project.cpp

clean:
	rm project
